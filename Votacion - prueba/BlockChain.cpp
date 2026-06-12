//
// Created by STEVEN on 10/06/2026.
//

#include "BlockChain.h"
#include <iostream>

BlockChain* BlockChain::instance = nullptr; // inicialización obligatoria del static

BlockChain::BlockChain() = default;

BlockChain *BlockChain::getInstance() {
    if (instance == nullptr) {
        instance = new BlockChain();
    }
    return instance;
}

bool BlockChain::isChainValid() const {
    for (size_t i = 1; i < blocks.size(); ++i) {
        const Block& current = blocks[i];
        const Block& prev = blocks[i - 1];

        if (current.current_hash != current.calcularHash()) {
            return false;
        }

        if (current.previous_hash != prev.current_hash) {
            return false;
        }
    }
    return true;
}

void BlockChain::addBlock(Block&& block) {
    const std::string prevHash = blocks.empty() ? "0" : blocks.back().current_hash; // determina el hash previo: vacía -> "0", sino el último bloque
    block.previous_hash = prevHash;  // enlaza con el bloque anterior
    block.mineBlock(difficulty);     
    blocks.push_back(std::move(block)); 
    std::cout << "[BlockChain] Bloque #" << blocks.back().id
              << " minado. Hash: " << blocks.back().current_hash
              << " | Nonce: " << blocks.back().nonce << "\n";
}