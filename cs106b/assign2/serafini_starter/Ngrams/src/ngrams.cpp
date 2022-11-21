// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include"map.h"
#include"vector.h"
#include"simpio.h"
#include"strlib.h"

using namespace std;
void welcome();
void getInputFile(fstream& input,string& filename, int gramN);
Map<Vector<string>,Vector<string>> generateNgram(const int gramN,fstream& input);
int main() {
    // TODO: Finish the program!
    fstream input;//input
    string filename;
    int gramN=0;
    Map<Vector<string>,Vector<string>> ngramMap;
    welcome();
    getInputFile(input,filename,gramN);
    ngramMap= generateNgram(gramN,input);
    cout<<ngramMap;


    cout << "Exiting." << endl;
    return 0;
}
void welcome(){
    cout<<"Welcome to CS 106B Random Writer ('N-Grams').\n\
    This program makes random text based on a document. \n\
    Give me an input file and an 'N' value for groups \n\
    of words, and I'll create random text for you."<<endl;
}

void getInputFile(fstream& input,string& filename, int& gramN){

    do{
        filename=getLine("Input file name?");
        input.open(filename);
        if(!input.is_open()){
            cout<<"Unable to open that file.  Try again."<<endl;
        }
    }while(!input.is_open());

    do{
        gramN=getInteger("Value of N?");
        if(gramN<2){
            cout<<"N must be 2 or greater."<<endl;
        }

    }while(gramN<2);

}
Map<Vector<string>,Vector<string>> generateNgram(const int gramN,fstream& input){
    Map<Vector<string>,Vector<string>> ngramMap;
    string word;
    Vector<string> wordlist;
    Vector<string> window,suffix;
    while(input>>word){
        wordlist.add(word);
    }
    for(int i=0;(i=wordlist.size());i++){
        window.clear();
        for(int j=i;j<i+gramN-1;j++){
            window.add(wordlist[j%wordlist.size()]);
        }
        suffix.add(wordlist.get(i+gramN));
        ngramMap.put(window,suffix);
    }
    return ngramMap;
}
