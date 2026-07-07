#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>

using namespace std;

class Manager : public Employee {
private:
    double bonus;
    int teamSize;

public:
    Manager(string name, double hourlyWage, int teamSize);
    bool awardBonus(double amount);
    double calculatePay();
    bool qualifiesForPromotion();
    int getTeamSize();
};




#endif