#pragma once
template<typename Instanceble>
class Instance{
    protected:
        Instance(const Instance&) = delete;
        Instance& operator=(const Instance&) = delete;
        Instance() = default;
        ~Instance() = default;
    public:
        static Instanceble& getInstance(){
            static Instanceble instance;
            return instance;
        }
};