#ifndef COURSEINFORMATION_H
#define COURSEINFORMATION_H

#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

class CourseInformation {
private:
public:
    //课程信息变量
    int courseTypeId = 0;
    string courseName = "";
    int courseId = 0;
    string teacherName = "";
    int credit;
    int termOnSchedule;
    int startTime;
    int endTime;
    int day;
    int ifReutrn = 0;
    bool study = false; // 用于存储该课程是否有被学习过
    string dependenceTxt;
    vector<CourseInformation*> prerequisites; // 先修课程列表
    vector<CourseInformation*> successors; // 后继课程列表

    //广义表变量
    int atomType = 0;//0表示为子表，1表示为原子，通过后面程序进行定义
    CourseInformation* next = NULL;
    CourseInformation* childnext = NULL;
    CourseInformation* queuenext = NULL;
    CourseInformation* termnext = NULL;
    CourseInformation* stacknext = NULL;

    CourseInformation(int cTId) : courseTypeId(cTId) {}

    CourseInformation(int cTId, string cName, int cId, string tName, int c, int tOSch, int sTime, int eTime, int wDay, string dep) {
        courseTypeId = cTId;
        courseName = cName;
        courseId = cId;
        teacherName = tName;
        credit = c;
        termOnSchedule = tOSch;
        startTime = sTime;
        endTime = eTime;
        day = wDay;
        dependenceTxt = dep;
        atomType = 1;
    }

    string GetDependence() { return dependenceTxt; }
    void SetAtomType(int type) { atomType = type; }
};

#endif // !COURSEINFORMATION_H
