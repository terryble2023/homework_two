#include "intro_node.hpp"

#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <utility>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using namespace std;

IntroNode::IntroNode(const string & node_name)
: rclcpp::Node(node_name)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("/intro/out", 10);
    //发布器：/intro/out，队列长度10

    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "/intro/in",10,bind(&IntroNode::topicCallBack, this, std::placeholders::_1));
    //订阅器：/intro/in，队列长度10，回调函数绑定：topicCallBack，_1是占位符，用于接收消息。
    //指针绑定出来的对象变成一个“不需要参数就能调用”的东西，但订阅器要求回调能接收一条消息，于是对不上。
    //所以需要使用占位符_1，将消息作为参数传递给回调函数。

    timer_ = this->create_wall_timer(
        1s, bind(&IntroNode::timerCallBack, this));
    //定时器：1s，回调函数绑定：timerCallBack

    RCLCPP_INFO(this->get_logger(), "IntroNode %s created", node_name.c_str());
}
void IntroNode::timerCallBack()
{
    std_msgs::msg::String msg;
    msg.data = student_id_ + " | seq = " + std::to_string(seq_);
    ++seq_;
    publisher_->publish(msg);
}
void IntroNode::topicCallBack(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
}


