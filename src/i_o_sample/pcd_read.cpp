#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("table_scene_lms400.pcd", *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read the pcd file \n");
        return -1;
    }
    for (const auto& point: *cloud)
        std::cout << " " << point.x
                  << " " << point.y
                  << " " << point.z << std::endl;

    std::cout << "Loaded "
              << cloud->width * cloud->height
              << " data points from loaded pcd file with the following fields: "
              << std::endl;

    return 0;
}
