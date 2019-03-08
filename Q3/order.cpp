#include"order.h"

/* Constructor */
Order::Order(std::string Date, int Product, int Customer)
{
    date = Date;
    product_id = Product;
    customer_id = Customer;
}
