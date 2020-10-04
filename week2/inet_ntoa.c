#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main() {

	struct in_addr someAddr;
	if(inet_aton("10.0.0.1",&someAddr)) // "10.0.0.1" -> &someAddr
		printf("The address is valid\n");
	else
		printf("The address is invalid\n");

	char *addrStr;
	addrStr = inet_ntoa(someAddr); // addrStr <- someAddr
	printf("%s\n",addrStr );

	return 0;
}

// cấu trúc: char *inet_ntoa(struct in_addr abc)
// trả về một string địa chỉ ip từ struct in_addr