#pragma once

#include <string>

/// @brief Interface for an object that manipulates date and time values
class IDateTime {
    public:
        /// @brief Virtual destructor
        virtual ~IDateTime() = default;

        /// @brief Converts date/time to string representation
        /// @return String representation of date/time
        virtual const std::string toString() const = 0;

        /// @brief Gets unix time
        /// @return Seconds since 00:00:00 UTC 1/1/1970
        virtual int getTime() const = 0;

        /// @brief Sets the time value
        /// @param unixTime Seconds since 00:00:00 UTC 1/1/1970
        virtual void setTime(int unixTime) = 0;
};