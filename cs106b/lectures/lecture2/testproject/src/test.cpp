//populate a vector

//headers
#include<iostream>
#include "console.h"
#include "simpio.h"
#include<unistd.h>
//for file
#include<fstream>
#include"filelib.h"

using namespace std;


//main
int __main(){
//    int a;
    string s;
//    a=getInteger("please inputa an integer:","that wasn't an integer");
//    s=getLine("please type a string:");
//    cout<<"your integer:"<<a<<endl;
//    cout<<"your string:"<<s<<endl;

//    getcwd(buffer,)
    ifstream stream;
    cout<<"current working dirctory: "<<
    openFile(stream, "./readme.txt");
    getline(stream,s);
//    cout<<"the dir is:"<<
    cout<<"the first line of the file is:"\
       <<s<<endl;

    return 0;
}
