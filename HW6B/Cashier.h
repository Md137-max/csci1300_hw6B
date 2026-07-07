#ifndef CASHIER_H
#define CASHIER_H

#include "Employee.h"

#include <iostream>
#include <string>

using namespace std;

class Cashier : public Employee {
private:
    int itemsScanned;
    double tipsCollected;

public:
    Cashier(string name, double hourlyWage);
    bool logShift(int items);
    bool addTips(double amount);
    double calculatePay();
    double performanceScore();
};




#endif