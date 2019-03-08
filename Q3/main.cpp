/*
*	AP2018 : HW2 - Question 3
*	Mohammad Mohsen Jadidi 9423029 @AUT
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"order.h"

std::vector<std::string> unique(std::vector<std::string>);
std::vector<int> unique(std::vector<int>);

int main()
{
    std::vector<Order> order;       // Order object for store initial list of orders 
    std::string date{};             // string for store %day %time
    std::string temp{};             // temporory string for read undesired character from file
    int product{}, costumer{};      // These variable store  %product_id %customer_id

    /* Read file */
    std::ifstream in{"db.txt"};
	while (!in.eof())
	{
        std::getline(in, temp, '[');
        std::getline(in, date, ' ');
        std::getline(in, temp, ' ');
		in >> product;
        in >> costumer;
        Order object{date, product, costumer};
        order.push_back(object);        // Fill the order vector
	}
    in.close();

    std::vector<std::string> date_vec;  // vector of date
    /* initialize date_vec */
    for(size_t i = 0; i < order.size(); i++)
    {
        date_vec.push_back(order[i].date);
    }

    /* Remove duplicates */
    date_vec = unique(date_vec);

    /* Calculate count of products and count of costumers */
    for(size_t i = 0; i < date_vec.size(); i++)
    {  
        int product_count{},costumer_count{};       /* Count of products and  ...
                                                       Count of costumers at one date */
        std::vector<int> product_vec,costumer_vec;  /* Vector of products and  ...
                                                       Vector of costumers at one date */

        for(size_t j = 0; j < order.size(); j++)
        {
            if(!order[j].date.compare(date_vec[i]))
            {
                product_vec.push_back(order[j].product_id);
                costumer_vec.push_back(order[j].customer_id);
            }                  
        }
        product_count = (unique(product_vec)).size();   // Remove duplicates from product_vec
        costumer_count = (unique(costumer_vec)).size(); // Remove duplicates from costumer_vec

        /* Write in console*/
        std::cout << date_vec[i] << " ";
        std::cout << product_count << " " << costumer_count << std::endl;

        /* Write in dbnew.txt file*/
        std::ofstream of{};
		of.open("dbnew.txt", std::ofstream::app);
        of << date_vec[i] << " ";
        of << product_count << " " << costumer_count << std::endl;
		of.close();
    }
    
    return 0;
}

/* Remove duplicates of any element and return unique vector of string */
std::vector<std::string> unique(std::vector<std::string> date)
{
    std::vector<std::string> unique_vec; // Vector of unique elements
    unique_vec.push_back(date[0]);

    for(size_t i = 1; i < date.size(); i++)
    {
        bool flag{false};
        std::string temp{date[i]};
        for(size_t j = 0; j < unique_vec.size(); j++)
        {
            if(!temp.compare(unique_vec[j]))    // Element is duplicate?
                flag = true;            
        }
        if(flag == false)   // This is false if element isn't duplicate
        {
                unique_vec.push_back(temp);
        }     
    }

    return unique_vec;
}

/* Remove duplicates of any element and return unique vector of int */
std::vector<int> unique(std::vector<int> vec)
{
    std::vector<int> unique_vec;    // Vector of unique elements
    unique_vec.push_back(vec[0]);

    for(size_t i = 1; i < vec.size(); i++)
    {
        bool flag{false};
        int temp{vec[i]};
        for(size_t j = 0; j < unique_vec.size(); j++)
        {
            if(temp == unique_vec[j])       // Element is duplicate?
                flag = true;            
        }
        if(flag == false)       // This is false if element isn't duplicate
        {
                unique_vec.push_back(temp);
        }     
    }

    return unique_vec;
}