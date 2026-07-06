#ifndef COURSEINFORMATIONOVERVIEW_H
#define COURSEINFORMATIONOVERVIEW_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "CourseInformation.h"
#include "GeneralList.h"
#include "QueueList.h"
#include "CourseStack.h"
#include "Graph.h"
#include "CourseInformationOverview.h"

using namespace std;

class CourseInformationOverview {
public:
    CourseInformationOverview() {}

    void Title(int i)
    {
        cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                                   第" << i << "学期课表总览                                                    |" << endl;
        cout << "+----------------+--------------------+-------------------+-------------+-----------+---------------+------------------+" << endl;
        cout << "|   CourseType   |     Course Name    |    Teacher Name   |    Credit   |    Term   |    Sessions   |   Prerequisite   |" << endl;
        cout << "+----------------+--------------------+-------------------+-------------+-----------+---------------+------------------+" << endl;
    }

    void CenterOut(int a)
    {
        for (int i = 0; i < a; i++)
        {
            cout << " ";
        }
    }

    void Line(string courseTypeId, string courseName, string teacherName, string courseCredit, string courseTerm, string sessions, string limitation)
    {
        int paddingId = (16 - courseTypeId.length()) / 2;
        int paddingName = (20 - courseName.length()) / 2;
        int paddingTeacher = (19 - teacherName.length()) / 2;
        int paddingCredit = (13 - courseCredit.length()) / 2;
        int paddingTerm = (11 - courseTerm.length()) / 2;
        int paddingSessions = (15 - sessions.length()) / 2;
        int paddingLimitation = (18 - limitation.length()) / 2;

        cout << "|";
        CenterOut(paddingId);
        cout << courseTypeId;
        if (courseTypeId.length() % 2 != 0) {
            paddingId++;
        }
        CenterOut(paddingId);
        cout << "|";

        CenterOut(paddingName);
        cout << courseName;
        if (courseName.length() % 2 != 0) {
            paddingName++;
        }
        CenterOut(paddingName);
        cout << "|";

        CenterOut(paddingTeacher);
        cout << teacherName;
        if (teacherName.length() % 2 == 0) {
            paddingTeacher++;
        }
        CenterOut(paddingTeacher);
        cout << "|";

        CenterOut(paddingCredit);
        cout << courseCredit;
        if (courseCredit.length() % 2 == 0) {
            paddingCredit++;
        }
        CenterOut(paddingCredit);
        cout << "|";

        CenterOut(paddingTerm);
        cout << courseTerm;
        CenterOut(paddingTerm);
        cout << "|";

        CenterOut(paddingSessions);
        cout << sessions;
        if (sessions.length() % 2 == 0) {
            paddingSessions++;
        }
        CenterOut(paddingSessions);
        cout << "|";

        CenterOut(paddingLimitation);
        if (limitation == "0")
        {
            cout << " ";
        }
        else
        {
            cout << limitation;
        }
        CenterOut(++paddingLimitation);
        cout << "|" << endl;
        cout << "+----------------+--------------------+-------------------+-------------+-----------+---------------+------------------+" << endl;
    }
};

#endif // !COURSEINFORMATIONOVERVIEW_H

