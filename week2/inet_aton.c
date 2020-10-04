#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main() {

	struct in_addr someAddr;
	if(inet_aton("10.0.0.1", &someAddr))
		printf("The address is valid\n"); // 1
	else
		printf("The address is invalid\n");

	printf("%d\n",inet_aton("0.0.0.267", &someAddr) ); // 0

	return 0;
}

// cấu trúc: int inet_aton(const char *ipaddr, struct in_addr abc)
// tham số 1: địa chỉ ip, tham số 2: kiểu struct in_addr
// trả về: nếu địa chỉ ip tồn tại thì trả về 1, ngược lại trả về 0