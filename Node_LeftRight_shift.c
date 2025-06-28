#include<stdio.h>
#include<stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* head=NULL;
void insertAtEnd(int value) {
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
struct Node* temp=head;
newNode->data=value;
newNode->next=NULL;
if(head==NULL) {
head=newNode;
}
else {
while(temp->next!=NULL) {
temp=temp->next;
}
temp->next=newNode;

}
}
void display() {
struct Node* temp=head;
while(temp!=NULL) {
printf("Element:%d\n",temp->data);
temp=temp->next;
}
printf("NULL\n");
}
void rightshift(int val) {
    struct Node* temp=head;
    while(val){
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head=temp;
    struct Node* last=head;
    while(last->next!=head){
        last=last->next;
    }
    last->next=NULL;
    val--;
    }
}
void leftshift(int val){
    struct Node* temp=head;
    while(val){
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    struct Node *last;
    last=head->next;
    head->next=NULL;
    head=last;
    val--;
    }
}
int main() {
insertAtEnd(10);
insertAtEnd(20);
insertAtEnd(30);
insertAtEnd(40);
insertAtEnd(50);
display();
leftshift(4);
display();
return 0;
}
