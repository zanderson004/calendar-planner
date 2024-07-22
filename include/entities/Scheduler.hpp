#pragma once

#include "interfaces/IScheduler.hpp"

#include <functional>
#include <unordered_map>

/// @brief Implementation of a basic scheduler object using vectors
class Scheduler : public IScheduler {
    private:
        /// @brief Map of all tasks considered by the scheduler
        std::unordered_map<std::string, std::reference_wrapper<const ITask>> m_tasks;

        /// @brief Returns a value defining the relative importance of a task
        /// @param task The task being considered
        /// @return The relative weight of the tasks
        double weighting(const ITask& task) const;
        
    public:
        void addTask(const ITask& task) override;
        void removeTask(std::string taskId) override;
        const ITask& getNextTask() const override;
};