// Implementation of Queue using Linked List
#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    int get() const
    {
        return data;
    }

    void set(int object)
    {
        data = object;
    }

    Node *getNext() const
    {
        return next;
    }

    void setNext(Node *nextNode)
    {
        next = nextNode;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;

    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x)
    {
        Node *newNode = new Node();
        newNode->set(x);
        newNode->setNext(nullptr);

        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1; // Return a special value indicating an empty queue
        }

        Node *temp = front;
        int value = temp->get();

        front = front->getNext();

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        return value;
    }

    void display() const
    {
        Node *current = front;

        while (current != nullptr)
        {
            cout << current->get() << " ";
            current = current->getNext();
        }

        cout << endl;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }
};

int main()
{
    int n, k;
    Queue Q;
    cout << "Enter the total numbers you want to enter \n";
    cin >> k;
    cout << "Enter numbers randomly \n";
    for (int i = 1; i <= k; i++)
    {
        cin >> n;
        if (n % 2 == 0)
            Q.enqueue(n); // calling Enqueue for insertion
    }
    cout << "The even numbers are \n";
    Q.display();
    Q.dequeue(); // calling dequeue
    cout << "After Removing the first Even number\n";
    Q.display();
    return 0;
}