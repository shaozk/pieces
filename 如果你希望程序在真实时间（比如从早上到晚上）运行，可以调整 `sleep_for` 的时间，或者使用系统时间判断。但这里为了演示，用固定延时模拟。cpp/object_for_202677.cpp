#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <random>

// 模拟一个陪伴对象
class Companion {
public:
    Companion(const std::string& name) : name_(name) {}

    // 约会
    void date() {
        std::cout << "[" << name_ << "] 我们一起去浪漫的餐厅约会吧！\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "[" << name_ << "] 今天的晚餐真美味，和你在一起很开心。\n";
    }

    // 逛街
    void shopping() {
        std::cout << "[" << name_ << "] 我们去商场逛逛吧，看看有什么新衣服。\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "[" << name_ << "] 这件裙子很适合你，我们买下来吧！\n";
    }

    // 对话
    void chat() {
        std::cout << "[" << name_ << "] 今天过得怎么样？有什么想和我分享的吗？\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "[" << name_ << "] 我也有好多话想对你说，你是我最重要的人。\n";
    }

    // 睡觉
    void sleep() {
        std::cout << "[" << name_ << "] 夜深了，我们该休息了。晚安，亲爱的。\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "[" << name_ << "] 明天见，我会一直陪着你。\n";
    }

    // 启动一天的陪伴流程
    void runDay() {
        std::cout << "===== 2026年7月初7 情人节 =====" << std::endl;
        std::cout << "[" << name_ << "] 今天是我们特别的日子，我会一直陪着你。\n";

        // 按顺序执行四个活动
        date();
        shopping();
        chat();
        sleep();

        std::cout << "[" << name_ << "] 今天结束了，感谢你陪我度过这一天。\n";
        std::cout << "===== 程序自动停止 =====" << std::endl;
    }

private:
    std::string name_;
};

int main() {
    // 创建一个陪伴对象，名字可以自定义
    Companion companion("小爱");
    companion.runDay();
    return 0;
}
