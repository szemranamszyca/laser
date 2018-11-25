add_executable(TestControlPanel main.cpp TestControlPanel.cpp)      

target_link_libraries(
    TestControlPanel
    ControlPanel
    libgtest
    libgmock
    test_warnings --coverage
)

add_test(NAME TestControlPanel
         COMMAND TestControlPanel)
