#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <netdb.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char **argv) {
        int i;
        struct hostent *host;
        host = gethostbyname("sunsite.unc.edu");
        if ( host != NULL ){
                printf("Official name: %s\n", host->h_name);
                for ( i = 0; host->h_aliases[i] != 0; i++ )
                        printf("   alias[%d]: %s\n", i+1,host->h_aliases[i]);
                        printf("Address type=%d\n", host->h_addrtype);
                        for ( i = 0; i < host->h_length; i++ )
                                printf("Addr[%d]: %s\n", i+1,
                        inet_ntoa(host->h_addr_list[i]));
        } else
                perror("sunsite.unc.edu");        
}