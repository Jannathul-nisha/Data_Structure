#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node *head=NULL;
void insertAtBegining(int value) {
	struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=value;
	if(head==NULL) {
		newNode->next=NULL;
		head=newNode;
	}
	else {
		newNode->next=head;
		head=newNode;
	}
	printf("Inserted : %d\n",value);
}
void insertAtEnd(int value) {
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	struct Node* temp=head;
	if(head==NULL) {
		head=newNode;
	}
	else {
		while(temp->next!=NULL) {
			temp=temp->next;
		}
		temp->next=newNode;
	}
	printf("Inserted:%d\n",value);
}
void insertAtPosition(int value,int pos) {
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	int i;
	struct Node* temp=head;
	if(head==NULL)
		newNode->next=NULL;
	if(pos==1) {
		newNode->next=head;
		head=newNode;
	}
	else {
		for(i=1; i<pos-1; i++) {
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
	printf("Inserted:%d\n",value);
}
void deleteAtBeginig() {
	struct Node* temp=head;
	if(head==NULL)
		printf("List is Empty\n");
	else {
		head=temp->next;
	}
	printf("Element deleted is : %d\n",temp->data);
	free(temp);
}
void deleteAtEnd() {
	struct Node* temp=head;
	struct Node *del;
	if(head==NULL)
		printf("List is empty\n");
	else {
		while(temp->next->next!=NULL) {
			temp=temp->next;
		}
		del=temp->next;
		temp->next=NULL;
	}
	printf("Element deleted is :%d\n",del->data);
	free(del);
}
void display() {
	printf("The list of element in a list is :\n");
	struct Node* temp=head;
	while(temp!=NULL) {
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
int main() {
	insertAtBegining(10);
	insertAtBegining(20);
	insertAtBegining(30);
	insertAtEnd(40);
	insertAtPosition(35,2);
	deleteAtBeginig();
	deleteAtEnd();
	display();
	return 0;
}