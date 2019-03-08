#ifndef ORDER_H
#define ORDER_H

#include<string>
#include<vector>

class Order
{
//private:
public:
    std::string date;           // store date in the form of %day %time
    int product_id, customer_id;// store %product_id and %customer_id

    Order(std::string Date, int Product, int Customer); // Constructor
};

#endif