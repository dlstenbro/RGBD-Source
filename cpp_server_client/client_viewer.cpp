#include "client_viewer.h"

#include <iostream>

using namespace std;

Viewer::Viewer(){



}

void Viewer::showViewer(){
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile ("bunny.pcd", *cloud);

	pcl::visualization::CloudViewer viewer("Cloud Viewer");
	viewer.showCloud(cloud);
	while(!viewer.wasStopped()){

	}

	


}

int main(){

	Viewer viewer;
	viewer.showViewer();
}
