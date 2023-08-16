/**
 * @file DateTest.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <gtest/gtest.h>

#include "../include/dt/date/Date.hpp"

/**
 * @brief @c Date test 1.
 */
TEST(Date, GIVEN_defaultDateObject_WHEN_created_THEN_defaultValuesSet) {
    dt::Date date;

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c Date test 2.
 */
TEST(Date, GIVEN_dateObject_WHEN_createdWithInvalidYear_THEN_defaultValuesSet) {
    dt::Date date{1, 1, 10000};

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c Date test 3.
 */
TEST(Date, GIVEN_dateObject_WHEN_createdWithInvalidMonth_THEN_defaultValuesSet) {
    dt::Date date{1, 24, 2001};

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c Date test 4.
 */
TEST(Date, GIVEN_dateObject_WHEN_createdWithInvalidDay_THEN_defaultValuesSet) {
    dt::Date date{50, 1, 2001};

    ASSERT_EQ(0, date.getDay());
    ASSERT_EQ(0, date.getMonth());
    ASSERT_EQ(0, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c Date test 5.
 */
TEST(Date, GIVEN_dateObject_WHEN_createdWithValidValues_THEN_valuesSet) {
    dt::Date date{22, 12, 2001};

    ASSERT_EQ(22, date.getDay());
    ASSERT_EQ(12, date.getMonth());
    ASSERT_EQ(2001, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c Date test 6.
 */
TEST(Date, GIVEN_dateObject_WHEN_createdWithLeapYear_THEN_valuesSet) {
    dt::Date date{22, 12, 2004};

    ASSERT_EQ(22, date.getDay());
    ASSERT_EQ(12, date.getMonth());
    ASSERT_EQ(2004, date.getYear());
    ASSERT_TRUE(date.isLeapYear());
}

/**
 * @brief @c Date test 7.
 */
TEST(Date, GIVEN_dateObject_WHEN_toStringCalled_THEN_dateCorrectlyFormatted) {
    std::string formattedDate1{"22-12-2004"};
    std::string formattedDate2{"02-02-1969"};

    dt::Date date1{22, 12, 2004};
    dt::Date date2{2, 2, 1969};

    ASSERT_EQ(formattedDate1, date1.toString());
    ASSERT_EQ(formattedDate2, date2.toString());
}

/**
 * @brief @c Date test 8.
 */
TEST(Date, GIVEN_dateObject_WHEN_setDateCalledWithValidDate_THEN_valuesSet) {
    dt::Date date;
    date.setDate(9, 7, 2002);

    ASSERT_EQ(9, date.getDay());
    ASSERT_EQ(7, date.getMonth());
    ASSERT_EQ(2002, date.getYear());
    ASSERT_FALSE(date.isLeapYear());
}

/**
 * @brief @c Date test 9.
 */
TEST(Date, GIVEN_dateObject_WHEN_getDayOfTheWeekCalled_THEN_correctDayReturned) {;
    dt::Date date{17, 7, 2023};
    ASSERT_EQ("Monday", date.getDayOfWeek());

    dt::Date date2{18, 7, 2023};
    ASSERT_EQ("Tuesday", date2.getDayOfWeek());

    dt::Date date3{19, 7, 2023};
    ASSERT_EQ("Wednesday", date3.getDayOfWeek());

    dt::Date date4{20, 7, 2023};
    ASSERT_EQ("Thursday", date4.getDayOfWeek());

    dt::Date date5{21, 7, 2023};
    ASSERT_EQ("Friday", date5.getDayOfWeek());

    dt::Date date6{22, 7, 2023};
    ASSERT_EQ("Saturday", date6.getDayOfWeek());

    dt::Date date7{23, 7, 2023};
    ASSERT_EQ("Sunday", date7.getDayOfWeek());
}

/**
 * @brief @c Date test 10.
 */
TEST(Date, GIVEN_dateObject_WHEN_setDateCalledWithInvalidDate_THEN_exceptionThrown) {
    dt::Date date;
    ASSERT_THROW(date.setDate(9, 20, 2002), dt::InvalidDateException);
}

/**
 * @brief @c Date test 11.
 */
TEST(Date, GIVEN_twoDifferentDateObjects_WHEN_compared_THEN_notEqual) {
    dt::Date date1{22, 12, 2001};
    dt::Date date2{9, 7, 2002};

    ASSERT_NE(date1, date2);
    ASSERT_NE(date2, date1);
}

/**
 * @brief @c Date test 12.
 */
TEST(Date, GIVEN_twoEqualDateObjects_WHEN_compared_THEN_equal) {
    dt::Date date1{22, 12, 2001};
    dt::Date date2{22, 12, 2001};

    ASSERT_EQ(date1, date2);
    ASSERT_EQ(date2, date1);
}

/**
 * @brief @c Date test 13.
 */
TEST(Date, GIVEN_twoDifferentDateObjects_WHEN_compared_THEN_correctValuesReturned) {
    dt::Date date1{22, 12, 2001};
    dt::Date date2{9, 7, 2002};

    ASSERT_LT(date1, date2);
    ASSERT_GT(date2, date1);
}

/**
 * @brief @c Date test 14.
 */
TEST(Date, GIVEN_dateObject_WHEN_addDaysCalled_THEN_correctDateSet) {
    dt::Date expectedDate{1, 8, 2023};

    dt::Date date{28, 7, 2023};
    date.addDays(4);
    ASSERT_EQ(expectedDate, date);

    dt::Date expectedDate2{12, 7, 2023};
    date.addDays(-20);
    ASSERT_EQ(expectedDate2, date);
}

/**
 * @brief @c Date test 15.
 */
TEST(Date, GIVEN_dateObject_WHEN_addMonthsCalled_THEN_correctDateSet) {
    dt::Date expectedDate{28, 4, 2024};

    dt::Date date{28, 8, 2023};
    date.addMonths(8);
    ASSERT_EQ(expectedDate, date);

    dt::Date expectedDate2{28, 4, 2022};
    date.addMonths(-24);
    ASSERT_EQ(expectedDate2, date);

    dt::Date expectedDate3{28, 1, 2023};
    date.addMonths(9);
    ASSERT_EQ(expectedDate3, date);

}

/**
 * @brief @c Date test 16.
 */
TEST(Date, GIVEN_dateObject_WHEN_addYearsCalled_THEN_correctDateSet) {
    dt::Date expectedDate{28, 7, 2028};

    dt::Date date{28, 7, 2023};
    date.addYears(5);
    ASSERT_EQ(expectedDate, date);

    dt::Date expectedDate2{28, 7, 2018};
    date.addYears(-10);
    ASSERT_EQ(expectedDate2, date);
}

/**
 * @brief @c Date test 17.
 */
TEST(Date, GIVEN_dateObject_WHEN_pasredFromStringWithValidPatternAndDate_THEN_correctDateSet) {
    dt::Date expectedDate{22, 12, 2001};
    dt::Date date{"22-12-2001"};
    ASSERT_EQ(expectedDate, date);
    ASSERT_EQ(22, date.getDay());
    ASSERT_EQ(12, date.getMonth());
    ASSERT_EQ(2001, date.getYear());

    dt::Date expectedDate2{9, 7, 2002};
    dt::Date date2{"2002/09/07"};
    ASSERT_EQ(expectedDate2, date2);
    ASSERT_EQ(9, date2.getDay());
    ASSERT_EQ(7, date2.getMonth());
    ASSERT_EQ(2002, date2.getYear());
}

/**
 * @brief @c Date test 18.
 */
TEST(Date, GIVEN_dateObject_WHEN_parsedFromStringWithValidPatternAndInvalidDate_THEN_exceptionThrown) {
    ASSERT_THROW(dt::Date date{"22/22/2001"}, dt::InvalidDateException);
    ASSERT_THROW(dt::Date date{"46/12/2001"}, dt::InvalidDateException);
    ASSERT_THROW(dt::Date date{"22-90-2001"}, dt::InvalidDateException);
    ASSERT_THROW(dt::Date date2{"2001-90-56"}, dt::InvalidDateException);
}

/**
 * @brief @c Date test 19.
 */
TEST(Date, GIVEN_dateObject_WHEN_parsedFromStringWithInvalidPattern_THEN_exceptionThrown) {
    ASSERT_THROW(dt::Date date{"22-12/2001"}, dt::DateParseException);
    ASSERT_THROW(dt::Date date2{"invalid_date"}, dt::DateParseException);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
