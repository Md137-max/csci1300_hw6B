
#include "Store.h"

using namespace std;

void Store::hireCashier(Cashier c) {
    cashiers.push_back(c); 
}

void Store::hireManager(Manager m) {
    managers.push_back(m);
}

int Store::cashierCount() {
    return cashiers.size();
}

int Store::managerCount() {
    return managers.size();
}

double Store::totalPayroll() {
    double sum = 0.0;

    for (size_t i = 0; i < cashiers.size(); i++) {
        sum += cashiers[i].calculatePay();
    }
    for (size_t i = 0; i < managers.size(); i++) {
        sum += managers[i].calculatePay();
    }
    return sum;
}

Cashier Store::topCashier() {
   
    if (cashiers.size() == 0) {
        return Cashier("None", 0.0);
    }
    int TopCash = 0;
    for (size_t i = 0; i < cashiers.size(); i++) {
        
        if (cashiers[i].performanceScore() > cashiers[TopCash].performanceScore()) {
            TopCash = i;
        }
        else if (cashiers[i].performanceScore() == cashiers[TopCash].performanceScore()) {
           
            if (cashiers[i].getID() < cashiers[TopCash].getID()) {
                    TopCash = i;
                }
    
            }
        }
        return cashiers[TopCash];
        }
    
     


vector<Manager> Store::promotionEligible() {
    vector<Manager> eligible;
    for (size_t i = 0; i < managers.size(); i++) {
        if (managers[i].qualifiesForPromotion() == true) {
            eligible.push_back(managers[i]);
        }
    }
    return eligible;
}

bool Store::promoteToManager(int employeeID, int teamSize) {
    for (size_t i = 0; i < cashiers.size(); i++) {
        
        if (cashiers[i].getID() == employeeID) {
            string name = cashiers[i].getName();
            double wage = cashiers[i].getHourlyWage();
            int hours = cashiers[i].getHoursWorked();           
           
            Manager promoted(name, wage, teamSize); {
                if (teamSize < 0) {
                    teamSize = 0;
                }
            }
            promoted.logHours(hours);
            managers.push_back(promoted);

            vector<Cashier> updatedCashiers;
            for (size_t j = 0; j < cashiers.size(); j++) {
                if (j != i) {
                    updatedCashiers.push_back(cashiers[j]);
                }
            }
            cashiers = updatedCashiers;
            return true;
        }
    }
            return false;
        }
    


string Store::generateReport() {
    string report = "";
    report += "=== JojaMart Weekly Report ===\n";
    report += "Total Employees: " + to_string(cashierCount() + managerCount()) + "\n";
     string payroll = to_string(totalPayroll());
    payroll = payroll.substr(0, payroll.find('.') + 3);

    report += "Total Payroll: $" + payroll + "\n";

    Cashier best = topCashier();

    string score = to_string(best.performanceScore());
    score = score.substr(0, score.find('.') + 3);

    report += "Top Cashier: " + best.getName() +
              " (" + score + " items/hr)\n";

    report += "Promotion Eligible Managers: ";

    vector<Manager> eligible = promotionEligible();

    if (eligible.size() == 0) {
        report += "None";
    }
    else {
        for (size_t i = 0; i < eligible.size(); i++) {
            report += eligible[i].getName();

            if (i < eligible.size() - 1) {
                report += ", ";
            }
        }
    }

    return report;
}
