#include    <ros/ros.h>

#include    <std_msgs/Int64.h>

#include    <iostream>

#include    <thread>

void thread_spin( ros::NodeHandle* node_handle );

void callback( const std_msgs::Int64& message );

int main( int argv , char** argc )
{
    ros::init( argv , argc , "imu" );

    ros::NodeHandle nh("");

    ros::Subscriber sub_int64 = nh.subscribe( "test_thread/int64" , 1 , &callback );

    ros::Rate rate( 5 );

    std::thread spin_thread( &thread_spin , &nh );

    int count = 0; 

    while( nh.ok() )
    {
        count++;
        std::cout   << "In loop nh.ok() count is " << count  << std::endl;
        rate.sleep();
    }

    std::cout   << "Before join\n";
    spin_thread.join();
    std::cout << "out of loop close program\n";
}

void thread_spin( ros::NodeHandle* node_handle )
{
    if( node_handle->ok() )
    {
        std::cout   << "node ok let start spin\n";
        ros::spin();
        std::cout   << "finish spin\n";
    }
    else
    {
        std::cout   << "node didn't ok\n";
    }
    std::cout   << "End function thread_spin\n";
}

void callback( const std_msgs::Int64& message )
{
    std::cout   << "Callback called number is " << message.data << "\n";
}
