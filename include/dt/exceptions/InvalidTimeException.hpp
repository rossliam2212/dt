/**
 * @file InvalidTimeException.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 29/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_INVALIDTIMEEXCEPTION_HPP
#define DATEANDTIME_LIB_INVALIDTIMEEXCEPTION_HPP

#include <exception>
#include <string>

namespace dt {
    /**
     * @brief @c InvalidTimeException class.
     *
     * This exception is thrown when a @c TimeStamp object is set to an invalid time. <br>
     *
     * Inherits from std::exception.
     * @namespace @c dt
     */
    class InvalidTimeException : public std::exception {
    public:
        explicit InvalidTimeException(const char* message);
        explicit InvalidTimeException(const std::string& message);
        ~InvalidTimeException() _NOEXCEPT override = default;

        const char* what() const _NOEXCEPT override;

    private:
        std::string message;
    };
}

#endif //DATEANDTIME_LIB_INVALIDTIMEEXCEPTION_HPP
