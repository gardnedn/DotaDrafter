//
//  main.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 5/19/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include <iostream>
#include "hero.cpp"
#include <vector>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::vector<Hero> heroPool;
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
    
    heroPool.push_back(Lesh);
    heroPool.push_back(Abadon);
    heroPool.push_back(Phoenix);
    heroPool.push_back(Axe);
    heroPool.push_back(Riki);
    heroPool.push_back(TA);
    
    
    //std::cout << h.getPush();
    return 0;
}
