#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/visualization/point_cloud_color_handlers.h>
    
using namespace std;
using namespace pcl;


class Viewer{


	


	public:
		Viewer(void);
		void showViewer(PointCloud<PointXYZRGB> receivedCloud);


	private:
	

};
