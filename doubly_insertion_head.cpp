#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrToLL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    } 
    cout<<endl;
}

Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* prev = head;
    head = head->next;
    prev->back=nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}

Node* InsertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}

int main(){
    vector<int>arr = {12,5,8,7};
    Node* head = convertArrToLL(arr);
    print(head);
    head = InsertBeforeHead(head,3);
    print(head);
    return 0;
}