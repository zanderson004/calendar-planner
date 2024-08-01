#pragma once

#include <string>
#include <memory>

/// @brief Interface for an object that manipulates date and time values
class IDateTime {
    public:
        /// @brief Virtual destructor
        virtual ~IDateTime() = default;

        /// @brief Converts date/time to string representation
        /// @return String representation of date/time
        virtual const std::string toString() const = 0;

        /// @brief Sets the time value
        /// @param unixTime Seconds since 00:00:00 UTC 1/1/1970
        virtual void setTime(int unixTime) = 0;

        /// @brief Sets the time value with specified parameters
        /// @param year Year value
        /// @param month Month from (1 - 12)
        /// @param day Day (1 - 31)
        /// @param hour Hour (0 - 23)
        /// @param minute Minute (0 - 59)
        virtual void setTime(int year, int month, int day, int hour, int minute) = 0;

        /// @brief Gets the time value
        /// @return Seconds since 00:00:00 UTC 1/1/1970
        virtual int getTime() const = 0;

        /// @brief Clones a unique pointer to an implementation of IDateTime
        /// @return Deep copy to the same implementation
        virtual std::unique_ptr<IDateTime> clone() const = 0;
};