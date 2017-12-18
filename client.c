#include "stream.h"

int mode;


void traiterRep(int sa, char *req, int *taille){

}



int selectionMode(){
	return 0;
}


void entrerJeuClient(){

}



void acceuil(){
printf("********************************************************************************\n");
printf("*				BIENVENUE A QUIIIIIZZ'VIT !		       *\n");
printf("********************************************************************************\n");
printf(">Veuillez selectionner un mode de jeu :\n");
printf("	> Joueur : (Tapez 1)\n");
printf("	> Spectateur : (Tapez 2)\n");
printf("\n\nVotre choix :\n"); scanf("%i", &mode);

printf("mode selectionné : %i\n",mode);

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
	printf("#connection établie \n");
	acceuil();
	//TODO Démarrage de la socket d'écoute serveur client	


	/* Création du thread du client */
	//CHECK(thread_clt = pthread_create(...,NULL,...,...), "Erreur de creation du thread du client");

	close (sa);
	return 0;
}
