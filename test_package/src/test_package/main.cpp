#include <variant_topic_tools/MessageDataType.h>

#include <test_msgs/Test.h>
#include <geometry_msgs/Quaternion.h>

namespace traits = ros::message_traits;

template <class T>
void test()
{
  variant_topic_tools::MessageType type;
  type.setMD5Sum(traits::MD5Sum<T>::value());
  type.setDataType(traits::DataType<T>::value());
  type.setDefinition(traits::Definition<T>::value());

  variant_topic_tools::MessageDefinition definition(type);
  variant_topic_tools::MessageDataType data_type = definition.getMessageDataType();

  ROS_INFO("DataType: %s", type.getDataType().c_str());
  ROS_INFO("getNumVariableMembers: %zu", data_type.getNumVariableMembers());

  for (size_t i = 0; i < data_type.getNumVariableMembers(); ++i)
  {
    const variant_topic_tools::MessageMember member = data_type.getMember(i);
    ROS_INFO("member_%zu: %s", i, member.getName().c_str());
  }

  std::cout << std::endl;
}
int main(int argc, char *argv[])
{
  ros::init(argc, argv, "test_package");

  // OK
  test<geometry_msgs::Quaternion>();

  // NG
  test<test_msgs::Test>();
}
