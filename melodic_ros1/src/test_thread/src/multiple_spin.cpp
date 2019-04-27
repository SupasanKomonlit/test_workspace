#include    <ros/ros.h>

#include    <std_msgs/Int64.h>

#include    <iostream>

#include    <memory>

#include    <thread>

class ros_single_thread
{

    public:
        ros_single_thread( int my_id , std::shared_ptr<ros::NodeHandle> ptr_node_handle );

        void setup_subscriber( std::string topic_name );

        void callback( const std_msgs::Int64& message );

        bool spin(); 

    protected:
        int my_id;
        std::shared_ptr<ros::NodeHandle> ptr_node_handle;
        std::thread my_thread;
        ros::Subscriber my_sub;

        void thread_spin();

}; // class single_thread



int main( int argv , char** argc )
{

    ros::init( argv , argc , "test" );
    std::shared_ptr< ros::NodeHandle > ptr_node_handle = std::make_shared< ros::NodeHandle >("");
    ros_single_thread first_thread( 1 , ptr_node_handle );
    ros_single_thread second_thread( 2 , ptr_node_handle );
    ros::Rate rate( 1 );

    first_thread.setup_subscriber( "topic_01" );
    second_thread.setup_subscriber( "topic_02" );
    
    first_thread.spin();
    second_thread.spin();

    while( ptr_node_handle->ok() )
    {
        std::cout << "Loop ok\n";
        rate.sleep();
    }
}

ros_single_thread::ros_single_thread( int my_id 
        , std::shared_ptr< ros::NodeHandle > ptr_node_handle )
{
    this->ptr_node_handle = ptr_node_handle;
    this->my_id = my_id;
}

void ros_single_thread::setup_subscriber( std::string topic_name )
{
    // ros not ok with std::bind
    this->my_sub = this->ptr_node_handle->subscribe( topic_name , 1 ,
        &ros_single_thread::callback , this  
    );
}

void ros_single_thread::callback( const std_msgs::Int64& message)
{
    std::cout   << "Callback called on thread " << this->my_id << std::endl
                << "And message is " << message.data << std::endl;
}

void ros_single_thread::thread_spin()
{
    std::cout   << "Start spin thread " << this->my_id << std::endl;
    ros::spin();
    std::cout   << "End spin thread " << this->my_id << std::endl;
} 

bool ros_single_thread::spin()
{
    this->my_thread = std::thread( std::bind( &ros_single_thread::thread_spin , this ) );
    return true;
}
