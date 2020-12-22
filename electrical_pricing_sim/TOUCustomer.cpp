
#include "Reading.h"
#include "TOUCustomer.h"
float TOUCustomer::computeBalance(list<Reading>& li){
    float balance = 0;
    std::list<Reading>::iterator it;
    int j = 1;
    for(it = li.begin(); it != li.end(); ++it){
        //variable i creates segments for each day to make it easier to handle the data
        int i = 0;
        //j % 24 will result in 0
        if(j == 24) {
            i = 1;
        }else {
            i = j % 24;
        }

        // a series of if statements to handle the time of use prices when generating the balance.
        if(i == 1) {
            int counter = 0;
            while(counter < 7) {
                balance += float(it->getKwh() * 10.5);
                counter++;
            }
        }else if(i == 7){
            int counter = 0;
            while(counter < 11){
                balance += float(it->getKwh() * 21.7);
                counter++;
            }
        }else if(i == 11){
            int counter = 0;
            while(counter < 17){
                balance += float(it->getKwh() * 15.0);
                counter++;
            }
        }else if(i == 17){
            int counter = 0;
            while(counter < 19){
                balance += float(it->getKwh() * 21.7);
                counter++;
            }
        }else if(i == 19){
            int counter = 0;
            while(counter < 25){
                balance += float(it->getKwh() * 10.5);
                counter++;
            }
        }
        j++;
    }
    return balance;
}