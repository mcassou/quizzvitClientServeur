#include "stream.h"

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

	CHECK(se = socket(AF_INET, SOCK_STREAM, 0), "0: Probleme Creation de la Socket d'ecoute");


/***************************************************************** Adressage de la Socket se*********************************************************************/
	svc.sin_family = AF_INET;
	svc.sin_port =	htons(PORT_SRV);
	inet_aton(IP_SRV, &(svc.sin_addr));
	memset(&svc.sin_zero, 0, 8);
	
	CHECK(bind(se, (struct sockaddr *)&svc, sizeof(svc)), "1: Probleme Addressage de la Socket d'ecoute");

/***************************************************************************************************************************************************************/

	/* Un serveur multiple doit indiquer le nombre de clients mis en attente de connexion par l'appel */
	CHECK(listen(se,10), "Erreur listen");
	

/***************************************************************** Boucle reception serveur *******************************************************************/
	while (1)
	{
		lenClt = sizeof(clt); // On peut pas mettre sizeof dans accept
		
		/* Acceptation d'une requête de connexion par le serveur */
		CHECK((sd = accept(se, (struct sockaddr *)&clt, &lenClt)), "Requete non acceptee par le serveur");
		
		//clonage processus
		int pid;
		//CHECK(pid=fork(),"Fork failed");
		if(pid==0){
			close(se);			
			//traitement éxecuter par serveur fils
			//TODO identifier requete => switch case exemple : Stockage info. 
			printf("client connecté \n");
			close(sd);
			exit(0);
		}

	close(sd);
		
	}
	
	close(se);
	return 0;
}

