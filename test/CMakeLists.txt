cmake_minimum_required(VERSION 3.8)

set(This SimTests)

set(Sources SimTests.cpp Data.cpp Graph.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Simulation
)

add_test(
    NAME ${This}
    COMMAND ${This}
)