#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

	if(argc != 2) {
		printf("Invalid input\n");
		printf("Format: ./resolver hostname/IP\n");
		return 1;
	} else {
		char str[256];
		strcpy(str,argv[1]);
		//const char s[2] = ".";
		char *token;

		token = strtok(str,".");
		int num = atoi(token);

		if(num == 0) { // para 1 is string, check hostname
			struct hostent *he;
			struct in_addr **addr_list; 
			he = gethostbyname(argv[1]);
			if(he == NULL) { // if hostname is invalid
				printf("Not found information\n");
				return 1;
			} else { // hostname is valid
				printf("Official IP: %s\n", inet_ntoa(*(struct in_addr*)he->h_addr));
				printf("Alias IP:\n");
				addr_list = (struct in_addr **)he->h_addr_list;
				int i;
				for(i=0;addr_list[i] != NULL; i++) {
					printf("%s \n", inet_ntoa(*addr_list[i]));
				}
				return 0;
			}
		} else { // para 1 is ip address
			struct hostent *he;
			struct in_addr **addr_list;
			struct in_addr addr;
			inet_aton(argv[1], &addr);
			he = gethostbyaddr(&addr, sizeof(addr), AF_INET);
			if(he == NULL) {
				printf("Not found information\n");
				return 1;
			} else {
				printf("Official name: %s\n",he->h_name);
				printf("Alias name: \n");
				//addr_list = (struct in_addr **)he->h_addr_list;
				int i;
				for(i=0; he->h_aliases[i] != NULL; i++) {
					printf("%s\n", he->h_aliases[i]);
				}

			return 0;
			}
		}

	}

}