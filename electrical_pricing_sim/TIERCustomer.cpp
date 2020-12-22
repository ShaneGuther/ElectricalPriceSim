//
// Created by Shane Guther on 2020-12-22.
//

#include "TIERCustomer.h"

float computeBalance(list<Reading>& li){
    float balance = 0;
    std::list<Reading>::iterator it;
    for(it = li.begin(); it != li.end(); it++){
        if(balance < kwhCap) {
            balance += float(it->getKwh() * 12.6);
        }else if(balance >= kwhCap){
            balance += float(it->getKwh() * 14.6);
        }
    }
    return balance;
}