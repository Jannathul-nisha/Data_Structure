//o(n)
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *last=NULL;
void insertAtBegining(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    if(last==NULL){
    newNode->next=newNode;
    last=newNode;
    }
    else{
        newNode->next=last->next;
        last->next=newNode;
    }
    printf("Inserted:%d\n",data);
}
void insertAtEnd(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    if(last==NULL){
    newNode->next=newNode;
    last=newNode;
    }
    else{
        newNode->next=last->next;
        last->next=newNode;
        last=newNode;
    }
    printf("Inserted:%d\n",data);
}
void deleteAtBegining(){
    struct Node* del=last->next;
    if(last==NULL){
    printf("List is empty\n");
    }
    if(last->next==last){
        del=last;
        last=NULL;             //omly one element in a list
    }
    else{
    struct Node* temp=last->next;
    last->next=last->next->next;
    }
    printf("Deleted :%d\n",del->data);
    free(del);
}
void deleteAtEnd(){
    struct Node* del=last;
    struct Node *temp=last->next;
    if(last==NULL){
    printf("List is empty\n");
    }
    if(last->next==last){
        del=last;
        last=NULL;             //omly one element in a list
    }
    else{
    while(temp->next!=last){
        temp=temp->next;
    }
    temp->next=last->next;
    last=temp;
    }
    printf("Deleted :%d\n",del->data);
    free(del);
}
void display(){
    if(last==NULL)
    printf("List is empty\n");
    else{
    struct Node *temp=last->next;
    do{
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=last->next);
    }
    
}
int main(){
    insertAtBegining(3);
    insertAtBegining(4);
    insertAtBegining(5);
    insertAtEnd(1);
    insertAtEnd(12);
    deleteAtBegining();
    deleteAtEnd();
    display();
    return 0;
}