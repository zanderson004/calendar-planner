#pragma once

#include "interfaces/ITask.hpp"
#include "interfaces/IDateTime.hpp"

/// @brief Basic implementation of a task object
class Task : public ITask {
    private:
        /// @brief Used to generate unique ids
        static int m_idCounter;

        /// @brief Name of the task
        std::string m_name;

        /// @brief Unique id number of the task
        int m_id;

        /// @brief Description of the task
        std::string m_description;

        /// @brief Date and time at which the task is due
        std::unique_ptr<IDateTime> m_dueDateTime;

    public:
        /// @brief Constructs a task with all fields specified
        /// @param name Name of the task
        /// @param description  Description of the task
        /// @param unixTime Seconds since since 00:00:00 UTC 1/1/1970 at which the task is due
        Task(std::string name, std::string description, std::unique_ptr<IDateTime> dueDateTime);

        /// @brief Constructs a task without a description
        /// @param name Name of the task
        /// @param unixTime Seconds since since 00:00:00 UTC 1/1/1970 at which the task is due
        Task(std::string name, std::unique_ptr<IDateTime> dueDateTime);

        /// @brief Default destructor included for rule of 5
        ~Task() = default;

        /// @brief Copy constructor deep copies the IDateTime pointer
        /// @param other Existing object
        Task(const Task& other);

        /// @brief Move constructor
        /// @param other Existing object
        Task(Task&& other) noexcept;

        /// @brief Copy assignment operator deep copies the IDateTime pointer
        /// @param other Existing object
        /// @return Result of assignment expression
        Task& operator=(const Task& other); 

        /// @brief Move assignment operator
        /// @param other Existing object
        /// @return Result of assignment expression
        Task& operator=(Task&& other) noexcept;

        const std::string& getName() const override;
        void setName(std::string name) override;
        const std::string getId() const override;
        const std::string& getDescription() const override;
        void setDescription(std::string description) override;
        const IDateTime& getDueDateTime() const override;
        void setDueDateTime(int unixTime) override;
};