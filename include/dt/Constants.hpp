/**
 * @file Constants.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_CONSTANTS_HPP
#define DATEANDTIME_LIB_CONSTANTS_HPP

#include <cstdint>

namespace dt {
    /**
     * @brief @c Constants related to the @c Date & @c TimeStamp classes.
     * @namespace @c dt::consts
    */
    namespace consts {
        static constexpr char LEADING_ZERO{'0'};
        static constexpr char DATE_SEPARATOR_DASH{'-'};
        static constexpr char DATE_SEPARATOR_SLASH{'/'};
        static constexpr char TIME_SEPARATOR{':'};

        static constexpr int DATE_PATTERNS{4};

        static constexpr int MIN_YEAR{1583};
        static constexpr int MAX_YEAR{9999};
        static constexpr int MIN_NUMBER_OF_MONTHS{1};
        static constexpr int MAX_NUMBER_OF_MONTHS{12};
        static constexpr int MONTHS_ADJUST_LOWER{0};
        static constexpr int MONTHS_ADJUST_UPPER{13};
        static constexpr int MAX_NUMBER_DAYS_IN_A_MONTH{31};
        static constexpr int FEBRUARY_LEAP_YEAR_DAYS{29};

        static constexpr int HOUR_MIN{0};
        static constexpr int HOUR_MAX{23};
        static constexpr int HOUR_ADJUST{24};
        static constexpr int MINUTE_MIN{0};
        static constexpr int MINUTE_MAX{59};
        static constexpr int MINUTE_ADJUST{60};
        static constexpr int SECOND_MIN{0};
        static constexpr int SECOND_MAX{59};
        static constexpr int SECOND_ADJUST{60};
        static constexpr int MILLISECOND_MIN{0};
        static constexpr int MILLISECOND_MAX{999};
        static constexpr int MILLISECOND_ADJUST{1000};

        static constexpr const char* MONDAY{"Monday"};
        static constexpr const char* TUESDAY{"Tuesday"};
        static constexpr const char* WEDNESDAY{"Wednesday"};
        static constexpr const char* THURSDAY{"Thursday"};
        static constexpr const char* FRIDAY{"Friday"};
        static constexpr const char* SATURDAY{"Saturday"};
        static constexpr const char* SUNDAY{"Sunday"};

        static constexpr const char* MONDAY_SHORT{"Mo"};
        static constexpr const char* TUESDAY_SHORT{"Tu"};
        static constexpr const char* WEDNESDAY_SHORT{"We"};
        static constexpr const char* THURSDAY_SHORT{"Th"};
        static constexpr const char* FRIDAY_SHORT{"Fr"};
        static constexpr const char* SATURDAY_SHORT{"Sa"};
        static constexpr const char* SUNDAY_SHORT{"Su"};

        static constexpr const char* COLOR_WHITE{"\x1B[97m"};
        static constexpr const char* COLOR_GREEN{"\x1B[32m"};
        static constexpr const char* COLOR_RESET{"\x1B[0m"};

        enum class Month : uint8_t {
            January = 1,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
        };
    }
}

#endif //DATEANDTIME_LIB_CONSTANTS_HPP
