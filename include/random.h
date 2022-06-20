#pragma once

#include <chrono>
#include <random>

namespace random {
    inline unsigned int seed() {
        return std::chrono::system_clock::now().time_since_epoch().count();
    }

    inline unsigned int int32(unsigned int seed = random::seed()) {
        std::mt19937 generator(seed);
        return generator();
    }

    inline unsigned long long int64(unsigned int seed = random::seed()) {
        std::mt19937_64 generator(seed);
        return generator();
    }
}
