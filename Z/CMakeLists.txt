
add_library(Z SHARED
  Z.hpp
  Z.cpp
  Z-serial.hpp
  C.hpp
  C.cpp
  C-serial.hpp
  serial_z_c.cpp
  )
target_link_libraries(Z XY)

add_executable(test_Z testing/test_Z.cxx)
target_link_libraries(test_Z Z)
add_test(NAME test_Z COMMAND test_Z)

add_executable(test_C testing/test_C.cxx)
target_link_libraries(test_C Z)
add_test(NAME test_C COMMAND test_C)
