/**
 * @file FormattedDateTest.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 02/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <gtest/gtest.h>

#include "../include/dt/date/FormattedDate.hpp"

/**
 * @brief @c FormattedDate test 1.
 */
TEST(FormattedDate, GIVEN_formattedDateObject_WHEN_created_THEN_defaultValuesSet) {
    dt::FormattedDate date;

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c FormattedDate test 2.
 */
TEST(FormattedDate, GIVEN_formattedDateObject_WHEN_createdWithInvalidYear_THEN_defaultValuesSet) {
    dt::FormattedDate date{1, 1, 10000, dt::DateFormat::DD_MM_YYYY};

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c FormattedDate test 3.
 */
TEST(Date, GIVEN_formattedDateObject_WHEN_createdWithInvalidMonth_THEN_defaultValuesSet) {
    dt::FormattedDate date{1, 24, 2001, dt::DateFormat::DD_MM_YYYY};

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c FormattedDate test 4.
 */
TEST(FormattedDate, GIVEN_formattedDateObject_WHEN_createdWithInvalidDay_THEN_defaultValuesSet) {
    dt::FormattedDate date{50, 1, 2001, dt::DateFormat::DD_MM_YYYY};

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c FormattedDate test 5.
 */
TEST(FormattedDate, GIVEN_formattedDateObject_WHEN_createdWithValidValues_THEN_valuesSet) {
    dt::FormattedDate date{22, 12, 2001, dt::DateFormat::DD_MM_YYYY};

    ASSERT_EQ(22, date.getDay());
    ASSERT_EQ(12, date.getMonth());
    ASSERT_EQ(2001, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c FormattedDate test 6.
 */
TEST(FormattedDate, GIVEN_formattedDateObject_WHEN_createdWithLeapYear_THEN_valuesSet) {
    dt::FormattedDate date{22, 12, 2004, dt::DateFormat::DD_MM_YYYY};

    ASSERT_EQ(22, date.getDay());
    ASSERT_EQ(12, date.getMonth());
    ASSERT_EQ(2004, date.getYear());
    ASSERT_TRUE(date.isLeapYear());
}

/**
 * @brief @c FormattedDate test 7.
 */
TEST(FormattedDate, GIVEN_formattedDateObject_WHEN_toStringCalled_THEN_dateCorrectlyFormatted) {
    std::string formattedDate1{"22-12-2001"};
    std::string formattedDate2{"12-22-2001"};
    std::string formattedDate3{"2001-12-22"};
    std::string formattedDate4{"2001-22-12"};

    std::string formattedDate5{"22/12/2001"};
    std::string formattedDate6{"12/22/2001"};
    std::string formattedDate7{"2001/12/22"};
    std::string formattedDate8{"2001/22/12"};

    dt::FormattedDate date1{22, 12, 2001, dt::DateFormat::DD_MM_YYYY};
    dt::FormattedDate date2{22, 12, 2001, dt::DateFormat::MM_DD_YYYY};
    dt::FormattedDate date3{22, 12, 2001, dt::DateFormat::YYYY_MM_DD};
    dt::FormattedDate date4{22, 12, 2001, dt::DateFormat::YYYY_DD_MM};

    dt::FormattedDate date5{22, 12, 2001, dt::DateFormat::DD__MM__YYYY};
    dt::FormattedDate date6{22, 12, 2001, dt::DateFormat::MM__DD__YYYY};
    dt::FormattedDate date7{22, 12, 2001, dt::DateFormat::YYYY__MM__DD};
    dt::FormattedDate date8{22, 12, 2001, dt::DateFormat::YYYY__DD__MM};

    ASSERT_EQ(formattedDate1, date1.toString());
    ASSERT_EQ(formattedDate2, date2.toString());
    ASSERT_EQ(formattedDate3, date3.toString());
    ASSERT_EQ(formattedDate4, date4.toString());
    ASSERT_EQ(formattedDate5, date5.toString());
    ASSERT_EQ(formattedDate6, date6.toString());
    ASSERT_EQ(formattedDate7, date7.toString());
    ASSERT_EQ(formattedDate8, date8.toString());
}

/**
 * @brief @c FormattedDate test 8.
 */
TEST(FormattedDate, GIVEN_formattedDateObject_WHEN_pasredFromStringWithValidPatternAndDate_THEN_correctDateSet) {
    dt::FormattedDate expectedDate{22, 12, 2001, dt::DateFormat::DD_MM_YYYY};
    dt::FormattedDate date{"22-12-2001", dt::DateFormat::DD_MM_YYYY};
    ASSERT_EQ(expectedDate, date);
    ASSERT_EQ(22, date.getDay());
    ASSERT_EQ(12, date.getMonth());
    ASSERT_EQ(2001, date.getYear());

    dt::FormattedDate expectedDate2{9, 7, 2002, dt::DateFormat::DD_MM_YYYY};
    dt::FormattedDate date2{"2002/09/07", dt::DateFormat::DD_MM_YYYY};
    ASSERT_EQ(expectedDate2, date2);
    ASSERT_EQ(9, date2.getDay());
    ASSERT_EQ(7, date2.getMonth());
    ASSERT_EQ(2002, date2.getYear());
}

