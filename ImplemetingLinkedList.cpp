#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
    this -> data = data;
    this -> next = NULL;

    }
};

//insert at head
void InsertAtFirst(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

//insert at tail
void InsertAtLast(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}

//insert at any position
void InsertAtPosition(Node* &head ,int d, int n){

    if(n == 1){
        InsertAtFirst(head, d);
        return;
    }
    Node* temp = head;
    int cnt =1;
    while( cnt < n-1){
        temp = temp -> next;
        cnt++;
    }

    //creating a node for d
    Node* NodeToInsert = new Node(d); 
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;

}
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
    cout<< temp -> data << " ";
    temp = temp -> next;
    }
}
int main()
{ 
    //created a new node
    Node* node1 =  new Node(10);
    //point head to the new node 
    Node* head = node1;
    Node* tail = node1;
    InsertAtLast(tail, 12);
    InsertAtLast(tail, 15);
    InsertAtPosition(head, 13, 3);
    printLL(head);
return 0;
}