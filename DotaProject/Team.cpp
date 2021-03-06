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
void Team::setIsRadiant(const bool& b){
    isRadiant = b;
}
bool Team::getIsRadiant() {
    return isRadiant;
}
void Team::setIsFirstPick(const bool& b){
    firstPick = b;
}
bool Team::isFirstPick() {
    return firstPick;
}
std::vector<Hero> Team::getSelectedHeroes() { return selectedHeroes; }
