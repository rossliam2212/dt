/**
 * @file InvalidDateException.hpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#ifndef DATEANDTIME_LIB_INVALIDDATEEXCEPTION_HPP
#define DATEANDTIME_LIB_INVALIDDATEEXCEPTION_HPP

#include <exception>
#include <string>

namespace dt {
    /**
     * @brief @c InvalidDateException class.
     *
     * This exception is thrown when a @c Date object is set to an invalid date. <br>
     *
     * Inherits from std::exception.
     * @namespace @c dt
     */
    class InvalidDateException : public std::exception {
    public:
        explicit InvalidDateException(const char* message);
        explicit InvalidDateException(const std::string& message);
        ~InvalidDateException() _NOEXCEPT override = default;

        const char* what() const _NOEXCEPT override;

    private:
        std::string message;
    };
}

#endif //DATEANDTIME_LIB_INVALIDDATEEXCEPTION_HPP
