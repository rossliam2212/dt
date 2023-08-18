/**
 * @file CalendarTest.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 04/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <gtest/gtest.h>

#include "../include/dt/date/Calendar.hpp"

/**
 * @brief @c Calendar test 1.
 */
TEST(Calendar, GIVEN_defaultCalendarObject_WHEN_created_THEN_defaultValuesSet) {
    dt::Date expectedDate{1, 1, 1583};
    dt::Calendar calendar;

    ASSERT_EQ(1, calendar.getCurrentDay());
    ASSERT_EQ(1, calendar.getCurrentMonth());
    ASSERT_EQ(1583, calendar.getCurrentYear());
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());
}

/**
 * @brief @c Calendar test 2.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_createdWithValidDayMonthYear_THEN_valuesSet) {
    dt::Date expectedDate{22, 12, 2001};
    dt::Calendar calendar{22, 12, 2001};

    ASSERT_EQ(22, calendar.getCurrentDay());
    ASSERT_EQ(12, calendar.getCurrentMonth());
    ASSERT_EQ(2001, calendar.getCurrentYear());
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());
}

/**
 * @brief @c Calendar test 3.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_createdWithValidMonthYear_THEN_valuesSet) {
    dt::Date expectedDate{1, 12, 2001};
    dt::Calendar calendar{12, 2001};

    ASSERT_EQ(1, calendar.getCurrentDay());
    ASSERT_EQ(12, calendar.getCurrentMonth());
    ASSERT_EQ(2001, calendar.getCurrentYear());
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());
}

/**
 * @brief @c Calendar test 4.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_createdWithDate_THEN_valuesSet) {
    dt::Date expectedDate{9, 7, 2002};

    dt::Date date{9, 7, 2002};
    dt::Calendar calendar{date};

    ASSERT_EQ(9, calendar.getCurrentDay());
    ASSERT_EQ(7, calendar.getCurrentMonth());
    ASSERT_EQ(2002, calendar.getCurrentYear());
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());
}

/**
 * @brief @c Calendar test 5.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_getDatesCalled_THEN_correctValuesReturned) {
    std::vector<dt::Date> expectedDates {
            {1, 8, 2023},
            {2, 8, 2023},
            {3, 8, 2023},
            {4, 8, 2023},
            {5, 8, 2023},
            {6, 8, 2023},
            {7, 8, 2023},
            {8, 8, 2023},
            {9, 8, 2023},
            {10, 8, 2023},
            {11, 8, 2023},
            {12, 8, 2023},
            {13, 8, 2023},
            {14, 8, 2023},
            {15, 8, 2023},
            {16, 8, 2023},
            {17, 8, 2023},
            {18, 8, 2023},
            {19, 8, 2023},
            {20, 8, 2023},
            {21, 8, 2023},
            {22, 8, 2023},
            {23, 8, 2023},
            {24, 8, 2023},
            {25, 8, 2023},
            {26, 8, 2023},
            {27, 8, 2023},
            {28, 8, 2023},
            {29, 8, 2023},
            {30, 8, 2023},
            {31, 8, 2023},
    };

    dt::Calendar calendar{8, 2023};
    for (int i{0}; i < calendar.getDates().size(); ++i) {
        ASSERT_EQ(expectedDates.at(i), calendar.getDates().at(i));
    }
}

/**
 * @brief @c Calendar test 6.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_incrementedPre_THEN_correctlyIncremented) {
    dt::Date expectedDate{1, 2, 2023};
    dt::Calendar calendar{1, 1, 2023};
    ++calendar;

    ASSERT_EQ(1, calendar.getCurrentDay());
    ASSERT_EQ(2, calendar.getCurrentMonth());
    ASSERT_EQ(2023, calendar.getCurrentYear());
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());

    dt::Date expectedDate2{1, 1, 2024};
    dt::Calendar calendar2{1, 12, 2023};
    ++calendar2;

    ASSERT_EQ(1, calendar2.getCurrentDay());
    ASSERT_EQ(1, calendar2.getCurrentMonth());
    ASSERT_EQ(2024, calendar2.getCurrentYear());
    ASSERT_EQ(expectedDate2, calendar2.getCurrentDate());
}

/**
 * @brief @c Calendar test 7.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_incrementedPost_THEN_correctlyIncremented) {
    dt::Date expectedDate{1, 2, 2023};
    dt::Calendar calendar{1, 1, 2023};
    calendar++;
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());

    dt::Date expectedDate2{1, 1, 2024};
    dt::Calendar calendar2{1, 12, 2023};
    calendar2++;

    ASSERT_EQ(1, calendar2.getCurrentDay());
    ASSERT_EQ(1, calendar2.getCurrentMonth());
    ASSERT_EQ(2024, calendar2.getCurrentYear());
    ASSERT_EQ(expectedDate2, calendar2.getCurrentDate());
}

/**
 * @brief @c Calendar test 8.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_decrementPre_THEN_correctlyDecremented) {
    dt::Date expectedDate{1, 1, 2023};
    dt::Calendar calendar{1, 2, 2023};
    --calendar;

    ASSERT_EQ(1, calendar.getCurrentDay());
    ASSERT_EQ(1, calendar.getCurrentMonth());
    ASSERT_EQ(2023, calendar.getCurrentYear());
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());

    dt::Date expectedDate2{1, 12, 2022};
    dt::Calendar calendar2{1, 1, 2023};
    --calendar2;

    ASSERT_EQ(1, calendar2.getCurrentDay());
    ASSERT_EQ(12, calendar2.getCurrentMonth());
    ASSERT_EQ(2022, calendar2.getCurrentYear());
    ASSERT_EQ(expectedDate2, calendar2.getCurrentDate());
}

/**
 * @brief @c Calendar test 9.
 */
TEST(Calendar, GIVEN_calendarObject_WHEN_decrementPost_THEN_correctlyDecremented) {
    dt::Date expectedDate{1, 1, 2023};
    dt::Calendar calendar{1, 2, 2023};
    calendar--;

    ASSERT_EQ(1, calendar.getCurrentDay());
    ASSERT_EQ(1, calendar.getCurrentMonth());
    ASSERT_EQ(2023, calendar.getCurrentYear());
    ASSERT_EQ(expectedDate, calendar.getCurrentDate());

    dt::Date expectedDate2{1, 12, 2022};
    dt::Calendar calendar2{1, 1, 2023};
    calendar2--;

    ASSERT_EQ(1, calendar2.getCurrentDay());
    ASSERT_EQ(12, calendar2.getCurrentMonth());
    ASSERT_EQ(2022, calendar2.getCurrentYear());
    ASSERT_EQ(expectedDate2, calendar2.getCurrentDate());
}