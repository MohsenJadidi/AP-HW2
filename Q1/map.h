#ifndef MAP_H
#define MAP_H

#include<vector>
#include<string>
#include<limits.h>

class Map
{
private:
    std::vector< std::vector<int> > map;// 2D Vector for store height of map
    int N;                              // Map size
    std::string route{" "};             // String for movement path
    std::vector<std::string> all_route; // All possible routes  
    int min_height{INT_MAX};            // Minimum height difference between all possible movement
    std::string min_route{};            // Route of min_height
                                        // r:right, d:down, o:oblique(diagonal)
    int heightRoute(std::string&);       // Calculate hight difference based on input string
    void permute(std::string, std::string); /* Rearranges the elements in the input string ...
                                               if input='ABC' ... permute function creat ...
                                               'ABC' 'ACB' 'BCA' 'BAC' 'CAB' 'CBA' */
    std::vector<std::string> unique(const std::vector<std::string>&); // Remove duplicates string from vector

  
public:
    Map (int n);                // Constructor
    void showMap();             // Display map
    std::string findRoute();    // Find Route with right & down movement
    std::string findRouteDiag();// Find Route with right, down movement & oblique(diagonal) movement
    void showRoute();           // Display Route in map that store in route(private member of class)
    void minRoute();            // Finds the shortest route in map



};

#endif