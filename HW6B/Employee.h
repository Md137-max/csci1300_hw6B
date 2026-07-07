#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    private:
    string name;
    double hourlyWage;
    int hoursWorked;
    int employeeID;
    static int nextID;

public:
    Employee(string name, double hourlyWage);
    bool logHours(int hours);
    double calculatePay();
    int getID();
    string getName();
    double getHourlyWage();
    int getHoursWorked();
};

#endif