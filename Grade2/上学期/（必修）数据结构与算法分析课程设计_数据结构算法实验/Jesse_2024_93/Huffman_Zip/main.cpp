#include "Huffman.h"

int main(int argc,const char* argv[]){
    char command;
    Huffman zipper;
    cout<<"Please enter the operation(tap z(ip) or d(ezip)"<<endl;
    cin>>command;
    switch (command)
    {
    case 'z':
        zipper.encoder();
        break;
    case 'd':
        zipper.decoder();
        break;
    default:
        cerr<<"You input the wrong command"<<endl;
        return -1;
    }
    return 0;
}