// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include"simpio.h"
#include"lexicon.h"
#include"stack.h"
#include"queue.h"
#include"hashset.h"
using namespace std;
//-----------------data----------------------
fstream dictfile;
Lexicon dictionary;
string startword,endword;
string dictname;
//-----------------func----------------------
//bool inDict(string newword);--> this is covered in lexicon
void welcome();
void loadDic(fstream& inFile, string& filename, Lexicon& dict);
bool LoadWord(string&s, string& e);
bool checkWord(string&s, string& e, const Lexicon& dic);
void findWord(string& startword,string& endword,const Lexicon& dic);

//------------------main---------------------
int main() {
    welcome();
    // read file dict
    loadDic(dictfile,dictname,dictionary);
    //loadWord
    while(LoadWord(startword,endword))
    {
        findWord(startword,endword,dictionary);
    }

    cout << "Have a nice day." << endl;
    return 0;
}
void welcome(){
    cout << "Welcome to CS 106B Word Ladder.\n"
            << "Please give me two English words, and I will change the\n"
            << "first into the second by changing one letter at a time.\n\n";
}

void loadDic(fstream& inFile, string& filename, Lexicon& dict)
{
    string dir="./res/";
    do{
        filename=dir+filename;
        inFile.open(filename);

    }while(inFile.fail());
    dict=Lexicon(inFile);
    //Lexion dict(filename)
}
bool LoadWord(string&s, string& e){
    s=getLine("Word #1 (or Enter to quit):");
    if(s.empty()) {return false;}
    e=getLine("Word #2 (or Enter to quit):");
    if(e.empty()) {return false;}
    s=toLowerCase(s);
    e=toLowerCase(e);
    return true;
}


bool checkWord(string&s, string& e, const Lexicon& dic){
    if(s.length()!=e.length()){
        cout<<"The two words must be the same length.\n";
        return false;
    }else if(!dic.contains(e)||!dic.contains(s)){
         cout << "The two words must be found in the dictionary.\n";
         return false;
    }else if(s==e){
        cout << "The two words must be different.\n";
        return false;
    }

    return true;
}
void findWord(string& startword,string& endword,const Lexicon& dic){
    if(!checkWord(startword,endword,dic)) return;
    Stack<string> ladder{startword};
    Queue<Stack<string>> Ladder{ladder};
    HashSet<string> usedWords{startword};


}
