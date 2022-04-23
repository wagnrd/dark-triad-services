#ifndef DARK_TRIAD_SERVICES_STATISTIC_FACTORY_HPP
#define DARK_TRIAD_SERVICES_STATISTIC_FACTORY_HPP

#include <json/value.h>

#include "include/service/characters/model/statistic.hpp"

class StatisticFactory {
public:
    static std::shared_ptr<Json::Value> to_json(const Statistic& statistic);
};

#endif //DARK_TRIAD_SERVICES_STATISTIC_FACTORY_HPP