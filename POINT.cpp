//
//  POINT.cpp
//  PCL_CLOUD_TEST
//
//  Created by saong on 2019/10/18.
//  Copyright © 2019 saong. All rights reserved.
//

#include "POINT.hpp"
point::point(std::string filedir){
    std::ifstream ifs;
    ifs.open(filedir, std::ios::in | std::ios::binary);
    liblas::ReaderFactory f ;
    liblas::Reader reader = f.CreateWithStream(ifs);
    liblas::Header const& header = reader.GetHeader();
    pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloudPtrr(new pcl::PointCloud<pcl::PointXYZ>);
    pointCloudPtr=pointCloudPtrr;
    int count = header.GetPointRecordsCount();
    pointCloudPtr->resize(count);
    pointCloudPtr->width = 1;
    pointCloudPtr->height = count;
    pointCloudPtr->is_dense = false;
    int i = 0;
    while (reader.ReadNextPoint())
    {
        liblas::Point const& p = reader.GetPoint();
        pointCloudPtr->points[i].x = p.GetX();
        pointCloudPtr->points[i].y = p.GetY();
        pointCloudPtr->points[i].z = p.GetZ();
        ++i;
    }
    cout<<endl<<"read success "<<endl<<"point count:"<<count<<endl;
};
void point::show_data(){

    for(pcl::PointCloud<pcl::PointXYZ>::iterator it = pointCloudPtr->begin(); it
         != pointCloudPtr->end(); it++){
        cout<<endl<<it->x<<" "<<it->y<<" "<<it->z;
        
    }
};

void point::visualization(){
    
    int showpoint = 0;
    pcl::visualization::PCLVisualizer *viewer;
    viewer = new pcl::visualization::PCLVisualizer("point cloud viewer");
    viewer->createViewPort (0.0, 0, 0.5, 1.0, showpoint);
    viewer->setBackgroundColor(0, 0, 0);
    viewer->addPointCloud<pcl::PointXYZ> (pointCloudPtr, "point cloud viewer",showpoint);
    viewer->spin();
    
};
    

