# Add each test here
add_executable(sphereTest sphere.cpp)

# Standard linking to gtest stuff.
target_link_libraries(sphereTest gtest gtest_main)

# Standard linking to gtest stuff.
target_link_libraries(sphereTest atum)

add_test(
  NAME
    unit
  COMMAND
    ${PROJECT_SOURCE_DIR}/bin/sphereTest
)
