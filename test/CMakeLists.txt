add_custom_command(OUTPUT libflibc-prefixed.a
  COMMAND ${CMAKE_OBJCOPY}
  ARGS $<TARGET_FILE:flibc::flibc> --prefix-symbols=flibc_ libflibc-prefixed.a
  DEPENDS flibc::flibc)
add_custom_target(flibc-prefixed.a DEPENDS libflibc-prefixed.a)

add_library(flibc-prefixed STATIC IMPORTED)
set_target_properties(flibc-prefixed PROPERTIES
  IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/libflibc-prefixed.a)
add_dependencies(flibc-prefixed flibc-prefixed.a)

add_executable(flibc-test
  ctype.c
  main.c
  stdio.c
  stdlib.c
  string.c)
target_include_directories(flibc-test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(flibc-test flibc-prefixed)
add_test(NAME flibc-test COMMAND flibc-test)
