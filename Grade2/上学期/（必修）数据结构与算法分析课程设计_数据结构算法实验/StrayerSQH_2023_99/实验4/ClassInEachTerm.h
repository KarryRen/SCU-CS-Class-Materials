#ifndef CLASSINEACHTERM_H
#define CLASSINEACHTERM_H

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

class ClassInEachTerm {
public:
    ClassInEachTerm() {}

    void Title()
    {
        cout << "    +-----+--------------+--------------+--------------+--------------+--------------+--------------+--------------+" << endl;
        cout << "    |                                                     ¿Î±í                                                     |" << endl;
        cout << "    +-----+--------------+--------------+--------------+--------------+--------------+--------------+--------------+" << endl;
        cout << "    |     |    Monday    |    Tuesday   |   Wednesday  |   Thursday   |    Friday    |   Saturday   |    Sunday    |" << endl;
        cout << "    +-----+--------------+--------------+--------------+--------------+--------------+--------------+--------------+" << endl;
    }

    void BreakLine()
    {
        cout << "    |                                                                                                              |" << endl;
        cout << "    +-----+--------------+--------------+--------------+--------------+--------------+--------------+--------------+" << endl;
    }

    string AddLength(string txt)
    {
        int add = 42 - txt.length();
        for (int i = 0; i < add; i++)
        {
            txt += " ";
        }

        return txt;
    }

    void Out(string txt, int s, int e)
    {
        for (int i = s; i < e; i++)
        {
            cout << txt[i];
        }
    }

    void Line(int i, string mon, string tue, string wed, string thu, string fri, string sat, string sun)
    {
        int k = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j == 1)
            {
                if (i + 1 >= 10)
                {

                    cout << "    | " << i + 1 << "  ";
                    cout << "|";
                }
                else
                {
                    cout << "    |  " << i + 1 << "  ";
                    cout << "|";
                }
                Out(mon, k * 14, (k + 1) * 14);
                cout << "|";
                Out(tue, k * 14, (k + 1) * 14);
                cout << "|";
                Out(wed, k * 14, (k + 1) * 14);
                cout << "|";
                Out(thu, k * 14, (k + 1) * 14);
                cout << "|";
                Out(fri, k * 14, (k + 1) * 14);
                cout << "|";
                Out(sat, k * 14, (k + 1) * 14);
                cout << "|";
                Out(sun, k * 14, (k + 1) * 14);
                cout << "|" << endl;
            }
            else
            {
                cout << "    |     ";
                cout << "|";
                Out(mon, k * 14, (k + 1) * 14);
                cout << "|";
                Out(tue, k * 14, (k + 1) * 14);
                cout << "|";
                Out(wed, k * 14, (k + 1) * 14);
                cout << "|";
                Out(thu, k * 14, (k + 1) * 14);
                cout << "|";
                Out(fri, k * 14, (k + 1) * 14);
                cout << "|";
                Out(sat, k * 14, (k + 1) * 14);
                cout << "|";
                Out(sun, k * 14, (k + 1) * 14);
                cout << "|" << endl;
            }
            k++;
        }
        cout << "    +-----+--------------+--------------+--------------+--------------+--------------+--------------+--------------+" << endl;
    }

};

#endif // !CLASSINEACHTERM_H

