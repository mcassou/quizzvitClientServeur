#include "stream.h"
#define PORT_SP 5001

//Zone des variables
Joueur joueur;




/** ***********************************************************************
 * \fn trimwhitespace
 * \file client.c
 * \brief Supprime le retour chariot d'une chaine de charactère
 * \return renvoie une chaine de caractère.
 * \param[out] (...)
 * \param[in] (...)
 * \author extraite de StackOverflow
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
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

/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
void traiterRep(int sa, char *req, int *taille){
	int repId;
	char rep[MAX_BUFF];
	//printf("[thread Client] -> traiterRep\n");
	CHECK(write(sa,req,strlen(req)+1),"[Client] Echec envoi requête");
	CHECK(read(sa,rep,MAX_BUFF),"[Client] Echec lecutre réponse");
	sscanf(rep,"%i",&repId);
	switch ( repId )
		      {
		case 100 :
			sscanf(rep,"%i %i",&repId,taille ); 
			printf("Joueur enregistré !\n");
		break;

		default : exit(0);
		break;
	}
}

/** ***********************************************************************
 * \fn testProtoSrv
 * \file client.c
 * \brief déroulé du ptotocole applicatif entre un client et le serveur d'enregistrement
 * \return void
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
void testProtoSrv(int sa){
	int N=0,i;
	char req[MAX_BUFF];
	memset(req,MAX_BUFF,0);
	
	//requête connexion : "envoie des infos joueur au serveur"
	sprintf(req,"%i: %i %i %s",100,joueur.mode,joueur.se,joueur.pseudo);
	//printf("[thread Client] -> ptotoServ req : %s\n",req);
	traiterRep(sa,req,&N);
	
}



/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
void selectionPseudo(){
	char pseudo[10];
	printf(">Veuillez selectionner un pseudo [9 charactères max]:\n");
	fgets(pseudo,9,stdin);
	trimwhitespace(pseudo);
	strncpy(joueur.pseudo,pseudo,9);
	printf("bonjour  %s !\n", joueur.pseudo);
	fflush(stdin);
}

/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
void selectionMode(){
	int mode,flag;
	printf("\n>Veuillez selectionner un mode de jeu :\n");
	printf("	> Joueur : (Tapez 1)\n");
	printf("	> Spectateur : (Tapez 2)\n");
	printf("\n\nVotre choix :\n"); scanf("%i", &mode);
	while(!flag){	
	if(mode > 2 || mode < 1){
		printf("\nChoix incorrecte, veuillez choisir un entrer un nombre entre 1 et 2\n"); scanf("%d", &mode);
		flag=0;
	}
	else flag=1;
	}
	printf("mode selectionné : %d\n",mode);
	joueur.mode = mode;
	//fflush(stdout);
}

/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
void entrerJeuClient(){

}




/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
void acceuil(){
system("clear");
printf("********************************************************************************\n");
printf("*				BIENVENUE A QUIIIIIZZ'VIT !		       *\n");
printf("********************************************************************************\n");

}


/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 12 Janvier 2018
 *
 * \version 1.0
************************************************************************** */
void * client(void *arg){
	int sa = *((int *) arg);
	free(arg);
	printf("[thread Client]\n");
	testProtoSrv(sa);
	pthread_exit(0);
}

/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 12 Janvier 2018
 *
 * \version 1.0
************************************************************************** */
void * servP(void *args){
	printf("[thread Serveur Partie]\n");
	/* Socket d'écoute */
	int se;
	/* Socket de la connexion */
	int sd;

	int lenClt;
	char buff[MAX_BUFF];

	/* addr */
	struct sockaddr_in svc;
	struct sockaddr_in clt;
	CHECK(se = socket(AF_INET, SOCK_STREAM, 0), "[SP] Probleme Creation de la Socket d'ecoute");
	/***************************************** Adressage de la Socket se du SP************************************************/
	svc.sin_family = AF_INET;
	svc.sin_port =	htons(PORT_SP);
	inet_aton(IP_SRV, &(svc.sin_addr));
	memset(&svc.sin_zero, 0, 8);
	
	CHECK(bind(se, (struct sockaddr *)&svc, sizeof(svc)), "[SP] Probleme Addressage de la Socket d'ecoute");
	/* Un serveur multiple doit indiquer le nombre de clients mis en attente de connexion par l'appel */
	CHECK(listen(se,1), "[SP] Erreur listen");
	while(1){
	/*
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
	*/
	}
	pthread_exit(0);
}

/** ***********************************************************************
 * \fn 
 * \file client.c
 * \brief 
 * \return 
 * \param[out]
 * \param[in] 
 * \author 
 * 
 * \date 30 Décembre 2017
 *
 * \version 1.0
************************************************************************** */
int main (void){
	Joueur joueur;// = {"",0,0};
	/* Socket de flux */
	int sa;
	int se_clt;
	int etat;
	char message[MAX_BUFF]="\n\n\tBienvenue dans QuizzVit !\n\n";
	char reponse[MAX_BUFF]="";
	int bonnesrepclt = 0;

	pthread_t th_SP, th_Client;
	void * res;

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

	//Démarrage de la socket d'écoute serveur client
	CHECK(pthread_create(&th_SP,NULL, servP,NULL),"[client] echec création thread Serveur Partie client"); //changer les paramètres

	// Création du thread du client 
	int * arg = malloc (sizeof(* arg));
	*arg =sa;
	CHECK(pthread_create(&th_Client,NULL, client,(void *)arg),"[client] echec création thread client"); //changer les paramètres
	
	
	CHECK(pthread_join(th_SP,&res),"[client] echec fermeture th_sp");
	CHECK(pthread_join(th_Client,&res),"[client] echec fermeture th_Client");

	close (sa);
	return 0;
}

// gcc -pthread client.c -o client.exe
// ./client.exe
