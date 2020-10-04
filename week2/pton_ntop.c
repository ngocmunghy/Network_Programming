#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main() {

	char str[INET_ADDRSTRLEN];
	struct sockaddr_in sa;

	// store this IP address in sa
	inet_pton(AF_INET,"192.0.2.33",&(sa.sin_addr));

	// now get it back and print it
	inet_ntop(AF_INET,&(sa.sin_addr),str,INET_ADDRSTRLEN);

	printf("%s\n",str);

	return 0;
}