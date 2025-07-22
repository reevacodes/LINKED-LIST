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

Node* insertionAtK(Node* head,int K,int el){
    if(head==NULL){
        if(K==1) return new Node(el);
        else return NULL;
    }
    if(K==1){
        Node* temp = new Node(el,head);
        return temp;
    }
    Node* temp = head;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt == K-1){
            Node* k = new Node(el);
            k->next = temp->next;
            temp->next=k;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrToLL(arr);
    print(head);
    head = insertionAtK(head,3,6);
    print(head);
    return 0;
} 