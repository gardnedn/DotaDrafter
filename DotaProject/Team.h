//
//  Team.h
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#ifndef __DotaProject__Team__
#define __DotaProject__Team__

#include <stdio.h>
#include <vector>
#include "Hero.h"
class Team {
private:
    std::vector<Hero> selectedHeroes;
    bool isRadiant, firstPick;
public:
    Team();
    void addHero(Hero& h);
    void setIsRadiant(const bool& b);
    bool getIsRadiant();
    void setIsFirstPick(const bool& b);
    bool isFirstPick();
    
};


#endif /* defined(__DotaProject__Team__) */
/*

 class Hero {
 
 public:
 std::string name;
 unsigned char status;
 int push;
 
 Hero();
 Hero(const std::string&);
 void setStatus(const unsigned char& s);
 void setPush(const int&);
 int getPush();
 std::string getName();
 };
 
*/