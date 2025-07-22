#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrToLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp =new Node(arr[i]);
        mover->next = temp;
        mover=temp;     //mover=mover->next
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

Node* insertionAtLast(Node* head,int el){
    if(head==NULL)return new Node(el);
    Node* temp = head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next = new Node(el);
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrToLL(arr);
    print(head);
    head = insertionAtLast(head,1);
    print(head);
    return 0;
} 