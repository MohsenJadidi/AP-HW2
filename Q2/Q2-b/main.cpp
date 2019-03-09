#include<iostream>
#include<ctime>
#include<iomanip>
#include"libVec.h"
#include"libArr.h"

template<typename T>
void runTime(T, int);

int main()
{
    float n{1e6};           // Maximum iteration for loop

    libArr arrobj;
    libVec vecobj;
     
    std::cout << "** Array **\n";
    std::cout <<"  n\t\tsum\t    runtime\n";
    std::cout << std::setw(40) << std::setfill('-') << '\n' << std::setfill(' ');
    for(int i = 1; i <= n; i *= 10)
    {
        runTime(arrobj,i);
    }
    
    std::cout << "\n** Vector **\n";
    std::cout <<"  n\t\tsum\t    runtime\n";
    std::cout << std::setw(40) << std::setfill('-') << '\n' << std::setfill(' ');
    for(int i = 1; i <= n; i *= 10)
    {
        runTime(vecobj,i);
    }

    return 0;
}

template<typename T>
void runTime(T obj,int n)
{
    double sum{};
    std::cout << std::setw(7) << n;
    clock_t t = clock();
    sum = obj.counter(n) ;
    t = clock() - t;
    std::cout << std::setw(15) << std::fixed <<std::setprecision(0) 
              << sum << "\t" << std::setw(10)<< std::fixed << std::setprecision(6) 
              << (static_cast<double>(t)/CLOCKS_PER_SEC) * 1000 << " msec\n";
}