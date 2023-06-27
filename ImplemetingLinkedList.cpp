#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtFirst(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void InsertAtTail(Node* &tail,Node* &head, int d){
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
void InsertAtAnyPosition(Node* &head, int n, int d){
    if(n ==1){
        InsertAtFirst(head, d);
        return;
    }
    Node* temp = head;
    int cnt =1;
    while( cnt < n-1 ){
        temp = temp -> next;
        cnt++;
    }
    Node* NodeToInsert = new Node(d); 
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
}

void reverseLL(Node* &head, Node* &tail){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    tail = head;
    head = prev;
}

void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data<<" ";
        temp = temp -> next;
    }

}
int main()
{
    Node* n1 = new Node(20);
    Node* head = n1;
    Node* tail = n1;
    InsertAtTail(tail,head, 40);
    InsertAtFirst(head, 10);
    InsertAtAnyPosition(head,3,30);
    printLL(head);
    cout<<endl;
    reverseLL(head,tail);
    printLL(head);
return 0;
}

//output : 10 20 30 40
//         40 30 20 10
