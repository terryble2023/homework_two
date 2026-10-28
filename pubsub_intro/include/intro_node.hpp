#ifndef PUBSUB_INFO_INTRO_NODE_HPP
#define PUBSUB_INFO_INTRO_NODE_HPP

#include <iostream>
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;


class IntroNode : public rclcpp::Node
{
    public:
        explicit IntroNode(const std::string & node_name = "intro_node");
        //explicit: 显式构造函数，防止自动隐式转换
        //默认节点是"intro_node"，对应了/intro_node
    private:
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
        rclcpp::TimerBase::SharedPtr timer_;

        void timerCallBack();
        void topicCallBack(const std_msgs::msg::String::SharedPtr msg);
        const std::string student_id_ = "011125321";
        int seq_ = 0;
};


#endif