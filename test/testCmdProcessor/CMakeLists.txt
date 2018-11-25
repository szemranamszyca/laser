add_executable(TestCmdProcessor main.cpp TestCmdProcessor.cpp)      

target_link_libraries(
    TestCmdProcessor
    CmdProcessor
    libgtest
    libgmock
    project_warnings --coverage
)

add_test(NAME TestCmdProcessor
         COMMAND TestCmdProcessor)
