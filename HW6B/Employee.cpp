#include "Employee.h"

int Employee::nextID = 1000;
 

Employee::Employee(string n, double hW) {

    if (n == "") {
        name = "Unknown";
    }
    else { name = n;
    }
    if (hW < 0) {
        hW = 0.0;
    }
    else {
         hourlyWage = hW;
    }
    hoursWorked = 0;
    employeeID = nextID++;
}

bool Employee::logHours(int hours){
    
    if (hours < 0) {
        return false;
    }
    else {
        hoursWorked += hours;
        return true;
    }
}


double Employee::calculatePay() {
    if (hoursWorked <= 40) {
        return hoursWorked * hourlyWage;
    }
    else if (hoursWorked >= 41 && hoursWorked <= 60) {
        return hoursWorked * (hourlyWage * 1.5);
    }
    else {
        return hoursWorked * (hourlyWage * 2);
    }
}

int Employee::getID() {
    return employeeID;
}
string Employee::getName(){
    return name;
}
double Employee::getHourlyWage(){
    return hourlyWage;
}

int Employee::getHoursWorked() {
    return hoursWorked;
}