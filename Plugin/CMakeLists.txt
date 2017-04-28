
add_library(Plugin SHARED
  P.hpp
  P.cpp
  P-serial.hpp
  Plugin.hpp
  Plugin.cpp
  InitPlugin.cpp
  serial_plugin_p.cpp
  )
target_link_libraries(Plugin Z)

add_executable(test_Plugin testing/test_Plugin.cxx)
target_link_libraries(test_Plugin Plugin )
add_test(NAME test_Plugin COMMAND test_Plugin)

add_executable(test_Plugin_2 testing/test_Plugin_2.cxx)
set(PLUGIN_TEST_ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(test_Plugin_2 XY -ldl)
add_test(NAME test_Plugin_2 COMMAND test_Plugin_2)
set_property(TEST test_Plugin_2
  APPEND PROPERTY ENVIRONMENT ${PLUGIN_TEST_ENVIRONMENT}
  )
