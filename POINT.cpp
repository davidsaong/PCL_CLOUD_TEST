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
    ofstream fout;
    fout.open("/Users/saong/Desktop/big.pts",ios::out|ios::trunc);
//    fout<<pointCloudPtr->size();
    size_t p_Count=pointCloudPtr->size()/2;
      fout<<p_Count;
//    for(pcl::PointCloud<pcl::PointXYZ>::iterator it = pointCloudPtr->begin(); it
//         != pointCloudPtr->end(); it++){
//
//        fout<<endl<<it->x<<" "<<it->y<<" "<<it->z<<0<<" "<<0<<" "<<0<<" "<<0;
//
//    }
    for(size_t i = 0;i<p_Count; i++){

        fout<<endl<<pointCloudPtr->at(i).x<<" "<<pointCloudPtr->at(i).y<<" "<<pointCloudPtr->at(i).z<<0<<" "<<0<<" "<<0<<" "<<0;

    }
    fout.close();
};

void point::visualization(){
    
    pcl::visualization::PCLVisualizer *viewer;
    viewer = new pcl::visualization::PCLVisualizer("point cloud viewer");

    viewer->addPointCloud<pcl::PointXYZ> (pointCloudPtr, "point cloud viewer");
 
    while (!viewer->wasStopped())
    {
        viewer->spinOnce();
    }
//    viewer->spin();
    
};
    

