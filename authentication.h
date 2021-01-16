#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctime>

//LINKED LIST SEMENTARA UNTUK TESTING. Pas digabungin, isi nodenya diubah saja.
//Code dibawah untuk register dan login tidak akan mengubah isi linked list.
//Hanya menambah node baru dengan pushtail.
//Isi dari createNode() dan struct Node bisa diubah dan ditambah kecuali username dan password
struct Node {
    char username[255];
    char password[255];
    Node *prev, *next;
} *head, *tail;

Node *createNode(const char *username, const char *password) {
    Node *newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->username, username);
    strcpy(newNode->password, password);
    newNode->prev=newNode->next=NULL;

    return newNode;
}

//register user pakai pushtail. Gak pakai pushhead karena kalau kosong, head bakal kebikin sendiri pakai if pertama
void pushTail(const char *username, const char *password) {
    Node *temp=createNode(username, password);

    if(!head) {
        head=tail=temp;
    }

    else {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

//output tergantung function return 1 atau 0
int reg(const char *name, const char *password) {

    Node *curr=head;
    int flag=1;
    while(curr) {

        if(strcmp(curr->username, name)==0) { //kalau username telah diambil, return 0 
            return 0;
        }
        curr=curr->next;
    }

    pushTail(name, password); //kalau username belum ada, register user tersebut
    return 1;
}

//output tergantung function return 1 atau 0
int login(const char *logname, const char *logpass) {

    Node *curr=head;
    int flag=0;
    while(curr) {
        
        if(strcmp(curr->username, logname)==0 && strcmp(curr->password, logpass)==0) { //kalau username dan password ada di database dan benar
            flag=1;
            return 1;
        }
        curr=curr->next;
    }

    return 0; //kalau tidak ada, return 0;
}

void printList() {
    
    Node *curr=head;
    while(curr) {

        if(curr==head) {
            printf(" (head) ");
        }

        else if(curr==tail) {
            printf(" (tail) ");
        }

        printf("%s %s ", curr->username, curr->password);
        curr=curr->next;
    }
}

int mainopen() {

    int n;
    scanf("%d", &n);

    //CURRENTUSER == USER SEKARANG. DITENTUKAN MELALUI FUNGSI LOGIN DIBAWAH
    char currentUser[255];
    if(n==1)
    {
        	char name[255];
            char pass[255];
            
            printf("-----------------------------------------\n");
			printf("Please type in your username [lowercase || 1..24]: name\b\b\b\b");
			scanf("%s" , &name);
			printf("Please type in your password [lowercase || 1..24]: pass\b\b\b\b");
			scanf("%s" , &pass);
			getchar();
			puts("");

            //fungi register user. Menerima hanya jika username unik -> liat line 40
            if(reg(name, pass)==1) {
                printf("--- Registration Successfull ---\n\n");
			    printf("Press enter to continue!");
			    getchar();
            }
            
            else if(reg(name, pass)==0) {
                printf("Username already taken.\n");
            }
			
    }
    if(n==2)
    {
            char logname[255];
            char logpass[255];
            
            printf("-----------------------------------------\n");
			printf("Username: ");
			scanf("%s", &logname);
			printf("Password: ");
			scanf("%s" , &logpass);
			getchar();
			
            //kalau logpass dan logname ada di database -> login berhasil
            //CURRENT USER DITENTUKAN. PAKAI CURRENT USER UNTUK OPERASI LAINNYA
            if(login(logname, logpass)==1) {
                strcpy(currentUser, logname);
                puts("");
				puts("---Login Successfull---");
				printf("Press enter to continue!");
				getchar();
				system("cls");	
            }

            //kalau logname atau logpass salah
            else if(login(logname, logpass)==0) {
                printf("Your password or username is wrong!\n");
				printf("Press enter to go back!");
				getchar();
				system("cls");
            }
    }
    return 0;
}