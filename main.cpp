#include <iostream>
#include <thread>
#include "RuntimeMeasure.hpp"

void sumlong(size_t start, size_t end, size_t &ans)
{
    size_t s1 = 0;
    for (long i = start; i < end; ++i)
    {
        s1 += i;
    }
    ans = s1;
}
const size_t  s = 1000000000;
int main()
{
    TimeMeasure([]()
                {
                    size_t  ans1, ans2;
                    std::thread t1(sumlong, 1, s / 2, std::ref(ans1));
                    std::thread t2(sumlong, s / 2, s, std::ref(ans2));
                    t1.join();
                    t2.join();
                    std::cout << (ans1 + ans2) << std::endl;
                });

    TimeMeasure([]()
                {
                    size_t ans3;
                    sumlong(0, s, std::ref(ans3));
                    std::cout << "1 threads: " << ans3 << std::endl;
                });
    std::cout<<sizeof(size_t)<<std::endl;
    std::cout<<sizeof(long long)<<std::endl;
    return 0;
}
