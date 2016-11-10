//
//  HeroPool.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include "HeroPool.h"
#include "Hero.h"
#include <string>
#include <vector>
#include <iostream>
    HeroPool::HeroPool() {
        Hero::Hero Lesh = Hero("Leshrac");
        Lesh.setPush(80);
        
        Hero::Hero Abadon = Hero("Abadon");
        Abadon.setPush(70);
        
        Hero::Hero Phoenix = Hero("Phoenix");
        Phoenix.setPush(60);
        
        Hero::Hero Axe = Hero("Axe");
        Axe.setPush(50);
        
        Hero::Hero Riki = Hero("Axe");
        Riki.setPush(40);
        
        Hero::Hero TA = Hero("Axe");
        TA.setPush(30);
        pool.push_back(TA);
        pool.push_back(Lesh);
        
    }


std::vector<Hero::Hero> HeroPool::getPool() { std::cout << pool.back().getName(); return pool;}

