#ifndef STORE_H
#define STORE_H

#include "Employee.h"
#include "Manager.h"
#include "Cashier.h"

#include <iostream>
#include <string>
#include<vector>

using namespace std;


class Store {
private:
    vector<Cashier> cashiers;
    vector<Manager> managers;

public:
    void hireCashier(Cashier c);
    void hireManager(Manager m);
    int cashierCount();
    int managerCount();
    double totalPayroll();
    Cashier topCashier();
    vector<Manager> promotionEligible();
    bool promoteToManager(int employeeID, int teamSize);
    string generateReport();
};



#endif