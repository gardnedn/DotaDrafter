//
//  DraftMove.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "DraftMove.h"
#include "Hero.h"

class DraftMove {
    Hero h;
    unsigned char action; //ban, pick.
    unsigned int round; //round the move is made. only positive so unsigned
public:
    DraftMove(const Hero& hero, const unsigned char& a, const unsigned int r) {
        h = hero;
        action = a;
        round = r;
    }
    
};

