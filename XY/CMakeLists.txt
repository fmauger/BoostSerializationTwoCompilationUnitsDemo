
configure_file(config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/config.hpp @ONLY)

add_library(XY SHARED
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  X.hpp
  X.cpp
  X-serial.hpp
  Y.hpp
  Y.cpp
  Y-serial.hpp
  A.hpp
  A.cpp
  A-serial.hpp
  B.hpp
  B.cpp
  B-serial.hpp
  PluginSupport.hpp
  PluginSupport.cpp
  serial_xy_ab.cpp
  )
target_link_libraries(XY Boost::serialization)

add_executable(test_X testing/test_X.cxx)
target_link_libraries(test_X XY)
add_test(NAME test_X COMMAND test_X)

add_executable(test_Y testing/test_Y.cxx)
target_link_libraries(test_Y XY)
add_test(NAME test_Y COMMAND test_Y)

add_executable(test_AB testing/test_AB.cxx)
target_link_libraries(test_AB XY)
add_test(NAME test_AB COMMAND test_AB)
