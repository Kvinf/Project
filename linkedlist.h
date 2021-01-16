#include "authentication.h"

const int MAX_ELEMENT = 10;//ini bisa diubah ntar sesuai dengan berapa jumlah pengguna
const int MAX_LENGTH = 255;// nama pengguna
char HASHTABLES[MAX_ELEMENT][MAX_LENGTH];//hashnya nih

struct NodeHash{//ini nodenya hash kita kasih nama berbeda menghindari bentrok
    char name[255];
    int index;
    NodeHash *next,*prev;// pake node 2 arah
}*headhash[MAX_ELEMENT], *tailhash[MAX_ELEMENT];//nama tail dan head juga milih hash

NodeHash *createNodeHash(const char *name,int *index) {//utk create node
  NodeHash *newNode = (NodeHash*)malloc(sizeof(NodeHash));
  newNode->index = *index;
  strcpy(newNode->name, name);
  newNode->next = newNode->prev = NULL;
  return newNode;
}

int hash(const char *str){// ini idenya setiap org register namanya depan ditaruh angka user keberapa biar gampang ditanda
    return str[0]-'0';//kita ambil indeks dri angka pertama
}
void addfriend(NodeHash *temp,const int *index){// ini sebenarnya push tail
    tailhash[*index]->next = temp;
    temp->prev = tailhash[*index];
    tailhash[*index] = temp;
}

void poptail(int index) {//masih fail
        NodeHash *newTail = tailhash[index]->prev;
        tailhash[index]->prev = newTail->next = NULL;
        free(tailhash[index]);
        tailhash[index] = newTail;
}

void removefriend(int index,const char *str){//unfriend
    if ((strcmp(headhash[index]->name,str)==0)){
        puts("Why you remove yourself?"); 
    }else if(strcmp(tailhash[index]->name,str)==0){
        poptail(index);
    }else{
        NodeHash *curr = headhash[index];
        while(curr && strcmp(curr->name,str)!=0) {
            curr = curr->next;
        }
        if(curr && strcmp(curr->name,str)==0){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->prev = curr->next = NULL;
            free(curr);
            curr = NULL;
        }else{
            puts("Friend not Founded");
        }
    }
}
void inserthash(const char *str){// ini yg masukin barang ke hashnya
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
void viewhash(){// cuma buat print
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

