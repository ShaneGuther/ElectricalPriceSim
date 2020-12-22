//
// Created by Shane Guther on 2020-12-22.
//
#include "Reading.h"
#ifndef ELECTRICALPRICESIM_TIERCUSTOMER_H
#define ELECTRICALPRICESIM_TIERCUSTOMER_H


class TIERCustomer : Customer {
private:
    //Cutoff for the tiered pricing structure (1000kwh/month)
    double const kwhCap = 1000;
public:
    float computeBalance(list<Reading>& li){ }
};


#endif //ELECTRICALPRICESIM_TIERCUSTOMER_H
