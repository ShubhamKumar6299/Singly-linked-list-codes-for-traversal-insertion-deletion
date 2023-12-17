

//3rd attemp to learn single linked lists
// #include<RadheRadhe
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"the memory is free for tha value "<<value<<endl;
    }

};

void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node* &head)
{
    Node* temp = head;
    if(temp == NULL)
    {
        cout<<"there is nothing to print as it is empty";
        return;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node* &tail, Node* &head, int position, int d)
{
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while(cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    //creating node to insert at position other than first or last
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail, int position)
{
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        //deleting any other node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deleteWithValue(Node* &head,Node* &tail, int value)
{
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL)
    {
        if(temp->data != value)
        {
            temp = temp->next;
            cnt++;
        }
        else if(temp->data == value)
        {
            deleteNode(head,tail,cnt);
        }
        else{
            cout<<"The value is not present in the linked list"<<endl;
        }

    }
    
    
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head ,20);
    print(head);
    insertAtTail(tail,51);
    insertAtTail(tail,1234);
    insertAtTail(tail,234);
    insertAtTail(tail,23);
    print(head);
    insertAtPosition(tail, head, 2,345);
    print(head);
    /*
    deleteNode(head,tail,3);
    print(head);
    cout<<"head data"<<head->data<<endl;
    cout<<"tail data"<<tail->data<<endl;
    deleteNode(head,tail,6);
    print(head);
    cout<<"head data"<<head->data<<endl;
    cout<<"tail data"<<tail->data<<endl;
    deleteNode(head,tail,5);
    print(head);
    cout<<"head data"<<head->data<<endl;
    cout<<"tail data"<<tail->data<<endl;
    */
   deleteWithValue(head,tail,23);
   
   print(head);
    

    
}
