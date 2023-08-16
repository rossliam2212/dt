/**
 * @file StopWatchTest.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 03/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <gtest/gtest.h>
#include <thread>

#include "../include/dt/time/StopWatch.hpp"

/**
 * @brief @c StopWatch test 1.
 */
TEST(StopWatch, GIVEN_stopWatchObject_WHEN_getElapsedMillisecondsCalled_THEN_correctMillisecondsReturned) {
    dt::StopWatch stopWatch;
    stopWatch.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    stopWatch.stop();

    ASSERT_LE(500, stopWatch.getElapsedMilliseconds());
}

/**
 * @brief @c StopWatch test 2.
 */
TEST(StopWatch, GIVEN_stopWatchObject_WHEN_getElapsedSecondsCalled_THEN_correctMillisecondsReturned) {
    dt::StopWatch stopWatch;
    stopWatch.start();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    stopWatch.stop();

    ASSERT_LE(1.0, stopWatch.getElapsedSeconds());
}
