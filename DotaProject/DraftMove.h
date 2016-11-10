//
//  DraftMove.h
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#ifndef __DotaProject__DraftMove__
#define __DotaProject__DraftMove__

#include <stdio.h>
#include "Hero.h"
class DraftMove {
    Hero hero;
    unsigned char action; //ban, pick.
    unsigned int round; //round the move is made. only positive so unsigned
public:
    DraftMove(const Hero& hero, const unsigned char& a, const unsigned int r);
    Hero getHero() ;
    unsigned char getAction() ;
    unsigned int getRound() ;
};


#endif /* defined(__DotaProject__DraftMove__) */
