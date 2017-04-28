
add_library(XY SHARED
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

add_executable(test_X_2 testing/test_X_2.cxx)
target_link_libraries(test_X_2 XY)
add_test(NAME test_X_2 COMMAND test_X_2)

add_executable(test_Y testing/test_Y.cxx)
target_link_libraries(test_Y XY)
add_test(NAME test_Y COMMAND test_Y)

add_executable(test_Y_2 testing/test_Y_2.cxx)
target_link_libraries(test_Y_2 XY)
add_test(NAME test_Y_2 COMMAND test_Y_2)

add_executable(test_AB testing/test_AB.cxx)
target_link_libraries(test_AB XY)
add_test(NAME test_AB COMMAND test_AB)

add_executable(test_AB_2 testing/test_AB_2.cxx)
target_link_libraries(test_AB_2 XY)
add_test(NAME test_AB_2 COMMAND test_AB_2)
