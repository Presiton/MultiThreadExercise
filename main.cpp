#include <iostream>
#include <mutex>
#include <thread>
#include <functional>
#include <string>
#include <chrono>
#include "RuntimeMeasure.hpp"

//function object 仿函数
struct A
{
    void operator()(std::string &s)
    {
        std::cout << s << std::endl;
    }
};

void threadtest()
{
    std::string a = "furyhorn";
    std::thread f1 = std::thread([&a]()
                                 {
                                     long long sum = 0;
                                     for (int i = 0; i < 100000000; ++i)
                                     {
                                         sum += i;
                                     }
                                     std::cout << a << std::endl;
                                     std::cout << sum << std::endl;
                                 });
    f1.join();
}

int main()
{
    std::string a = "abc";
    std::thread t1 = std::thread(A(), std::ref(a));
    t1.join();
    auto f = [&a](int c, int d)//lambda表达式 匿名函数
    {
        std::cout << a << std::endl;
        std::cout << c + d << std::endl;
    };
    f(1, 2);

    TimeMeasure([]()
                {
                    threadtest();
                });
    return 0;
}
