//
//  main.cpp
//  PCL_CLOUD_TEST
//
//  Created by saong on 2019/10/18.
//  Copyright © 2019 saong. All rights reserved.
//

#include <iostream>
#include "POINT.hpp"
int main(int argc, const char * argv[]) {
    
    point p("/Users/saong/Desktop/台科大掃描1.las");
        
    p.visualization();
    
    cout<<endl;
    
    return 0;
}
