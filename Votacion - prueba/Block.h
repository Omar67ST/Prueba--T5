//
// Created by STEVEN on 10/06/2026.
//

#ifndef HOMEWORK_PROTOTYPE_BLOCK_H
#define HOMEWORK_PROTOTYPE_BLOCK_H

#include <string>
#include <vector>

#include "Vote.h"

class Block {
    friend class BlockChain;
private:
    int id;
    std::string previous_hash;
    std::vector<Vote> list_votes;
    int nonce;
    std::string current_hash;
public:
    Block(int _id, std::string&& _prevHash, const std::vector<Vote>& _votes);
    [[nodiscard]] std::string calcularHash() const;
    void mineBlock(int difficulty);

    int getNonce() const {
        return nonce;
    }
    std::string getCurrentHash() const { return current_hash; }
};
#endif //HOMEWORK_PROTOTYPE_BLOCK_H