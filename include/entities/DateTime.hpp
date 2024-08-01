#pragma once

#include "interfaces/IDateTime.hpp"

/// @brief Implementation of a basic date and time object
class DateTime : public IDateTime {
    private:
        /// @brief Stores the seconds since 00:00:00 UTC 1/1/1970 as an int
        int m_unixTime;
        
    public:
        /// @brief Construct object with specified date and time value
        /// @param unixTime Seconds since 00:00:00 UTC 1/1/1970
        DateTime(int unixTime);

        /// @brief Construct object with specified parameters
        /// @param year Year value
        /// @param month Month from (1 - 12)
        /// @param day Day (1 - 31)
        /// @param hour Hour (0 - 23)
        /// @param minute Minute (0 - 59)
        DateTime(int year, int month, int day, int hour, int minute);

        const std::string toString() const override;
        void setTime(int unixTime) override;
        void setTime(int year, int month, int day, int hour, int minute) override;
        int getTime() const override;
        std::unique_ptr<IDateTime> clone() const override;
};