#include "stream.h"

int mode;

void traiterRep(int sa, char *req, int *taille){

}

int selectionMode(){
	return 0;
}

void entrerJeuClient(){

}

void questions(int q){
	switch(q) {
		case 1:
			printf("\n");
		break; 

		case 2: 
			printf("\n");
		break; 

		case 3: 
			printf("\n");
		break; 

		case 4: 
			printf("\n");
		break; 

		case 5: 
			printf("\n");
		break; 

		case 6: 
			printf("\n");
		break; 

		case 7: 
			printf("\n");
		break; 

		case 8: 
			printf("\n");
		break; 

		case 9: 
			printf("\n");
		break; 

		case 10: 
			printf("\n");
		break;

		case 11:
			printf("\n");
		break; 

		case 12: 
			printf("\n");
		break; 

		case 13: 
			printf("\n");
		break; 

		case 14: 
			printf("\n");
		break; 

		case 15: 
			printf("\n");
		break; 

		case 16: 
			printf("\n");
		break; 

		case 17: 
			printf("\n");
		break; 

		case 18: 
			printf("\n");
		break; 

		case 19: 
			printf("\n");
		break; 

		case 20: 
			printf("\n");
		break;
	} 
}

char reponses(int r){
	char reponse[MAX_BUFF]="";
	switch(r){
		case 1:
			return reponse = "";
		break; 

		case 2: 
			return reponse = "";
		break; 

		case 3: 
			return reponse = "";
		break; 

		case 4: 
			return reponse = "";
		break; 

		case 5: 
			return reponse = "";
		break; 

		case 6: 
			return reponse = "";
		break; 

		case 7: 
			return reponse = "";
		break; 

		case 8: 
			return reponse = "";
		break; 

		case 9: 
			return reponse = "";
		break; 

		case 10: 
			return reponse = "";
		break;

		case 11:
			return reponse = "";
		break; 

		case 12: 
			return reponse = "";
		break; 

		case 13: 
			return reponse = "";
		break; 

		case 14: 
			return reponse = "";
		break; 

		case 15: 
			return reponse = "";
		break; 

		case 16: 
			return reponse = "";
		break; 

		case 17: 
			return reponse = "";
		break; 

		case 18: 
			return reponse = "";
		break; 

		case 19: 
			return reponse = "";
		break; 

		case 20: 
			return reponse = "";
		break;
	}
	return reponse;
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
	char reponse[MAX_BUFF]="";
	int bonnesrepclt = 0;

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

	for(i=1, i<=20, i++){
		questions(i);
		reponse = reponses(i);
		scanf("%s",reponseclt);
		if(strcmp(reponse, reponseclt) == 0){
			printf("\nBonne reponse !\n");
			bonnesrepclt++;
		} else{
			printf("\nMauvaise reponse !\n");
		}
	}

	close (sa);
	return 0;
}

// gcc client.c -o client.exe
// ./client.exe