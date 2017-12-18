#include "stream.h"

int mode;
char pseudo[10];

/**********************************************************************************************************/
/* elevève le retour chariot dune chaîne

*/
char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}
/*********************************************************************************************************/

void traiterRep(int sa, char *req, int *taille){

}

void selectionPseudo(){
	printf(">Veuillez selectionner un pseudo :\n");
	fgets(pseudo,9,stdin);
	trimwhitespace(pseudo);
	printf("bonjour  %s !\n", pseudo);
	//fflush(stdout);
}

void selectionMode(){
	printf("\n>Veuillez selectionner un mode de jeu :\n");
	printf("	> Joueur : (Tapez 1)\n");
	printf("	> Spectateur : (Tapez 2)\n");
	printf("\n\nVotre choix :\n"); scanf("%i", &mode);	
	if(mode > 2 || mode < 1){
		printf("\nChoix incorrecte, veuillez choisir un entrer un nombre entre 1 et 2\n"); scanf("%d", &mode);
	}
	printf("mode selectionné : %d\n",mode);
	//fflush(stdout);
}


void entrerJeuClient(){

}



void acceuil(){
printf("********************************************************************************\n");
printf("*				BIENVENUE A QUIIIIIZZ'VIT !		       *\n");
printf("********************************************************************************\n");
//system("clear");
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
	selectionPseudo();
	selectionMode();
	//TODO Démarrage de la socket d'écoute serveur client	


	/* Création du thread du client */
	//CHECK(thread_clt = pthread_create(...,NULL,...,...), "Erreur de creation du thread du client");

	close (sa);
	return 0;
}
