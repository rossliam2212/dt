/**
 * @file DateTimeUtilsTest.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 31/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <gtest/gtest.h>

#include "../include/dt/utils/DateTimeUtils.hpp"

/**
 * @brief @c DateTimeUtils test 1.
 */
TEST(DateTimeUtils, GIVEN_dateObjects_WHEN_daysBetweenCalled_THEN_correctValuesReturned) {
    dt::Date date1{1, 1, 2023};
    dt::Date date2{31, 7, 2023};
    dt::Date date3{9, 7, 2002};
    dt::Date date4{22, 12, 2001};

    ASSERT_EQ(211, dt::DateTimeUtils::daysBetween(date1, date2));
    ASSERT_EQ(199, dt::DateTimeUtils::daysBetween(date3, date4));
    ASSERT_EQ(7680, dt::DateTimeUtils::daysBetween(date1, date4));
    ASSERT_EQ(7692, dt::DateTimeUtils::daysBetween(date2, date3));
}

/**
 * @brief @c DateTimeUtils test 2.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_monthsBetweenCalled_THEN_correctValuesReturned) {
    dt::Date date1{1, 1, 2023};
    dt::Date date2{31, 7, 2023};
    dt::Date date3{9, 7, 2002};
    dt::Date date4{22, 12, 2001};

    ASSERT_EQ(6, dt::DateTimeUtils::monthsBetween(date1, date2));
    ASSERT_EQ(7, dt::DateTimeUtils::monthsBetween(date3, date4));
    ASSERT_EQ(253, dt::DateTimeUtils::monthsBetween(date1, date4));
    ASSERT_EQ(252, dt::DateTimeUtils::monthsBetween(date2, date3));
}

/**
 * @brief @c DateTimeUtils test 3.
 */
TEST(DateTimeUtils, GIVEN_dateObjects_WHEN_yearsBetweenCalled_THEN_correctValuesReturned) {
    dt::Date date1{1, 1, 2023};
    dt::Date date2{1, 1, 2024};
    dt::Date date3{1, 1, 2012};
    dt::Date date4{1, 1, 2000};

    ASSERT_EQ(1, dt::DateTimeUtils::yearsBetween(date1, date2));
    ASSERT_EQ(24, dt::DateTimeUtils::yearsBetween(date4, date2));
    ASSERT_EQ(11, dt::DateTimeUtils::yearsBetween(date1, date3));
    ASSERT_EQ(12, dt::DateTimeUtils::yearsBetween(date4, date3));
    ASSERT_EQ(12, dt::DateTimeUtils::yearsBetween(date2, date3));
    ASSERT_EQ(23, dt::DateTimeUtils::yearsBetween(date4, date1));
}

/**
 * @brief @c DateTimeUtils test 4.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_isLeapYearCalled_THEN_correctValuesReturned) {
    ASSERT_TRUE(dt::DateTimeUtils::isLeapYear(1804));
    ASSERT_TRUE(dt::DateTimeUtils::isLeapYear(1960));
    ASSERT_TRUE(dt::DateTimeUtils::isLeapYear(2040));
    ASSERT_FALSE(dt::DateTimeUtils::isLeapYear(2023));
    ASSERT_FALSE(dt::DateTimeUtils::isLeapYear(2011));
    ASSERT_FALSE(dt::DateTimeUtils::isLeapYear(1887));
}

/**
 * @brief @c DateTimeUtils test 5.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_daysInMonthCalled_THEN_correctValuesReturned) {
    ASSERT_EQ(31, dt::DateTimeUtils::daysInMonth(2023, 8)); // Aug 2023
    ASSERT_EQ(28, dt::DateTimeUtils::daysInMonth(2023, 2)); // Feb 2023
    ASSERT_EQ(29, dt::DateTimeUtils::daysInMonth(2040, 2)); // Feb 2023
}

/**
 * @brief @c DateTimeUtils test 6.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_daysInYearCalled_THEN_correctValuesReturned) {
    ASSERT_EQ(365, dt::DateTimeUtils::daysInYear(2023));
    ASSERT_EQ(366, dt::DateTimeUtils::daysInYear(2040));
    ASSERT_EQ(365, dt::DateTimeUtils::daysInYear(2022));
}

/**
 * @brief @c DateTimeUtils test 7.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_dayOfYearCalled_THEN_correctValuesReturned) {
    dt::Date date{1, 1, 2023};
    ASSERT_EQ(1, dt::DateTimeUtils::dayOfYear(date));

    dt::Date date2{"01-03-2023"};
    ASSERT_EQ(60, dt::DateTimeUtils::dayOfYear(date2));
}

/**
 * @brief @c DateTimeUtils test 8.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_daysToMinutesCalled_THEN_correctValuesReturned) {
    ASSERT_EQ(1440, dt::DateTimeUtils::daysToMinutes(1));
    ASSERT_EQ(7200, dt::DateTimeUtils::daysToMinutes(5));
    ASSERT_EQ(0, dt::DateTimeUtils::daysToMinutes(-10));
}

/**
 * @brief @c DateTimeUtils test 9.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_daysToSecondsCalled_THEN_correctValuesReturned) {
    ASSERT_EQ(86400, dt::DateTimeUtils::daysToSeconds(1));
    ASSERT_EQ(432000, dt::DateTimeUtils::daysToSeconds(5));
    ASSERT_EQ(0, dt::DateTimeUtils::daysToSeconds(-10));
}

/**
 * @brief @c DateTimeUtils test 10.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_daysToHoursCalled_THEN_correctValuesReturned) {
    ASSERT_EQ(24, dt::DateTimeUtils::daysToHours(1));
    ASSERT_EQ(120, dt::DateTimeUtils::daysToHours(5));
    ASSERT_EQ(0, dt::DateTimeUtils::daysToHours(-10));
}

/**
 * @brief @c DateTimeUtils test 11.
 */
TEST(DateTimeUtils, GIVEN_dateTimeUtils_WHEN_parseDateStrings_THEN_datesCorrectlyParsed) {
    std::vector<std::string> dateStrings {
            "22-12-2001",
            "22/12/2001",
            "22-11-2001",
            "09-07-2002",
            "22-10-2010",
    };
    std::vector<dt::Date> expectedDates {
            {"22-12-2001"},
            {"22/12/2001"},
            {"22-11-2001"},
            {"09-07-2002"},
            {"22-10-2010"}
    };

    std::vector<dt::Date> result{dt::DateTimeUtils::parseDateStrings(dateStrings)};
    for (int i{0}; i < result.size(); ++i) {
        ASSERT_EQ(expectedDates.at(i), result.at(i));
    }
}
