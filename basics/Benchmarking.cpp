#include <iostream>
#include <memory>
#include <chrono>
#include <array>

class Timer {
public:
    Timer() {
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        Stop();
    }

    void Stop() {
        auto endTimepoint = std::chrono::high_resolution_clock ::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(
                m_StartTimepoint).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(
                endTimepoint).time_since_epoch().count();
        auto duration = stop - start;
        double ms = duration * 0.001;

        std::cout << duration << "micro-s (" << ms << "ms)\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

int main() {
    int value = 0;
    {
        Timer timer;
        for (int i = 0; i < 1000000; i++) {
            value += 2;
        }
    }
    std::cout << value << std::endl;

    struct Vector2 {
        float x, y;
    };

    std::cout << "Make Shared" << std::endl;
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPointers;
        Timer timer;
        for (int i = 0; i < sharedPointers.size(); i++) {
            sharedPointers[i] = std::make_shared<Vector2>();
        }
    }

    std::cout << "New Shared" << std::endl;
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPointers;
        Timer timer;
        for (int i = 0; i < sharedPointers.size(); i++) {
            sharedPointers[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }

    std::cout << "Make Unique" << std::endl;
    {
        std::array<std::unique_ptr<Vector2>, 1000> sharedPointers;
        Timer timer;
        for (int i = 0; i < sharedPointers.size(); i++) {
            sharedPointers[i] = std::make_unique<Vector2>();
        }
    }
}