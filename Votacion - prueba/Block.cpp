//
// Created by STEVEN on 10/06/2026.
//
#include <sstream>
#include <iomanip>

#include "Block.h"

Block::Block(int _id, std::string&& _prevHash, const std::vector<Vote>& _votes)
    : id(_id), previous_hash(_prevHash), list_votes(_votes), nonce(0) {
        
    }

std::string Block::calcularHash() const {
    std::stringstream ss;

    ss << id << previous_hash << nonce;
    for (const auto& vote : list_votes) {
        ss << vote.hash << static_cast<int>(vote.candidate);
    }

    std::hash<std::string> hasher;
    size_t hash_number = hasher(ss.str());

    std::stringstream hex_ss;
    hex_ss << std::hex << std::setw(16) << std::setfill('0') << hash_number;
    return hex_ss.str();
}

void Block::mineBlock(const int difficulty) {
    const std::string target(difficulty, '0');
    while (current_hash.substr(0,difficulty) != target) {
        nonce++;
        current_hash = calcularHash();
    }
}