//
//  DraftMove.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "DraftMove.h"
#include "Hero.cpp"

class DraftMove {
    Hero h;
    unsigned char action; //ban, pick.
public:
    DraftMove(Hero& hero, const unsigned char& a) {
        h = hero;
        action = a;
    }
    
};

