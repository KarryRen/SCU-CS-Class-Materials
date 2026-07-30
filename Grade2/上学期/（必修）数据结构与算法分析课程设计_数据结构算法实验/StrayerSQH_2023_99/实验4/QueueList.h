#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "CourseInformation.h"
#include "GeneralList.h"
#include "CourseStack.h"
#include "Graph.h"
#include "CourseInformationOverview.h"
#include "ClassInEachTerm.h"

using namespace std;

class QueueList {
private:
public:
    int size = 0;
    CourseInformation* head = NULL;
    CourseInformation* current = NULL;
    QueueList() {}

    bool In(int num)
    {
        current = head;
        while (current != NULL)
        {
            if (current->courseTypeId == num)
            {
                return true;
            }
            else
            {
                current = current->queuenext;
            }
        }

        return false;
    }

    void AddCourse(CourseInformation* course)
    {
        if (head == NULL)
        {
            head = course;
            current = course;
        }
        else
        {
            current = head;
            while (current->queuenext != NULL)
            {
                current = current->queuenext;
            }
            current->queuenext = course;
        }
        size++;
    }

    void AddCourseForTerm(CourseInformation* course)
    {
        if (head == NULL)
        {
            head = course;
            current = course;
        }
        else
        {
            current->termnext = course;
            current = current->termnext;
        }
        size++;
    }

    CourseInformation* GetCourseInNumber(int num)
    {
        current = head;
        for (int i = 0; i < num; i++)
        {
            current = current->queuenext;
        }

        return current;
    }

    void ChangeCourse(CourseInformation* front, CourseInformation* change, CourseInformation* back)
    {
        if (front->childnext == change)
        {
            front = change;
            head = change;
        }
        else
        {
            front->queuenext = change;
            change->queuenext = back;
        }
    }

    int GetSize()
    {
        return size;
    }
};

#endif // !QUEUELIST_H

