#ifndef COURSESTACK_H
#define COURSESTACK_H

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
#include "Graph.h"
#include "CourseInformationOverview.h"
#include "ClassInEachTerm.h"

using namespace std;

class CourseStack {
private:
    int size = 0;
public:
    CourseInformation* head = NULL;
    CourseInformation* current = NULL;

    CourseStack() {}

    void Push(CourseInformation* add)
    {
        if (head == NULL)
        {
            head = add;
            current = add;
        }
        else
        {
            current->stacknext = add;
            current = current->stacknext;
        }
        size++;
    }

    CourseInformation* Top()
    {
        return current;
    }

    void Pop()
    {
        CourseInformation* tmp = head;

        if (current == head)
        {
            head = NULL;
            current = NULL;
        }
        else
        {
            while (tmp->stacknext != current)
            {
                tmp = tmp->stacknext;
            }

            current = tmp;
            current->stacknext = NULL;
        }
        size--;
    }

    int GetSize()
    {
        return size;
    }

    string GetCourseName(int courseTypeId)
    {
        if (courseTypeId == 0)
        {
            return "";
        }
        else
        {
            current = head;
            while (current != NULL)
            {
                if (current->courseTypeId == courseTypeId)
                {
                    return current->courseName + "_" + to_string(current->courseId) + " " + current->teacherName;
                }
                current = current->stacknext;
            }
        }

    }
};

#endif // !COURSESTACK_H

