#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main() {

	struct in_addr someAddr;
	someAddr.s_addr = inet_addr("0.0.0.1");
	printf("%u\n",someAddr.s_addr );

	return 0;
}

// cấu trúc: in_addr_t inet_addr(const char *ipaddr)
// trả về: -1 nếu có lỗi, ngược lại là kiểu in_addr_t