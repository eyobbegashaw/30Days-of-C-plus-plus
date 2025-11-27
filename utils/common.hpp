#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Common utility functions and definitions

// Debug macro
#ifdef DEBUG
#define DBG(x) std::cout << "DEBUG: " << x << std::endl
#else
#define DBG(x)
#endif

// Print vector elements
template<typename T>
void printVector(const std::vector<T>& vec, const std::string& name = "Vector") {
    std::cout << name << ": ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Simple timer class
class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}
    
    void reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }
    
    double elapsed() const {
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(end_time - start_time).count();
    }
};

#endif // COMMON_HPP