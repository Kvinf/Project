#include "linkedlist.h"
    char name[255],logname[255];
	char pass[255],logpass[255];

    void mainMenu(){
	    int n;
	printf("Oo=====================================oO\n");
	printf("	      STUDY NETWORK     		\n");
	printf("Oo=====================================oO\n");
	puts("");
	
	puts("[All User]");
	puts("");
	
	puts("No.	Username");
	puts("");
	
	printf("-----------------------------------------\n");
	puts("[1] Register");
	puts("[2] Login");
	puts("[3] Exit");
	
	printf("-----------------------------------------\n");
	puts("Press 0 and enter to abort an operation");
	printf("-----------------------------------------\n");
	printf(">> ");
	scanf("%d" ,&n);
	
	
	if(n == 1){//Register
			printf("-----------------------------------------\n");
			printf("Please type in your username [lowercase || 1..24]: name\b\b\b\b");
			scanf("%s" ,name);
			printf("Please type in your password [lowercase || 1..24]: pass\b\b\b\b");
			scanf("%s" ,pass);
			getchar();
			puts("");
			printf("--- Registration Successfull ---\n\n");
			printf("Press enter to continue!");
			getchar();
			system("cls");
			mainMenu();
	}else if(n == 2){//Login
			printf("-----------------------------------------\n");
			printf("Username: ");
			scanf("%s", logname);
			printf("Password: ");
			scanf("%s" ,logpass);
			getchar();
			
			//kondisi kalau username sama trus passnya juga sama
			if(name == logname && pass == logpass){ //kenapa gak tersaring kondisinya ya?? disini ada bug entah
													//kalau diganti jadi dinamis bisa ilang
				puts("");
				puts("---Login Successfull---");
				printf("Press enter to continue!");
				getchar();
				system("cls");
				//mainMenu2();
				
			}else{//kondisi kalau salah satu antara username atau passnya salah
				printf("Your password or username is wrong!\n");
				printf("Press enter to go back!");
				getchar();
				system("cls");
				mainMenu();
			}
	}else if(n == 3){//exit
			return;
	}else{//kalau ketik selain 1-3 hasilnya terkembali otomatis ke main menu
		printf("There is no such thing!\n");
		printf("Press enter to go Back...");
		getchar();
		system("cls");
		mainMenu();
	}
}

void mainMenu2(){
	int n;
	time_t now = time(0);
	char *waktu = ctime(&now);
	
	printf("Oo=====================================oO\n");
	printf("	Welcome \n" );
	printf("Oo=====================================oO\n");
	printf("Logged in: %s" ,waktu);
	printf("-----------------------------------------\n\n");
	printf("[All Friends of romario]");
	printf("No. Username\n");
	printf("-----------------------------------------\n");
 	printf("		>>Menu<<\n");
	printf("-----------------------------------------\n");
	printf("[1] Add Friend\n");
	printf("[2] Remove Friend\n");
	printf("[3] View Inbox\n");
	printf("[4] View Sent Request\n");
	printf("[5] Add, Edit, Announce, Delete Note\n");
	printf("[6] Log out\n");
	
	printf("-----------------------------------------\n");
	printf(">> ");
	scanf("%d" ,&n);
	
	if(n == 1){// Add Friend
		printf("-----------------------------------------\n");
		printf("[All User]\n");
		printf("No. Username\n");
		printf("\n\n");
		puts("Which use do you want to add?");
		printf(">> ");
		puts("");
		
		if(  ){//jika nama yang diketik ada di username addnya baru di push
			printf("--Your request has been sent to %s--" ,name);//jika kondisi terpenuhi
			printf("Press enter to continue!");
			getchar();
			system("cls");
			mainMenu2();
		}else{//jika tidak ada namanya/tidak sesuai namanya
			printf("There is no such thing!");
			printf("Press enter to go Back!");
			getchar();
			system("cls");
			mainMenu2();
		}
	}else if(n == 2){//Remove friend
		printf("-----------------------------------------\n");
		printf("[All Friends of %s]\n" ,name);//namanya
		printf("No. Username\n");
		printf("\n\n");
		puts("Which user do you want to remove?");
		printf(">> ");
		puts("");
		
		if(){//jika nama yang diketik ada di username addnya baru di pop
			printf("-- You are no longer friends with %s--" ,name);//jika kondisi terpenuhi
			printf("Press enter to continue!");
			getchar();
			system("cls");
			mainMenu2();
		}else{//jika tidak ada namanya/tidak sesuai namanya
			printf("There is no such thing!");
			printf("Press enter to go Back!");
			getchar();
			system("cls");
			mainMenu2();
		}
		
	}else if(n == 3){//view Inbox
		printf("-----------------------------------------\n");
		printf("[All Friend Requests of %s]" ,name);// %s nama itu nama akun yg login skrg ya(ngingatkan aja :D)
		printf("No. Username\n");
		printf("\n\n");
		puts("Which user do you want to be accepted?");
		printf(">> ");
		puts("");
		
		if( ){//kalau nama yg diketik sesuai dengan request baru di hubungkan linknya
			printf("-- You accepted the request from %s--" ,name);
			printf("Press enter to continue!");
			getchar();
			system("cls");
			mainMenu2();
		}else{//jika tidak ada namanya/tidak sesuai namanya
			printf("There is no such thing!");
			printf("Press enter to go Back!");
			getchar();
			system("cls");
			mainMenu2();
		}
	}else if(n == 6){//logOut
		mainMenu();//langsung balik ke main menu
	}
}