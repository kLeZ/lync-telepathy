project(lync-telepathy)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(TelepathyQt4 REQUIRED)
enable_testing()

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${TELEPATHY_QT4_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set(lync-telepathy_SRCS lync-telepathy.cpp protocols.cpp cm-wrapper.cpp main.cpp)

qt4_automoc(${lync-telepathy_SRCS})
add_executable(lync-telepathy ${lync-telepathy_SRCS} ${MCS})
target_link_libraries(lync-telepathy ${QT_QTCORE_LIBRARY} ${TELEPATHY_QT4_LIBRARIES})

add_subdirectory(tests)
