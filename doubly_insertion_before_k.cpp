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

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}

Node* InsertBeforeTail(Node* head, int val){
    if(head->next == NULL) return insertBeforeHead(head,val);
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val,tail,prev); 
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBeforeK(Node* head, int k, int val){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }

    if (k <= 1) return insertBeforeHead(head, val);

    else if(temp == NULL){
        return InsertBeforeTail(head, val);
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode; 
    return head;
}

int main(){
    vector<int>arr = {12,5,8,7};
    Node* head = convertArrToLL(arr);
    print(head);
    head = insertBeforeK(head,4,9);
    print(head);
    return 0;
}