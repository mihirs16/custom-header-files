#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std; 
  
int main(int argc, char** argv) 
{ 
    if (argc != 4) {
        cout << "To compile and run .cpp -> .\\crun [c/cpp] [path-to-file] [filename]";
        return 0;
    }

    string pathToCompile = argv[2];
    string fileToCompile = argv[3];
    string cpp = "cpp";
    string c = "c";

    if (argv[1] == cpp) {
        string compileCMD = "g++ ." + pathToCompile + "\\" + fileToCompile + ".cpp" + " -o " + "." + pathToCompile + "\\" + fileToCompile;
        string runCMD = "." + pathToCompile + "\\" + fileToCompile;

        cout << "compiling::" << pathToCompile + "\\" + fileToCompile + ".cpp" << endl;
        cout << "running::" << pathToCompile + "\\" + fileToCompile + ".exe" << endl;

        system ((compileCMD).c_str());
        system ((runCMD).c_str());
    } else if (argv[1] == c) {
        string compileCMD = "gcc ." + pathToCompile + "\\" + fileToCompile + ".cpp" + " -o " + "." + pathToCompile + "\\" + fileToCompile;
        string runCMD = "." + pathToCompile + "\\" + fileToCompile + ".exe";

        cout << "compiling::" << pathToCompile + "\\" + fileToCompile + ".cpp" << endl;
        system ((compileCMD).c_str());
        cout << "running::" << pathToCompile + "\\" + fileToCompile + ".exe" << endl;
        system ((runCMD).c_str());
    }

    return 0; 
} 