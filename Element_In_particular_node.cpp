#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void insertAtEnd(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void findElement(int value){
    struct Node* temp=head;
    int i;
    for(i=1;i<value;i++){
        temp=temp->next;
    }
    printf("The element in the node is %d\n",temp->data);
}
void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("Element :%d\n",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
   // insertAtEnd(50);
    findElement(4);
    display();
    return 0;
}
