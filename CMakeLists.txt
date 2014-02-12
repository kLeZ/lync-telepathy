project(lync-telepathy)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
enable_testing()

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(lync-telepathy_SRCS lync-telepathy.cpp main.cpp)
qt4_automoc(${lync-telepathy_SRCS})
add_executable(lync-telepathy ${lync-telepathy_SRCS})
target_link_libraries(lync-telepathy ${QT_QTCORE_LIBRARY})

add_subdirectory(tests)
