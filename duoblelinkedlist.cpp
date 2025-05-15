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

            newNode->prev = NULL;

            START = newNode;

            return;
        }
        node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }
        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll number not allowed" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
    }
    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        cout << "\nEnter roll number of the student whose record is to be deleted";
        int rollNO;
        cin >> rollNO;

        node *current = START;
        while (current != NULL && current->noMhs != rollNO)
            current = current->next;
        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            delete current;
            cout << "record with roll number " << rollNO << "deleted" << endl;
        }
    }
    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        node *currentnode = START;

        cout << "\nRecord is accending oerder of roll number are: \n";
        int i = 0;
        while (currentnode != NULL)
        {
            cout << i + 1 << ". " << currentnode->noMhs << " " << endl;
            currentnode = currentnode->next;
        }
    }
    void retraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        node *currentnode = START;
        int i = 0;
        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
            i++;
        }
        cout << "\nRecord is descending order of roll number are: \n";
        while (currentnode != NULL)
        {
            cout << i + 1 << ". " << currentnode->noMhs << " " << endl;
            currentnode = currentnode->prev;
            i++;
        }
    }
    void searchdata()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        int rollNO;
        cout << "\nEnter the roll number to search : ";
        cin >> rollNO;

        node *current = START;
        while (current != NULL && current->noMhs != rollNO)
            current = current->next;

        if (current == NULL)
        {
            cout << "record not found\n";
        }
        else
        {
            cout << "record found\n";
            cout << "roll number: " << current->noMhs << endl;
        }
    }
};
int main()
{
    doublelinkedlist list;
    char choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add record\n";
        cout << "2. delete record\n";
        cout << "3. view ascending\n";
        cout << "4. view descending\n";
        cout << "5. search record \n";
        cout << "6. exit \n";
        cout << "enter your choice:";

        cin >> choice;
        switch (choice)
        {
        case '1':
            list.addnode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.retraverse();
            break;
        case '5':
            list.searchdata();
            break;
        case '6':
            return 0;
        default:
            cout << "invalid option\n";
        }
        cout << "\nPress enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
       
    } while(choice != '6');
}
