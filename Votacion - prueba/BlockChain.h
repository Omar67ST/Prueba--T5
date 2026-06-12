//
// Created by STEVEN on 10/06/2026.
//

#ifndef HOMEWORK_PROTOTYPE_BLOCKCHAIN_H
#define HOMEWORK_PROTOTYPE_BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class BlockChain {
    explicit BlockChain();
private:
    static BlockChain* instance;
    std::vector<Block> blocks;      // cadena de bloques
    int difficulty = 3;             // cantidad de ceros exigidos al inicio del hash
public:
    static BlockChain* getInstance();
    BlockChain(const BlockChain&) = delete;
    BlockChain& operator=(const BlockChain&) = delete;
    void addBlock(Block&& block);           
    [[nodiscard]] bool isChainValid() const;
    [[nodiscard]] const std::vector<Block>& getBlocks() const { return blocks; }
};

#endif //HOMEWORK_PROTOTYPE_BLOCKCHAIN_H