#include <iostream>
#include <string>
using namespace std;

class node{
    public:
    int noMhs;
    node *next;
    node *prev;
};

class doublelinkedlist{
    private:
    node *START;

    public:
    doublelinkedlist(){
        START = NULL;
    }

    void addnode(){
        int nim;
        string nim;
        cout << "\nEnter the roll number of the student";
        cin >> nim;
    }

};
