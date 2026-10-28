#include <memory>
#include "intro_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  //初始化ros2上下文

  auto node = std::make_shared<IntroNode>();
  //创建并启动节点，交给智能指针管理

  rclcpp::spin(node);
  //启动节点，等待回调函数被调用
  
  rclcpp::shutdown();
  //关闭ros2上下文
  return 0;
}
