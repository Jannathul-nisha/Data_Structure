#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node* next;
};
struct Node* head=NULL;
void insertAtBegining(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("Element inserted:%d\n",value);
}
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
    printf("Element inserted:%d\n",value);
}
void inversionOfList(){
    struct Node* current=head;
    struct Node* pre=NULL,*next;
    while(current!=NULL){
        next=current->next;//2000
        current->next=pre;//NULL
        pre=current;
        current=next;
       
    }
    head=pre;
    printf("Inverted \n");
}
void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("Element:%d\n",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    insertAtBegining(50);
    insertAtBegining(40);
    insertAtBegining(30);
    insertAtBegining(20);
    insertAtBegining(10);
    insertAtEnd(60);
    insertAtEnd(70);
    insertAtEnd(80);
    insertAtEnd(90);
    insertAtEnd(100);
    display();
    inversionOfList();
    display();
    return 0;
}

