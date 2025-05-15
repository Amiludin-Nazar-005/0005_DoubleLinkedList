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
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed " << endl;
                return;
            }
            // step 4: newnode.next = start
            newNode->next = START;

            // step 5 : start . prev
            if (START != NULL)
                START->prev = NULL;

            newNode->prev = NULL

                START = newNode;
            return;
        }
        node * current = START;
        while (current-> next != NULL && current -> next-> noMhs < nim ){
            current = current -> next;
        }
        if (current -> next != NULL && nim == current ->next->noMhs){
            cout << "\nDuplicate roll number not allowed"<< endl;
            return;
        }

        newNode->next = current -> next;
        newNode-> prev = current;
    }
};