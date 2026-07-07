#ifndef SCHEDULEAUDIT_H
#define SCHEDULEAUDIT_H

#include <string>
#include<vector>

using namespace std;

class ScheduleAudit {
private:
    string plannedSchedule;
    string actualSchedule;
    double bestSimilarityScore;
    int bestAlignmentIndex;

public:
    ScheduleAudit(string plannedSchedule, string actualSchedule);
    double findBestAlignment();
    int getBestAlignmentIndex();
    double getBestSimilarityScore();
    vector<string> detectDiscrepancies();
};


    #endif