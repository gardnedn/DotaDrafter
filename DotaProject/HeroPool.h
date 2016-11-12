//
//  HeroPool.h
//  DotaProject
//
//  Created by Daniel Gardner on 10/31/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#ifndef __DotaProject__HeroPool__
#define __DotaProject__HeroPool__

#include <stdio.h>
#include "Hero.h"
#include <vector>
class HeroPool {
private:
    std::vector<Hero> pool;
    
public:
    //
    HeroPool();
    std::vector<Hero> getPool();
    
};


#endif /* defined(__DotaProject__HeroPool__) */
