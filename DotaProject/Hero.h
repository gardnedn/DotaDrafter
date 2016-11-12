//
//  Hero.h
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#ifndef __DotaProject__Hero__
#define __DotaProject__Hero__

#include <stdio.h>
#include <string>
class Hero {
private:
    std::string name;
    unsigned char status;
    int push;
public:
    

    Hero();
    Hero(const std::string&);
    
    void setName(const std::string& s);
    void setStatus(const unsigned char& s);
    void setPush(const int&);
    
    std::string getName();
    unsigned char getStatus();
    int getPush();
    
};


#endif /* defined(__DotaProject__Hero__) */
