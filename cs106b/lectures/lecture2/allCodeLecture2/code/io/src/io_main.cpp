#include <iostream>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "filelib.h"

using namespace std;

int main() {
    int a;
    string s;

    // read from the keyboard
    a = getInteger("Please enter an integer: ","That wasn't an integer!");
    s = getLine("Please type in a string: ");
    cout << "Your integer: " << a << endl;
    cout << "Your string: " << s << endl;

    // read from a file
    ifstream stream;
    openFile(stream, "readme.txt");
    getline(stream,s);
    cout << "The first line of the file is: " << s << endl;
    stream.close();
    return 0;
}
