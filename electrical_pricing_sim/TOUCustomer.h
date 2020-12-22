
#include "Reading.h"
#include "Customer.h"
#include <list>

#ifndef ELECTRICALPRICESIM_TOUCUSTOMER_H
#define ELECTRICALPRICESIM_TOUCUSTOMER_H


class TOUCustomer : public Customer{
public:
    float computeBalance(list<Reading>& li);
};


#endif //ELECTRICALPRICESIM_TOUCUSTOMER_H
