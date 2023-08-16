/**
 * @file Date.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_DATE_HPP
#define DATEANDTIME_LIB_DATE_HPP

#include <array>
#include <iostream>
#include <regex>
#include <string_view>
#include <sstream>
#include <ostream>

#include "../Constants.hpp"
#include "../utils/DateTimeUtils.hpp"
#include "../exceptions/DateParseException.hpp"
#include "../exceptions/InvalidDateException.hpp"

namespace dt {
    /**
     * @brief @c Date class.
     *
     * This class represents a specific date in the format @c DD-MM-YYYY.
     * @namespace @c dt
     */
    class Date {
    public:
        Date() = default;
        Date(int d, int m, int y);
        Date(const std::string& date);
        ~Date() = default;

        void addDays(int days);
        void addMonths(int months);
        void addYears(int years);

        void setDate(int d, int m, int y);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        std::string getDayOfWeek() const;
        bool isLeapYear() const;
        std::string toString() const;

        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Date& date);

    private:
        bool isValidDate(int d, int m, int y);
        void adjustDate();
        std::string addLeadingZerosToDateComponent(int component) const;
        void parse(const std::string& date);
        void convertStrToDate(std::string_view pattern, const std::string& date);
        std::string getDayOfWeek(int d) const;

        int day{0};
        int month{0};
        int year{0};
        bool leapYear{false};
        static const std::array<std::string, consts::DATE_PATTERNS> datePatterns;
    };
}

#endif //DATEANDTIME_LIB_DATE_HPP
