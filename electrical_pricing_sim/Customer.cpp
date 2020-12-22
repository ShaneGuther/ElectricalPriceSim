//
// Created by Shane Guther on 2020-12-21.
//

#include "Customer.h"
Customer() = default;

Customer(int m, int tk){
    meterNum = m;
    totalKwh = tk;
}
//getter and setter for the balance
void setBalance(float b){
    balance = b;
};

float getBalance(){
    return balance;
};

//used to set the reading variable after object creation
void setReadings(list<Reading>& li){
    elecUsage = li;
}
list<Reading> getReading(){
    return elecUsage;
}

//abstract function to be implemented by inherited classes
virtual float computeBalance(list<Reading>&) = 0;

//generates a reading for each customer
list<Reading> addReading(){
    srand(time(NULL));
    //for loop for 720 hours (30 days, 24h a day)
    for(int i = 1; i <= 720; i++){
        float kwh = (float)0.05 + (float)(rand()) / (float)(RAND_MAX/(2.0 - 0.05));
        Reading hourlyReading(kwh, i);
        elecUsage.push_back(hourlyReading);
    }
    return elecUsage;
}
