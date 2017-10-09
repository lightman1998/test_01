#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    int data;
};

template <class T>
class LinkedList{
public:
    LinkedList():head(0), tail(0){};
    ~LinkedList();

    void push_back(T val);
    void push_front(T val);
    void reverse();
    void display() const;
private:
    Node * head;
    Node * tail;
};
template <class T>
void LinkedList<T>::push_front(T val)
{
    Node * newNode = new Node;

    newNode->data = val;
    newNode->next = head;

    head = newNode;

    if(tail==0)
        tail = head;
}
template <class T>
void LinkedList<T>::push_back(T val)
{
    Node * newNode = new Node;

    newNode->data = val;
    newNode->next = 0;

    if(tail==0)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    Node * tmp;
    while(head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}
template <class T>
void LinkedList<T>::display() const
{
    Node * current = head;

    while(current)
    {
        cout<<current->data<<' ';
        current = current->next;
    }
}
template <class T>
void LinkedList<T>::reverse()
{
    if (head == 0)
        return;

    tail = head;

    Node * current = head->next;
    tail->next = 0;
    Node * right;

    while(current)
    {
        right = current->next;

        current->next = head;
        head = current;
        current = right;
    }

    tail->next = 0;
}

int main()
{
    LinkedList<int> intList;

    intList.push_front(3);
    intList.push_front(2);
    intList.push_front(1);

    intList.push_back(4);
    intList.push_back(5);
    intList.push_back(6);

    cout << "Normal: ";
    intList.display();

    intList.reverse();

    cout << "\nReversed: ";
    intList.display();

    cout << endl;
    //system("pause");
    return 0;
}
