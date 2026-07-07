#include <iostream>
#include <string>
#include <vector>

#include "Store.h"
#include "Cashier.h"
#include "Manager.h"
#include "ScheduleAudit.h"

using namespace std;

string promptString(string prompt) {
    cout << prompt << endl;
    string input;
    getline (cin, input);
    return input;
}
int promptInt(string prompt, int minVal, int maxVal) {
while(true) {
    string input = promptString(prompt);
    try {
        size_t position;
        int value = stoi(input, &position);
        if (value >= minVal && value <= maxVal && position == input.length()) {
            return value;
        }
    }
    catch(...) {
        
    }
}
}
double promptDouble(string prompt, double minVal, double maxVal) {
    while(true) {
        string input = promptString(prompt);
    try {
        size_t position;
        double value = stod(input, &position);
        if (value >= minVal && value <= maxVal && position == input.length()) {
            return value;
        }
    }
    catch(...) {
        
    }
    }
}

int main() {

 Store store;

vector<Cashier> storeCashiers;
vector<Manager> storeManagers;

int NumCashier = promptInt("How many cashiers?", 0, 100);
for (int i = 0; i < NumCashier; i++) {
    double wage = promptDouble("Hourly wage: ", 0, 1000);
    string name = promptString("Name: ");

Cashier example(name, wage);
int hours = promptInt("Hours worked: ", 0, 999);
example.logHours(hours);
int items = promptInt("Items scanned: ", 0, 1000);
example.logShift(items);
double tips = promptDouble("Tips collected: ", 0, 100000);
example.addTips(tips);
store.hireCashier(example);
}

int NumManager = promptInt("How many Managers?", 0, 100);
for (int i = 0; i < NumManager; i++) {
    double wage = promptDouble("Hourly wage: ", 0, 1000);
    string name = promptString("Name: ");
    int teamSize = promptInt("Team size: ", 0, 100);

    Manager example(name, wage, teamSize);

    int hours = promptInt("Hours worked: ", 0, 999);
    example.logHours(hours);
    double bonus = promptDouble("Bonus: ", 0, 1000000);
    example.awardBonus(bonus);

    store.hireManager(example);
}

string planned = promptString("Planned schedule: ");
string actual = promptString("Actual schedule: ");

ScheduleAudit audit(planned, actual);


return 0;
}