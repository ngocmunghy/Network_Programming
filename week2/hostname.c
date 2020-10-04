#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

	char hostname[1024];
	gethostname(hostname,1024);

	printf("hostname: %s\n",hostname);

	return 0;
}