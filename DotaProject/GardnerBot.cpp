//
//  GardnerBot.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 11/12/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "GardnerBot.h"
#include <numeric>
//will have to implement weights -can only be finalized once i have every draft attribute i want
//so will have to be a basic rough draft.


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

//possibly could have the evaluate in the team class, however we do need the weights vectors. which
//we could maybe pass in
double GardnerBot::evaluate(std::vector<int> weights, Team t) {
    
    return std::accumulate(t.getSelectedHeroes().begin(), t.getSelectedHeroes().end(),0);
    

}

void GardnerBot::alphaBeta(HeroPool hp, int currDepth, double alpha, double beta, Team team) {
    
}

/*essentially there are two situations:
    - radiant first pick vs dire second pick
    - dire first pick vs radiant second pick.
*/