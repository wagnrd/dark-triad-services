#ifndef DARK_TRIAD_SERVICES_STATISTIC_HPP
#define DARK_TRIAD_SERVICES_STATISTIC_HPP

#include <string>

class Statistic {
public:
    uint64_t createdTimestamp{};
    uint64_t lastUsedTimestamp{};
};

#endif //DARK_TRIAD_SERVICES_STATISTIC_HPP