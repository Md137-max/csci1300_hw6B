#include "Manager.h"
#include "Cashier.h"
#include "Employee.h"

using namespace std;

Manager::Manager(string n, double hW, int tS)
: Employee(n, hW) {

if (tS < 0) {
    teamSize = 0;
}
else {
    teamSize = tS;
}
    bonus = 0.0;

} 

bool Manager::awardBonus(double amount) {
    if (amount < 0) {
        return false;
    }
    else {
        bonus += amount;
        return true;
    }
}

double Manager::calculatePay() {
    return Employee::calculatePay() + bonus;
}

bool Manager::qualifiesForPromotion() {
    if (getHoursWorked() >= 160 && bonus > 0.0 && teamSize >= 2) {
        return true;
    }
        return false;
}

int Manager::getTeamSize() {
    return teamSize;
}