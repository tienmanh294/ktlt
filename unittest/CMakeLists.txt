cmake_minimum_required(VERSION 3.8)

set(This UnitTest)

set(Sources
    UnitTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    ktlt
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
