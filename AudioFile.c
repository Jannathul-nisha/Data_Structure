//Audio file 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct Node{
    char audio[50];
    struct Node *next;
};
struct Node *head=NULL;
struct Node* creatNode(char value[]){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->audio,value);
    newNode->next=NULL;
    return newNode;
}
void insertAtBegin(char str[]){
    struct Node *newNode=creatNode(str);
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("Added to the list:%s\n",str);
}
void display(){
    struct Node *temp=head;
    if(temp==NULL){
        printf("The list is empty\n");
        return ;
    }
    while(temp!=NULL){
        printf("%s\n",temp->audio);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    char name[50];
    int count=0,choice;
    do{
    printf("To add enter(1)\nTo view the list enter(2)\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
    do{
        printf("Enter name of the song(type no to quite)\n");
        scanf("%s",name);
        if(strcmp(name,"no")==0||strcmp(name,"No")==0){
            break;
        }
        insertAtBegin(name);
    }while(count!=1);
    break;
    case 2:
    display();
    break;
    default:
    printf("Invalid option\n");
}
}while(1);
    return 0;
}
