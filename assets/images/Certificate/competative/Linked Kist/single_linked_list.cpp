#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;


    }
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};
void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}
void insert_at_head(Node * &head,int data)
{
    Node * temp=new Node(data);
    temp->next=head;
    head=temp;

}
void display(Node * &head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<< temp->data<<endl;
        temp=temp->next;
    }
}
void insert_at_tail(Node * &tail,int data)
{
    Node *temp=new Node(data);
    tail->next=temp;
    tail=temp;

}
void insert_at_postion(Node * &head,int data,int postion)
{
    if (postion==1)
    {
        insert_at_head(head,data);
    }
    else{

    Node * temp=new Node(data);
    Node * prev=head;
    int t=postion-2;
    while(t--)
    {
        prev=prev->next;

    }
    temp->next=prev->next;
    prev->next=temp;
    }



}

int main()
{
    
    Node * node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    // insert_at_head(head,12);
    // insert_at_head(head,22);
    insert_at_tail(tail,22);
    insert_at_tail(tail,32);
    insert_at_postion(head,1,2);
    display(head);
    deleteNode(3,head);
    display(head);
    
}