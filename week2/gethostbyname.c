#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<errno.h>
#include<arpa/inet.h>

// A program that convert from a hostname to ip address

int main(int argc, char *argv[]) {

	if(argc !=2 ) {
		printf("Not invalid argv!\n");
		exit(1);
	}

	struct hostent *h = gethostbyname(argv[1]);
	if(h == NULL) {
		herror("gethostbyname");
		exit(1);
	}
	printf("Hostname: %s\n",h->h_name);
	printf("IP address: %s\n", inet_ntoa(*(struct in_addr*)h->h_addr)); 

	return 0;
}