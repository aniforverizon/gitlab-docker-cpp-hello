set(TESTNAME vanilla)
set(TESTSRC main.cpp)
add_executable(${TESTNAME} ${TESTSRC})
target_link_libraries(${TESTNAME} gtest_main gtest)
add_test(NAME ${TESTNAME}
    COMMAND ${TESTNAME}
    WORKING_DIRECTORY .)