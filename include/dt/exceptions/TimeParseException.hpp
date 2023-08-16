/**
 * @file TimeParseException.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 01/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_TIMEPARSEEXCEPTION_HPP
#define DATEANDTIME_LIB_TIMEPARSEEXCEPTION_HPP

#include <exception>
#include <string>

namespace dt {
    /**
     * @brief @c TimeParseException class.
     *
     * This exception is thrown when a trying to parse an invalid string representation of a @c TimeStamp object. <br>
     *
     * Inherits from @c std::exception.
     * @namespace @c dt
     */
    class TimeParseException : public std::exception {
    public:
        explicit TimeParseException(const char* message);
        explicit TimeParseException(const std::string& message);
        ~TimeParseException() _NOEXCEPT override = default;

        const char* what() const _NOEXCEPT override;

    private:
        std::string message;
    };
}

#endif //DATEANDTIME_LIB_TIMEPARSEEXCEPTION_HPP
