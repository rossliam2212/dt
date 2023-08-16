/**
 * @file TimeStampTest.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 01/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <gtest/gtest.h>

#include "../include/dt/time/TimeStamp.hpp"

/**
 * @brief @c TimeStamp test 1.
 */
TEST(TimeStamp, GIVEN_timeStampObject_WHEN_createdWithValidTime_THEN_correctValuesSet) {
    dt::TimeStamp time{1, 1, 1, 1};

    ASSERT_EQ(1, time.getHour());
    ASSERT_EQ(1, time.getMinute());
    ASSERT_EQ(1, time.getSecond());
    ASSERT_EQ(1, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 2.
 */
TEST(TimeStamp, GIVEN_defaultTimeStampObject_WHEN_created_THEN_defaultValuesSet) {
    dt::TimeStamp time;

    ASSERT_EQ(0, time.getHour());
    ASSERT_EQ(0, time.getMinute());
    ASSERT_EQ(0, time.getSecond());
    ASSERT_EQ(0, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 3.
 */
TEST(TimeStamp, GIVEN_defaultTimeStampObject_WHEN_createdWithInvalidHour_THEN_defaultValuesSet) {
    dt::TimeStamp time{25, 1, 1, 1};

    ASSERT_EQ(0, time.getHour());
    ASSERT_EQ(0, time.getMinute());
    ASSERT_EQ(0, time.getSecond());
    ASSERT_EQ(0, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 4.
 */
TEST(TimeStamp, GIVEN_defaultTimeStampObject_WHEN_createdWithInvalidMinute_THEN_defaultValuesSet) {
    dt::TimeStamp time{1, 80, 1, 1};

    ASSERT_EQ(0, time.getHour());
    ASSERT_EQ(0, time.getMinute());
    ASSERT_EQ(0, time.getSecond());
    ASSERT_EQ(0, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 5.
 */
TEST(TimeStamp, GIVEN_defaultTimeStampObject_WHEN_createdWithInvalidSecond_THEN_defaultValuesSet) {
    dt::TimeStamp time{1, 1, 80, 1};

    ASSERT_EQ(0, time.getHour());
    ASSERT_EQ(0, time.getMinute());
    ASSERT_EQ(0, time.getSecond());
    ASSERT_EQ(0, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 6.
 */
TEST(TimeStamp, GIVEN_defaultTimeStampObject_WHEN_createdWithInvalidMillisecond_THEN_defaultValuesSet) {
    dt::TimeStamp time{0, 1, 1, 1000};

    ASSERT_EQ(0, time.getHour());
    ASSERT_EQ(0, time.getMinute());
    ASSERT_EQ(0, time.getSecond());
    ASSERT_EQ(0, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 7.
 */
TEST(TimeStamp, GIVEN_timeStamp_WHEN_parsedFromStringWithValidPatternAndValidTime_THEN_correctTimeSet) {
    dt::TimeStamp time{"01:01:01:001"};

    ASSERT_EQ(1, time.getHour());
    ASSERT_EQ(1, time.getMinute());
    ASSERT_EQ(1, time.getSecond());
    ASSERT_EQ(1, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 8.
 */
TEST(TimeStamp, GIVEN_timeStamp_WHEN_parsedFromStringWithInvalidPattern_THEN_exceptionThrown) {
    ASSERT_THROW(dt::TimeStamp time{"01:01:01:0001"}, dt::DateParseException);
    ASSERT_THROW(dt::TimeStamp time{"001:01:01:001"}, dt::DateParseException);
    ASSERT_THROW(dt::TimeStamp time{"01:001:01:001"}, dt::DateParseException);
    ASSERT_THROW(dt::TimeStamp time{"01:01:001:001"}, dt::DateParseException);
}

/**
 * @brief @c TimeStamp test 9.
 */
TEST(TimeStamp, GIVEN_timeStampObject_WHEN_addHoursCalled_THEN_correctValuesSet) {
    dt::TimeStamp expectedTime{4, 1, 1, 1};
    dt::TimeStamp time{1, 1, 1, 1};
    time.addHours(3);
    ASSERT_EQ(expectedTime, time);

    dt::TimeStamp expectedTime2{23, 1, 1, 1};
    time.addHours(-5);
    ASSERT_EQ(expectedTime2, time);

    dt::TimeStamp expectedTime3{0, 1, 1, 1};
    time.addHours(1);
    ASSERT_EQ(expectedTime3, time);
}

/**
 * @brief @c TimeStamp test 10.
 */
TEST(TimeStamp, GIVEN_timeStampObject_WHEN_addMinutesCalled_THEN_correctValuesSet) {
    dt::TimeStamp expectedTime{1, 4, 1, 1};
    dt::TimeStamp time{1, 1, 1, 1};
    time.addMinutes(3);
    ASSERT_EQ(expectedTime, time);

    dt::TimeStamp expectedTime2{0, 59, 1, 1};
    time.addMinutes(-5);
    ASSERT_EQ(expectedTime2, time);

    dt::TimeStamp expectedTime3{2, 0, 1, 1};
    time.addMinutes(61);
    ASSERT_EQ(expectedTime3, time);
}

/**
 * @brief @c TimeStamp test 11.
 */
TEST(TimeStamp, GIVEN_timeStampObject_WHEN_addSecondsCalled_THEN_correctValuesSet) {
    dt::TimeStamp expectedTime{1, 1, 4, 1};
    dt::TimeStamp time{1, 1, 1, 1};
    time.addSeconds(3);
    ASSERT_EQ(expectedTime, time);

    dt::TimeStamp expectedTime2{1, 0, 59, 1};
    time.addSeconds(-5);
    ASSERT_EQ(expectedTime2, time);

    dt::TimeStamp expectedTime3{1, 1, 0, 1};
    time.addSeconds(1);
    ASSERT_EQ(expectedTime3, time);
}

/**
 * @brief @c TimeStamp test 12.
 */
TEST(TimeStamp, GIVEN_timeStampObject_WHEN_addMillisecondsCalled_THEN_correctValuesSet) {
    dt::TimeStamp expectedTime{1, 1, 1, 4};
    dt::TimeStamp time{1, 1, 1, 1};
    time.addMilliseconds(3);
    ASSERT_EQ(expectedTime, time);

    dt::TimeStamp expectedTime2{1, 1, 0, 999};
    time.addMilliseconds(-5);
    ASSERT_EQ(expectedTime2, time);

    dt::TimeStamp expectedTime3{1, 1, 1, 0};
    time.addMilliseconds(1);
    ASSERT_EQ(expectedTime3, time);
}

/**
 * @brief @c TimeStamp test 13.
 */
TEST(TimeStamp, GIVEN_timeStampObject_WHEN_setTimeCalledWithValidTime_THEN_correctValuesSet) {
    dt::TimeStamp time;
    time.setTime(1, 1, 1, 1);

    ASSERT_EQ(1, time.getHour());
    ASSERT_EQ(1, time.getMinute());
    ASSERT_EQ(1, time.getSecond());
    ASSERT_EQ(1, time.getMillisecond());
}

/**
 * @brief @c TimeStamp test 14.
 */
TEST(TimeStamp, GIVEN_timeStampObject_WHEN_toStringCalled_THEN_timeCorrectlyFormatted) {
    std::string formattedTime1{"01:01:01:001"};
    std::string formattedTime2{"12:10:05:222"};
    dt::TimeStamp time1{1, 1, 1, 1};
    dt::TimeStamp time2{12, 10, 5, 222};

    ASSERT_EQ(formattedTime1, time1.toString());
    ASSERT_EQ(formattedTime2, time2.toString());
}

/**
 * @brief @c TimeStamp test 15.
 */
TEST(TimeStamp, GIVEN_twoEqualTimeStampObjects_WHEN_compared_THEN_equal) {
    dt::TimeStamp time1{1, 1, 1, 1};
    dt::TimeStamp time2{1, 1, 1, 1};

    ASSERT_EQ(time1, time2);
    ASSERT_EQ(time2, time1);
    ASSERT_LE(time1, time2);
    ASSERT_LE(time2, time1);
    ASSERT_GE(time1, time2);
    ASSERT_GE(time2, time1);
}

/**
 * @brief @c TimeStamp test 16.
 */
TEST(TimeStamp, GIVEN_twoDifferentTimeStampObjects_WHEN_compared_THEN_notEqual) {
    dt::TimeStamp time1{1, 1, 1, 1};
    dt::TimeStamp time2{12, 1, 1, 1};
    ASSERT_NE(time1, time2);
    ASSERT_NE(time2, time1);
}

/**
 * @brief @c TimeStamp test 17.
 */
TEST(TimeStamp, GIVEN_twoDifferentTimeStampObjects_WHEN_compared_THEN_correctValuesReturned) {
    dt::TimeStamp time1{1, 1, 1, 1};
    dt::TimeStamp time2{12, 1, 1, 1};
    ASSERT_LT(time1, time2);
    ASSERT_GT(time2, time1);
}
