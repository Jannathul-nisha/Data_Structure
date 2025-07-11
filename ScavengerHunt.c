//scavendure hunt.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
  char data[50];
  struct Node *next;
};
struct Node *head=NULL;
struct Node* creatNode(char value[]){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data,value);
    newNode->next=NULL;
    return newNode;
}
void insertAtEnd(char value[]){
    struct Node *newNode=creatNode(value);
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted hint\n");
}
void enter(){
    getchar();
    return ;
}
void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%s\n",temp->data);
        temp=temp->next;
    }
    printf("Game over\n");
}
void start(){
    struct Node *temp=head;
    while(temp!=NULL){
        enter();
        printf("%s\n",temp->data);
        temp=temp->next;
    }
    printf("Game over\n");
}
int main(){
    int choice,count;
    char name[50];
    do{
    printf("To add clue(1)\nTo view the list enter(2)\nTo start enter (3)\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter clue(type no to quite)\n");
        scanf(" %[^\n]s",name);
        if(strcmp(name,"no")==0||strcmp(name,"No")==0){
            //count++;
            break;
        }
        insertAtEnd(name);
    break;
    case 2:
    display();
    break;
    case 3:
    start();
    default:
    printf("Invalid option\n");
    }
    }while(1);
    return 0;
}
