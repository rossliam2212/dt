/**
 * @file FormattedDate.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 02/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_FORMATTEDDATE_HPP
#define DATEANDTIME_LIB_FORMATTEDDATE_HPP

#include "Date.hpp"

namespace dt {
    /**
     * @brief @c DateFormat enum class.
     *
     * This enum class is used to define the various formats a date can be represented in. <br>
     *
     * The available formats are:
     * <ul>
     *  <li>@c DateFormat::DD_MM_YYYY   - Represents the date format as "DD-MM-YYYY" (e.g., 22-12-2001)</li>
     *  <li>@c DateFormat::MM_DD_YYYY   - Represents the date format as "MM-DD-YYYY" (e.g., 12-22-2001)</li>
     *  <li>@c DateFormat::YYYY_MM_DD   - Represents the date format as "YYYY-MM-DD" (e.g., 2001-12-22)</li>
     *  <li>@c DateFormat::YYYY_DD_MM   - Represents the date format as "YYYY-DD-MM" (e.g., 2001-22-12)</li>
     *  <li>@c DateFormat::DD__MM__YYYY - Represents the date format as "DD/MM/YYYY" (e.g., 22/12/2001)</li>
     *  <li>@c DateFormat::MM__DD__YYYY - Represents the date format as "MM/DD/YYYY" (e.g., 12/22/2001)</li>
     *  <li>@c DateFormat::YYYY__MM__DD - Represents the date format as "YYYY/MM/DD" (e.g., 2001/12/22)</li>
     *  <li>@c DateFormat::YYYY__DD__MM-  Represents the date format as "YYYY/DD/MM" (e.g., 2001/22/12)</li>
     * @namespace @c dt
     */
    enum class DateFormat : u_int8_t {
        DD_MM_YYYY,     // 22-12-2001
        MM_DD_YYYY,     // 12-22-2001
        YYYY_MM_DD,     // 2001-12-22
        YYYY_DD_MM,     // 2001-22-12
        DD__MM__YYYY,   // 22/12/2001
        MM__DD__YYYY,   // 12/22/2001
        YYYY__MM__DD,   // 2001/12/22
        YYYY__DD__MM,   // 2001/22/12
    };

    /**
     * @brief @c FormattedDate class.
     *
     * This class represents a specific date with a specified format.
     * @namespace @c dt
     * @see @c DateFormat for the available date formats.
     */
    class FormattedDate {
    public:
        FormattedDate() = default;
        FormattedDate(int d, int m, int y, DateFormat format);
        FormattedDate(const std::string& date, DateFormat format);
        FormattedDate(const Date& date, DateFormat format);
        ~FormattedDate() = default;

        void addDays(int days);
        void addMonths(int months);
        void addYears(int years);

        void setDate(int d, int m, int y);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        std::string getDayOfWeek();
        bool isLeapYear() const;
        std::string toString() const;

        bool operator<(const FormattedDate& other) const;
        bool operator>(const FormattedDate& other) const;
        bool operator<=(const FormattedDate& other) const;
        bool operator>=(const FormattedDate& other) const;
        bool operator==(const FormattedDate& other) const;
        bool operator!=(const FormattedDate& other) const;
        friend std::ostream& operator<<(std::ostream& os, const FormattedDate& date);

    private:
        std::string addLeadingZerosToDateComponent(int component) const;

        Date date;
        DateFormat format{DateFormat::DD_MM_YYYY};
    };
}

#endif //DATEANDTIME_LIB_FORMATTEDDATE_HPP
