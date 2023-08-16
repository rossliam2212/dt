cmake_minimum_required(VERSION 3.25)
project(dt)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_INSTALL_DIR include/dt)

set(HEADER_FILES
        include/dt/Constants.hpp
        include/dt/date/Date.hpp
        include/dt/time/TimeStamp.hpp
        include/dt/utils/DateTimeUtils.hpp
        include/dt/exceptions/InvalidDateException.hpp
        include/dt/exceptions/InvalidTimeException.hpp
        include/dt/exceptions/DateParseException.hpp
        include/dt/exceptions/TimeParseException.hpp
        include/dt/date/FormattedDate.hpp
        include/dt/time/StopWatch.hpp
        include/dt/date/Calendar.hpp)

set(SOURCE_FILES
        src/date/Date.cpp
        src/time/TimeStamp.cpp
        src/utils/DateTimeUtils.cpp
        src/exceptions/InvalidDateException.cpp
        src/exceptions/InvalidTimeException.cpp
        src/exceptions/DateParseException.cpp
        src/exceptions/TimeParseException.cpp
        src/date/FormattedDate.cpp
        src/time/StopWatch.cpp
        src/date/Calendar.cpp)

# Library
add_library(dt STATIC ${SOURCE_FILES})
target_include_directories(dt PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS dt EXPORT dtTargets ARCHIVE DESTINATION lib)
install(EXPORT dtTargets FILE dtTargets.cmake NAMESPACE dt:: DESTINATION lib/cmake/dt)

install(FILES include/dt/Constants.hpp DESTINATION include/dt)
install(FILES include/dt/date/Date.hpp DESTINATION include/dt/date)
install(FILES include/dt/date/FormattedDate.hpp DESTINATION include/dt/date)
install(FILES include/dt/date/Calendar.hpp DESTINATION include/dt/date)
install(FILES include/dt/time/TimeStamp.hpp DESTINATION include/dt/time)
install(FILES include/dt/time/StopWatch.hpp DESTINATION include/dt/time)
install(FILES include/dt/utils/DateTimeUtils.hpp DESTINATION include/dt/utils)
install(FILES include/dt/exceptions/InvalidDateException.hpp DESTINATION include/dt/exceptions)
install(FILES include/dt/exceptions/InvalidTimeException.hpp DESTINATION include/dt/exceptions)
install(FILES include/dt/exceptions/DateParseException.hpp DESTINATION include/dt/exceptions)
install(FILES include/dt/exceptions/TimeParseException.hpp DESTINATION include/dt/exceptions)


# Google Test
include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.13.0)
FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif ()

set(TEST_FILES
        test/DateTest.cpp
        test/DateTimeUtilsTest.cpp
        test/TimeStampTest.cpp
        test/FormattedDateTest.cpp
        test/StopWatchTest.cpp
        test/CalendarTest.cpp)
add_executable(tests ${TEST_FILES} ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(tests gtest_main gmock_main)