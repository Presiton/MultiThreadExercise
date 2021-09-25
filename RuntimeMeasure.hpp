//
// Created by INTEL on 2021/9/25.
//

#ifndef MUTEXEXERCISE_RUNTIMEMEASURE_HPP
#define MUTEXEXERCISE_RUNTIMEMEASURE_HPP

template<class T>
void TimeMeasure(T&& func);


template<class T>
void TimeMeasure(T&& func)
{
    auto start = std::chrono::system_clock::now();
    func();
    std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
    std::cout << "elapsed: " << diff.count() << " seconds" << std::endl;
}

//function object ·Âº¯Êý
//struct A
//{
//    void operator()(std::string &s)
//    {
//        std::cout << s << std::endl;
//    }
//};

#endif //MUTEXEXERCISE_RUNTIMEMEASURE_HPP
