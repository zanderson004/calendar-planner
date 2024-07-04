#pragma once

/// @brief Interface for a class that contains other elements by index
/// @tparam T The type of objects stored
template <class T>
class ICollection {
    public:
        /// @brief Virtual destructor
        virtual ~ICollection() = default;

        /// @brief Get the size of the collection
        /// @return The number of elements in the collection
        virtual int size() const = 0;

        /// @brief Gets the element at the specified index
        /// @param index The index to get from
        /// @return The element at index
        virtual const T& at(int index) const = 0;

        /// @brief Pushes an element to the collection
        /// @param element The element to add
        virtual void push(T element) = 0;

        /// @brief Erases an element at a specified index
        /// @param index The index to erase from
        virtual void erase(int index) = 0;
};