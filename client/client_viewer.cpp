#include "client_viewer.h"

#include <iostream>



Viewer::Viewer(){



}

void Viewer::showViewer(PointCloud<PointXYZRGB> receivedCloud){

	//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
	//pcl::io::loadPCDFile ("bunny.pcd", *cloud);
	//pcl::visualization::CloudViewer cloudViewer("Cloud Viewer");

	//cloudViewer.showCloud(receivedCloud);

	//cout << "displaying points..." << endl;
	for (size_t i = 0; i < receivedCloud.points.size (); ++i)
	{
		
		
		std::cerr << "    " << receivedCloud.points[i].x << " " << receivedCloud.points[i].y << " " << receivedCloud.points[i].z << std::endl;
	}
   
 //   pcl::visualization::CloudViewer viewer("Cloud Viewer");
    
    //blocks until the cloud is actually rendered
 //   viewer.showCloud(receivedCloud);



/*
	while(!cloudViewer.wasStopped())
	{
		// do nothing
	}
*/
	


}


