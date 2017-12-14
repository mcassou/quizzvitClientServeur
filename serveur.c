#include "stream.h"

int main ()
{
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


	CHECK(se = socket(AF_INET, SOCK_STREAM, 0), "0: Probleme Creation de la Socket d'ecoute");

	/* Adressage de la Socket */
	svc.sin_family = AF_INET;
	svc.sin_port =	htons(PORT_SRV);
	inet_aton(IP_SRV, &(svc.sin_addr));
	memset(&svc.sin_zero, 0, 8);
	
	CHECK(bind(se, (struct sockaddr *)&svc, sizeof(svc)), "1: Probleme Addressage de la Socket d'ecoute");

	/* Un serveur multiple doit indiquer le nombre de clients mis en attente de connexion par l'appel */
	CHECK(listen(se,5), "Erreur listen");
	
	/* Attente reception message */
	while (1)
	{
		lenClt = sizeof(clt); // On peut pas mettre sizeof dans accept
		
		/* Acceptation d'une requête de connexion par le serveur */
		CHECK(sd = accept(se, (struct sockaddr *)&clt, &lenClt), "Requete non acceptee par le serveur");

		dialogueClt(sd, tableau, sizeof(tableau)/MAX_BUFF);
		close(sd);
		
	}
	
	close(se);
	exit (0);
}