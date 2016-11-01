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

    HeroPool::HeroPool() {
        
        Hero Lesh = Hero("Leshrac");
        Lesh.setPush(80);
        
        Hero Abadon = Hero("Abadon");
        Abadon.setPush(70);
        
        Hero Phoenix = Hero("Phoenix");
        Phoenix.setPush(60);
        
        Hero Axe = Hero("Axe");
        Axe.setPush(50);
        
        Hero Riki = Hero("Axe");
        Riki.setPush(40);
        
        Hero TA = Hero("Axe");
        TA.setPush(30);
        
        pool.push_back(Lesh);
        pool.push_back(Abadon);
        pool.push_back(Phoenix);
        pool.push_back(Axe);
        pool.push_back(Riki);
        pool.push_back(TA);
    }

