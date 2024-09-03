#ifndef _HEXURO_TIMER_
#define _HEXURO_TIMER_

#include <chrono>
#include <iostream>

namespace Hexuro {
    class Timer {
    public:
        Timer() {
            reset();
        }

        void reset() {
            start_time = std::chrono::high_resolution_clock::now();
        }

        double elapsed() const {
            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end_time - start_time;
            return duration.count();
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    };

}

#endif