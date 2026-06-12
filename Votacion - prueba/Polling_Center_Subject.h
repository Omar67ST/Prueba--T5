//
// Created by STEVEN on 11/06/2026.
//

#ifndef HOMEWORK_PROTOTYPE_POLLING_CENTER_SUBJECT_H
#define HOMEWORK_PROTOTYPE_POLLING_CENTER_SUBJECT_H

#include <vector>
#include <iostream>

#include "Polling_Station_Observer.h"

class PollingCenterSubject {
    std::vector<PollingStationObserver*> observers;
    public:
        void attach(PollingStationObserver* observer) {
            observers.push_back(observer);
        }
        void notificarNuevoBloque(const Block& bloque) {
            std::cout << "[Red Electoral] Notificando bloque a "
                << observers.size() << " mesa(s)..\n";
                
        for (auto* obs : observers) {
            obs->update(bloque); // llama a update en cada mesa
        }
    }
};

#endif //HOMEWORK_PROTOTYPE_POLLING_CENTER_SUBJECT_H