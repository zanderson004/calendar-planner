#include "entities/Task.hpp"

int Task::m_idCounter = 0;

Task::Task(std::string name, std::string description, std::unique_ptr<IDateTime> dueDateTime):
    m_name(std::move(name)), m_id(m_idCounter++), m_description(std::move(description)), m_dueDateTime(std::move(dueDateTime)) {}

Task::Task(std::string name, std::unique_ptr<IDateTime> dueDateTime): Task(std::move(name), "", std::move(dueDateTime)) {}

Task::Task(const Task& other):
    Task(other.m_name, other.m_description, other.m_dueDateTime->clone()) {}

Task::Task(Task&& other) noexcept:
    m_name(std::move(other.m_name)), m_id(other.m_id), m_description(std::move(other.m_description)), m_dueDateTime(std::move(other.m_dueDateTime)) {
        other.m_id = -1;
    }

Task& Task::operator=(const Task& other) {
    if (this != &other) {
        m_name = other.m_name;
        m_id = m_idCounter++;
        m_description = other.m_description;
        m_dueDateTime = other.m_dueDateTime->clone();
    }
    return *this;
}

Task& Task::operator=(Task&& other) noexcept {
    if (this != &other) {
        m_name = std::move(other.m_name);
        m_id = other.m_id;
        other.m_id = -1;
        m_description = std::move(other.m_description);
        m_dueDateTime = std::move(other.m_dueDateTime);
    }
    return *this;
}

Task::Task(const Task& oth):
    m_name(std::move(oth.m_name)), m_id(oth.m_id), m_description(std::move(oth.m_description)), m_dueDateTime(std::move(oth.m_dueDateTime)) {}

const std::string& Task::getName() const {
    return m_name;
}

void Task::setName(std::string name) {
    m_name = std::move(name);
}

const std::string Task::getId() const {
    return "Task#" + std::to_string(m_id);
}

const std::string& Task::getDescription() const {
    return m_description;
}

void Task::setDescription(std::string description) {
    m_description = std::move(description);
}

const IDateTime& Task::getDueDateTime() const {
    return *m_dueDateTime;
}

void Task::setDueDateTime(int unixTime) {
    m_dueDateTime->setTime(unixTime);
}