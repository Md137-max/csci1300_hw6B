#include "Cashier.h"
#include "Employee.h"

using namespace std;

Cashier::Cashier(string n, double hW) 
    : Employee(n, hW) {

    itemsScanned = 0;
    tipsCollected = 0.0;
}

bool Cashier::logShift(int items) {
    if (items < 0) {
        return false;
    }
    else {
        itemsScanned += items;
        return true;
    }

}
bool Cashier::addTips(double amount){
    if (amount < 0) {
        return false;
    }
    else {
        tipsCollected += amount;
        return true;
    }
}

double Cashier::calculatePay() {
   return Employee::calculatePay() + tipsCollected;
}

double Cashier::performanceScore() {
    if (getHoursWorked() == 0) {
        return 0.0;
    }
    else{ 
    return static_cast<double>(itemsScanned) / getHoursWorked();
    }

}