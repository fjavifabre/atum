
# Sphere test
add_executable(sphereTest sphere.cpp)
target_link_libraries(sphereTest gtest gtest_main)
target_link_libraries(sphereTest atum)
add_test(
  NAME
  sphereTest
  COMMAND
  ${PROJECT_SOURCE_DIR}/bin/sphereTest
)

# Triangle test
add_executable(triangleTest triangle.cpp)
target_link_libraries(triangleTest gtest gtest_main)
target_link_libraries(triangleTest atum)
add_test(
  NAME
  triangleTest
  COMMAND
  ${PROJECT_SOURCE_DIR}/bin/triangleTest
)



