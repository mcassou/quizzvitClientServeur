#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#include <pthread.h>

#include <arpa/inet.h>

/**
*	/brief 
*	/param sts {}
*	/param msg {} 
*/
#define CHECK(sts, msg); if ((sts) == -1) { perror (msg) ; exit (-1);}

#define PORT_SRV 5000
#define IP_SRV "127.0.0.1"

#define MAX_BUFF 1024
typedef char T_Tab[][MAX_BUFF];
