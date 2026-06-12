//
// Created by STEVEN on 11/06/2026.
//

#ifndef HOMEWORK_PROTOTYPE_POLLING_STATION_OBSERVER_H
#define HOMEWORK_PROTOTYPE_POLLING_STATION_OBSERVER_H
#include "Block.h"

class PollingStationObserver {
public:
    virtual ~PollingStationObserver() = default;
    virtual void update(const Block& newBlock) = 0;
};

#endif //HOMEWORK_PROTOTYPE_POLLING_STATION_OBSERVER_H