/**
 * @file Calendar.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 04/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_CALENDAR_HPP
#define DATEANDTIME_LIB_CALENDAR_HPP

#include <vector>

#include "Date.hpp"

namespace dt {
    /**
     * @brief @c Calendar class.
     * @namespace @c dt
     */
    class Calendar {
    public:
        Calendar();
        Calendar(int day, int month, int year);
        Calendar(int month, int year);
        Calendar(const Date& date);
        ~Calendar() = default;

        Calendar& operator++();
        Calendar& operator++(int);
        Calendar& operator--();
        Calendar& operator--(int);

        std::string toString() const;
        void displayAllDates();

        int getCurrentDay() const;
        int getCurrentMonth() const;
        int getCurrentYear() const;
        Date getCurrentDate() const;
        std::vector<Date> getDates() const;
        bool isLeapYear() const;

        friend std::ostream& operator<<(std::ostream& os, const Calendar& calendar);

    private:
        void setDates();
        std::string formatCalendar() const;

        int currentDay{1};
        int currentMonth{1};
        int currentYear{1583};
        std::vector<Date> dates;
    };
}

#endif //DATEANDTIME_LIB_CALENDAR_HPP
