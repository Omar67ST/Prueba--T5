//
// Created by STEVEN on 10/06/2026.
//

#ifndef HOMEWORK_PROTOTYPE_VOTE_H
#define HOMEWORK_PROTOTYPE_VOTE_H

#include <string>

#include "Candidate.h"

struct Vote {
    std::string hash;
    Candidate candidate;
};

#endif //HOMEWORK_PROTOTYPE_VOTE_H