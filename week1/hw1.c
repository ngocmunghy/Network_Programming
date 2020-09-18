#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedlist.h"

int main() {
	node head = NULL,tmp;
	FILE *f;
	int choice,count;
	char dem[10],newname[30],newpass[30],username[30],userpass[30];
	do{
		printf("USER MANAGEMENT PROGRAM\n");
		printf("---------------------------------\n");
		printf("\t1. Register\n");
		printf("\t2. Sign in\n");
		printf("\t3. Search\n");
		printf("\t4. Sign out\n");
		printf("Your choice(1-4, other to quit): ");
		scanf("%d",&choice);
		gets(dem);
		switch(choice) {
			case 1:

				printf("\n====== Register ======\n");
				f = fopen("account.txt","a+");
				printf("Username: ");
				scanf("%s",newname);
				gets(dem);
				//tmp = head;
				tmp = findByName(head,newname);
				if(tmp) {
					printf("Account existed\n");
					break;
				} else {
					printf("Password: ");
					scanf("%s",newpass);
					gets(dem);
					printf("Successful registration\n");
					head = addTail(head,newname,newpass);
					
					fprintf(f, "%s %s %d\n",newname,newpass,1);
					
				} 	
				fclose(f);			
				break;

			case 2:

				count = 0;
				printf("\n====== Sign in ======\n");

				label1: printf("Username: ");
				scanf("%s",username);
				gets(dem);
				tmp = findByName(head, username);
				if(!tmp) {
					printf("Cannot find account\n");
					goto label1;
				} else if(tmp->node_t.status == 0) {
					printf("Account is blocked\n");
					goto label1;
				}
				label2: printf("Password: ");
				scanf("%s",userpass);
				gets(dem);
				if(strcmp(tmp->node_t.pass,userpass) != 0) {
					printf("Password is incorrect !\n");
					count++;
					if(count <= 3) {
						goto label2;
					} else {
						tmp->node_t.status = 0;
						printf("Password is incorrect. Account is blocked !\n");
					}
				} else {
					tmp->node_t.isSignIn = 1;
					printf("Hello %s !\n", tmp->node_t.name);
				}


				f = fopen("account.txt","w");
				int i,num = numOfNodes(head);
				tmp = head;
				for(i=0;i<num;i++) {
					fprintf(f, "%s %s %d\n", tmp->node_t.name,tmp->node_t.pass,tmp->node_t.status);
					tmp = tmp->next;
				}
				fclose(f);

				break;
			case 3:

				printf("Username: ");
				scanf("%s",username);
				gets(dem);
				tmp = findByName(head,username);
				if(!tmp) {
					printf("Cannot find account\n");
				} else {
					if(tmp->node_t.status == 0) {
						printf("Account is blocked\n");
					} else {
						printf("Account is active\n");
					}
				}

				break;
			case 4:

				printf("Username: ");
				scanf("%s",username);
				tmp = findByName(head,username);
				if(!tmp) {
					printf("Cannot find account\n");
				} else {
					if(tmp->node_t.isSignIn == 0) {
						printf("Account is not sign in\n");
					} else {
						printf("Goodbye %s\n",tmp->node_t.name);
						tmp->node_t.isSignIn = 0;
					}
				}

				break;

			default:
				freeList(head);
				printf("Thank you for using\n");
				return 0;
		}

	} while(1);
	return 0;
}