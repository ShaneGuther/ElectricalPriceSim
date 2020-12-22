
#include "Customer.h"
#include "Reading.h"
Customer::Customer() = default;

Customer::Customer(int m, int tk){
    meterNum = m;
    totalKwh = tk;
}
//getter and setter for the balance
void Customer::setBalance(float b){
    balance = b;
};

float Customer::getBalance(){
    return balance;
};

//used to set the reading variable after object creation
void Customer::setReadings(list<Reading>& li){
    elecUsage = li;
}
list<Reading> Customer::getReading(){
    return elecUsage;
}

//abstract function to be implemented by inherited classes
//virtual float Customer::computeBalance(list<Reading>&) = 0;

//generates a reading for each customer
list<Reading> Customer::addReading(){
    srand(time(NULL));
    //for loop for 720 hours (30 days, 24h a day)
    for(int i = 1; i <= 720; i++){
        float kwh = (float)0.05 + (float)(rand()) / (float)(RAND_MAX/(2.0 - 0.05));
        Reading hourlyReading(kwh, i);
        elecUsage.push_back(hourlyReading);
    }
    return elecUsage;
}
