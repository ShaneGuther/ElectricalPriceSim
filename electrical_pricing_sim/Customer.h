
#include "Reading.h"
#include <iostream>
#include <list>

#ifndef ELECTRICALPRICESIM_CUSTOMER_H
#define ELECTRICALPRICESIM_CUSTOMER_H

using namespace std;

class Customer {
private:
    int meterNum;
    list<Reading> elecUsage;
    float totalKwh;
    float balance;
public:
    Customer();
    Customer(int m, int tk);

    //getter and setter for the balance
    void setBalance(float b);
    float getBalance();

    //used to set the reading variable after object creation
    void setReadings(list<Reading>& li);
    list<Reading> getReading();

    virtual float computeBalance(list<Reading>&) = 0;
    list<Reading> addReading();

};


#endif //ELECTRICALPRICESIM_CUSTOMER_H
