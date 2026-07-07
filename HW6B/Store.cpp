#include "Manager.h"
#include "Cashier.h"
#include "Employee.h"
#include "Store.h"

using namespace std;

void Store::hireCashier(Cashier c) {
    cashiers.push_back(c) 
}

void Store::hireManager(Manager m) {
    managers.push_back(m)
}

int Store::cashierCount() {
    return cashiers.size();
}

int Store::managerCount() {
    return managers.size();
}

double Store::totalPayroll() {
    return (Cashier::calculatePay() + Manager::calculatePay());
}

Cashier Store::topCashier() {
   
    if (cashiers.size() == 0) {
        return Cashier("None", 0.0);
    }
    for (int i = 0; i < cashiers.size(); i++) {
        int TopCash = 0;
        if (cashiers[i].performanceScore() > cashiers[0].performanceScore()) {
            TopCash = i;
            return cashiers[i];
        }
        if (i == 0) {
            for (int j = 0; j < cashiers.size(); j++) {
                int oldest = 0;
                if (cashiers[i].getID() < cashiers[0].getID()) {
                    oldest = i;
                }
                return cashiers[i];
            }
        }
    }
    
}

vector<Manager> Store::promotionEligible() {
    for (int i = 0; i < managers.size(); i++) {
        if (managers[i].qualifiesForPromotion() == true) {
            promotionEligible.push_back(i);
        }
    }
}

bool Store::promoteToManager(int employeeID, int teamSize) {
    for (int i = 0; i < managers.size(); i++) {
        int NewManager;
        if (managers[i].getID() == managers[i].employeeID()) {
            NewManager = i;
            return managers[NewManager];
        }
        else {
            return false;
        }
    }
}