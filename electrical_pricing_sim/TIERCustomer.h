//Cutoff for the tiered pricing structure (1000kwh/month)
#define KWHCAP 1000

#include "Reading.h"
#include "Customer.h"
#include <list>


#ifndef ELECTRICALPRICESIM_TIERCUSTOMER_H
#define ELECTRICALPRICESIM_TIERCUSTOMER_H


using namespace std;


class TIERCustomer : public Customer {
public:
    float computeBalance(list<Reading>& li);
};


#endif //ELECTRICALPRICESIM_TIERCUSTOMER_H
