#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctime>

const int MAX_ELEMENT = 10;
const int MAX_LENGTH = 255;
char HASHTABLES[MAX_ELEMENT][MAX_LENGTH];

int keisi = -1;

struct Node{
    char name[255];
    int index;
    Node *next,*prev;
}*head[MAX_ELEMENT], *tail[MAX_ELEMENT];

Node *createNode(const char *name) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = newNode->prev = NULL;
  return newNode;
}

int hash(const char *str){
    return str[0]-'0';
}
void inserthashandfriends(const char *str){
    int index = hash(str);
    Node *temp = createNode(str);
    if (index>MAX_ELEMENT){
        puts("USER IS FULL");
        return;
    }
    if (head[index] == NULL){
        head[index]=tail[index]=temp;
    }else if(head[index] != NULL){
        tail[index]->next = temp;
        tail[index]->prev = head[index];
        tail[index] = temp;
    }
}
void viewhash(){
    for (int i = 0;i<MAX_ELEMENT;i++){
        if (head[i]){
            printf("Akun %d: ", i+1);
            Node *curr = head[i];
            while(curr){
                printf("%s <--> ", curr->name);
                curr = curr->next;
            }
            puts(" NULL");
        }
    }
}

