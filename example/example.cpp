/**
 * @file example.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 16/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include <dt/date/Date.hpp>
#include <dt/date/FormattedDate.hpp>
#include <dt/date/Calendar.hpp>

void dates();
void calendars();
void timestamps();

int main() {
    dates();
    calendars();
    timestamps();
    return 0;
}

void dates() {
    std::cout << "========== Dates/FormattedDates ==========" << "\n";

    // Dates
    dt::Date date1{22, 12, 2001};
    dt::Date date2{"22-12-2001"};
    dt::Date date3{"22/12/2001"};
//    dt::Date date4{"22/12-2001"}; // Throws exception - Invalid date format
//    dt::Date date5{"1/1/2001"}; // Throws exception - Invalid date format => "01/01/2001"

    std::cout << date1 << "\n";
    std::cout << date2 << "\n";
    std::cout << date3 << "\n\n";

    // Formatted Dates
    dt::FormattedDate fDate1{1, 1, 2023, dt::DateFormat::DD_MM_YYYY};   // 1-1-2023
    dt::FormattedDate fDate2{1, 1, 2023, dt::DateFormat::MM_DD_YYYY};   // 1-1-2023
    dt::FormattedDate fDate3{1, 1, 2023, dt::DateFormat::YYYY_DD_MM};   // 2023-1-1
    dt::FormattedDate fDate4{1, 1, 2023, dt::DateFormat::YYYY_MM_DD};   // 2023-1-1
    dt::FormattedDate fDate5{1, 1, 2023, dt::DateFormat::DD__MM__YYYY}; // 1/1/2023
    dt::FormattedDate fDate6{1, 1, 2023, dt::DateFormat::MM__DD__YYYY}; // 1/1/2023
    dt::FormattedDate fDate7{1, 1, 2023, dt::DateFormat::YYYY__DD__MM}; // 2023/1/1
    dt::FormattedDate fDate8{1, 1, 2023, dt::DateFormat::YYYY__MM__DD}; // 2023/1/1

    std::cout << fDate1 << "\n";
    std::cout << fDate2 << "\n";
    std::cout << fDate3 << "\n";
    std::cout << fDate4 << "\n";
    std::cout << fDate5 << "\n";
    std::cout << fDate6 << "\n";
    std::cout << fDate7 << "\n";
    std::cout << fDate8 << "\n\n";
}

void calendars() {
    std::cout << "========== Calendars ==========" << "\n";

    dt::Calendar calendar1{22, 12, 2001};

    dt::Date date1{"16-10-1965"};
    dt::Calendar calendar2{date1};

    dt::Calendar calendar3{12, 2025}; // Dec 2025

    std::cout << calendar1 << "\n\n";
    std::cout << calendar2 << "\n\n";
    std::cout << calendar3 << "\n\n";
}

void timestamps() {
    std::cout << "========== TimeStamps ==========" << "\n";

}