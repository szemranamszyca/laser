add_executable(testControlPanel main.cpp TestControlPanel.cpp)

target_link_libraries(
    testControlPanel
    ControlPanel
    libgtest
    libgmock
)

add_test(NAME testControlPanel
         COMMAND testControlPanel)