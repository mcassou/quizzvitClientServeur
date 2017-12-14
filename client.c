#include "stream.h"

void entrerJeuClient(){

}

int main (void){

	/* Socket de flux */
	int sa;

	int etat;

	char message[MAX_BUFF]="\n\n\tBienvenue dans QuizzVit !\n\n";

	/* addr */
	struct sockaddr_in svc;

	//int thread_clt = 0;

	CHECK(sa = socket(AF_INET, SOCK_STREAM, 0), "0: Probleme Creation Socket de flux sa");

	/* Adressage de la Socket */
	svc.sin_family = AF_INET;
	svc.sin_port =	htons (PORT_SRV);
	svc.sin_addr.s_addr = inet_addr (IP_SRV);
	memset (&svc.sin_zero, 0, 8);

	/* Demande de connexion par le client */
	CHECK(etat = connect(sa, (struct sockaddr *)&svc, sizeof (svc)), "Erreur de la demande de connexion");

	/* Création du thread du client */
	CHECK(thread_clt = pthread_create(...,NULL,...,...), "Erreur de creation du thread du client");

	close (sa);
	return 0;
}