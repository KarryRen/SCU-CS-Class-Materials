#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#define MAX_SIZE 100000
#define MAX_LEN 1000
#define MAX_WORD MAX_SIZE/100
struct HuffmanNode
{
    char word;//字符
    int weight=-1;
    HuffmanNode* lchild=nullptr;
    HuffmanNode* rchild=nullptr;
    HuffmanNode(char word_arguement,int weight_arguement){
        word=word_arguement;
        weight=weight_arguement;
    }
};
// Define the comparison object to be used in std::priority_queue
struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->weight > r->weight);
    }
};
class Huffman{
private:
    char path[MAX_WORD];//文件路径，文件名
    char data[MAX_SIZE];//文件数据缓存区
    map<char,int> word_counter;//词频表
    HuffmanNode* root;//哈夫曼树的根节点
    map<char,string> zip_code;//压缩编码表
    string result;//压缩后的二进制字符串
    int wordtype_size=0;//字符种类个数
public:
    void encoder(){
        ifstream infile;
        cout<<"Please enter the filename of the file you operate"<<endl;
        cout<<"ATTENTION:the file must be in the same folder of the code"<<endl;
        cin>>path;
        infile.open(path);
        if(!infile.is_open()){
            cout<<"There is no existed file"<<endl;
            exit(EXIT_FAILURE);
        }
        //txt->字符数组
        char* Buffer_pointer=data;
        while(infile.getline(Buffer_pointer,MAX_LEN)){
            while(*Buffer_pointer!='\0'){
                Buffer_pointer++;
            }
            if(*Buffer_pointer=='\0'){
            *Buffer_pointer='\n';
            }
        Buffer_pointer++;
        }
        Buffer_pointer--;
        *Buffer_pointer='\0';
        infile.close();
        word_count();//统计词频并由小到大排序
        tree_generate();//生成二叉树和编码
        zip();//根据编码，生成压缩txt/二进制文件
        key_generate();//txt文件,以便其他用户解码
    }
    void decoder(){
        ifstream infile;
        cout<<"Please enter the filename of the file you operate"<<endl;
        cout<<"ATTENTION:the file must be in the same folder of the code"<<endl;
        cin>>path;
        infile.open(path,ios::binary);
        if(!infile.is_open()){
            cout<<"There is no existed file"<<endl;
            exit(EXIT_FAILURE);
        }
        //bin->字符数组
        char* Buffer_pointer=data;
        while(infile.getline(Buffer_pointer,MAX_LEN)){
            while(*Buffer_pointer!='\0'){
                Buffer_pointer++;
            }
            if(*Buffer_pointer=='\0'){
            *Buffer_pointer='\n';
            }
        Buffer_pointer++;
        }
        Buffer_pointer--;
        *Buffer_pointer='\0';
        infile.close();
        dezip();//根据编码表内容一一对应解码，并生成txt文件/二进制文件
    }
//统计词频表
    void word_count(){
        for(int i = 0; data[i]!='\0'; i++){
            word_counter[data[i]]++;//下标为对于字符,比如word_counter['p']=3;表示p出现了3次
            //map默认是由小到大排序
	    }
    }
//生成哈夫曼树
    void tree_generate(){
        //优先级队列minHeap
        priority_queue<HuffmanNode*,vector<HuffmanNode*>,compare> minHeap;
        for(auto pair: word_counter){//对于词频表word_counter中的每一个字符以及对于的权重
            minHeap.push(new HuffmanNode(pair.first,pair.second));//pair.first是字符,pair.second是词频
        }
        //根据队列生成树关系
        while(minHeap.size()!=1){
            //将最小的两个字符对应的HuffmanNode取出来
            HuffmanNode* left=minHeap.top();
            minHeap.pop();
            HuffmanNode* right=minHeap.top();
            minHeap.pop();
            int weight_sum=left->weight+right->weight;//相加权值
            //构造权值和代表的节点，用'\0'表示无字符
            HuffmanNode* temp=new HuffmanNode('\0',weight_sum);
            //构造父子关系
            temp->lchild=left;
            temp->rchild=right;
            minHeap.push(temp);
        }
        //循环完后剩下的那个节点就是根节点
        root=minHeap.top();
    }
//根据哈夫曼树生成编码,将文件压缩
    void zip(){
        key_generate();
        //将字符替换成压缩编码
        ofstream outfile;
        outfile.open(path,ios::binary);
        if(!outfile.is_open()){
            cout<<"读取文件失败"<<endl;
            exit(EXIT_FAILURE);
        }
        char outdata[MAX_SIZE]={'\0'};
        for(int i=0;i<result.length();i++){
            outdata[i]=result[i];
        }
        outfile.write(outdata,result.length());
        outfile.close();
    }
//根据哈夫曼树编码解压缩
    void dezip(){
        //将txt文件重新生成到map<char,char>中,并生成哈夫曼树
        key_regenerate();
        //将压缩编码替换成字符
        char* binchar=data;
        string outdata;
        HuffmanNode* tempnode=root;
        while(*binchar=='0'||*binchar=='1'){
                if(*binchar=='0'){
                    tempnode=tempnode->lchild;
                }
                if(*binchar=='1'){
                    tempnode=tempnode->rchild;
                }
                if(tempnode->word!='\0'){
                    outdata+=tempnode->word;
                    tempnode=root;
                }
            binchar++;
        }
        ofstream outfile(path);
        if(!outfile.is_open()){
            cout<<"outfile error"<<endl;
            exit(EXIT_FAILURE);
        }
        outfile.write(outdata.c_str(),outdata.length());
        }
//生成编码表
    void key_generate(){
        //string zip_code[MAX_WORD];
        string temp_code="";
        //生成编码表
        char path[MAX_LEN];
        HuffmanNode* temp=root;
        //遍历哈夫曼树,生成编码表
        huffman_dfs(temp,temp_code,zip_code);//深度遍历哈夫曼树，生成编码表
        for(int i=0;data[i]!='\0';i++){
            result+=zip_code[data[i]];
        }
        ofstream outcodetable("index.csv",ios::out);
        for (auto pair:word_counter) {    //加了个for循环去将第一列写成全部Q，第二列写成123...
            if(pair.first=='\n'||pair.first=='\t'||pair.first==' '){
                if(pair.first=='\n')
                outcodetable<<"\\n"<<','<<pair.second<<endl;
                if(pair.first=='\t')
                outcodetable<<"\\t"<<','<<pair.second<<endl;
                if(pair.first==' ')
                outcodetable<<"\\0"<<','<<pair.second<<endl;//空格
            }
            else
            {
                outcodetable<<pair.first<<','<<pair.second<<endl;
            }
	    } 
        outcodetable.close();
    }
//根据编码表重新生成树
    void key_regenerate(){
        //利用csv文件内容生成word_counter,再生成树
        ifstream incodetable("index.csv");
        if(!incodetable.is_open()){
            cout<<"该文件的未压缩或编码表被删除"<<endl;
            exit(EXIT_FAILURE);
        }
        string line;
        while (getline(incodetable, line)) {
            stringstream ss(line);
            char key;
            int value;
            ss>>key;
            if(key=='\\'){
                ss>>key;
                if(key=='n'){
                    key='\n';
                }
                if(key=='t'){
                    key='\t';
                }
                if(key=='0'){
                    key=' ';
                }
            }
            ss.ignore();
            ss>>value;
           word_counter[key] =value;
        }

        incodetable.close();
        tree_generate();
    }

    void huffman_dfs(HuffmanNode* root,string code,map<char,string>& codes){
        if(root==nullptr)
        return ;
        if(root->lchild ==nullptr&&root->rchild==nullptr){
            codes[root->word]=code;
            return ;
        }
        huffman_dfs(root->lchild,code+'0',codes);
        huffman_dfs(root->rchild,code+'1',codes);
    }
};