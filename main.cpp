#include <iostream>
#include "Container.h"

using namespace std;

int main(/*int argc, char* argv[]*/) {
/*
    if(argc !=3)
    {
        cout << "incorrect command line! "
                "Waited: command in_file out_file"
             << endl;
        exit(1);
    }

    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
*/
    ifstream ifst(R"(D:\Study\ProgrammTehnology\Lab1\OOP\In.txt)");
    ofstream ofst(R"(D:\Study\ProgrammTehnology\Lab1\OOP\Out.txt)");

    if(!ifst) {
        cout << "No input file found!" << endl;
        return 0;
    }
    if(!ofst) {
        cout << "No output file found!" << endl;
        return 0;
    }

    cout << "Start"<< endl;
    container c;
    c.In(ifst);
    ofst << "Filled container. " << endl;
    c.Lenotext(ofst);
    c.Sort();
    c.Out(ofst);
    c.OutRep(ofst);
    c.Clear();
    ofst << "Empty container. " << endl;
    c.Out(ofst);
    cout << "Stop"<< endl;
    return 0;
}
