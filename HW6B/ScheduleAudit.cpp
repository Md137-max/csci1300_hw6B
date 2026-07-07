
#include "ScheduleAudit.h"

using namespace std;

ScheduleAudit::ScheduleAudit(string pS, string aS) {
    plannedSchedule = pS;
    actualSchedule = aS;
}
double ScheduleAudit::findBestAlignment() {
    string shortest;
    string longest;

    if (plannedSchedule.size() <= actualSchedule.size()) {
        shortest = plannedSchedule;
        longest = actualSchedule;
    }
    else {
        shortest = actualSchedule;
        longest = plannedSchedule;
    }

    bestSimilarityScore = 0.0;
    bestAlignmentIndex = 0;
for (size_t i = 0; i <= longest.length() - shortest.length(); i++) {
    int match = 0;
    for (size_t j = 0; j < shortest.length(); j++) {
        if (shortest[j] == longest[i + j]) {
            match++;
        }
    }
    double score = (double)match / shortest.length();
    if (score > bestSimilarityScore) {
        bestSimilarityScore = score;
        bestAlignmentIndex = i;
    }
}
return bestSimilarityScore;
}

int ScheduleAudit::getBestAlignmentIndex() {
return bestAlignmentIndex;
}

double ScheduleAudit::getBestSimilarityScore() {
return bestSimilarityScore;
}

vector<string> ScheduleAudit::detectDiscrepancies() {
findBestAlignment();
vector<string>discrepencies;
string shortest;
string longest;
bool plannedSHorter;

if(plannedSchedule.length() <= actualSchedule.length()) {
    shortest = plannedSchedule;
    longest = actualSchedule;
    plannedSHorter = true;
}
else {
    shortest = actualSchedule;
    longest = plannedSchedule;
    plannedSHorter = false;
}
//option 1
for (size_t i = 0; i < shortest.length(); i++ ) {
    if (longest[bestAlignmentIndex + 1] != shortest[i]) {
        //mismatch message
        string mismatched;
        if(plannedSHorter) {
            mismatched = "Mismatch at position " + to_string(i + 1) + ": planned " + string(1, shortest[i]) + " but worked " + string(1, longest[bestAlignmentIndex + i]);
        }
        else {
            mismatched = "Mismatch at position " + to_string(i + 1) + ": planned " + string(1, longest[bestAlignmentIndex + 1]) + " but worked " + string(1, shortest[i]);
        }
        discrepencies.push_back(mismatched);
    }
}
//option 2
for (size_t i = 0; i < bestAlignmentIndex; i++) {

    if (plannedSHorter) {
        discrepencies.push_back(
            "Unplanned Shift at position " + to_string(i + 1) +
            ": worked " + string(1, longest[i]) +
            " with no shift planned");
    }
    else {
        discrepencies.push_back(
            "Missed Shift at position " + to_string(i + 1) +
            ": " + string(1, longest[i]) +
            " was planned but never worked");
    }
}

//Option 3
for (size_t i = bestAlignmentIndex + shortest.length(); i < longest.length(); i++) {

    if (plannedSHorter) {
        discrepencies.push_back(
            "Unplanned Shift at position " + to_string(i + 1) +
            ": worked " + string(1, longest[i]) +
            " with no shift planned");
    }
    else {
        discrepencies.push_back(
            "Missed Shift at position " + to_string(i + 1) +
            ": " + string(1, longest[i]) +
            " was planned but never worked");
    }
}
return discrepencies;
}