//
//  GardnerBot.h
//  DotaProject
//
//  Created by Daniel Gardner on 11/12/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#ifndef __DotaProject__GardnerBot__
#define __DotaProject__GardnerBot__

#include <stdio.h>
#include "Team.h"
#include "HeroPool.h"
#include "DraftMove.h"
#include <vector>
class GardnerBot {
public: GardnerBot();
    Team getDire();
    Team getRadiant();
    HeroPool getPool();
    std::vector<DraftMove> getMvStack();
private:
    Team dire;
    Team radiant;
    HeroPool pool;
    std::vector<DraftMove> mvStack;
    
    double evaluate(std::vector<int> weights, Team t);
    void alphaBeta(HeroPool hp, int currDepth, double alpha, double beta,Team team);
    
};


#endif /* defined(__DotaProject__GardnerBot__) */
