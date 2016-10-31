//
//  Hero.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 5/19/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "Hero.h"
#include <string>
class Hero {
    std::string name;
    unsigned char status; //pick, ban, available.
    int push; //, highGround, gank, lane, heal, damage, vision; //etc
public:
    Hero() {
    }
    Hero(const std::string& n) {
        name = n;
        status = 'a'; //either b for banned, p for picked, a for available.
    }
    //make a constructor for all the values once we have them.
    
    int getPush() {
        return push;
    }
    void setPush(const int& p) {
        push = p;
    }
    void setStatus(const unsigned char& s) {
        status = s;
    }
    //    void sethighGround(const int& p);
    //    void setGank(const int& p);
    //    void setLane(const int& p);
    //    void setHeal(const int& p);
    //    void setDamage(const int& p);
    //    void setVision(const int& p);
    
    
};
