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

Node* insertBeforeX(Node* head,int x,int el){
    if(head==NULL)return NULL;
    if(head->data==x) return new Node(el,head);
    Node* temp = head;
    while(temp->next){
    if(temp->next->data==x){
        Node* val = new Node(el,temp->next);
        temp->next = val;
        break;
    }
    temp=temp->next;
}
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrToLL(arr);
    print(head);
    head = insertBeforeX(head,2,1);
    print(head);
    return 0;
} 