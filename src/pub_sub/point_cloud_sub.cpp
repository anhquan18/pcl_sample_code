#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <boost/foreach.hpp>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

void callback(const PointCloud::ConstPtr& msg)
{
    printf("Cloud: width = %d, height = %d\n", msg->width, msg->height);
    // for loop?
    BOOST_FOREACH (const pcl::PointXYZ& pt, msg->points)
        printf("\t(%f, %f, %f)\n", pt.x, pt.y, pt.z);
}

int main(int argc, char** argv)
{
    ros::init (argc, argv, "sub_pcl");
    ros::NodeHandle nh;

    // crane-x7 d435 point cloud
    //ros::Subscriber sub = nh.subscribe<PointCloud> ("/camera/depth_registered/points", 1, callback);

    // gazebo crane-x7 d435 point cloud
    ros::Subscriber sub = nh.subscribe<PointCloud> ("/camera/depth/color/points", 1, callback);
    ros::spin();
}
