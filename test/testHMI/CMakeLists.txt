add_executable(TestHMI main.cpp TestHMI.cpp)

target_link_libraries(
    TestHMI 
    HMI
    libgtest
    libgmock
    test_warnings --coverage
)

add_test(NAME TestHMI
	COMMAND TestHMI)
