#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctime>

const int MAX_ELEMENT = 10;
const int MAX_LENGTH = 255;
char HASHTABLES[MAX_ELEMENT][MAX_LENGTH];

struct Node{
    char name[255];
    int index;
    Node *next,*prev;
}*head[MAX_ELEMENT], *tail[MAX_ELEMENT];

Node *createNode(const char *name,int *index) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->index = *index;
  strcpy(newNode->name, name);
  newNode->next = newNode->prev = NULL;
  return newNode;
}

int hash(const char *str){
    return str[0]-'0';
}
void addfriend(Node *temp,const int *index){
    tail[*index]->next = temp;
    tail[*index]->prev = head[*index];
    tail[*index] = temp;
}

void popTail(int *index) {//masih fail
    Node *newTail = tail[*index]->prev; // A -><- B (newTail) -><- C (tail)
    tail[*index]->prev = newTail->next = NULL; // A -><- B (newTail) || C (tail)
    free(tail); // A -><- B (newTail)
    tail[*index] = newTail; // A -><- B (tail, newTail)
}

void removefriend(int index,const char *str){//masih fail
    if (tail[index]->name == str){
        popTail(&index);
    }else{
        Node *curr = head[index];
        while(curr && curr->name != str) {
            curr = curr->next;
        }
        curr->prev->next = curr->next; // 20->next = 40
        curr->next->prev = curr->prev; // 40->prev = 20
        curr->prev = curr->next = NULL; // set pointers to NULL
        free(curr); // free assigned memory
        curr = NULL; // remove value
    }
}
void inserthash(const char *str){
    int index = hash(str);
    Node *temp = createNode(str,&index);
    if (index>MAX_ELEMENT){
        puts("USER IS FULL");
        return;
    }
    if (head[index] == NULL){
        head[index]=tail[index]=temp;
    }else if(head[index] != NULL){
        addfriend(temp,&index);
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
//===================================================================================== batas hash

