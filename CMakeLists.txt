cmake_minimum_required(VERSION 3.9.1)

project(laser_emulator)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
    -Wall
    -Wextra # reasonable and standard
    -Wshadow # warn the user if a variable declaration shadows one from a
          # parent context
    -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                    # non-virtual destructor. This helps catch hard to
                    # track down memory errors
    -Wold-style-cast # warn for c-style casts
    -Wcast-align # warn for potential performance problem casts
    -Wunused # warn on anything being unused
    -Woverloaded-virtual # warn if you overload (not override) a virtual
                      # function
    -Wpedantic # warn if non-standard C++ is used
    -Wconversion # warn on type conversions that may lose data
    -Wsign-conversion # warn on sign conversions
    -Wmisleading-indentation # warn if identation implies blocks where blocks
                          # do not exist
    -Wduplicated-cond # warn if if / else chain has duplicated conditions
    -Wduplicated-branches # warn if if / else branches have duplicated code
    -Wlogical-op # warn about logical operations being used where bitwise were
              # probably wanted
    -Wnull-dereference # warn if a null dereference is detected
    -Wuseless-cast # warn if you perform a cast to the same type
    -Wdouble-promotion # warn if float is implicit promoted to double
    -Wformat=2 # warn on security issues around functions that format output
            # (ie printf)
)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}")

enable_testing()
add_subdirectory(test)

add_subdirectory(HMI/src)
add_subdirectory(cmdProcessor/src)
add_subdirectory(controlPanel/src)

### add pthreads support
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

### end pthreads support



add_executable(laser src/Laser.cpp ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(laser HMI CmdProcessor ControlPanel Threads::Threads)