#include "authentication.h"

const int MAX_ELEMENT = 10;
const int MAX_LENGTH = 255;
char HASHTABLES[MAX_ELEMENT][MAX_LENGTH];

struct NodeHash{
    char name[255];
    int index;
    NodeHash *next,*prev;
}*headhash[MAX_ELEMENT], *tailhash[MAX_ELEMENT];

NodeHash *createNodeHash(const char *name,int *index) {
  NodeHash *newNode = (NodeHash*)malloc(sizeof(NodeHash));
  newNode->index = *index;
  strcpy(newNode->name, name);
  newNode->next = newNode->prev = NULL;
  return newNode;
}

int hash(const char *str){
    return str[0]-'0';
}
void addfriend(NodeHash *temp,const int *index){
    tailhash[*index]->next = temp;
    tailhash[*index]->prev = headhash[*index];
    tailhash[*index] = temp;
}

void poptail(int *index) {//masih fail
    NodeHash *newTail = tailhash[*index]->prev; // A -><- B (newTail) -><- C (tail)
    tailhash[*index]->prev = newTail->next = NULL; // A -><- B (newTail) || C (tail)
    free(tailhash); // A -><- B (newTail)
    tailhash[*index] = newTail; // A -><- B (tail, newTail)
}

void removefriend(int index,const char *str){//masih fail
    if (tailhash[index]->name == str){
        poptail(&index);
    }else{
        NodeHash *curr = headhash[index];
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
    NodeHash *temp = createNodeHash(str,&index);
    if (index>MAX_ELEMENT){
        puts("USER IS FULL");
        return;
    }
    if (headhash[index] == NULL){
        headhash[index]=tailhash[index]=temp;
    }else if(headhash[index] != NULL){
        addfriend(temp,&index);
    }
}
void viewhash(){
    for (int i = 0;i<MAX_ELEMENT;i++){
        if (headhash[i]){
            printf("Akun %d: ", i+1);
            NodeHash *curr = headhash[i];
            while(curr){
                printf("%s <--> ", curr->name);
                curr = curr->next;
            }
            puts(" NULL");
        }
    }
}
//===================================================================================== batas hash

