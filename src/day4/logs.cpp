//
// Created by joel on 2019-03-23.
//

#include "logs.hpp"
#include <cstddef>
#include <limits>
#include <utility>

std::tuple<int, int> logs::getMaxSleeperInfo(const storage& logs)
{
    auto maxSleeperId = std::numeric_limits<int>::max();
    auto maxSleeperTimeSum = 0;

    // First find out which elf slep the most.
    for (const auto& log : logs) {
        auto sleepSum = 0;
        for (const auto& minCnt : log.second) {
            sleepSum += minCnt;
        }

        if (sleepSum > maxSleeperTimeSum) {
            maxSleeperTimeSum = sleepSum;
            maxSleeperId = log.first;
        }
    }

    // The find which minute said elf slept most.
    auto maxSleeperMinute = 0;
    auto maxSleeperTime = 0;
    for (size_t min = 0; min < logs.at(maxSleeperId).size(); min++) {
        if (logs.at(maxSleeperId).at(min) > maxSleeperTime) {
            maxSleeperTime = logs.at(maxSleeperId).at(min);
            maxSleeperMinute = static_cast<int>(min);
        }
    }

    return std::make_tuple(maxSleeperId, maxSleeperMinute);
}

// Find the ID and minut of elf that sleeps the most times on a minute.
std::tuple<int, int> logs::getMaxFrequentSleeperInfo(const logs::storage& logs)
{
    auto maxSleeperId = std::numeric_limits<int>::max();
    auto maxSleeperTime = 0;
    auto maxSleeperMinute = 0;

    for (const auto& log : logs) {
        for (size_t min = 0; min < log.second.size(); min++) {
            if (maxSleeperTime < log.second.at(min)) {
                maxSleeperTime = log.second.at(min);
                maxSleeperMinute = static_cast<int>(min);
                maxSleeperId = log.first;
            }
        }
    }

    return std::make_tuple(maxSleeperId, maxSleeperMinute);
}
