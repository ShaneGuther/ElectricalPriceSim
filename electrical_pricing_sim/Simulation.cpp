
#include "Simulation.h"
#include "Customer.h"
#include "TIERCustomer.h"
#include "TOUCustomer.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void Simulation::printResult(){
    vector<TOUCustomer> touVect;
    vector<TIERCustomer> tierVect;
    cout << "Simulation run : " << endl;
    cout << "Number of customers in each group :       1000" << endl;
    cout << endl << endl;

    //total electrical usage to be divided by 100 for average usage
    float touUsage;
    float tierUsage;

    //total balances to be divided by 1000 for average balance
    float touBalances = 0;
    float tierBalances = 0;

    float smallBalanceTOU = 0;
    float largeBalanceTOU = 0;

    float smallBalanceTier = 0;
    float largeBalanceTier = 0;


    for(int i = 0; i < 2000; i++){
        //generate random 6 digit meter number
        long meterNum = rand() % 899998 + 100000;

        if(i < 1000) {
            TOUCustomer *newTou = new TOUCustomer;
            list<Reading> tempList = newTou->addReading();
            list<Reading>::iterator tempIt;
            tempIt = tempList.begin();
            for(; tempIt != tempList.end(); tempIt++){
                touUsage += tempIt->getKwh();
            }
            newTou->setReadings(tempList);
            newTou->setBalance(newTou->computeBalance(tempList));
            touVect.push_back(*newTou);
        }else{
            TIERCustomer *newTier = new TIERCustomer;
            list<Reading> tempList = newTier->addReading();
            list<Reading>::iterator tempIt;
            tempIt = tempList.begin();
            for(; tempIt != tempList.end(); tempIt++){
                tierUsage += tempIt->getKwh();
            }
            newTier->setReadings(tempList);
            newTier->setBalance(newTier->computeBalance(tempList));
            tierVect.push_back(*newTier);
        }
    }

    int i = 0;
    int maxIndexTOU = 0;
    int minIndexTOU = 0;

    int maxIndexTier = 0;
    int minIndexTier = 0;


    vector<TOUCustomer>::iterator it;
    it = touVect.begin();
    largeBalanceTOU = (*it).getBalance();
    smallBalanceTOU = (*it).getBalance();

    //TOU calculations
    for(; it != touVect.end(); it++){
        touBalances += (*it).getBalance();
        if((*it).getBalance() > largeBalanceTOU){
            maxIndexTOU = i;
        }
        if((*it).getBalance() < smallBalanceTOU){
            minIndexTOU = i;
        }
        i++;
    }


    i = 0;
    vector<TIERCustomer>::iterator itt;
    itt = tierVect.begin();
    largeBalanceTier = (*itt).getBalance();
    smallBalanceTier = (*itt).getBalance();


    //TIER calculations using vector
    for(; itt != tierVect.end(); itt++){
        tierBalances += (*itt).getBalance();
        if((*itt).getBalance() > largeBalanceTier){
            maxIndexTier = i;
        }
        if((*itt).getBalance() < smallBalanceTier){
            minIndexTier = i;
        }
        i++;
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    // TOU Customer simulation
    cout << "TOU Customers: " << endl;
    cout << "Average electric consumption: " << (touUsage/1000) << " kWh " << endl;
    cout << "Average balance/per customer: $" << ((touBalances / 1000) * .01)  << endl;
    cout << "Largest Balance: $" << (touVect[maxIndexTOU].getBalance() * .01) << endl;
    cout << "Smallest Balance: $" << (touVect[minIndexTOU].getBalance() * .01) << endl;

    cout << endl << endl;

    //TIER customer simulation
    cout << "TIER Customers: " << endl;
    cout << "Average electric consumption: " << (tierUsage/1000) << " kWh " << endl;
    cout << "Average balance/per customer: $" << ((tierBalances / 1000) * .01)  << endl;
    cout << "Largest Balance: $" << (tierVect[maxIndexTier].getBalance() * .01) << endl;
    cout << "Smallest Balance: $" << (tierVect[minIndexTier].getBalance() * .01) << endl;
}