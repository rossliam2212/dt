/**
 * @file StopWatch.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 03/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/time/StopWatch.hpp"

namespace dt {
    /**
     * @brief Starts the stopwatch.
     */
    void StopWatch::start() {
        if (!running) {
            startTime = std::chrono::high_resolution_clock::now();
            running = true;
        }
    }

    /**
     * @brief Stops the stopwatch.
     */
    void StopWatch::stop() {
        if (running) {
            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            elapsed += duration.count();
            running = false;
        }
    }

    /**
     * @brief Resets the stopwatch.
     */
    void StopWatch::reset() {
        running = false;
        elapsed = 0;
    }

    /**
     * @brief Gets the elapsed time in milliseconds.
     * @return The elapsed time in milliseconds.
     */
    long long StopWatch::getElapsedMilliseconds() const {
        if (running) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - startTime);
            return elapsed + duration.count() / 1000;
        }
        return elapsed / 1000;
    }

    /**
     * @brief Gets the elapsed time in seconds.
     * @return The elapsed time in seconds.
     */
    double StopWatch::getElapsedSeconds() const {
        return static_cast<double>(getElapsedMilliseconds()) / 1000.0;
    }
}