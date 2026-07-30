#ifndef GENERALLIST_H
#define GENERALLIST_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "CourseInformation.h"
#include "QueueList.h"
#include "CourseStack.h"
#include "Graph.h"
#include "CourseInformationOverview.h"
#include "ClassInEachTerm.h"

using namespace std;

class GeneralList {
private:
public:
    CourseInformation* head = NULL;
    CourseInformation* currentTableId = NULL;
    CourseInformation* currentChild = NULL;
    int courseNum = 20;
    GeneralList() {}

    //创建广义表，默认创建的广义表有MAX个表链节点
    void CreateGeneralList(int size)
    {
        for (int i = 1; i <= size; i++)
        {
            CourseInformation* tmp = new CourseInformation(i);
            if (head == NULL)
            {
                head = tmp;
                currentTableId = tmp;
            }
            else
            {
                currentTableId->next = tmp;
                currentTableId = currentTableId->next;
            }
        }
    }

    // 在广义表中添加课程
    void AddCourseInEachType(CourseInformation* courseInformation)
    {
        currentTableId = head;
        while (currentTableId->courseTypeId != courseInformation->courseTypeId)
        {
            currentTableId = currentTableId->next;
        }

        if (currentTableId->childnext == NULL)
        {
            currentChild = courseInformation;
            currentTableId->childnext = currentChild;
            currentTableId->dependenceTxt = courseInformation->dependenceTxt;
        }
        else
        {
            currentChild->childnext = courseInformation;
            currentChild = currentChild->childnext;
        }
    }

    //从广义表中获取某一课程类型下的所有课程信息
    CourseInformation* GetCourseInformationInGeneralList(int cTId)
    {
        currentTableId = head;
        while (currentTableId->courseTypeId != cTId)
        {
            currentTableId = currentTableId->next;
        }

        return currentTableId;
    }

    //简短广义表，删去无课程的课程类型
    void ShortGeneralList()
    {
        currentTableId = head;
        while (currentTableId != NULL)
        {
            if (currentTableId->childnext == NULL)
            {
                CourseInformation* tmp = currentTableId;
                currentTableId = currentTableId->next;
                if (tmp == head)
                {
                    head = currentTableId;
                }
                delete tmp;
                courseNum--;
            }
            else
            {
                currentTableId->courseName = currentTableId->childnext->courseName;
                currentTableId->credit = currentTableId->childnext->credit;
                currentTableId->termOnSchedule = currentTableId->childnext->termOnSchedule;
                currentTableId = currentTableId->next;
            }
        }
    }

    //获取课程种类数
    int GetTotalCourseTypeNum()
    {
        return courseNum;
    }
};
#endif // !GENERALLIST_H

