#include "entities/Task.hpp"

int Task::m_idCounter = 0;

Task::Task(std::string name, std::string description, std::unique_ptr<IDateTime> dueDateTime):
    m_name(std::move(name)), m_id(m_idCounter++), m_description(std::move(description)), m_dueDateTime(std::move(dueDateTime)) {}

Task::Task(std::string name, std::unique_ptr<IDateTime> dueDateTime): Task(name, "", std::move(dueDateTime)) {}

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

void Task::setDueDateTime(std::unique_ptr<IDateTime> dueDateTime) {
    m_dueDateTime = std::move(dueDateTime);
}