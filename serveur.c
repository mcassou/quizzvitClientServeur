#include "stream.h"

//tableau de joueur
Joueur joueur[40];

void derouter(int sig){
	int status;
	int pid=wait(&status);
	printf("le processus de service [PID=%d], vient de se terminer avec le status %d\n",pid,status);
}



int main (){
/**************************************************************** Bloc de déclaration variables**********************************************************/
	//TODO déclarer un structure joueur et initialiser un tableau de joueur.

	//tableau des questions
	T_Tab quizz = {"Question 1",
                   "Question 2",
                   "Question 3",
                   "Question 4",
                   "Question 5",
                   "Question 6",
                   "Question 7",
                   "Question 8",
                   "Question 10",
                   "Question 9",
                   "Question 11",
                   "Question 12",
                   "Question 13",
                   "Question 14"};

	/* Socket d'écoute */
	int se;

	/* Socket de la connexion */
	int sd;

	int lenClt;
	char buff[MAX_BUFF];

	/* addr */
	struct sockaddr_in svc;
	struct sockaddr_in clt;
/****************************************************************************************************************************************************************/

/****************************************************************************************************************************************************************/
	CHECK(se = socket(AF_INET, SOCK_STREAM, 0), "[SERVEUR] Probleme Creation de la Socket d'ecoute");


/***************************************************************** Adressage de la Socket se*********************************************************************/
	svc.sin_family = AF_INET;
	svc.sin_port =	htons(PORT_SRV);
	inet_aton(IP_SRV, &(svc.sin_addr));
	memset(&svc.sin_zero, 0, 8);
	
	CHECK(bind(se, (struct sockaddr *)&svc, sizeof(svc)), "[SERVEUR] Probleme Addressage de la Socket d'ecoute");

/***************************************************************************************************************************************************************/

	/* Un serveur multiple doit indiquer le nombre de clients mis en attente de connexion par l'appel */
	CHECK(listen(se,20), "Erreur listen");
	


	struct sigaction newAct;
	newAct.sa_handler = derouter;
	newAct.sa_flags = SA_RESTART;
	CHECK(sigemptyset(&newAct.sa_mask),"...............");
	CHECK(sigaction(SIGCHLD,&newAct,NULL),"..............");

/***************************************************************** Boucle reception serveur *******************************************************************/
	
	//TODO identifier requete => switch case exemple : Stockage info. 
	// boucle de réception
	while ( 1 )
		  { 
		    int sd;
		    struct sockaddr_in ac;
		    socklen_t taille = sizeof ( ac );
		    CHECK( ( sd = accept ( se, ( struct sockaddr * ) &ac, &taille ) ), "[SERVEUR] Requete non acceptee par le serveur" );
		   
		    //clonage processus
		    int pid;
		    CHECK(pid=fork(),"Fork failed");
		    if(pid == 0 ){
				close(se);
				//boucle de test
				while(1){
					system("clear");
					printf("test...pid : %i\n",getpid());
					sleep(4);
				} 
				close(sd); 
				exit(0);
		    }
		    close ( sd ); 
		}
		  close ( se );
	return(0);
}


// gcc serveur.c -o serveur.exe
// ./serveur.exe
