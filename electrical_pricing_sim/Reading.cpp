//
// Created by Shane Guther on 2020-12-22.
//

#include "Reading.h"

Reading(float k, int t){
    kwh = k;
    timeHours = t;
}
void setKwh(float k){
    kwh = k;
}
float getKwh(){
    return kwh;
}