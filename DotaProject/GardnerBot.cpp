//
//  GardnerBot.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 11/12/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "GardnerBot.h"


Team GardnerBot::getDire() {
    return dire;
}
Team GardnerBot::getRadiant() {
    return radiant;
}
HeroPool GardnerBot::getPool() {
    return pool;
}
std::vector<DraftMove> GardnerBot::getMvStack() {
    return mvStack;
}

double GardnerBot::evaluate(std::vector<int> weights, Team t) {
    return 0.0;
}

void GardnerBot::alphaBeta(HeroPool hp, int currDepth, double alpha, double beta,
               bool firstTeamToPick, bool isRadiant, Team team) {
    
}
