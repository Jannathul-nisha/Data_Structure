//File
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct Node {
    char directory[MAX];
    struct Node* prev;
    struct Node* next;
};
struct Node* current = NULL;
struct Node* createNode(char dir[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->directory, dir);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void addDirectory(char directory[]) {
    struct Node* newNode = createNode(directory);
    if (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL) {
            struct Node* Delete = temp;
            temp = temp->next;
            free(Delete);
        }
        current->next = NULL;
    }
    if (current != NULL) {
        current->next = newNode;
        newNode->prev = current;
    }

    current = newNode;
    printf("In directory: %s\n", directory);
}
void previous() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved back to: %s\n", current->directory);
    } else {
        printf("No previous directory.\n");
    }
}
void next() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to: %s\n", current->directory);
    } else {
        printf("No next directory.\n");
    }
}
void displayHistory() {
    if (current == NULL) {
        printf("No history.\n");
        return;
    }
    struct Node* temp=current;
    while (temp->prev!=NULL)
        temp = temp->prev;

    printf("\nDirectory History is:\n");
    while(temp!=NULL){
        if(temp==current)
            printf(" %s(current)\n",temp->directory);
        else
            printf(" %s\n",temp->directory);
        temp=temp->next;
    }
}
int main(){
    int choice;
    char directoryName[MAX];

    while(1){
        printf("1. Change Directory\n");
        printf("2. For Previous Directory\n");
        printf("3. For Next Directory\n");
        printf("4. For displaying Directory History \n");
        printf("5. To Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  
        switch (choice) {
            case 1:
                printf("Enter directory path: ");
                fgets(directoryName,sizeof(directoryName),stdin);
                directoryName[strcspn(directoryName,"\n")]='\0'; 
                addDirectory(directoryName);
                break;
            case 2:
                previous();
                break;
            case 3:
                next();
                break;
            case 4:
                displayHistory();
                break;
            case 5:
                printf("Exiting..\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
