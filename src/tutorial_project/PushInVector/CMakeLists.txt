add_library( PushInVector SHARED push_data.cpp)
install ( TARGETS PushInVector DESTINATION bin )
install ( FILES PushInVector.hpp DESTINATION include )
ament_export_libraries( PushInVector )
