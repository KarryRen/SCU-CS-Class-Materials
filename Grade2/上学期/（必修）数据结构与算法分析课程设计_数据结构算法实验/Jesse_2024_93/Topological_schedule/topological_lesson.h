#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#define MAX_SIZE 100
#define MAX_SEMESTER 8
using namespace std;

//课结构
struct Lesson
{
    string index="\0";//课程编号
    string name;//课程名字
    int lesson_hour;//学时数
    int assigned_semester;//上课学期
    vector<string> pre_lessons;//先决课程条件
};
struct Sorted_Lesson
{
    string index="\0";//课程编号
    string name;//课程名字
    int assigned_semester;//安排好的上课学期
};
//图结构
struct Node
{
    int vertex;
    Node *next=nullptr;
};
struct Headnode
{
    string index;
    Node *link=nullptr;
};

//主类结构及主要函数
class topological_lesson
{
private:
    int n[MAX_SEMESTER]={0};//每个学期的课程数
    char filename[MAX_SIZE];//文件名
    int lesson_in[MAX_SIZE]={0};//节点入度
    int h;//除去已指定学期课后剩下的课程数
    Headnode head[MAX_SIZE];//encoder后的邻接链表
    vector<Lesson> lessons;//拓扑排序前的课程
    vector<Sorted_Lesson> sorted_lessons;//拓扑排序后的课程编号
public:
    void load()//将课程信息存储在vector中
    {
        int j=0; 
        cout<<"Please enter the filename of the file you operate"<<endl;
        cout<<"ATTENTION:the file must be in the same folder of the code"<<endl;
        cin>>filename;
        ifstream infile(filename);  
        if (!infile.is_open()) {
            cout<<"There is no existed file"<<endl;
            exit(EXIT_FAILURE);
        }
        string line;
        while (getline(infile, line)) { 
            istringstream iss(line); 
            Lesson lesson;
            if (!line.empty()&&line.substr(0, 2) != "//"&&j==0)
            {
                for(j;j<=7;j++) iss>>n[j];//首先将第一个非空行和注释行的内容装进课程数数组里
            }
            if (iss >> lesson.index >> lesson.name >> lesson.lesson_hour >> lesson.assigned_semester) //再将其他行装进lesson里
            {
                string pre_lesson;//特别处理含一个或多个先决条件的课程
                while(iss>>pre_lesson)
                lesson.pre_lessons.push_back(pre_lesson);
                lessons.push_back(lesson);  
            }
        }
        infile.close();  
    }

    void graph_generate()//生成图的邻接表
    {
        int n=0,q=0;
        for(int m=0;m<lessons.size();m++){
            if(lessons[m].assigned_semester==0)//将需要计算机安排的课程装入顶点节点 
            {   
                head[n].index=lessons[m].index;
                n++;
            }
        } 
        h=n;//需要计算机安排的课程数
        for(int p=0;p<lessons.size();p++)//构建邻接表
        {   
            if(lessons[p].pre_lessons.size()!=0)
            {
                for(int o=0;o<lessons[p].pre_lessons.size();o++)
                {    
                    q=0;
                    Node *temp1=new Node();
                    while(head[q].index!=lessons[p].pre_lessons[o]) //查找先决课程对应的编号
                        q++;
                    temp1->vertex=p;//
                    temp1->next=nullptr;
                    if(head[q].link==nullptr)//如果还没有孩子
                        head[q].link=temp1;
                    else {//如果有，则插到尾部
                        Node *temp2=head[q].link;
                        while(temp2->next!=nullptr)    
                            temp2=temp2->next;
                        temp2->next=temp1;
                    } 
                }   
                lesson_in[p]=lessons[p].pre_lessons.size();   
            }
        }
    }

    void topological_sort()//拓扑排序
    {
        int top=-1,j;
        queue<int> in_0_headnode; 
        //将入度为0的节点传成一条关系链
        for(int i=0;i<h;i++){
            if(lesson_in[i]==0){
                in_0_headnode.push(i);
            }
        }
        int cur_semester=1;//实际上是1
        //一直将入度为0的点出栈，并进入拓扑排序后的vector
        while(cur_semester<=MAX_SEMESTER){   
            int cur_semester_lessons=0;
            int queue_size=in_0_headnode.size();//当前学期入度为0的课程数
            for(int i=0;i<lessons.size();i++){//压入已经指定好学期数的课程
                if(lessons[i].assigned_semester==cur_semester){
                    Sorted_Lesson temp;
                    temp.assigned_semester=cur_semester;
                    temp.index=lessons[i].index;
                    temp.name=lessons[i].name;
                    sorted_lessons.push_back(temp);
                    cur_semester_lessons++;
                }
            }
            while(queue_size--&&cur_semester_lessons<n[cur_semester-1]){
                //可能会有根据后面课程依赖度排序的操作，这里先不管
                if(lessons[in_0_headnode.front()].assigned_semester==0){
                    for(Node* node_ptr=head[in_0_headnode.front()].link;node_ptr!=nullptr;node_ptr=node_ptr->next){
                        if(!(--lesson_in[node_ptr->vertex])){
                            in_0_headnode.push(node_ptr->vertex);
                        }
                    }
                    Sorted_Lesson temp;
                    temp.assigned_semester=cur_semester;
                    temp.name=lessons[in_0_headnode.front()].name;
                    temp.index=lessons[in_0_headnode.front()].index;
                    sorted_lessons.push_back(temp);
                    cur_semester_lessons++;
                    in_0_headnode.pop();
                }
            }
            cur_semester++;
        }       
    }

    void print(){//输出可能的选课顺序
        cout<<"第1学期课程"<<endl;
        int i;
        for(i=0;i<sorted_lessons.size()-1;i++){
            cout<<sorted_lessons[i].index<<'\t'<<sorted_lessons[i].name<<endl;   
            if(sorted_lessons[i].assigned_semester!=sorted_lessons[i+1].assigned_semester){
                cout<<"第"<<sorted_lessons[i+1].assigned_semester<<"学期课程"<<endl;
            }
        }
        cout<<sorted_lessons[i].index<<'\t'<<sorted_lessons[i].name<<endl;
    }
};