#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor

    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }

        cout<<"Memory is free with data "<<value<<endl;
    }
};

//INSERTION

//insertion at head
void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next=head;
    head = temp;
}

//insertion at tail(last)
void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//insert at Position
void insertAtPosition(Node* &head,Node* &tail,int position,int data){
    Node* temp = head;

    //inserting at start
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    int count = 1;
    while(count < position-1){
        temp= temp->next;
        count++;
    }

    //inserting at last
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

//DELETION

void deleteAtPosition(Node* &head,Node* &tail,int position){

    //if first node is to be deleted
    if(position == 1){
        Node* temp = head;
        head = temp->next;

        //doing this to delete the node from memory
        temp->next = NULL;
        delete temp;
    }

    //if element is middle or last
    else{
    Node* curr = head;
    Node* prev = NULL;
    int count = 1;
    while(count<position){
        prev = curr;
        curr = curr->next;
        count++;
    }
    if(curr->next == NULL){
        tail = prev;
    }
    prev->next = curr->next;

    //doing this to delete the node from memory
    curr->next = NULL;
    delete curr;
    }
}


//TRAVERSAL
//printing the linked list
void printList(Node* &head){

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        cout<<"next is "<<temp<<endl;
    }
    cout<<endl;
}


int main(){

    //creating node type pointer for first node.
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    //declaring node 1 as head
    Node* head = node1;
    //Printing nodes after adding in front
    // printList(head);
    // insertAtHead(head,12);
    // printList(head);
    // insertAtHead(head,13);
    // printList(head);

//Declaring tail at head
    Node* tail = node1;
   // printList(head);
    insertAtTail(tail,12);
    //printList(head);
    insertAtTail(tail,13);
    printList(head);

   // insertAtPosition(head,tail,4,65);
 //   printList(head);
    // cout<<"Tail "<<tail->data<<endl;
    // cout<<"Head "<<head->data<<endl;
    deleteAtPosition(head,tail,3);
    printList(head);
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Head "<<head->data<<endl;

}