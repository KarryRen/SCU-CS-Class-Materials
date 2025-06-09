#include "editor.h"
int main(int argc,const char* argv[]){
    editor e;
    bool is_quit=false; 
    e.load();
    while(true){
            cout<<"Your commands:";
            char mode;//操作指令
            cin>>mode;
            char command=e.Tolower(mode);
            switch (command){
                case 'b':
                    e.begin();
                    break;
                case 'c':
                    e.change();
                    break;
                case 'd':
                    e.del();
                    break;
                case 'e':
                    e.end();
                    break;
                case 'f':
                    e.find();
                    break;
                case 'g':
                    e.go();
                    break;
                case 'h':
                    e.help();
                    break;
                case 'i':
                    e.insert();
                    break;
                case 'l':
                    e.length();
                    break;
                case 'n':
                    e.next();
                    break;
                case 'p':
                    e.prior();
                    break;
                case 'q':
                    is_quit=true;
                    break;
                case 's':
                    e.substitute();
                    break;
                case 'v':
                    e.view();
                    break;
                case '?':
                    e.help();
                    break;
                default:
                    cout<<"Plaese use the correct command,or tab h/H/?"<<endl;//显示所有命令对应功能
            }
            if(is_quit){
                e.save();
                break;
            }
    }
    return 0;
}