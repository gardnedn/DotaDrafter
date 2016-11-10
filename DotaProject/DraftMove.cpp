//
//  DraftMove.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "DraftMove.h"
#include "Hero.h"


    DraftMove::DraftMove(const Hero& h, const unsigned char& a, const unsigned int r) {
        hero = h;
        action = a;
        round = r;
    }
Hero DraftMove::getHero() {
    return hero;
}
unsigned char DraftMove::getAction() {
    return action;
}
unsigned int DraftMove::getRound() {
    return round;
}


