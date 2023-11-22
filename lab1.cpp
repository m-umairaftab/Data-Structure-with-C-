#include <iostream>
using namespace std;
class Faculty
{
    string name, post;
    int age;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setPost(string post)
    {
        this->post = post;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    string getName()
    {
        return name;
    }
    string getPost()
    {
        return post;
    }
    int getAge()
    {
        return age;
    }
};
class Node
{
    Faculty object;
    Node *nextNode;

public:
    void set(Faculty object)
    {
        this->object.setName(object.getName());
        this->object.setPost(object.getPost());
        this->object.setAge(object.getAge());
    }
    Faculty get()
    {
        return object;
    }
    void setNext(Node *nextNode)
    {
        this->nextNode = nextNode;
    }
    Node *getNext()
    {
        return nextNode;
    }
};
class List
{
    int size;
    Node *headNode;
    Node *currentNode;

public:
    List();
    void add(Faculty addObject);
    Faculty get();
    bool next();
    friend void traverse(List list);
};
/* Constructor */
List::List()
{
    headNode = new Node();
    headNode->setNext(NULL);
    currentNode = NULL;
    size = 0;
}
void List::add(Faculty addObject)
{
    Node *newNode = new Node();
    newNode->set(addObject);
    if (currentNode != NULL)
    {
        newNode->setNext(currentNode->getNext());
        currentNode->setNext(newNode);
        currentNode = newNode;
    }
    else
    {
        newNode->setNext(NULL);
        headNode->setNext(newNode);
        currentNode = newNode;
    }
    size++;
}

/* get() class method */
Faculty List::get()
{
    if (currentNode != NULL)
        return currentNode->get();
}

/* next() class method */
bool List::next()
{
    if (currentNode == NULL)
        return false;
    currentNode = currentNode->getNext();
    if (currentNode == NULL || size == 0)
        return false;
    else
        return true;
}

/* Friend function to traverse linked list */
void traverse(List list)
{
    Node *savedCurrentNode = list.currentNode;
    list.currentNode = list.headNode;
    cout << "=============Display Faculty Information=================" << endl
         << endl;
    for (int i = 1; list.next(); i++)
    {
        Faculty member;
        member = list.get();
        cout << "Name : " << member.getName() << endl;
        cout << "Age : " << member.getAge() << endl;
        cout << "Post : " << member.getPost() << endl;
    }
    list.currentNode = savedCurrentNode;
}
int main()
{
    Faculty member;
    string name, post;
    List list;
    int age;
    cout << " ========== Enter Faculty Information ==========\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Faculty member age : \n";
        cin >> age;
        cout << "Enter Faculty member name : \n";
        cin >> name;
        if (age >= 25 && age <= 35)
        {
            post = "Lecturer";
        }
        if (age >= 36 && age <= 45)
        {
            post = "Assistant Professor";
        }
        if (age >= 46 && age <= 60)
        {
            post = "Professor";
        }
        member.setName(name);
        member.setAge(age);
        member.setPost(post);
        list.add(member);
    }
    traverse(list);

    return 0;
}