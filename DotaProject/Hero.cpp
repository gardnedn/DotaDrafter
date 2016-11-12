 //
 //
 #include "Hero.h"
 #include <string>
#include <iostream>

Hero::Hero() {
    name = "Danny";
    status = 'a';
    push = 0;
}
Hero::Hero(const std::string& n) {
         name = n;
         status = 'a'; //either b for banned, p for picked, a for available.
         push = 0;
     }
     //make a constructor for all the values once we have them.
 
std::string Hero::getName() {
    return name;
}

void Hero::setName(const std::string& s) {
    name = s;
}
unsigned char Hero::getStatus() {
    return status;
}
void Hero::setStatus(const unsigned char& s) {
         status = s;
     }


int Hero::getPush() {
    return push;
}
void Hero::setPush(const int& p) {
    push = p;
}



//     void sethighGround(const int& p);
//     void setGank(const int& p);
//     void setLane(const int& p);
//     void setHeal(const int& p);
//     void setDamage(const int& p);
//     void setVision(const int& p);
 


