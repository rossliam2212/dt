/**
 * @file Calendar.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 04/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/date/Calendar.hpp"

namespace dt {
    /**
     * @brief @c Calendar constructor.
     */
    Calendar::Calendar() {
        setDates();
    }

    /**
     * @brief @c Calendar constructor.
     * @param day
     *          The starting day.
     * @param month
     *          The starting month.
     * @param year
     *          The starting year.
     */
    Calendar::Calendar(int day, int month, int year) {
        if (DateTimeUtils::isValidDate(day, month, year)) {
            currentDay = day;
            currentMonth = month;
            currentYear = year;
            setDates();
        }
    }

    /**
     * @brief @c Calendar constructor.
     * @param month
     *          The starting month.
     * @param year
     *          The starting year.
     */
    Calendar::Calendar(int month, int year) {
        if (DateTimeUtils::isValidDate(currentDay, month, year)) {
            currentMonth = month;
            currentYear = year;
            setDates();
        }
    }

    /**
     * @brief @c Calendar constructor.
     * @param date
     *          The starting date.
     */
    Calendar::Calendar(const dt::Date& date)
        : currentDay{date.getDay()},
          currentMonth{date.getMonth()},
          currentYear{date.getYear()} {
        setDates();
    }

    /**
     * @brief Overloaded pre-increment operator. Increments the month by one and adjusts the year if necessary.
     * @return A reference to the object after incrementing.
     */
    Calendar& Calendar::operator++() {
        ++currentMonth;
        if (currentMonth > 12) {
            currentMonth = 1;
            ++currentYear;
        }

        setDates();
        return *this;
    }

    /**
     * @brief Overloaded post-increment operator. Increments the month by one and adjusts the year if necessary.
     * @return A reference to the object after incrementing.
     */
    Calendar& Calendar::operator++(int) {
        ++currentMonth;
        if (currentMonth > 12) {
            currentMonth = 1;
            ++currentYear;
        }

        setDates();
        return *this;
    }

    Calendar& Calendar::operator--() {
        --currentMonth;
        if (currentMonth <= 0) {
            currentMonth = 12;
            --currentYear;
        }

        setDates();
        return *this;
    }

    Calendar& Calendar::operator--(int) {
        --currentMonth;
        if (currentMonth <= 0) {
            currentMonth = 12;
            --currentYear;
        }

        setDates();
        return *this;
    }

    /**
     * @brief Converts the calendar to a string.
     * @return The calendar as a string.
     */
    std::string Calendar::toString() const {
        return formatCalendar();
    }

    /**
     * @brief Displays all the date objects from the current month.
     */
    void Calendar::displayAllDates() {
        for (const auto& d : dates) {
            std::cout << d << "\n";
        }
    }

    /**
     * @brief Gets the current day.
     * @return The current day.
     */
    int Calendar::getCurrentDay() const {
        return currentDay;
    }

    /**
     * @brief Gets the current month.
     * @return The current month.
     */
    int Calendar::getCurrentMonth() const {
        return currentMonth;
    }

    /**
     * @brief Gets the current year.
     * @return The current year.
     */
    int Calendar::getCurrentYear() const {
        return currentYear;
    }

    /**
     * @brief Gets the current date that corresponds with the current day.
     * @return The current date.
     */
    Date Calendar::getCurrentDate() const {
        return dates.at(currentDay-1);
    }

    /**
     * @brief Gets all the dates from the current month.
     * @return All the dates from the current month.
     */
    std::vector<Date> Calendar::getDates() const {
        return dates;
    }

    /**
     * @brief Checks if the current year is a leap year.
     * @return @c true if the year is a leap year, @c false otherwise.
     */
    bool Calendar::isLeapYear() const {
        return DateTimeUtils::isLeapYear(currentYear);
    }

    /**
     * @brief Creates all the day objects based on the day, month and year set.
     */
    void Calendar::setDates() {
        if (!dates.empty()) {
            dates.clear();
        }
        for (int i{1}; i <= DateTimeUtils::daysInMonth(currentYear, currentMonth); ++i) {
            dates.emplace_back(i, currentMonth, currentYear);
        }
    }

    /**
     * @brief Formats the calendar so that it is outputted correctly.
     * @return Thr formatted calendar.
     */
    std::string Calendar::formatCalendar() const {
        const std::string monthStr{DateTimeUtils::getMonthShortStr(currentMonth)};
        std::string currentDayColor{};
        std::stringstream ss;

        ss << monthStr <<  " " << currentYear << "\n";
        ss << "Mo Tu We Th Fr Sa Su\n";

        if (dates.at(0).getDayOfWeek() == consts::MONDAY) {
            if (currentDay == 1) {
                ss << consts::COLOR_GREEN << " 1" << consts::COLOR_RESET;
            } else {
                ss << " 1";
            }
        } else if (dates.at(0).getDayOfWeek() == consts::TUESDAY) {
            if (currentDay == 1) {
                ss << consts::COLOR_GREEN << "    1" << consts::COLOR_RESET;
            } else {
                ss << "    1";
            }
        } else if (dates.at(0).getDayOfWeek() == consts::WEDNESDAY) {
            if (currentDay == 1) {
                ss << consts::COLOR_GREEN << "       1" << consts::COLOR_RESET;
            } else {
                ss << "       1";
            }
        } else if (dates.at(0).getDayOfWeek() == consts::THURSDAY) {
            if (currentDay == 1) {
                ss << consts::COLOR_GREEN << "          1" << consts::COLOR_RESET;
            } else {
                ss << "          1";
            }
        } else if (dates.at(0).getDayOfWeek() == consts::FRIDAY) {
            if (currentDay == 1) {
                ss << consts::COLOR_GREEN << "             1" << consts::COLOR_RESET;
            } else {
                ss << "             1";
            }
        } else if (dates.at(0).getDayOfWeek() == consts::SATURDAY) {
            if (currentDay == 1) {
                ss << consts::COLOR_GREEN << "                1" << consts::COLOR_RESET;
            } else {
                ss << "                1";
            }
        } else if (dates.at(0).getDayOfWeek() == consts::SUNDAY) {
            if (currentDay == 1) {
                ss << consts::COLOR_GREEN << "                   1\n" << consts::COLOR_RESET;
            } else {
                ss << "                   1\n";
            }
        }

        for (int day{2}; day <= dates.size(); ++day) {
            if (day == currentDay) {
                currentDayColor = consts::COLOR_GREEN;
            } else {
                currentDayColor = consts::COLOR_WHITE;
            }

            if (dates.at(day-1).getDayOfWeek() == consts::SUNDAY) {
                if (day >= 10) {
                    ss << " " << currentDayColor << day << consts::COLOR_RESET << "\n";
                } else {
                    ss << "  " << currentDayColor << day << consts::COLOR_RESET << "\n";
                }
            } else if (dates.at(day-1).getDayOfWeek() == consts::MONDAY) {
                if (day >= 10) {
                    ss << currentDayColor << day << consts::COLOR_RESET;
                } else {
                    ss << " " << currentDayColor << day << consts::COLOR_RESET;
                }
            } else {
                if (day >= 10) {
                    ss << " " << currentDayColor << day << consts::COLOR_RESET;
                } else {
                    ss << "  " << currentDayColor << day << consts::COLOR_RESET;
                }
            }
        }
        return ss.str();
        }

    /**
     * @brief Overloaded stream output operator.
     * @param os
     *          The output stream.
     * @param calendar
     *          The calendar object to output.
     * @return The output stream.
     */
    std::ostream& operator<<(std::ostream& os, const Calendar& calendar) {
        os << calendar.toString();
        return os;
    }
}