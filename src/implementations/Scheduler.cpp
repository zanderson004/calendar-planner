#include "entities/Scheduler.hpp"

#include <random>
#include <algorithm>

double Scheduler::weighting(const ITask& task) const {
    double timeDiff = static_cast<double>(task.getDueDateTime().getTime() - time(nullptr));
    return 1.0 / timeDiff;
}

void Scheduler::addTask(const ITask& task) {
    std::string id = task.getId();
    m_tasks.emplace(id, std::cref(task));
}

void Scheduler::removeTask(std::string taskId) {
    m_tasks.erase(taskId);
}

const ITask& Scheduler::getNextTask() const {
    // Generate weightings
    std::vector<double> probabilities;
    std::vector<std::reference_wrapper<const ITask>> tasks;

    double weightedSum = 0;
    for (auto& [id, task] : m_tasks) {
        double weight = weighting(task);
        probabilities.push_back(weight);
        tasks.push_back(task);
        weightedSum += weight;
    }

    // Convert to probability distribution function
    if (probabilities.size() > 0) probabilities[0] /= weightedSum;
    for (size_t i = 1; i < probabilities.size(); i++) {
        probabilities[i] /= weightedSum;
        probabilities[i] += probabilities[i-1];
    }

    // Choose task
    double randVal = static_cast<double>(rand()) / RAND_MAX;
    auto probabilityIterator = std::lower_bound(probabilities.begin(), probabilities.end(), randVal);
    size_t index = static_cast<size_t>(probabilityIterator - probabilities.begin());
    return tasks[index].get();
}