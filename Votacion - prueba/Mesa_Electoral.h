//
// Created by STEVEN on 11/06/2026.
//

#ifndef HOMEWORK_PROTOTYPE_MESA_ELECTORAL_H
#define HOMEWORK_PROTOTYPE_MESA_ELECTORAL_H

#include <iostream>
#include <string>
#include "Polling_Station_Observer.h"
#include "BlockChain.h"

// Mesa Electoral: nodo de la red, tiene su propia copia local de la blockchain
class MesaElectoral : public PollingStationObserver {
    std::string name;        
    BlockChain* local_chain; 

public:
    explicit MesaElectoral(const std::string& _name)
        : name(_name), local_chain(BlockChain::getInstance()) {}

    void update(const Block& newBlock) override {
        if (newBlock.getCurrentHash().empty()) {
            std::cout << "[" << name << "] Bloque recibido inválido, descartando.\n";
            return;
        }
        local_chain->addBlock(Block(newBlock)); // copia el bloque ya minado
        std::cout << "[" << name << "] Bloque recibido y agregado. "
                  << "Cadena valida: "
                  << (local_chain->isChainValid() ? "SI" : "NO") << "\n";
    }

    const std::string& getName() const { return name; }
};

#endif //HOMEWORK_PROTOTYPE_MESA_ELECTORAL_H