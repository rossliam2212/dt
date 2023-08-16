/**
 * @file DateParseException.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 31/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_DATEPARSEEXCEPTION_HPP
#define DATEANDTIME_LIB_DATEPARSEEXCEPTION_HPP

#include <exception>
#include <string>

namespace dt {
    /**
     * @brief @c DateParseException class.
     *
     * This exception is thrown when a trying to parse an invalid string representation of a @c Date object. <br>
     *
     * Inherits from std::exception.
     * @namespace @c dt
     */
    class DateParseException : public std::exception {
    public:
        explicit DateParseException(const char* message);
        explicit DateParseException(const std::string& message);
        ~DateParseException() _NOEXCEPT override = default;

        const char* what() const _NOEXCEPT override;

    private:
        std::string message;
    };
}

#endif //DATEANDTIME_LIB_DATEPARSEEXCEPTION_HPP
