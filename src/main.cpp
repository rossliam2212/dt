#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <thread>

#include "../include/dt/date/Date.hpp"
#include "../include/dt/date/Calendar.hpp"
#include "../include/dt/date/FormattedDate.hpp"
#include "../include/dt/time/StopWatch.hpp"
#include "../include/dt/time/TimeStamp.hpp"
#include "../include/dt/utils/DateTimeUtils.hpp"

int main() {
//    std::cout << sizeof(u_int8_t) << std::endl;

//    dt::Date d{1, 7, 2023};
//    dt::Date d{30, 6, 2023};
//    d.addDays(-2); // 30-6-2023
//    std::cout << d << "\n";
//
//    dt::TimeStamp t{18, 46, 37, 200};
//    std::cout << t << "\n";

//    try {
//        dt::Date date1{"22-12-2001"};
//        dt::Date date2{"2001-12-22"};
//        dt::Date date3{"22/12/2001"};
//        dt::Date date4{"2001/12-22"};
//    } catch(const dt::DateParseException& ex) {
//        std::cout << ex.what() << "\n";
//    }

//    std::cout << dt::DateTimeUtils::getDayOfWeek("31-07/2023") << "\n";
//    dt::Date date;

//    dt::TimeStamp time{1, 1, 1, 1};
//    std::cout << time << "\n";

//    const char* pattern{"%H:%M:%S."};
//    std::stringstream ss;
//    std::chrono::system_clock::time_point now{std::chrono::system_clock::now()};
//    std::time_t now_c{std::chrono::system_clock::to_time_t(now)};
//    const std::tm* timePtr{std::localtime(&now_c)};
//    ss << std::put_time(timePtr, pattern);
//
//    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000;
//    ss << std::setfill('0') << std::setw(3) << milliseconds;
//
//    std::cout << ss.str() << "\n";

//    dt::TimeStamp time1;
//    time1.setToCurrentTime();
//    std::cout << time1 << "\n";


//    dt::FormattedDate date{"22/12-2001", dt::DateFormat::YYYY__DD__MM};
//    std::cout << date << "\n";

//    dt::StopWatch stopWatch;
//    stopWatch.start();
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    stopWatch.stop();
//    std::cout << stopWatch.getElapsedMilliseconds() << "\n";

    dt::Date date1{"09/07/2023"};
    dt::Calendar calendar{date1};
    std::cout << calendar << "\n";
    calendar++;
    std::cout << "\n";
    std::cout << calendar << "\n";


    std::vector<std::string> dates {
        "22-12-2001",
        "22/12/2001",
        "22-12/2001"
    };

    auto result = dt::DateTimeUtils::parseDateStrings(dates);
    for (const auto& d : result) {
        std::cout << d << "\n";
    }

    return 0;
}
