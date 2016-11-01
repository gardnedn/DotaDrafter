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
    std::string name;
    unsigned char status;
    int push;

public:
    Hero();
    Hero(const std::string&);
    void setStatus(const unsigned char& s);
    void setPush(const int&);
    int getPush();
    std::string getName();
};


#endif /* defined(__DotaProject__Hero__) */
