
#include "TIERCustomer.h"
#include "Reading.h"

float TIERCustomer::computeBalance(list<Reading>& li){
    float balance = 0;
    std::list<Reading>::iterator it;
    for(it = li.begin(); it != li.end(); it++){
        if(balance < float(KWHCAP)) {
            balance += float(it->getKwh() * 12.6);
        }else if(balance >= float(KWHCAP)){
            balance += float(it->getKwh() * 14.6);
        }
    }
    return balance;
}