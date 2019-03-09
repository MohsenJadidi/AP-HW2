#include"libArr.h"

double libArr::counter(int n)
{
    double arr[n]{};
    for(int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    double sum{};
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    return sum; 
}
