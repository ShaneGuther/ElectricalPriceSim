
#include "Reading.h"

Reading::Reading(float k, int t){
    kwh = k;
    timeHours = t;
}
void Reading::setKwh(float k){
    kwh = k;
}
float Reading::getKwh(){
    return kwh;
}