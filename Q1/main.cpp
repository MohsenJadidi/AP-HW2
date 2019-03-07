/*
*	AP2018 : HW2 - Question 1
*	Mohammad Mohsen Jadidi 9423029 @AUT
*/

#include<iostream>
#include"map.h"

int main()
{   
    /* Section A */
    int dim{};         // Dimension of map
    std::cout << "##### Section A #####\n\n";
    std::cout << "Enter dimensions of map : ";
    std::cin >> dim;
    Map map{dim};     // Creat Map object
    map.showMap();
    std::string p{map.findRoute()};
    map.showRoute();
    
    /* Section B */
    std::cout << "\n###### Section B #####\n\n";
    p = map.findRouteDiag();
    map.showRoute();

    /* Section C */
    std::cout << "\n##### Section C #####\n\n";
    map.minRoute();
    map.showRoute();

    return 0;
}