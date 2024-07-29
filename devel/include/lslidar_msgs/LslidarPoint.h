// Generated by gencpp from file lslidar_msgs/LslidarPoint.msg
// DO NOT EDIT!


#ifndef LSLIDAR_MSGS_MESSAGE_LSLIDARPOINT_H
#define LSLIDAR_MSGS_MESSAGE_LSLIDARPOINT_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace lslidar_msgs
{
template <class ContainerAllocator>
struct LslidarPoint_
{
  typedef LslidarPoint_<ContainerAllocator> Type;

  LslidarPoint_()
    : time(0.0)
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , azimuth(0.0)
    , distance(0.0)
    , intensity(0.0)  {
    }
  LslidarPoint_(const ContainerAllocator& _alloc)
    : time(0.0)
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , azimuth(0.0)
    , distance(0.0)
    , intensity(0.0)  {
  (void)_alloc;
    }



   typedef float _time_type;
  _time_type time;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef double _azimuth_type;
  _azimuth_type azimuth;

   typedef double _distance_type;
  _distance_type distance;

   typedef double _intensity_type;
  _intensity_type intensity;





  typedef boost::shared_ptr< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> const> ConstPtr;

}; // struct LslidarPoint_

typedef ::lslidar_msgs::LslidarPoint_<std::allocator<void> > LslidarPoint;

typedef boost::shared_ptr< ::lslidar_msgs::LslidarPoint > LslidarPointPtr;
typedef boost::shared_ptr< ::lslidar_msgs::LslidarPoint const> LslidarPointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lslidar_msgs::LslidarPoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::lslidar_msgs::LslidarPoint_<ContainerAllocator1> & lhs, const ::lslidar_msgs::LslidarPoint_<ContainerAllocator2> & rhs)
{
  return lhs.time == rhs.time &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.azimuth == rhs.azimuth &&
    lhs.distance == rhs.distance &&
    lhs.intensity == rhs.intensity;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::lslidar_msgs::LslidarPoint_<ContainerAllocator1> & lhs, const ::lslidar_msgs::LslidarPoint_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace lslidar_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4f9dbdcdc2cb5386e16b2ab1f416979d";
  }

  static const char* value(const ::lslidar_msgs::LslidarPoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4f9dbdcdc2cb5386ULL;
  static const uint64_t static_value2 = 0xe16b2ab1f416979dULL;
};

template<class ContainerAllocator>
struct DataType< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lslidar_msgs/LslidarPoint";
  }

  static const char* value(const ::lslidar_msgs::LslidarPoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Time when the point is captured\n"
"float32 time\n"
"\n"
"# Converted distance in the sensor frame\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"# Raw measurement from Leishen M10\n"
"float64 azimuth\n"
"float64 distance\n"
"float64 intensity\n"
;
  }

  static const char* value(const ::lslidar_msgs::LslidarPoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.azimuth);
      stream.next(m.distance);
      stream.next(m.intensity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LslidarPoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lslidar_msgs::LslidarPoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lslidar_msgs::LslidarPoint_<ContainerAllocator>& v)
  {
    s << indent << "time: ";
    Printer<float>::stream(s, indent + "  ", v.time);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "azimuth: ";
    Printer<double>::stream(s, indent + "  ", v.azimuth);
    s << indent << "distance: ";
    Printer<double>::stream(s, indent + "  ", v.distance);
    s << indent << "intensity: ";
    Printer<double>::stream(s, indent + "  ", v.intensity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LSLIDAR_MSGS_MESSAGE_LSLIDARPOINT_H
