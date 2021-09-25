#include <iostream>
#include <thread>
#include "RuntimeMeasure.hpp"

void sumlong(long start, long end, long &ans)
{
    long s = 0;
    for (long i = start; i < end; ++i)
    {
        s += i;
    }
    ans = s;
}

const long s = 1000000000;

int main()
{
    TimeMeasure([]()
                {
                    long ans1, ans2, ans3;
                    std::thread t1 = std::thread(sumlong, 0, s / 3, std::ref(ans1));
                    std::thread t2 = std::thread(sumlong, s / 3, (s * 2) / 3, std::ref(ans2));
                    std::thread t3 = std::thread(sumlong, (s*2)/3, s, std::ref(ans3));
                    t1.join();
                    t2.join();
                    t3.join();
                    std::cout << "3 threads: " << (ans1 + ans2 + ans3) << std::endl;
                });

    TimeMeasure([]()
                {
                    long ans4;
                    sumlong(0, s, std::ref(ans4));
                    std::cout << "1 threads: " << ans4 << std::endl;
                });
    return 0;
}
