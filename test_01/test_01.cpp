#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

class List
{
    Node *Head;
public:
    List() { Head=NULL; }
    ~List();
    void Add(int x);
    void Show();
    Node * reverse( Node * head);
};

List::~List() {
    while(Head!=NULL) {
        Node *temp = Head->next;
        delete Head;
        Head = temp;
    }
}

void List:: Add(int x) {
    Node *temp = new Node;
    temp-> data = x;
    temp-> next = Head;
    Head = temp;
}

void List::Show()
{
    Node *temp = Head;
    while(temp!= NULL) {
        cout<< temp->data<<"";
        temp = temp->next;
    }
}
Node * List:: reverse( Node * head) {
    Node *reversed_list = NULL;
    for (Node *node = head, *next_nod; node !=NULL; node = next_nod) {
        next_nod = node->next;
        node->next = reversed_list;
        reversed_list = node;
    }
    return reversed_list;
}

int main(){
        return 0;
}
