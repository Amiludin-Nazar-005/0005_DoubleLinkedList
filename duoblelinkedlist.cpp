#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
    node *prev;
};

class doublelinkedlist
{
private:
    node *START;

public:
    doublelinkedlist()
    {
        START = NULL;
    }

    void addnode()
    {
        int nim;
        string nim;
        cout << "\nEnter the roll number of the student";
        cin >> nim;

        // step 1: allcate memory for new node
    node *newNode = new node();

    // step 2 : assign value to the data fields
    newNode->noMhs = nim;

    // step 3: insert st beginning
    if (START == NULL || nim <= START->noMhs){
        if (START != NULL && nim == START->noMhs){
            cout << "\nDuplicate number not allowed "<< endl;
            return;
        }
    }
    // step 4: newnode.next = start
    newNode->next = START;
    }

};