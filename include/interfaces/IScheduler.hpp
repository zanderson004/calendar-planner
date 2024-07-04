#pragma once

#include "interfaces/ITask.hpp"
#include "interfaces/ICollection.hpp"

/// @brief Interface for object that can schedule tasks for the user
class IScheduler {
    public:
        /// @brief Virtual destructor
        virtual ~IScheduler() = default;

        /// @brief Adds a task to the scheduler
        /// @param task The task to be added
        virtual void addTask(ITask task) = 0;

        /// @brief Removes a task from the scheduler
        /// @param taskId The task to be removed
        virtual void removeTask(int taskId) = 0;

        /// @brief Gets the next task to be completed
        /// @return The task to be completed
        virtual const ITask& getNextTask() const = 0;

        /// @brief Gets all tasks in the scheduler
        /// @return A collection of all tasks in the scheduler
        virtual const ICollection<ITask>& getAllTasks() const = 0;
};