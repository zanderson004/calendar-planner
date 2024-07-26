#pragma once

#include "interfaces/IDateTime.hpp"

#include <string>
#include <memory>

/// @brief Interface for a task object
class ITask {
    public:
        /// @brief Virtual destructor
        virtual ~ITask() = default;

        /// @brief Gets the name of a task
        /// @return Name of task
        virtual const std::string& getName() const = 0;

        /// @brief Sets the name of a task
        /// @param name New name
        virtual void setName(std::string name) = 0;

        /// @brief Gets the unique id of the task
        /// @return Unique id
        virtual const std::string getId() const = 0;

        /// @brief Gets the description of a task
        /// @return Description of task
        virtual const std::string& getDescription() const = 0;

        /// @brief Sets the description of a task
        /// @param description New description
        virtual void setDescription(std::string description) = 0;

        /// @brief Gets the due date of a task
        /// @return Due date and time of task
        virtual const IDateTime& getDueDateTime() const = 0;

        /// @brief Sets the due date and time of a task
        /// @param unixTime Seconds since 00:00:00 UTC 1/1/1970
        virtual void setDueDateTime(int unixTime) = 0;
};