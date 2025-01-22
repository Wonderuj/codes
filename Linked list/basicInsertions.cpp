#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* next;

    Node(int v){
        val=v;
        next=NULL;
    }
};

void traverse(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->val<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

void insertHead(Node* &head, int val){

    Node * newNode= new Node(val);
    newNode->next=head;
    head=newNode;
}

void insertEnd(Node* &head, int val){

    if(head==NULL){
        insertHead(head, val);
        return;
    }

    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }  //now temp wil be at last node

    Node* newNode= new Node(val);
    temp->next=newNode;
    newNode->next=NULL;
}

void insertMiddle(Node* &head, int val, int k){
    if(k==1){
        insertHead(head,val);
        return;
    }

    Node* newNode=new Node(val);
    Node* prev=head;
    int cnt=1;
    while(cnt<(k-1)){
        prev=prev->next;
        cnt++;
    }
    newNode->next=prev->next;
    prev->next=newNode;
}

void deleteAtStart(Node* &head){
    if(head==NULL) return;

    Node* temp=head;
    head=head->next;
    free(temp);
}

void deleteAtEnd(Node* &head){

    if(head==NULL) return;
    if(head->next==NULL){
        deleteAtStart(head);
        return;
    }

    Node* secondLast= head;
    while(secondLast->next->next){
        secondLast=secondLast->next;
    }
    Node* last=secondLast->next;
    secondLast->next=NULL;
    free(last);

}

void deleteAtMiddle(Node* &head, int k){
    if(k==1){
        deleteAtStart(head);
        return;
    }

    Node* prev=head;
    int cnt=1;

    while(cnt<(k-1)){
        prev=prev->next;
        cnt++;
    }  //prev now points to k-1 th position

    Node* cur=prev->next; //node to be deleted
    prev->next=prev->next->next; //new link
    free(cur);
}

void solve(){
    Node* node1= new Node(1);
    Node* node2= new Node(2);
    node1->next=node2;
    Node* head=node1;

    insertHead(head, 3);
    insertEnd(head, 9);
    traverse(head);
    insertMiddle(head, 10 , 1);
    traverse(head);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //int _t; cin>>_t;while(_t--)
    solve();
}