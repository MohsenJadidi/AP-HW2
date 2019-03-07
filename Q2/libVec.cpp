#include"libVec.h"
#include<vector>

double libVec::counter(int n)
{
    std::vector<int> vec;
    for(int i = 0; i < n; i++)
    {
        vec.push_back(i);
    }

    double sum{};
    for(int i = 0; i < n; i++)
    {
        sum += vec[i];
    }
    
    return sum; 
}