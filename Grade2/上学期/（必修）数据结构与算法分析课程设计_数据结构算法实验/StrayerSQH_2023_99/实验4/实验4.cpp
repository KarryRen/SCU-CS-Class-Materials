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
#include "ClassInEachTerm.h"

using namespace std;

void Introduction()
{
    std::string courseInfo = "四川大学计算机学院 2024-2025 学年数据结构与算法分析课程实验课作业四";
    std::string name = "SQH";
    std::string studentID = "2023141460321";

    std::cout << "+----------------------------------------------------------------------------+" << std::endl;
    std::cout << "| " << courseInfo;
    std::cout << std::string(74 - courseInfo.length(), ' ') << " |" << std::endl;
    std::cout << "| 姓名：" << name;
    std::cout << std::string(68 - name.length(), ' ') << " |" << std::endl;
    std::cout << "| 学号：" << studentID;
    std::cout << std::string(68 - studentID.length(), ' ') << " |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------+" << std::endl;

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }
}

void MapZero(int courseMap[14][7])
{

    for (int m = 0; m < 14; m++)
    {
        for (int n = 0; n < 7; n++)
        {
            courseMap[m][n] = 0;
        }
    }
}


int main()
{
    string courseFileName = "SCU-Course.csv";
    ifstream courseFileName_csv(courseFileName, ios::in);

    if (!courseFileName_csv.is_open())
    {
        cout << "错误：SCU-Course.csv文件读取失败！" << endl;
        exit(1);
    }

    int term[8]; //存储八个学期中需要排的课程数量
    string eachTerm;
    string courseInformation;
    vector<string> courseInformations;

    //读取八个学期每个学期中需要排的课程数量
    getline(courseFileName_csv, eachTerm);
    istringstream iss(eachTerm);
    for (int i = 0; i < 8; i++)
    {
        iss >> term[i];
    }

    //读取CSV文件中每行课程的课程信息并存储到广义表中
    GeneralList eachCourseInformationGeneralList;//存储所有课程的广义表
    eachCourseInformationGeneralList.CreateGeneralList(20);
    QueueList eachTermTheCourseMustStudy[8]; //存储每个学期的必修课程

    while (getline(courseFileName_csv, courseInformation))
    {
        istringstream iss(courseInformation);
        string token;
        int cTId, cId, c, tOSch, sTime, eTime, wDay;
        string cName, tName, dep;

        // 读取课程类型ID
        iss >> cTId;    iss.ignore();
        // 读取课程名称
        getline(iss, cName, ' ');
        // 读取课程ID
        iss >> cId;     iss.ignore();
        // 读取教师名称
        getline(iss, tName, ' ');
        // 读取学分
        iss >> c;   iss.ignore();
        // 读取学期
        iss >> tOSch;   iss.ignore();
        // 读取上课时间
        iss >> sTime;   iss.ignore();
        // 读取下课时间
        iss >> eTime;   iss.ignore();
        // 读取周几上课
        iss >> wDay;    iss.ignore();
        // 读取依赖项数量
        iss >> dep;

        CourseInformation* tmpCourseInformation = new CourseInformation(cTId, cName, cId, tName, c, tOSch, sTime, eTime, wDay, dep);
        eachCourseInformationGeneralList.AddCourseInEachType(tmpCourseInformation); //在广义表中添加课程信息
        if (tmpCourseInformation->termOnSchedule != 0)
        {
            if (!eachTermTheCourseMustStudy[tOSch - 1].In(tmpCourseInformation->courseTypeId))
            {
                eachTermTheCourseMustStudy[tOSch - 1].AddCourse(tmpCourseInformation); //在每个学期的队列中存储学期必修课
            }
        }

    }
    eachCourseInformationGeneralList.ShortGeneralList(); //简短广义表，删去没有课程内容的课程类型

    //创建拓补图，安排每学期的课程
    Graph courseGraph(eachCourseInformationGeneralList.GetTotalCourseTypeNum());
    CourseInformation* eachCourseInformationGeneralListCurrent = eachCourseInformationGeneralList.head;
    int courseNum = eachCourseInformationGeneralList.courseNum;
    int c = 0;
    while (eachCourseInformationGeneralListCurrent != NULL && c != courseNum)
    {
        courseGraph.AddCourse(eachCourseInformationGeneralListCurrent);

        int dependenceNum = 0;
        int dependenceArrray[1000];
        string dependenceTxt = eachCourseInformationGeneralListCurrent->GetDependence();
        if (dependenceTxt != "0")
        {
            istringstream iss(dependenceTxt);
            string token;
            while (getline(iss, token, ','))
            {
                dependenceArrray[dependenceNum] = stoi(token);
                dependenceNum++;
            }

            for (int i = 0; i < dependenceNum; i++)
            {
                CourseInformation* findId = eachCourseInformationGeneralList.head;
                while (findId->courseTypeId != dependenceArrray[i] && findId != NULL)
                {
                    findId = findId->next;
                }
                // 增添一部分，用于判断依赖中是否存在以后学期才能上的必修课
                if (findId->termOnSchedule >= eachCourseInformationGeneralListCurrent->termOnSchedule)
                {
                    cout << findId->courseName << "的开设学期为第" << findId->termOnSchedule << "学期，而开设于" << eachCourseInformationGeneralListCurrent->termOnSchedule << "学期的课程" << eachCourseInformationGeneralListCurrent->courseName << "对其存在依赖！" << endl;
                    cout << "存在非法超前课程学习依赖，无法安排课表!" << endl;
                    exit(0);
                }
                else
                {
                    //一切正常的话继续程序
                    courseGraph.AddPrerequisite(findId, eachCourseInformationGeneralListCurrent);
                }
            }
        }
        eachCourseInformationGeneralListCurrent = eachCourseInformationGeneralListCurrent->next;
        c++;
    }

    // 拓补排序课程
    courseGraph.TopologicalSort(); 

    //课程信息概览
    Introduction(); //声明作者
    vector<CourseInformation*> result = courseGraph.result; //将拓补排序的课程结果取出

    for (int i = 0; i < 2; i++)
    {

        QueueList storeCurrentChild; //用于保存置入课表中的上一个必修课在广义表中的位置，以便后续调整
        CourseInformation* qListCurrent = eachTermTheCourseMustStudy[i].head;
        CourseStack courseStack;
        int courseMap[14][7] = { 0 };
        int numberOfCourseInQueue = eachTermTheCourseMustStudy[i].GetSize();
        int returntoNum = 0;

        // 创建默认上一个必修课在广义表中的位置为子表第一个元素
        for (int k = 0; k < numberOfCourseInQueue; k++)
        {
            storeCurrentChild.AddCourseForTerm(eachCourseInformationGeneralList.GetCourseInformationInGeneralList(qListCurrent->courseTypeId)->childnext);
            qListCurrent = qListCurrent->queuenext;
        }


        bool judge = false; //判断该必修课是否成功置入；
        bool rewritePermission = false;
        qListCurrent = eachTermTheCourseMustStudy[i].head;
        while (qListCurrent != NULL)
        {
            int courseTypeId = 0;
            CourseInformation* tmp = storeCurrentChild.GetCourseInNumber(returntoNum);
            //将必修课在现有的课表中插入
            while (tmp != NULL)
            {
                if (returntoNum == 0)
                {
                    MapZero(courseMap);
                }

                if (rewritePermission)
                {
                    CourseInformation* a = courseStack.Top();
                    for (int j = a->startTime - 1; j < a->endTime; j++)
                    {
                        courseMap[j][a->day - 1] = 0;
                    }
                    courseStack.Pop();
                    rewritePermission = false;

                    if (tmp->ifReutrn)
                    {
                        tmp->ifReutrn = 0;
                        courseTypeId = tmp->courseTypeId;
                        break;
                    }
                }
                if (courseMap[tmp->startTime - 1][tmp->day - 1] == 0 && courseMap[tmp->endTime - 1][tmp->day - 1] == 0)
                {
                    for (int j = tmp->startTime - 1; j < tmp->endTime; j++)
                    {
                        courseMap[j][tmp->day - 1] = tmp->courseTypeId;
                    }
                    judge = true;
                    break;
                }
                else
                {
                    if (tmp->childnext == NULL)
                    {
                        courseTypeId = tmp->courseTypeId;
                    }
                    tmp = tmp->childnext;
                    judge = false;
                }
            }

            if (judge) //如果在现有课表情况下顺利置入，则继续置入下一个必修课
            {
                eachCourseInformationGeneralList.GetCourseInformationInGeneralList(tmp->courseTypeId)->study = true;
                qListCurrent = qListCurrent->queuenext;
                if (tmp->childnext != NULL)
                {
                    CourseInformation* a = tmp;
                    tmp = tmp->childnext;
                    tmp->queuenext = a->queuenext;
                    courseStack.Push(a);
                    storeCurrentChild.ChangeCourse(storeCurrentChild.GetCourseInNumber(returntoNum - 1), tmp, storeCurrentChild.GetCourseInNumber(returntoNum + 1));
                }
                else
                {
                    tmp->ifReutrn = 1;
                    courseStack.Push(tmp);
                }
                returntoNum++;
            }
            else //表明没法在现有课表情况下顺利置入，则需要返回对上一步中的必修课时间进行调整
            {
                storeCurrentChild.ChangeCourse(storeCurrentChild.GetCourseInNumber(returntoNum - 1),
                    eachCourseInformationGeneralList.GetCourseInformationInGeneralList(courseTypeId)->childnext,
                    storeCurrentChild.GetCourseInNumber(returntoNum + 1));
                returntoNum--;
                rewritePermission = true;
                qListCurrent = eachTermTheCourseMustStudy[i].GetCourseInNumber(returntoNum);
            }

            if (returntoNum < 0)
            {
                cout << "第" << i << "学期必修课程之间始终存在冲突，无法安排课表！" << endl;
                break;
            }
        }

       
        //如果必修课课程数量未超过了学期最少课程数，则需要添加额外的其他课程
        int currentCourseSize = courseStack.GetSize();
        int t = 0;
        while (courseStack.GetSize() < term[i])
        {
            //从拓补排序中读取与当前课程不冲突的课程填入
            if (!result[t]->study && !eachCourseInformationGeneralList.GetCourseInformationInGeneralList(result[t]->courseTypeId)->study)
            {
                CourseInformation* tmp = eachCourseInformationGeneralList.GetCourseInformationInGeneralList(result[t]->courseTypeId)->childnext;
                while (tmp != NULL)
                {
                    if (courseMap[tmp->startTime - 1][tmp->day - 1] == 0 && courseMap[tmp->endTime - 1][tmp->day - 1] == 0)
                    {
                        for (int j = tmp->startTime - 1; j < tmp->endTime; j++)
                        {
                            courseMap[j][tmp->day - 1] = tmp->courseTypeId;
                        }
                        judge = true;
                        courseStack.Push(tmp);
                        eachCourseInformationGeneralList.GetCourseInformationInGeneralList(result[t]->courseTypeId)->study = true;
                        currentCourseSize++;
                        break;
                    }
                    else
                    {
                        tmp = tmp->childnext;
                    }
                }
            }
            t++;
        }

        //经过上述过程学期课程已经存储在courseStack栈中，调用输出课程概览和课表可视化
        CourseInformationOverview courseInformationOverview;
        courseInformationOverview.Title(i + 1);

        CourseInformation* stackCurrent = courseStack.head;
        while (stackCurrent != NULL)
        {
            courseInformationOverview.Line(to_string(stackCurrent->courseTypeId),
                stackCurrent->courseName + "_" + to_string(stackCurrent->courseId),
                stackCurrent->teacherName,
                to_string(stackCurrent->credit),
                to_string(stackCurrent->termOnSchedule),
                to_string(stackCurrent->day) + ": " + to_string(stackCurrent->startTime) + "-" + to_string(stackCurrent->endTime),
                stackCurrent->dependenceTxt);
            stackCurrent = stackCurrent->stacknext;
        }

        ClassInEachTerm classInEachTerm;
        classInEachTerm.Title();
        int j = 0;
        for (j = 0; j < 4; j++)
        {
            classInEachTerm.Line(j, 
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][0])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][1])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][2])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][3])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][4])), 
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][5])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][6])));
        }
        classInEachTerm.BreakLine();
        for (j = 4; j < 9; j++)
        {
            classInEachTerm.Line(j,
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][0])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][1])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][2])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][3])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][4])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][5])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][6])));
        }
        classInEachTerm.BreakLine();
        for (j = 9; j < 12; j++)
        {
            classInEachTerm.Line(j,
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][0])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][1])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][2])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][3])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][4])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][5])),
                classInEachTerm.AddLength(courseStack.GetCourseName(courseMap[j][6])));
        }
    }

    return 0;
}