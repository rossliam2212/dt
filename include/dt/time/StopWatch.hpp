/**
 * @file StopWatch.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 03/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_STOPWATCH_HPP
#define DATEANDTIME_LIB_STOPWATCH_HPP

#include <chrono>

namespace dt {
    /**
     * @brief @c StopWatch class.
     *
     * This class can be used to measure elapsed time between start and stop events.
     * @namespace @c dt
     */
    class StopWatch {
    public:
        StopWatch() = default;
        ~StopWatch() = default;

        void start();
        void stop();
        void reset();

        long long getElapsedMilliseconds() const;
        double getElapsedSeconds() const;

    private:
        bool running{false};
        long long elapsed{0};
        std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    };
}

#endif //DATEANDTIME_LIB_STOPWATCH_HPP
