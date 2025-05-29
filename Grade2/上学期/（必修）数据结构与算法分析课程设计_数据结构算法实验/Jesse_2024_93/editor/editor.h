#include <fstream>
#include <iostream>
#include <string.h>//c语言一些字符串操作库
using namespace std;
#define Maxrow 100 //最大行
#define Buffer 8192  //最大字符数
#define Maxlen Buffer/Maxrow //最大行长度
struct nodeblock{//块链的节点结构
    char word[Buffer]={'\0'};
    nodeblock* next=nullptr;
    int size=0;
};
struct rownodeblock{
    rownodeblock* rowprior=nullptr;
    rownodeblock* rownext=nullptr;
    nodeblock* next=nullptr;
};
char Buffer_data[Buffer]={'\0'};
class editor{
private:
    rownodeblock* head;//头指针
    rownodeblock* line_head[Maxrow];//各行的头指针
    int rows=0;//总行数
    int cur_row=0;//当前操作行
    rownodeblock* cur_row_pointer=head;
    char mode;//命令模式,h,i,n,b等
public:
//里面各类函数，对应各命令对应的操作

//读入读出，编码解码
void load(){
    cout<<"Please enter the input filename:";
    //txt->char []
    char infile_name[Buffer];
    cin>>infile_name;
    ifstream infile;
    infile.open(infile_name);
    if(!infile.is_open()){
        cout<<"读取文件失败"<<endl;
        exit(EXIT_FAILURE);
    }
    char* Buffer_pointer=Buffer_data;
    while(infile.getline(Buffer_pointer,Maxlen)){
        while(*Buffer_pointer!='\0'){
            Buffer_pointer++;
        }
        if(*Buffer_pointer=='\0')
            *Buffer_pointer='\n';
        Buffer_pointer++;
    }
    Buffer_pointer--;
    *Buffer_pointer='\0';
    infile.close();
    encoder();
}

void save(){
    //快链->char[]
    decoder();
    //char[]->txt
    char outfile_name[Buffer];
    cout<<"Please enter the output filename:";
    cin>>outfile_name;
    ofstream outfile;
    outfile.open(outfile_name);
    if(!outfile.is_open()){
        cout<<"读取文件失败"<<endl;
        exit(EXIT_FAILURE);
    }
    outfile.write(Buffer_data,sizeof(Buffer_data));
    outfile.close();
}
//char []->快链储存结构
void encoder(){
    int move=0;
    rownodeblock* temp_rownodeblock=head;
    bool is_break=false;
    //遍历缓冲区,存入块链
    for(int i=0;i<Maxrow&&move<=Buffer;i++){
        line_head[i]=new rownodeblock;
        temp_rownodeblock->rownext=line_head[i];
        line_head[i]->rowprior=temp_rownodeblock;
        temp_rownodeblock=temp_rownodeblock->rownext;
        nodeblock* temp_nodeblock=new nodeblock;
        line_head[i]->next=temp_nodeblock;
        for(int j=0;j<Maxlen;j++){
            if(temp_nodeblock->size==Buffer){
                temp_nodeblock->next=new nodeblock;
                temp_nodeblock=temp_nodeblock->next;
            }
            temp_nodeblock->word[j]=Buffer_data[move];
            move++;
            if(temp_nodeblock->word[j]=='\n'){
                break;
            }
            if(temp_nodeblock->word[j]=='\0'){
                is_break=true;
                break;
            }
            temp_nodeblock->size++;
        }
        rows++;
        if(is_break){
        break;
        }
    }
}
//快链储存结构->char []
void decoder(){
    
    int move=0;
    rownodeblock* temp_row=head->rownext;
    //遍历块链,存入缓冲区
    for(temp_row;temp_row!=nullptr;temp_row=temp_row->rownext){
        nodeblock* temp=temp_row->next;
        int position=0;
        while(temp!=nullptr){
            if(position>=Maxlen||temp->word[position]=='\0'){
                temp=temp->next;
                position=0;
            }
            if(temp==nullptr)
                break;
            Buffer_data[move]=temp->word[position];
            move++;
            position++;   
        }
    }
}

//字母变小写
char Tolower(char in){
    if(in>='A'&&in<='Z')
    in+='a'-'A';
    return in;
}
//命令b,到第一行
void begin(){
    cur_row=1;
    cur_row_pointer=head->rownext;
    view();
}
//命令e,到最后一行
void end(){
    cur_row=rows;
    while(cur_row_pointer->next!=nullptr){cur_row_pointer=cur_row_pointer->rownext;}
    view();
}
//命令c,替换指定词
void change(){
    cout<<"Enter the word you want to change:";
    char word_replaced[Maxlen];
    cin>>word_replaced;
    int word_replaced_size=size(word_replaced);//被替换字符串大小
    int position=0;//插入位置
    bool is_change=false;
    for(int i=0;i<cur_row_pointer->next->size-word_replaced_size+1;i++){
        position=0;
        for(int j=i;j<cur_row_pointer->next->size-word_replaced_size+1;j++){
            if(cur_row_pointer->next->word[j]==word_replaced[j]){
                position++;
            }
            else{
                break;
            }
        }
        if(position==word_replaced_size){
            is_change=true;
            position=i;
            break;
        }
    }
    if(!is_change){
        cout<<"There is no such word."<<endl;
        return ;
    }
    else{
        char word_new[Maxlen];
        cout<<"Enter the word you want to replace with:";
        cin>>word_new;
        int word_new_size=size(word_new);
        char temp[Maxlen];
        nodeblock* word_pointer=cur_row_pointer->next;
        for(int i=0;i<Maxlen;i++){
            temp[i]=word_pointer->word[i];
        }
        for(int i=position,j=0;i<position+word_new_size;i++,j++){
            word_pointer->word[i]=word_new[j];
        }
        for(int i=position+word_new_size,j=position+word_replaced_size;i<Maxlen&&j<Maxlen;i++,j++){
            word_pointer->word[i]=temp[j];
        }
        word_pointer->size+=word_new_size-word_replaced_size;
        view();
        cout<<endl;
    }
}
//命令d,删除改行
void del(){
    if(rows==0||cur_row==0){
        cout<<"Error,you can't delete anymore./This line"<<endl;
        return ;
    }
    rows--;
    rownodeblock* temp=cur_row_pointer;
    cur_row_pointer=cur_row_pointer->rowprior;
    cur_row_pointer->rownext=temp->rownext;
    if(cur_row_pointer->rownext!=nullptr)
        cur_row_pointer->rownext->rowprior=cur_row_pointer;
    cur_row--;
    delete temp->next;
    delete temp; 
    view();
} 
//命令f,全局搜索某词
void find(){
    cout<<"Enter the word you want to find:"<<endl;
    char word_find[Maxlen]={'\0'};
    cin>>word_find;
    int word_find_size=size(word_find);
    for(rownodeblock* move=head->rownext;move!=nullptr;move=move->rownext){//循环每一行
        nodeblock* word_move=move->next;
        char position_show[Maxlen]={' '};//指示词的位置
        for(word_move;word_move!=nullptr;word_move=word_move->next){
            int next[Maxlen];
            get_next(word_find,next,size(word_find));
            int j=1;
            int i=1;
            while(j<=size(word_find)&&i<=size(move->next->word))
            {
                if(j==0||move->next->word[i-1]==word_find[j-1])
                {
                    i++;
                    j++;
                }
                else
                j=next[j];
            }
            if(j>strlen(word_find)){
                int position=i-size(word_find)-1;
                for(int i=0;i<position;i++)
                position_show[i]=' ';
                for(int i=position;i<position+word_find_size;i++)
                position_show[i]='^';
                //显示位置
                if(move->rownext!=nullptr)
                    cout<<word_move->word;
                else
                    cout<<word_move->word<<endl;
                cout<<position_show<<endl;
            }
        }
    }
}
//用于kmp算法中计算出匹配不成功跳转的位置
void get_next(char str[],int* next,int strlen){//求srt串每一位点的最大相同前后缀
    int i=1;
    int j=0;
    next[1]=0;//没用next【0】是为了和主函数协调，主函数中j表示目前到达的srt串的位置，一旦j到达末端，那么表示两串吻合，搜索结束
    while(i<strlen)
    {
            if (str[i] == str[j])
            {
                i++;//后缀末端
                j++;//前缀末端
                next[i] = j;
            }
            else {
                if (j == 0) {
                    i++;
                    next[i] = 1;
                } else
                    j = next[j];
            }
    }
}

//命令go,跳转到指定行
void go(){
    cout<<"Which line do you want to go?";
    int go_line;
    cin>>go_line;
    if(go_line<1||go_line>rows){
        cout<<"There is no such line"<<endl;
        return ;
    }
    cur_row=go_line;
    rownodeblock* move=head;
    for(int temp=0;temp<go_line;temp++){
        move=move->rownext;
    }
    cur_row_pointer=move;
    view();
}
//命令i,插入指令
void insert(){
    cout<<"Please enter the row you want to insert:";
    int temp_row;
    cin>>temp_row;
    getchar();
    if(temp_row-rows>1){
        cout<<"Failed,you can only add line behind the last line in the file"<<endl;
        return ;
    }
    cur_row=temp_row;
    cur_row_pointer=head;//操作行数的指针
    //移动到目标行
    temp_row=0;
    while(temp_row<cur_row-1){
        cur_row_pointer=cur_row_pointer->rownext;
        temp_row++;
    }//移动到第cur_row行(第2行，指针移动两次)
    if(cur_row_pointer->rownext==nullptr){//插入到最后一行
        cur_row_pointer->rownext=new rownodeblock;
        cur_row_pointer->rownext->rowprior=cur_row_pointer;
    }
    else{//插入非最后一行
        rownodeblock* temp_rownodeblock=cur_row_pointer->rownext;
        cur_row_pointer->rownext=new rownodeblock;
        cur_row_pointer->rownext->rowprior=cur_row_pointer;
        cur_row_pointer->rownext->rownext=temp_rownodeblock;
        temp_rownodeblock->rowprior=cur_row_pointer->rownext;
    }   
    rows++;
    cur_row_pointer=cur_row_pointer->rownext;
    cout<<"Please enter the content you want to insert:";
    char temp_str[Maxlen];//这里Maxlen后续可以修改为无限大
    cin.getline(temp_str,Maxlen);
    char* move=temp_str;
    int position=0;//该快链操作字符的索引
    cur_row_pointer->next=new nodeblock;//建立快链
    nodeblock* temp_wordmove=cur_row_pointer->next;//操作该行的指针
    while(*move!='\0'){
        if(position==Maxlen){//如果该块装满了
            nodeblock* addwordmove=new nodeblock;
            temp_wordmove->next=addwordmove;
            temp_wordmove=temp_wordmove->next;
            position=0;
        }
        temp_wordmove->word[position]=*move;
        move++;
        position++;
        temp_wordmove->size++;
    }
    if(cur_row_pointer->rownext!=nullptr)
        temp_wordmove->word[position]='\n';
    else
        temp_wordmove->word[position]='\0';
    view();
}
//命令l，输出总共行数和该行word数
void length(){
    cout<<"There are "<<rows<<" lines in this file"<<endl;
    nodeblock* move=cur_row_pointer->next;
    int word_count=0;
    while(move!=nullptr){
        word_count+=move->size;
        move=move->next;
    }
    cout<<"Current line has "<<word_count<<" words"<<endl;
}
//命令p,移动到上一行
void prior(){
    if(cur_row_pointer->rowprior==head){
        cout<<"Warning: at start of lines"<<endl;
        return ;
    }
    cur_row_pointer=cur_row_pointer->rowprior;
    cur_row--;
    //输出该行内容
    view();
}
//命令n，移动到下一行
void next(){
    if(cur_row_pointer->rownext==nullptr){
        cout<<"Warning: at end of lines"<<endl;
        return ;
    }
    cur_row_pointer=cur_row_pointer->rownext;
    cur_row++;
    //输出该行内容
    view();
}
//命令v，显示该行内容
void view(){
    cout<<cur_row<<":";
    nodeblock* move=cur_row_pointer->next;
    while(move!=nullptr){
        cout<<move->word;
        move=move->next;
    }
}
//命令h,帮助指令:
void help(){
    cout<<"Valid commands are: b(egin) c(hange) d(el) e(nd)"<<endl;
    cout<<"f(ind) g(o) h(elp) i(nsert) l(ength) n(ext) p(rior)"<<endl;
    cout<<"q(uit) r(ead) s(ubsitute) v(iew) w(rite)"<<endl;
}
//命令s,替换指定行
void substitute(){
    cout<<"Which line do you want to substitute?";
    int sub_line;
    cin>>sub_line;
    getchar();
    if(sub_line<1||sub_line>rows){
        cout<<"There is no such line"<<endl;
        return ;
    }
    cout<<"What you want to substutite with?";
    char sub_content[Maxlen];
    cin.getline(sub_content,Maxlen);
    cur_row=sub_line;
    rownodeblock* row_move=head;
    for(int temp=0;temp<sub_line;temp++){
        row_move=row_move->rownext;
    }
    cur_row=sub_line;
    cur_row_pointer=row_move;
    nodeblock* word_move=row_move->next;
    char* being_sub_pointer=word_move->word;
    char* sub_pointer=sub_content;
    while(*sub_pointer!='\0'){
        *being_sub_pointer=*sub_pointer;
        being_sub_pointer++;
        sub_pointer++;
    }
    if(cur_row_pointer->next==nullptr)
        *being_sub_pointer='\0';
    else{
        *being_sub_pointer='\n';
        *++being_sub_pointer='\0';
    }
    word_move->size=size(sub_content);
    view();
}
//返回大小
int size(char* str){
    int str_size=0;
    while(*str){
        str_size++;
        str++;
    }
    return str_size;
}
}
;