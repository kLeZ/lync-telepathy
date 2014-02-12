
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(lync-telepathyTest_SRCS lync-telepathyTest.cpp)
qt4_automoc(${lync-telepathyTest_SRCS})
add_executable(lync-telepathyTest ${lync-telepathyTest_SRCS})
add_test(lync-telepathyTest lync-telepathyTest)
target_link_libraries(lync-telepathyTest ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY})
