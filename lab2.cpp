#include <iostream>
using namespace std;

class Node
{
private:
    int object;
    Node *nextNode;

public:
    int num_get() { return object; };
    void num_set(int object) { this->object = object; };
    Node *getNext() { return nextNode; };
    void setNext(Node *nextNode) { this->nextNode = nextNode; };
};

class Stack_array
{
public:
    Stack_array()
    {
        size = 5;
        current = -1;
    }                                              // constructor
    int pop_array() { return A[current--]; }       // The pop function
    void push_array(int x) { A[++current] = x; }   // The push function
    int isEmpty() { return (current == -1); }      // Will return true when stack is empty
    int isFull() { return (current == size - 1); } // Will return true when stack is full
private:
    int object;  // The data element
    int current; // Index of the array
    int size;    // max size of the array
    int A[5];    // Array of 5 elements
};

class stack_linkedlist
{
private:
    Node *head;

public:
    void push_list(int n);
    int pop_list();
};
// pushing elements into stack
void stack_linkedlist ::push_list(int n)
{

    Node *newNode = new Node();
    newNode->num_set(n);
    newNode->setNext(head);
    head = newNode;
}
// poping elements from stack and displaying values
int stack_linkedlist ::pop_list()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
    }
    int x = head->num_get();
    Node *p = head;
    head = head->getNext();
    delete p;
    cout << "  \n"
         << x;
    return x;
}

int main()
{
    int n = 0; // option
    int k;     // total number to be entered in linked list
    int j;     // used to push elements in linked list
    int m;     // used to push elements in linked list
    stack_linkedlist s;
    Stack_array sa;
    while (n < 5)
    {
        cout << "\n Enter Your Choice \n";
        cout << "1 : Add Stack Element in linked list \n";
        cout << "2 : Add Stack Element in array \n";
        cout << "3 : Pop Stack Elements in linked list and display \n";
        cout << "4 : Pop Stack Elements in array and display \n";
        cout << "Enter any other number to Close the program \n";

        scanf("%d", &n);

        switch (n)
        {
        case 1:
            cout << "Enter the total number you want to entered \n";
            cin >> k;
            cout << "Please enter the numbers \n";
            for (int i = 1; i <= k; i++)
            {
                cin >> j;
                s.push_list(j); // push the element at the top
            }
            cout << "Numbers added in linked list successfully \n";
            break;
        case 2:
            if (sa.isFull()) // checking stack is full or not
                cout << "\n Stack is full, can't insert new element";
            else
            {
                cout << "You can enter 5 numbers only in array \n";
                for (int i = 0; i < 5; i++)
                {
                    cin >> m;
                    sa.push_array(m); // push the element at the top
                }
            }
            break;
        case 3:
            cout << "The reverse of input in linked list is"
                 << "\n";
            for (int i = 1; i <= k; i++)
            {
                s.pop_list();
            }
            break;
        case 4:
            cout << "The reverse of input in array is"
                 << "\n";
            for (int i = 0; i < 5; i++)
            {
                if (!sa.isEmpty()) // checking stack is empty or not
                    cout << "\n " << sa.pop_array();
                else
                    cout << "\n Stack is empty, can't pop";
            }
        default:
            break;
        }
    }
    return 0;
}