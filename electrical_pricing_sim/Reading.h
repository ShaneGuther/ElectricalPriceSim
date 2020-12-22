//
// Created by Shane Guther on 2020-12-22.
//

#ifndef ELECTRICALPRICESIM_READING_H
#define ELECTRICALPRICESIM_READING_H


class Reading {
private:
    float kwh;
    //time considered to be in 24h time ie 0-23;
    int timeHours;
public:
    Reading(float k, int t){ }
    void setKwh(float k){ }
    float getKwh(){ }

};


#endif //ELECTRICALPRICESIM_READING_H
