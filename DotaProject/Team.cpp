//
//  Team.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "Team.h"
#include <vector>
#include "Hero.h"


Team::Team() {
        
    }
void Team::addHero(Hero& h) {
        selectedHeroes.push_back(h);
        h.setStatus('p');
    }

