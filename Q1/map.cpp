#include"map.h"
#include<iostream>
#include<iomanip>
#include<cmath>

/* Constructor */
Map::Map(int n)
{
    N = n;                  // Map size
 
    //srand((unsigned)time(NULL));
    int rnd_num{};          // Varible for random number
    int max_rnd_num{100};   // Maximum value of rnd_num

    /* Creat random map(n*n) */
    size_t count{static_cast<size_t> (n)};
    for(size_t i = 0; i < count; i++)
    {
        map.push_back(std::vector<int>());
        for(size_t j = 0; j < count; j++)
        {
            rnd_num = std::rand() % max_rnd_num;   
            map[i].push_back(rnd_num);  
        }
    }

    /* Display Map */
    std::cout << "This Map created : \n";
    for(size_t i = 0; i < count; i++)
    {
        for(size_t j = 0; j < count; j++)
        {
            std::cout << std::setw(2) <<map[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
    std::cout << std::setw(3*count) << std::setfill('-') << "-\n" << std::setfill(' ');
    
}

/* Display map */
void Map::showMap()
{
    size_t count = static_cast<size_t> (N);     // Size of map   
    std::cout << "Current map is : \n";
    for(size_t i = 0; i < count; i++)
    {
        for(size_t j = 0; j < count; j++)
        {
            std::cout << std::setw(2) << map[i][j] << " " ;
        }
        std::cout << std::endl;
        
    }
    std::cout << std::setw(3*count) << std::setfill('-') << "-\n";
}

/* Find Route with right & down movement */
std::string Map::findRoute()
{
    std::string path{""};               // Current passed movement
    size_t path_length{static_cast<size_t>( 2*(N-1) )};// length of route from origin to destination
    size_t current_x{}, current_y{};    // Current location in map
    int right_num{}, down_num{};        // Number of right(left) movement
    int right_height{}, down_height{};  // Value of diffirence height(for adjacent)
    unsigned int height_diff{};         // Value of diffirence height(for total path)

    std::cout << "*** Find Route ***\n";
    std::cout << "Move    direction    passed heights\n";
    for(size_t i{}; i < path_length; i++)
    {
        if(right_num < N-1 && down_num < N-1)   // True when we don't touching the wall
        {        
            right_height = std::abs( map[current_x][current_y] - map[current_x][current_y+1] );
            down_height = std::abs( map[current_x][current_y] - map[current_x+1][current_y] );         

            if(right_height <= down_height) 
            {
                current_y++;
                right_num++;
                path += "r";

                height_diff += right_height;
            }
            else
            {
                current_x++;
                down_num++;
                path += "d";

                height_diff += down_height;
            }
        }
        else if(right_num == N-1)   // Touching the right wall
        {
            down_height = std::abs( map[current_x][current_y] - map[current_x+1][current_y] );
            height_diff += down_height;

            current_x++;
            down_num++;
            path += "d";
        }
        else if(down_num == N-1)    // Touching the down wall
        {
            right_height = std::abs( map[current_x][current_y] - map[current_x][current_y+1] );
            height_diff += right_height;

            current_y++;
            right_num++;
            path += "r";
            
        }
        std::cout << " "<< std::setw(2) << std::setfill('0') << i+1 << std::setfill(' ')  
                  << std::setw(10) << path[i] << std::setw(15) << height_diff <<std::endl;

    }
    //
    std::cout <<"Total path : " <<path << std::endl;   
    std::cout << "Total difference of heights passed : " << height_diff << std::endl;
    std::cout << std::setw(25) << std::setfill('-') << "-\n" << std::setfill(' ');

    route = path;
    return path;
}

/* // Display Route in map that store in route(private member of class) */
void Map::showRoute()
{   
    size_t current_x{}, current_y{};    // Current location in map
    size_t index_route{};               // Current index in route string

    if(!route.compare(" ")) // First, we must calling the  findRoute() function
    {
        std::cout << "Calling findRoute() First ... ";
        std::string route{findRoute()};
    }
    std::string current_direction{route[index_route++]};
    
    std::cout << "Route in map : \n";
    size_t count = static_cast<size_t> (N); 
    for(size_t i = 0; i < count; i++)
    {
        for(size_t j = 0; j < count; j++)
        {
            if( i == 0 && j ==0)    // origin(0,0) location 
            {
                std::cout << std::setw(2) << "x" << " " ;
                continue;
            }
            // Right movement
            if(i == current_x && j == (current_y + 1) && ( !current_direction.compare("r") ))
            {
                std::cout << std::setw(2) << "x" << " " ;
                current_y++;
                current_direction = route[index_route++];
            }
            // Down movment
            else if(i == (current_x + 1) && j == current_y && ( !current_direction.compare("d") ))
            {
                std::cout << std::setw(2) << "x" << " " ;
                current_x++;
                current_direction = route[index_route++];
            }
            // Oblique(diagonal) movement
            else if(i == (current_x + 1) && j == (current_y + 1) && ( !current_direction.compare("o") ))
            {
                std::cout << std::setw(2) << "x" << " " ;
                current_x++;
                current_y++;
                current_direction = route[index_route++];
            }
            else
            {
                std::cout << std::setw(2) << "." << " " ;
            }
            
        }
        std::cout << std::endl;
        
    }
    std::cout << std::setw(3*count) << std::setfill('-') << "-\n" << std::setfill(' ');    
}

/* Find Route with right, down movement & oblique(diagonal) movement */
std::string Map::findRouteDiag()
{
    std::string path{""};                       // Current passed movement
    size_t max_index{static_cast<size_t> (N-1)};// length of route from origin to destination
    size_t current_x{}, current_y{};            // Current location in map
    int right_num{}, down_num{}, oblique_num{}; // Number of right(left,oblique) movement
    int right_height{}, down_height{},          // Value of diffirence height(for adjacent)
        oblique_height; 
    unsigned int height_diff{};                 // Value of diffirence height(for total path)
    
    std::cout << "*** Find Diag Route : ***\n";
    std::cout << "Move    direction    passed heights\n";
    size_t i{};     // iteration for while loop
    //for(size_t i{}; i < path_length; i++)
    while(current_x != max_index || current_y != max_index)  // While reach to destination
    {
        if(current_x <= max_index-1 && current_y <= max_index-1 )   //Still didn't reach to border of map
        {        
            right_height = std::abs( map[current_x][current_y] - map[current_x][current_y+1] );
            down_height = std::abs( map[current_x][current_y] - map[current_x+1][current_y] );
            oblique_height = std::abs( map[current_x][current_y] - map[current_x+1][current_y+1] );         

            // right height is minimum
            if(right_height <= down_height && right_height <= oblique_height) 
            {
                current_y++;
                right_num++;
                path += "r";

                height_diff += right_height;
            }
            // down height is minimum
            else if(down_height <= right_height && down_height <= oblique_height)
            {
                current_x++;
                down_num++;
                path += "d";

                height_diff += down_height;
            }
            // oblique height is minimum
            else
            {
                current_x++;
                current_y++;
                oblique_num++;
                path += "o";

                height_diff += oblique_height;
            }
            
        }
        else if(current_y == max_index) // Couldn't move right and oblique
        {
            down_height = std::abs( map[current_x][current_y] - map[current_x+1][current_y] );
            
                height_diff += down_height;

                current_x++;
                down_num++;
                path += "d";
            
        }
        else if(current_x == max_index) // Couldn't move down and oblique
        {
            right_height = std::abs( map[current_x][current_y] - map[current_x][current_y+1] );
            height_diff += right_height;

            current_y++;
            right_num++;
            path += "r";
            
        }
        std::cout << " "<< std::setw(2) << std::setfill('0') << i+1 << std::setfill(' ')  
                  << std::setw(10) << path[i] << std::setw(15) << height_diff <<std::endl;
        i++;
    }
    
    std::cout <<"Total path : " <<path << std::endl;   
    std::cout << "Total difference of heights passed : " << height_diff << std::endl;
    std::cout << std::setw(25) << std::setfill('-') << "-\n" << std::setfill(' ');

    route = path;
    return path;
}

/* Finds the shortest route in map */
void Map::minRoute()
{
    std::string str (N-1, 'r');     // string of 'r' and 'd' char
    str += std::string (N-1, 'd');
    permute("", str);               // Creat all permutation of str and calculate height
    all_route = unique(all_route);

    for(auto r : all_route)
    {
        int h = heightRoute(r);
        if( min_height > h )
        {
            min_height = h;
            min_route = r;
        }
    }

    std::cout << "*** Find Min Route *** \n";
    std::cout << "Min Route : " << min_route << " with height = " << min_height << std::endl;
    route = min_route;
}

/* Rearranges the elements in the input string if input='ABC' ... 
   permute function creat 'ABC' 'ACB' 'BCA' 'BAC' 'CAB' 'CBA' 
   and calculate height of every route and setting min_height and min_route */
void Map::permute(std::string str, std::string rest)
{
    std::string next_str{};
    std::string remaining_str{};

    if (rest == "") // Here Permutations are created (str string is Permutations)
    {
        //std::cout << str << std::endl;
        all_route.push_back(str);

    }
    else
    {
        for(size_t i = 0; i < rest.length(); i++)
        {
            next_str = str + rest[i];
            remaining_str = rest.substr(0, i) + rest.substr(i+1);
            permute(next_str, remaining_str);   // Recursive function
        }
        
    } 
}

/* Remove duplicates string from vector and return unique vector of string */
std::vector<std::string> Map::unique(const std::vector<std::string>& input)
{
    std::vector<std::string> unique_vec;
    unique_vec.push_back(input[0]);

    for(size_t i = 1; i < input.size(); i++)
    {
        bool flag{false};
        std::string temp{input[i]};
        for(size_t j = 0; j < unique_vec.size(); j++)
        {
            if(!temp.compare(unique_vec[j]))
                flag = true;            
        }
        if(flag == false)
        {
                unique_vec.push_back(temp);
        }     
    }

    return unique_vec;
}

/* Calculate hight difference based on input string */
int Map::heightRoute(std::string &path)
{

    size_t current_x{}, current_y{};// Current location in map
    int height_diff{};              // Value of diffirence height(for total path)

    int i{};    // iteration variable for loop
 
    while( i < 2*(N-1) )
    {
        if( path[i] == 'r') // Right movement
        {
            height_diff += std::abs( map[current_x][current_y] - map[current_x][current_y+1] );
            current_y++;
        }
        else // if(path[i] == 'd')  // Down movement
        {
            height_diff += std::abs( map[current_x][current_y] - map[current_x+1][current_y] );
            current_x++;
        }
        i++;      
    }    

    return height_diff;
}