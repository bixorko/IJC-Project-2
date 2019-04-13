///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                               tail2.cpp                             ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <queue>
using std::queue;
#include <iostream>
using std::cout;
using std::cin;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::getline;

int fileLoad(const char *filename);
int stdinLoad(queue<string>& q);
void printDefaultTail(char *argv[]);
void printDefaultTailStdin();
void printDefaultN(char *argv[]);
void printDefaultNFile(char *argv[]);

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);

    //TODO DOROBIT '+' TAIL
    if (argc == 1)
        printDefaultTailStdin();

    //TODO DOROBIT '+' TAIL
    else if (argc == 2)
        printDefaultTail(argv);

    //TODO DOROBIT '+' TAIL
    else if (argc == 3)
        printDefaultN(argv);

    //TODO DOROBIT '+' TAIL
    else if (argc == 4){
        printDefaultNFile(argv);
    }

    else{
        fprintf(stderr, "Zle zadane argumenty!\n");
        return -1;
    }

    return 0;
}

int fileLoad(const char *filename)
{
    ifstream myfile(filename);
    string line;
    int count = 0;
    while (getline(myfile, line)){
        count++;
    }

    return count;
}

int stdinLoad(queue<string>& q)
{
    int count = 0;
    string line;

    while (getline(cin, line)){
        count++;
        q.push(line);
    }

    return count;
}

void printDefaultTail(char *argv[])
{
    int count = fileLoad(argv[1]);
    ifstream myfile(argv[1]);
    string line;

    for (int i = 0; i < count - 10; i++) {
        getline(myfile, line);
    }

    while (getline(myfile, line)){
        cout << line << "\n";
    }
}

void printDefaultTailStdin()
{
    queue<string> q;
    int count = stdinLoad(q);

    for (int i = 0; i < count - 10; i++) {
        q.pop();
    }

    while(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
    }
}

void printDefaultN(char *argv[])
{
    queue<string> q;
    int count = stdinLoad(q);

    for (int i = 0; i < count - (strtol(argv[2],NULL,10)); i++) {
        q.pop();
    }

    while(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
    }
}

void printDefaultNFile(char *argv[])
{
    int count = fileLoad(argv[3]);
    ifstream myfile(argv[3]);
    string line;

    for (int i = 0; i < count - (strtol(argv[2],NULL,10)); i++) {
        getline(myfile, line);
    }

    while (getline(myfile, line)){
        cout << line << "\n";
    }
}