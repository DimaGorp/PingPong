#pragma once

// Base class for singletons.
// Inherit from Instance<T> to make T a singleton.
// Usage: class MyClass : public Instance<MyClass>
template <typename Instanceble>
class Instance {
   protected:
    // Prevent copying
    Instance(const Instance&) = delete;
    Instance& operator=(const Instance&) = delete;

    Instance() = default;
    ~Instance() = default;

   public:
    // Returns the single instance of Instanceble.
    // Created on first call, destroyed on program exit.
    static Instanceble& getInstance() {
        static Instanceble instance;
        return instance;
    }
};