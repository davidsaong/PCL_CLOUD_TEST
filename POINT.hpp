//
//  POINT.hpp
//  PCL_CLOUD_TEST
//
//  Created by saong on 2019/10/18.
//  Copyright © 2019 saong. All rights reserved.
//

#ifndef POINT_hpp
#define POINT_hpp

#include <stdio.h>
#include <pcl/io/pcd_io.h>  //檔案輸入輸出
#include <pcl/point_types.h>  //點型別相關定義
#include <pcl/visualization/cloud_viewer.h>  //點型別相關定義
#include <liblas/liblas.hpp>
#include <fstream>
#include <string>

#endif /* POINT_hpp */
class point{
    
    pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloudPtr;
    
public:
    
    point(std::string filedir);
    void show_data();
    void visualization();
};
