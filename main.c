#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
typedef struct matriculVoiture
{
	int matricule;
	char type[5];
	int kilometrage;
	char stats;
} matriculVoiture;

typedef struct Matricul
{
	matriculVoiture mat;
	struct Matricul *suivant;
} Matricul;

typedef struct Matricul *listeMatricul;


typedef struct voiture
{
	char marque[15];
	char nom[15];
	char couleur[7];
	char identit[5];
	char abs;
	int prixKilo;
	int prixJour;
	int nbplace;

} voiture;


typedef struct contrat
{
	float num;
	char nom[20];
	char pnom[20];
	int debu;
	int fin;
	char type[2];
	int cout;
	int assurance;
	char agencDepar[15];
	char agencRetour[15];
	int voit_loue;
	char supcond;
	char liv;
	char bebe;
} contrat;




typedef struct client
{
	int age;
	float num;
	char ville[15];
	int cin;
	int date_permi;
	char nom[20];
	int telephone;
	float ctr;
	char prenom[20];
}client;



typedef struct cellule
{
	voiture voit;
	struct cellule *suivant;
} cellule,*liste;


typedef struct cellule_client
{
	client person;
	struct cellule_client *suivant;
	struct cellule_client *precedent;
} cellule_client, *liste_client;


typedef struct CelluleContrat
{
	contrat cont;
	struct CelluleContrat *suivant;
}CelluleContrat, *ListeContrat;


typedef struct date
{
	int jj;
	int mm;
	int aa;
} date;
void A_Propos();

void AfficheClient ( client cl);

void AfficheContrat(contrat crt);

void AfficheType(voiture voit);

void AfficheVoiture(matriculVoiture mt);

cellule_client* chargementClient(char *nom);

ListeContrat chargementContrat(char *nom);

listeMatricul ChargementMatricul(char *nom);

liste chargementType(char *nom);

int ConditionLocation(client cl);

date convertDate();

int dateDiff(int fin);

void mono();

float generationCode();

liste inserer_en_fin(liste l,cellule *elt);

liste_client InsererEnFinClient(liste_client l,client cl);

liste_client insererClient(liste_client l, cellule_client *inser);

listeMatricul insererVoiture(listeMatricul l,Matricul *m);

int ListeMatriculVide(listeMatricul l);

int ListeVide(liste l);

int MenuGestionClient();

int MenuGestionVoiture();

int MenuLocation();

int MenuPrincipal();

void MessageUrgence(char *msg);

liste_client modifierClient(liste_client l);

ListeContrat ModifierContrat(ListeContrat l,listeMatricul m);

liste ModifierTypeVoiture(liste l);

void msgSauvCharg(char *msg);

listeMatricul rechecherMatricul(listeMatricul,int m);

liste_client RechercheClient(liste_client l,char *nom,char *pnom);

ListeContrat RechercheContrat(ListeContrat l);

liste RechercheTypeVoiture(liste l,char rech[]);

listeMatricul RechercheVoitureLibre(listeMatricul lm, char *typ);

void RetourContrat(ListeContrat lcr,listeMatricul lm,liste l);

cellule_client* RetourTete(cellule_client *t);

cellule_client* SaisieClient();

ListeContrat saisieContrat(cellule_client *person,listeMatricul l);

listeMatricul saisieMatricul(listeMatricul l1,liste l);

liste SaisieTypeVoiture(liste l);

void sauvgarde(liste l,char nom[]);

void sauvgardeClient(liste_client l,char *nom);

void SauvgardeContrat(ListeContrat l,char *nom);

void SauvgardeGeneral(int verif,liste stock_voiture,liste_client lesclients,ListeContrat lescontrat,listeMatricul stock_matricul);

void SauvgardeMatricule(listeMatricul l,char *nom);

void Statistique(liste typ,liste_client clt,listeMatricul mat,ListeContrat crt);

liste_client supprimerClient(liste_client l);

ListeContrat SupprimerContrat(ListeContrat l,CelluleContrat *supp);

listeMatricul supprimerMatricul(listeMatricul l);

liste SupprimerPosition(liste l,cellule *supp);

liste SupprimerVoiture(liste l);
 main()
{
	liste stock_voiture,typ;
	liste_client les_clients;
	ListeContrat uncontrat,lescontrat;
	cellule *voit;
	cellule_client *unclient;
	int choix_principal=0,choix_second=0,choix,tmp;
	listeMatricul stock_matricul,matr;
	char nom[20],pnom[20];

	les_clients=(cellule_client *)malloc(sizeof (cellule_client));
	les_clients=NULL;
	stock_voiture=(cellule *)malloc(sizeof (cellule));
	typ=(cellule *)malloc(sizeof (cellule));
	stock_voiture=NULL;
	stock_matricul=(Matricul *)malloc(sizeof (Matricul));
	stock_matricul=NULL;
	lescontrat=(CelluleContrat *)malloc(sizeof (CelluleContrat));
	lescontrat=NULL;
	stock_voiture=chargementType("type.txt");
	stock_matricul=ChargementMatricul("matricul.txt");
	les_clients=chargementClient("client.txt");
	lescontrat=chargementContrat("contrat.txt");
while((choix_second!=27)&&(choix_principal!=9))
{
	choix_principal=MenuPrincipal();

	switch(choix_principal)
	{

	case 1:
		while(choix_second!=27)
		{
			choix_second=MenuLocation();
			if(choix_second==49)
			{
				printf("\n\t\tUn contrat(1)\tLes contrats(2)");
				choix=getch();
				if(choix==49)
				{
					uncontrat=RechercheContrat(lescontrat);
					if(uncontrat==NULL)
						MessageUrgence("Contrat non-trouvee");
					else
						AfficheContrat(uncontrat->cont);
				}
				if(choix==50)
				{
					uncontrat=lescontrat;
					while(uncontrat!=NULL)
					{
						AfficheContrat(uncontrat->cont);
						uncontrat=uncontrat->suivant;
					}
				}
			}

			if(choix_second==50)
			{

				printf("\n\n\t\tSelectionner un client oui(o)/non(n) : ");
				do
				{	choix=getch();
				}while((choix!=111)&&(choix!=110));
				if(choix==111)
				{
					mono();

					printf("\n\nClient a selectionne...");
					printf("\n\nNom       : ");
					scanf("%s",&nom);
					printf("\n\nPrenom    : ");
					scanf("%s",&pnom);
					unclient=RechercheClient(les_clients,nom,pnom);
					if(unclient==NULL)
					{
						MessageUrgence("Client non-trouve");
						unclient=SaisieClient();
						uncontrat=saisieContrat(unclient,stock_matricul);
					}
					else
						uncontrat=saisieContrat(unclient,stock_matricul);
				}
				else
				{
					unclient=SaisieClient();
					uncontrat=saisieContrat(unclient,stock_matricul);
				}

				if(uncontrat==NULL)
				{
					MessageUrgence("Condition non-verifiee\n\t\t\t\tLocation impossible");
					MessageUrgence("Client non-sauvgarde");
				}
				else
				{
					if(choix==110)		
						les_clients=InsererEnFinClient(les_clients,unclient->person);

					
					uncontrat->suivant=lescontrat;
					lescontrat=uncontrat;
					MessageUrgence("Location effectuee");
				}
			}

			if(choix_second==51)
				RetourContrat(lescontrat,stock_matricul,stock_voiture);

			if(choix_second==52)
				lescontrat=ModifierContrat(lescontrat,stock_matricul);


			if(choix_second==53)
			{
				uncontrat=RechercheContrat(lescontrat);
				if(uncontrat==NULL)
					MessageUrgence("Contrat non-trouvee");
				else
				{
					lescontrat=SupprimerContrat(lescontrat,uncontrat);
					MessageUrgence("Contrat supprimer");
				}
			}

			if(choix_second==57)
				choix_second=27;
		}
			typ=stock_voiture;
			matr=stock_matricul;
			uncontrat=lescontrat;
			unclient=les_clients;
			SauvgardeGeneral(1,typ,unclient,uncontrat,matr);
			choix_second=0;
	


		break;
	case 2 :
		while(choix_second!=27)
		{
			choix_second=MenuGestionVoiture();

			if(choix_second==49)
			{
				printf("\n\nType (1)\t\tVoiture (2)");
				choix=getch();

				if(choix==49)		
				{
					printf("\n\nUn type (1)\t\tTous les types (2)");
					if(getch()==49)
					{
						mono();
						printf("\n\n\t\tType recherche...");
						printf("\n\n\t\tIdentifiant    :  ");
						scanf("%s",&nom);
						typ=RechercheTypeVoiture(stock_voiture,nom);
						if(typ==NULL)
							MessageUrgence("Type non-trouve");
						else
							AfficheType(typ->voit);
					}

					if(getch()==50)
					{
						typ=stock_voiture;
						while(typ!=NULL)
						{
							AfficheType(typ->voit);
							typ=typ->suivant;
						}
					}
				}

				if(choix==50)
				{
					printf("\n\n\t\tUne voiture (1)\t\tTous les voitures (2)");

					if(getch()==49)
					{
						mono();
						printf("\n\n\t\tVoiture recherchee...");
						printf("\n\n\t\tMatricul    :  ");
						scanf("%d",&tmp);

						matr=rechecherMatricul(stock_matricul,tmp);
						if(matr==NULL)
							MessageUrgence("Voiture non-trouvee");
						else
							AfficheVoiture(matr->mat);
					}

					if(getch()==50)
					{
						matr=stock_matricul;
						while(matr!=NULL)
						{
							AfficheVoiture(matr->mat);
							matr=matr->suivant;
						}
					}
				}
			}


			if(choix_second==50)
			{
				do
				{
					printf("\n\n\t\tType (1)\t\tVoiture (2)\n\t\t");
					
					choix=getch();
				}while((choix==49)&&(choix==50)&&(choix==27));


				if(choix==49)
				{
					voit=SaisieTypeVoiture(stock_voiture);
					stock_voiture=inserer_en_fin(stock_voiture,voit);
				}

	 			if(choix==50)		
				{
					matr=saisieMatricul(stock_matricul,stock_voiture);
					if(matr!=NULL)
						stock_matricul=insererVoiture(stock_matricul,matr);
				}

			}
			if(choix_second==51)
				stock_voiture=ModifierTypeVoiture(stock_voiture);

			if(choix_second==52)
			{
				do
				{
					printf("\n\n\t     Type (1)\t\tVoiture (2)\n\t\tchoix  :  ");
					scanf("%d",&choix);
				}while((choix==1)&&(choix==2)&&(choix==0));

				if(choix==1)
					stock_voiture=SupprimerVoiture(stock_voiture);
				else
					if(choix==2)
						stock_matricul=supprimerMatricul(stock_matricul);
			}

			if(choix_second==57)
				choix_second=27;
		}

		typ=stock_voiture;
		matr=stock_matricul;
		uncontrat=lescontrat;
		unclient=les_clients;
		SauvgardeGeneral(2,typ,unclient,uncontrat,matr);
		choix_second=0;
	
		break;

	case 3 :
		while(choix_second!=27)
		{
			unclient=(cellule_client *)malloc(sizeof (cellule_client));
			choix_second=MenuGestionClient();
			if(choix_second==49)
			{
				printf("\n\n\tUn client(1)\tLes clients(2)");
				choix=getch();
				if(choix==49)
				{
					mono();
					printf("\n\n\tClient recherche...");
					printf("\n\t\tNom          : ");
					scanf("%s",&nom);
					printf("\n\t\tPrenom       : ");
					scanf("%s",&pnom);
					unclient=RechercheClient(les_clients,nom,pnom);
					if(unclient==NULL)
						MessageUrgence("Client non-trouve");
					else
						AfficheClient(unclient->person);
				}
				if(choix==50)
				{
					unclient=les_clients;
					while(unclient!=NULL)
					{
						AfficheClient(unclient->person);
						unclient=unclient->suivant;
					}
				}
			}
			if(choix_second==50)
				les_clients=modifierClient(les_clients);

			if(choix_second==51)
				les_clients=supprimerClient(les_clients);

			if(choix_second==57)
				choix_second=27;
		}
		typ=stock_voiture;
		matr=stock_matricul;
		uncontrat=lescontrat;
		unclient=les_clients;
		SauvgardeGeneral(3,typ,unclient,uncontrat,matr);
		choix_second=0;

		break;

	case 4:
		typ=stock_voiture;
		matr=stock_matricul;
		uncontrat=lescontrat;
		unclient=les_clients;
		Statistique(typ,unclient,matr,uncontrat);
		break;

	case 8:
		A_Propos();

		break;

	case 9 :
		break;


	}
}

	typ=stock_voiture;
	matr=stock_matricul;
	uncontrat=lescontrat;
	unclient=les_clients;
	SauvgardeGeneral(9,typ,unclient,uncontrat,matr);
}

cellule_client* RetourTete(cellule_client *t)
{
	if(t!=NULL)

		while(t->precedent!=NULL)
			t=t->precedent;

	return t;
}


liste_client SaisieClient()
{
	client *clt;
    liste_client retour;

	mono();

	retour=(cellule_client *)malloc(sizeof (cellule_client));
	clt=(client *)malloc(sizeof (client));

	printf("\nSaisie personne........");

	printf("\n\t\tNom           : ");
	scanf("%s",&clt->nom);

	printf("\n\t\tPrenom        : ");
	scanf("%s",&clt->prenom);

	printf("\n\t\tAge           : ");
	scanf("%d",&clt->age);

	printf("\nAdresse...");

	printf("\nNumero        : ");
	scanf("%d",&clt->num);


	printf("\nVille         : ");
	scanf("%s",&clt->ville);
	printf("\nNum. CIN      : ");
	scanf("%d",&clt->cin);

	printf("\nDate permis (jjmmaaaa)  : ");
	scanf("%d",&clt->date_permi);
	clt->ctr=0;

	retour->person=*clt;
	retour->suivant=NULL;
	retour->precedent=NULL;

	return retour;
}

liste_client RechercheClient(liste_client l,char *nom,char *pnom)
{

	l=RetourTete(l);


	while(l!=NULL)
		{
			if(strcmp(l->person.nom,nom)==0)
				if(strcmp(l->person.prenom,pnom)==0)
					return l;

			l=l->suivant;
		}

 	return NULL;

}

liste_client modifierClient(liste_client l)
{
	liste_client modif;
	cellule_client *save;
	char nom[20],pnom[20];

	l=RetourTete(l);

	if(l==NULL)
		MessageUrgence("Pas de client");
	else
	{
		printf("\n\t\tNom    ( \x22 exit \x22 pour annuler) :  ");
		scanf("%s",&nom);
		if(strcmp(nom,"exit")!=0)
		{
			printf("\n\t\tPrenom ( \x22 exit \x22 pour annuler) :  ");
			scanf("%s",&pnom);
		}

		if((strcmp(pnom,"exit")!=0)&&(strcmp(nom,"exit")!=0))
		{
			modif=RechercheClient(l,nom,pnom);

			if(modif==NULL)
				MessageUrgence("Client non trouve");
			else
			{
				save=modif;
				modif=SaisieClient();
				save->person=modif->person;
				MessageUrgence("Client modifie");
			}
		}
	}

	return l;
}

liste_client supprimerClient(liste_client l)
{
	cellule_client *supp;
	char nom[20],pnom[20];



	if(l==NULL)
		MessageUrgence("Pas de client");
	else
	{
		printf("\n\t\tNom    :  ");
		scanf("%s",&nom);
		if(strcmp(nom,"exit")!=0)
		{
			printf("\n\t\tPrenom :  ");
			scanf("%s",&pnom);
		}

			l=RetourTete(l);
			supp=RechercheClient(l,nom,pnom);
			if(supp!=NULL)
			{
				if(supp==l)		
				{
					l=l->suivant;

					free(supp);
					MessageUrgence("Client supprime");
					return l;
				}

				else
					if(supp->suivant==NULL)
					{
						supp->precedent->suivant=NULL;
				
						MessageUrgence("Client supprime");
						return l;

					}
					else
					{
						supp->precedent->suivant=supp->suivant;
						supp->suivant->precedent=supp->precedent;
						free(supp);
						MessageUrgence("Client supprime");
						return l;
					}
			}
			else
				MessageUrgence("Client non trouve");

	}

	return l;

}
void AfficheClient(client cl)
{
	mono();

	printf("\n\tNom          : %s",cl.nom);
	printf("\t\tPrenom         : %s",cl.prenom);
	printf("\t\tCIN          : %d",cl.cin);
	printf("\n\n\tDate permis  : %d/%d/%d",cl.date_permi/10000,(cl.date_permi%10000)/100,(cl.date_permi%10000)%100);
	printf("\n\n\tAdresse...");
	printf("\n\n\tNum          : %d",cl.num);
	printf("\n\n\tVille        : %s",cl.ville);
	printf("\n\n\n");
	system("pause");
}

liste_client InsererEnFinClient(liste_client l,client cl)
{
	cellule_client *inser;

	inser=(cellule_client *)malloc(sizeof(cellule_client));
	inser->person=cl;

	l=RetourTete(l);

	if(l==NULL)
	{
		inser->precedent=NULL;
		inser->suivant=NULL;
		l=inser;
	}
	else
	{
		while(l->suivant!=NULL)
			l=l->suivant;

		inser->precedent=l;
		l->suivant=inser;
		inser->suivant=NULL;
	}

	return RetourTete(l);
}



void sauvgarde(liste l,char nom[25])
{
	FILE* stock;
	liste sauv;


	stock=fopen(nom,"w");

	sauv=(cellule *)malloc(sizeof (cellule));
	sauv=l;

	while(sauv!=NULL)
	{
		fwrite(&sauv->voit,sizeof(voiture),1,stock);
		sauv=sauv->suivant;
	}

	fclose(stock);


	msgSauvCharg("Sauvgarde des type");
}


liste chargementType(char *nom)
{
	FILE* stock;
	liste charge,retour;
	cellule *p;
	voiture voit;

	p=(cellule *)malloc(sizeof (cellule));

	retour=(cellule *)malloc(sizeof (cellule));
	retour=NULL;
	stock=fopen(nom,"r");

	if(stock!=NULL)
	{
		while(fread(&voit,sizeof(voiture),1,stock))
		{
			charge=(cellule *)malloc(sizeof (cellule));
			charge->voit=voit;
			charge->suivant=NULL;

			if (retour==NULL)
				retour=charge;
			else
			{
				p=retour;
				while(p->suivant!=NULL)
					p=p->suivant;
				p->suivant=charge;
			}
		}
	
	}

	msgSauvCharg("Chargement des types");
	return retour;
}

void SauvgardeMatricule(listeMatricul l,char *nom)
{
	FILE *fp;

	fp=fopen(nom,"w");

	while(l!=NULL)
	{
		fwrite(&l->mat,sizeof(matriculVoiture),1,fp);
		l=l->suivant;
	}



	fclose(fp);

	msgSauvCharg("Sauvgarde des matriculs");
}

listeMatricul ChargementMatricul(char *nom)
{
	FILE *stock;
	matriculVoiture mat;
	listeMatricul l,parc,retour;

	stock=fopen(nom,"r");

	retour=(listeMatricul )malloc(sizeof (listeMatricul));
	parc=(listeMatricul )malloc(sizeof (listeMatricul));
	retour=NULL;

	if(stock!=NULL)
	{
		while(fread(&mat,sizeof(matriculVoiture),1,stock))
		{
			l=(listeMatricul )malloc(sizeof (listeMatricul));
			l->mat=mat;
			l->suivant=NULL;

			if(retour==NULL)
				retour=l;
			else
			{
				parc=retour;
				while(parc->suivant!=NULL)
					parc=parc->suivant;
				parc->suivant=l;
			}
		}
	
	}

	msgSauvCharg("Chargement des matriculs");

	return retour;
}

void sauvgardeClient(liste_client l,char *nom)
{
	FILE *fp;

	l=RetourTete(l);

	fp=fopen(nom,"w");

	while(l!=NULL)
	{
		fwrite(&l->person,sizeof(client),1,fp);
		l=l->suivant;
	}

	fclose(fp);



	msgSauvCharg("Sauvgarde des clients");
}

liste_client chargementClient(char *nom)
{
	FILE *fp;
	client person;
	liste_client parc,retour;

	fp=fopen(nom,"r");

	retour=(liste_client)malloc(sizeof (liste_client));
	parc=(liste_client)malloc(sizeof (liste_client));
	retour=NULL;


	if(fp!=NULL)
	{
		while(fread(&person,sizeof(client),1,fp))
		{
			retour=InsererEnFinClient(retour,person);
		}


	}

	msgSauvCharg("Chargement des clients...");

	return retour;
}

void SauvgardeContrat(ListeContrat l,char *nom)
{
	FILE *fp;

	fp=fopen(nom,"w");

	while(l!=NULL)
	{
		fwrite(&l->cont,sizeof(contrat),1,fp);
		l=l->suivant;
	}


	fclose(fp);


	msgSauvCharg("Sauvgarde des contrats");

}

ListeContrat chargementContrat(char *nom)
{
	FILE* fp;
	contrat cont;
	ListeContrat l,parc,retour;

	fp=fopen(nom,"r");

	retour=(ListeContrat)malloc(sizeof (ListeContrat));
	parc=(ListeContrat)malloc(sizeof (ListeContrat));
	retour=NULL;


	if(fp!=NULL)
	{
		while(fread(&cont,sizeof(contrat),1,fp))
		{
			l=(ListeContrat)malloc(sizeof (ListeContrat));
			l->cont=cont;
			l->suivant=NULL;
			if(retour==NULL)
				retour=l;
			else
			{
				parc=retour;
				while(parc->suivant!=NULL)
					parc=parc->suivant;
				parc->suivant=l;
			}
		}
	
	}

	msgSauvCharg("Chargement des contrats");

	return retour;
}

void SauvgardeGeneral(int verif,liste stock_voiture,liste_client lesclients,ListeContrat lescontrat,listeMatricul stock_matricul)
{
	int tmp;

	if(verif==9)
	{
		do
		{
			system("cls");
			printf("\n\n");
			printf("\n   \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n   \xb3     Sauvgarder les changements ?     \xb3");
			printf("\n   \xb3          oui(o)    non(n)            \xb3");
			printf("\n    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
			{
				sauvgarde(stock_voiture,"type.txt");
				SauvgardeMatricule(stock_matricul,"matricul.txt");
				sauvgardeClient(lesclients,"client.txt");
				SauvgardeContrat(lescontrat,"contrat.txt");
			}
			if(tmp==110)
				MessageUrgence("Pas de sauvgarde");
		}while((tmp!=111)&&(tmp!=110));
	}

	if(verif==1)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\n \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n  \xb3     Sauvgarder les changements       \xb3");
			printf("\n \xb3     effectuer sur les contrat ?      \xb3");
			printf("\n  \xb3          oui(o)    non(n)            \xb3");
			printf("\n  \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
			{
				SauvgardeContrat(lescontrat,"contrat.txt");
				sauvgardeClient(lesclients,"client.txt");
			}
			if(tmp==110)
				MessageUrgence("Pas de sauvgarde");
		}while((tmp!=111)&&(tmp!=110));
	}

	if(verif==2)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\n                    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                    \xb3     Sauvgarder les changements       \xb3");
			printf("\n                    \xb3     effectuer sur les voitures ?     \xb3");
			printf("\n                    \xb3          oui(o)    non(n)            \xb3");
			printf("\n                    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
			{
				SauvgardeMatricule(stock_matricul,"matricul.txt");
				sauvgarde(stock_voiture,"type.txt");
			}
			if(tmp==110)
				MessageUrgence("Pas de sauvgarde");
		}while((tmp!=111)&&(tmp!=110));
	}

	if(verif==3)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\n                    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                    \xb3     Sauvgarder les changements       \xb3");
			printf("\n                    \xb3     effectuer sur les clients ?      \xb3");
			printf("\n                    \xb3          oui(o)    non(n)            \xb3");
			printf("\n                    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
			{
				sauvgardeClient(lesclients,"client.txt");
			}
			if(tmp==110)
				MessageUrgence("Pas de sauvgarde");
		}while((tmp!=111)&&(tmp!=110));
	}

}

void MessageUrgence(char *msg)
{
	int i;


	for(i=0;i<2;i++)
	{

		system("cls");
		Sleep(500);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\a\a%s",msg);
		Sleep(500);
	}
}

void  msgSauvCharg(char *msg)
{
	int j;

	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t%s",msg);
	for(j=0;j<=5;j++)
	{
		Sleep(120);
		printf(".");
	}

}
date convertDate()
{
	char *dat_buff;
	int tmp;
	date d;

	dat_buff=(char *)malloc(sizeof (char));
	_strdate(dat_buff);	

	strncpy(dat_buff+2,"0",1);
	strncpy(dat_buff+5,"0",1);

	tmp=atoi(dat_buff);

	d.mm=tmp/1000000;

	d.jj=((tmp%1000000)/1000);

	d.aa=((tmp%1000000)%1000)+2000;

	return d;

}

void A_Propos()
{
	mono();
	printf("\n\t\tLA FACULTE DE SCIENCE IBN ZOHAR ");
	printf("\n\n\n\t\tMini projet  : Gestion location de voiture");
	printf("\n\n\n\t\tRealiser par :RACHID IDBLAID");
	printf("\n\n\n\t\tEncadrer par :\t***Mr.BELQZIZ ***");
	printf("\n\n\n\n\t\t\tAnnee universitaire   2019/2020");
	printf("\n\n");
	system("pause");
}

void Statistique(liste typ,liste_client clt,listeMatricul mat,ListeContrat crt)
{
	int NBtyp=0,NBmat=0,NBcrt=0,NBclt=0,total=0,NBvoit=0,NBvoitl=0,cout=0;

	liste l;
	liste_client client;
	ListeContrat contrat;
	listeMatricul matricul;


	system("cls");

	mono();

	l=(liste)malloc(sizeof (liste));


	l=typ;

	while(l!=NULL)
	{
		NBtyp++;
		l=l->suivant;
	}

	matricul=(listeMatricul)malloc(sizeof (listeMatricul));
	matricul=mat;

	while(matricul!=NULL)
	{
		NBvoit++;
		if(strcmp(&matricul->mat.stats,"l")==0)
			NBvoitl++;
		matricul=matricul->suivant;
	}


	client=(liste_client)malloc(sizeof (liste_client));

	client=RetourTete(clt);
	while(client!=NULL)
	{
		NBclt++;
		client=client->suivant;
	}


	contrat=(ListeContrat)malloc(sizeof (ListeContrat));

	contrat=crt;

	while(contrat!=NULL)
	{
		NBcrt++;
		cout+=contrat->cont.cout;
		contrat=contrat->suivant;
	}



	printf("\n\n\n \xda");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	printf("\xbf\n");

	printf(" \xb3         \xb3");
	printf("    TYPE   \xb3");
	printf("  VOITURE  \xb3");
	printf("  CONTRAT  \xb3");
	printf("   CLIENT  \xb3");
	printf("  COUT LOCATION  \xb3");

	printf("\n \xc3");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc5");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	printf("\xb4\n");

	printf(" \xb3  TOTALE \xb3");
	printf("   %3.0d     \xb3",NBtyp);
	printf("   %3.0d     \xb3",NBvoit);
	printf("   %3.0d     \xb3",NBcrt);
	printf("   %3.0d     \xb3",NBclt);
	printf("    %7.0d      \xb3",cout);

	printf("\n \xc0");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1");
	printf("\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	printf("\xd9\n");
	printf("\n\n");
	system("pause");
}

int ConditionLocation(client cl)
{
	int tmp;
	int aa,mm,jj;

	if(cl.age>=25)
	{
		tmp=cl.date_permi;

		jj=tmp/1000000;
		mm=((tmp%1000000)/10000);
		aa=((tmp%1000000)%10000);

		if((convertDate().aa+2000)-aa>=2)
			return 0;
	}

	return 1;

}

ListeContrat saisieContrat(cellule_client *person,listeMatricul l)
{
	CelluleContrat *cel;
	Matricul *mat;
	int verif=0;
	char typ[5];

	if(ConditionLocation(person->person)!=0)
		return NULL;

	mono();

	mat=(Matricul *)malloc(sizeof (Matricul));
	cel=(CelluleContrat *)malloc(sizeof (CelluleContrat));

	strcpy(cel->cont.nom,person->person.nom);
	strcpy(cel->cont.pnom,person->person.prenom);

	cel->cont.num=generationCode();

	printf("\n\tNumero contrat : %.0f",cel->cont.num);

	do
	{
		if(verif==3)
			goto END_SAISIE;

		printf("\n\n\tType Voiture louee     :  ");
		scanf("%s",&typ);
		mat=RechercheVoitureLibre(l,typ);
		if(mat==NULL)
		{
			printf("\n\t\tPas de voiture disponible");
			verif++;
		}

	}while(mat==NULL);

	printf("\n\tVoiture disponible : %i TUN %i",mat->mat.matricule/10000,mat->mat.matricule%10000);
	cel->cont.voit_loue=mat->mat.matricule;
	do
	{
		printf("\n\tType de location (km/jr) :  ");
		scanf("%s",&cel->cont.type);
	} while((strcmp(cel->cont.type,"km")!=0)&&(strcmp(cel->cont.type,"jr")!=0));

	if(strcmp(cel->cont.type,"km")==0)
	{
		cel->cont.debu=mat->mat.kilometrage;
		printf("\n\t\tKilometrage actuel du vehicule  :  %d",cel->cont.debu);
		cel->cont.fin=0;
	}
	else
	{
		printf("\n\tDate du debut    :  ");
		scanf("%d",&cel->cont.debu);

		printf("\n\tDate retour      :  ");
		scanf("%d",&cel->cont.fin);
	}

	printf("\n\tAgence de location   :  ");
	scanf("%s",&cel->cont.agencDepar);

	printf("\n\t\tLes options......");

	do
	{
		printf("\n\t2eme conducteur (o/n) :");
		scanf("%s",&cel->cont.supcond);
	} while((cel->cont.supcond!='o')&&(cel->cont.supcond!='n'));

	do
	{
		printf("\n\tLivraison  (o/n) :  ");
		scanf("%s",&cel->cont.liv);
	}while((cel->cont.liv!='o')&&(cel->cont.liv!='n'));

	do
	{
		printf("\n\tSiege bebe (o/n) :  ");
		scanf("%s",&cel->cont.bebe);
	} while((cel->cont.bebe!='o')&&(cel->cont.bebe!='n'));


	do
	{
		printf("\n\n\t\tValider location oui(o) / non(n)");
		verif=getch();
	}while((verif!=111)&&(verif!=110));
	if(verif==110)
		return NULL;

	strcpy(cel->cont.agencRetour,"TMP");

	cel->cont.cout=0;

	person->person.ctr=cel->cont.num;

	mat->mat.stats='l';		

	return cel;

	END_SAISIE :			
	MessageUrgence("Contrat Annule");
	return NULL;

}

ListeContrat RechercheContrat(ListeContrat l)
{
	ListeContrat parc;
	int mat;
	char nom[20],pnom[20];

	parc=(ListeContrat)malloc(sizeof (ListeContrat));

	printf("\n\tMatricul voiture louee   :  ");
	scanf("%d",&mat);
	printf("\n\tNom      :  ");
	scanf("%s",&nom);
	printf("\n\tPrenom   :  ");
	scanf("%s",&pnom);

	parc=l;
	while(parc!=NULL)
	{
		if(parc->cont.voit_loue==mat)
			if(strcmp(parc->cont.nom,nom)==0)
				if(strcmp(parc->cont.pnom,pnom)==0)
					return parc;

		parc=parc->suivant;

	}

	return NULL;

}

void RetourContrat(ListeContrat lcr,listeMatricul lm,liste l)
{
	ListeContrat crt;
	listeMatricul mat;
	liste typ;

	int supcond=20;
	int bebe =15;
	int livraison =20;

	crt=(ListeContrat)malloc(sizeof (ListeContrat));
	mat=(listeMatricul)malloc(sizeof (listeMatricul));
	typ=(liste)malloc(sizeof (liste));

	mono();

	crt=RechercheContrat(lcr);

	if(crt==NULL)
		MessageUrgence("Contrat non-trouve");
	else
	{
		crt->cont.cout=0;
		mat=rechecherMatricul(lm,crt->cont.voit_loue);
		typ=RechercheTypeVoiture(l,mat->mat.type);

		printf("\n\tContrat numero   :  %.0f",crt->cont.num);

		printf("\n\tAgence de retour   :  ");
		scanf("%s",&crt->cont.agencRetour);

		if(strcmp(crt->cont.type,"km")==0)
		{
			printf("\n\tKilometrage retour  :  ");
			scanf("%d",&crt->cont.fin);
			 mat->mat.kilometrage=crt->cont.fin;
		}
		else
		{
			printf("\n\tDuree (jour)  :  ");
			scanf("%d",&crt->cont.fin);
			printf("\n\tKilometrage retour  :  ");
			scanf("%d",&mat->mat.kilometrage);
		}

		if(crt->cont.bebe=='o')
			crt->cont.cout+=bebe;
		if(crt->cont.liv=='o')
			crt->cont.cout+=livraison;
		if(crt->cont.supcond=='o')
			crt->cont.cout+=supcond;

		if(strcmp(crt->cont.type,"km")==0)
			crt->cont.cout+=(crt->cont.fin-crt->cont.debu)*typ->voit.prixKilo;
		else
			crt->cont.cout+=crt->cont.fin*typ->voit.prixJour;

		printf("\n\tCout   :  %d\n\n",crt->cont.cout);

		strcpy(&mat->mat.stats,"n");

	}


	system("pause");
}


void AfficheContrat(contrat crt)
{
	mono();

	printf("\n\tN\xf8 du contrat  :  %.0f",crt.num);

	printf("\n\n\tAgence de location :  %s",crt.agencDepar);
	printf("\t\tAgence de retour   :  %s",crt.agencRetour);

	printf("\n\n\tNom locataire      :  %s",crt.nom);
	printf("\t\tType de location   :  %s",crt.type);

	printf("\n\n\tPrenom             :  %s",crt.pnom);
	printf("\t\tVoiture loue       :  %dMAR%d",crt.voit_loue/10000,crt.voit_loue%10000);
	printf("\n\n\tDebut              :  %d",crt.debu);
	printf("\t\tFin                :  %d",crt.fin);

	printf("\n\n\tLes options...");
	printf("\n\n\tLivraison  : %c\t\tSup.conducteur  : %c\t\tSiege beb\x82  : %c",crt.liv,crt.supcond,crt.bebe);

	printf("\n\n\tCout location    :   %d TTC",crt.cout);

	printf("\n\n");

	system("pause");

}



ListeContrat SupprimerContrat(ListeContrat l,CelluleContrat *supp)
{
	ListeContrat parc;			



	if(supp==l)		
	{
		l=l->suivant;
	
	}

	parc=(CelluleContrat *)malloc(sizeof (CelluleContrat));	

	parc=l;
	while((parc!=NULL)&&(parc->suivant!=supp))
		parc=parc->suivant;

	if(parc->suivant==supp)
	{
		parc->suivant=supp->suivant;
	
	}

	return l;

}


ListeContrat ModifierContrat(ListeContrat l,listeMatricul m)
{
	ListeContrat rech;
	listeMatricul mat;
	contrat crt;
	int verif=0;


	if(l==NULL)
	{
		MessageUrgence("Pas de contrat disponible");
		return l;
	}

	rech=(ListeContrat)malloc(sizeof (ListeContrat));

	rech=RechercheContrat(l);

	if(rech==NULL)
	{
		MessageUrgence("Contrat non-trouve");
		return l;
	}

	mat=(listeMatricul)malloc(sizeof (listeMatricul));

	mat=rechecherMatricul(m,rech->cont.voit_loue);
	strcpy(&mat->mat.stats,"n");


	strcpy(crt.nom,rech->cont.nom);
	strcpy(crt.pnom,rech->cont.pnom);
	crt.num=rech->cont.num;
	do
	{
		if(verif==2)
			goto END_SAISIE;

		printf("\n\n\tVoiture louee     :  ");
		scanf("%d",&crt.voit_loue);
		mat=rechecherMatricul(m,crt.voit_loue);
		if((mat->mat.stats=='l')&&(mat!=NULL))
		{
			printf("\n\t\t\tVoiture louee");
			verif++;
		}

	}while((mat!=NULL)&&(mat->mat.stats!='n'));

	do
	{
		printf("\n\tType de location  :  ");
		scanf("%s",&crt.type);
	} while((strcmp(crt.type,"km")!=0)&&(strcmp(crt.type,"jr")!=0));

	if(strcmp(crt.type,"km")==0)
	{
		crt.debu=mat->mat.kilometrage;
		printf("\n\t\tKilometrage actuel du vehicule  :  %d",crt.debu);
	}
	else
	{
		printf("\n\tDate du debut    :  ");
		scanf("%d",&crt.debu);

		printf("\n\tDate retour      :  ");
		scanf("%d",&crt.fin);
	}

	printf("\n\tAgence de location   :  ");
	scanf("%s",&crt.agencDepar);

	printf("\n\t\tLes options......");

	do
	{
		printf("\n\t2eme conducteur :  ");
		scanf("%s",&crt.supcond);
	} while((crt.supcond!='o')&&(crt.supcond!='n'));

	do
	{
		printf("\n\tSiege bebe      :  ");
		scanf("%s",&crt.bebe);
	} while((crt.bebe!='o')&&(crt.bebe!='n'));

	do
	{
		printf("\n\tLivraison       :  ");
		scanf("%s",&crt.liv);
	}while((crt.liv!='o')&&(crt.liv!='n'));

	do
	{
		printf("\n\n\t\tValider location oui(o) / non(n)");
		verif=getch();
	}while((verif!=111)&&(verif!=110));
	if(verif==110)
		return l;			

	strcpy(crt.agencRetour,rech->cont.agencRetour);

	crt.cout=0;

	mat->mat.stats='l';
	rech->cont=crt;

	MessageUrgence("Contrat modifie");
	return l;

END_SAISIE:
	MessageUrgence("Modification annule");
	return l;

}


float generationCode()
{
	char *dat_buff;
	int jj,mm,aa,tmp2,tmp;
	float code;

	dat_buff=(char *)malloc(sizeof (char));
	_strdate(dat_buff);

	strncpy(dat_buff+2,"0",1);
	strncpy(dat_buff+5,"0",1);
	tmp=atoi(dat_buff);///************

	mm=tmp/1000000;
	jj=((tmp%1000000)/1000);
	aa=((tmp%1000000)%1000);
	tmp=jj*10000+mm*100+aa;

	_strtime(dat_buff);
	strncpy(dat_buff+2,"0",1);
	strncpy(dat_buff+5,"0",1);
	tmp2=atoi(dat_buff);

	jj=tmp2/1000000;
	mm=((tmp2%1000000)/1000);
	aa=((tmp2%1000000)%1000);
	tmp2=(jj*10000+mm*100+aa)/100;

	code=(float)tmp*10000+tmp2;

	return code;
}


void mono()
{

	system("cls");
	system("color B0");
	char tmpbuf[128],datebuf[128];

    _strtime( tmpbuf );

    _strdate( datebuf );

	printf("\xc9");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");

	printf("\xbb");

	printf("\n\xba %s \xba		      \xba Location voiture \xba 		   \xba %s \xba\n",tmpbuf,datebuf);

	printf("\xc8");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\xbc");

	printf("\n\n");

}

int MenuPrincipal()
{
	int choix;

	mono();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principale \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Location..............................1   \xba");
	printf("\n               \xba    Gestion voitures......................2   \xba");
	printf("\n               \xba    Gestion clients.......................3   \xba");
	printf("\n               \xba    Statistique...........................4   \xba");
	printf("\n               \xba    A propos..............................8   \xba");
	printf("\n               \xba    Quitter...............................9   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

	scanf("%d",&choix);

	return choix;
}

int MenuLocation()
{
	int choix;

	mono();

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Location voiture\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n   \xba                                              \xba");
	printf("\n  \xba    Visualiser contrat....................1   \xba");
	printf("\n   \xba    louer  voiture........................2   \xba");
	printf("\n    \xba    retourner voiture.....................3   \xba");
	printf("\n    \xba    Modifier contrat......................4   \xba");
	printf("\n    \xba    Supprimer contrat.....................5   \xba");
	printf("\n     \xba    Retour................................9   \xba");
	printf("\n    \xba                                              \xba");
	printf("\n  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");


	choix=getch();
	putch(choix);
	Sleep(120);

	return choix;
}

int MenuGestionVoiture()
{
	int choix;

	mono();

	printf("\n   \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n    \xb3 Gestion voiture \xb3");
	printf("\n    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n    \xba                                              \xba");
	printf("\n    \xba    Visualiser voiture....................1   \xba");
	printf("\n               \xba    Ajouter voiture.......................2   \xba");
	printf("\n   \xba    Modifier voiture......................3   \xba");
	printf("\n   \xba    Supprimer voiture.....................4   \xba");
	printf("\n    \xba    Aide..................................5   \xba");
	printf("\n     \xba    Retour................................9   \xba");
	printf("\n     \xba                                              \xba");
	printf("\n     \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");


	choix=getch();
	putch(choix);
	Sleep(120);

	return choix;
}

int MenuGestionClient()
{
	int choix;

	mono();

	printf("\n    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n    \xb3 Gestion client  \xb3");
	printf("\n    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n   \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n  \xba                                              \xba");
	printf("\n   \xba    Visualiser client.....................1   \xba");
	printf("\n    \xba    Modifier client.......................2   \xba");
	printf("\n   \xba    Supprimer client......................3   \xba");
	printf("\n    \xba    Aide..................................4   \xba");
	printf("\n      \xba    Retour................................9   \xba");
	printf("\n     \xba                                              \xba");
	printf("\n     \xba                                              \xba");
	printf("\n   \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");


	choix=getch();
	putch(choix);
	Sleep(120);

	return choix;
}

int ListeMatriculVide(listeMatricul l)
{
	if(l==NULL)
		return 0;
	else
		return 1;
}

listeMatricul insererVoiture(listeMatricul l,Matricul *m)
{
	if(ListeMatriculVide(l)==0)
		return m;
	else
		m->suivant=l;

	return m;
}

listeMatricul rechecherMatricul(listeMatricul l,int m)
{
	Matricul *parc;

	if(l!=NULL)
	{
		parc=l;
		while(parc!=NULL)
		{
			if(parc->mat.matricule==m)
				return parc;
			parc=parc->suivant;
		}
	}

	return NULL;
}

listeMatricul RechercheVoitureLibre(listeMatricul lm, char *typ)
{

	if(lm==NULL)
		return NULL;
	if((strcmp(&lm->mat.stats,"n")==0) && (strcmp(lm->mat.type,typ)==0))
		return lm;
	else return RechercheVoitureLibre(lm->suivant,typ);
}

listeMatricul supprimerMatricul(listeMatricul l)
{
	Matricul *parc,*m;
	int mat;

	if(l==NULL)
	{
		MessageUrgence("Pas de voiture a supprimer");
		return l;
	}

	do
	{
		printf("\n\tMatricule :  ");
		scanf("%d",&mat);
	}while((mat<=9999999)&&(mat>=10000)&&(mat==0));
	if(mat!=0)
	{
		m=rechecherMatricul(l,mat);

		if(m!=NULL)
		{
			if(l==m)
			{
				l=l->suivant;
//				free(m);
				MessageUrgence("Voiture supprimer");
				return l;
			}
			parc=l;
			while((parc->suivant!=m)&&(parc!=NULL))
				parc=parc->suivant;

			if(parc->suivant==m)
			{
				parc->suivant=m->suivant;
//				free(m);
				MessageUrgence("Voiture supprimer");

			}
			else
				MessageUrgence("Voiture non trouvee");
		}
	}
	return l;


}


int ListeVide(liste l)
{
	if(l==NULL)
		return 0;
	else
		return 1;

}

liste inserer_en_fin(liste l,cellule *elt)
{
	cellule *p;

	p=(cellule *)malloc(sizeof (cellule));

	if (ListeVide(l)==0)
		return elt;

	p=l;
	while(p->suivant!=NULL)
	{
		p=p->suivant;
	}
	p->suivant=elt;
	return l;
}


liste SupprimerPosition(liste l,cellule *supp)
{
	cellule *tmp;
	tmp=l;
	while((tmp->suivant!=supp)&&(tmp!=NULL))
		tmp=tmp->suivant;

	if(tmp->suivant==supp)
	{
		tmp->suivant=supp->suivant;
		free(supp);
	}

	return l;
}

liste RechercheTypeVoiture(liste l,char rech[3])
{
	liste tmp;


	tmp=(cellule *)malloc(sizeof (cellule));

	tmp=l;


	if(tmp==NULL)
		return NULL;

	if(strcmp(tmp->voit.identit,rech)==0)
		return tmp;
	else
		return RechercheTypeVoiture(tmp->suivant,rech);

}

liste SaisieTypeVoiture(liste l)
{


	cellule *voit_final;
	voiture voit;

	mono();

	voit_final=(cellule *)malloc(sizeof (cellule));

	printf("\n\n\tSaisie d'un type de voiture......\n");

	printf("\n\tMarque        :  ");
	scanf("%s",&voit.marque);

	printf("\tNom           :  ");
	scanf("%s",&voit.nom);


	printf("\n\tCouleur       :  ");
	scanf("%s",&voit.couleur);

	printf("\n\tNb de place :  ");
	scanf("%d",&voit.nbplace);

	printf("\n\tTarif par Km (millime)  :  ");
	scanf("%d",&voit.prixKilo);

	printf("\n\tTarif par jour (millime):  ");
	scanf("%d",&voit.prixJour);

	do
	{
		printf("\n\tIdentificateur    :  ");
		scanf("%s",&voit.identit);
	}while(RechercheTypeVoiture(l,voit.identit)!=NULL);


	voit_final->voit=voit;
	voit_final->suivant=NULL;


	return voit_final;

}

listeMatricul saisieMatricul(listeMatricul l1,liste l)
{
	Matricul *m;


	mono();

	m=(Matricul *)malloc(sizeof (Matricul))
	;

	if(ListeVide(l)==1)
	{	do
		{
			printf("\n\tType      :  ");
			scanf("%s",&m->mat.type);
		}while((RechercheTypeVoiture(l,m->mat.type)==NULL)&&(strcmp(m->mat.type,"exit")));

		if(strcmp(m->mat.type,"exit")!=0)
		{
			do
			{
				do
				{
					printf("\n\tMatricule :  ");
					scanf("%d",&m->mat.matricule);
				}while((m->mat.matricule>9999999)||(m->mat.matricule<10000));
			}while((rechecherMatricul(l1,m->mat.matricule)==NULL)&&(m->mat.matricule==0));

			if(rechecherMatricul(l1,m->mat.matricule)!=NULL)
			{
				MessageUrgence("Matricul existant");
				goto FIN;
			}

			printf("\n\tKilometrage   :  ");
			scanf("%d",&m->mat.kilometrage);

			strcpy(&m->mat.stats,"n");
		}
		else
			return NULL;

	}
	else
	{
		MessageUrgence("Pas de type disponible");
		return NULL;
	}
	m->suivant=NULL;
	return m;

FIN : return NULL;

}

liste ModifierTypeVoiture(liste l)
{
	liste modif;
	cellule *v_modif;
	char rech[3];

	printf("\n\tDonnee identifiant du type   :  ");
	scanf("%s",&rech);

	modif=RechercheTypeVoiture(l,rech);

	if(ListeVide(modif)==1)
	{
		printf("\n\nRe-saisie de la voiture....");
		v_modif=SaisieTypeVoiture(l);
		modif->voit=v_modif->voit;
	}
	else
	MessageUrgence("Voiture non trouvee");

	return l;
}

liste SupprimerVoiture(liste l)
{
	liste supp;
	char rech[3];

	if(ListeVide(l)==0)
		MessageUrgence("Suppression impossible\n\t\t\t\tPas de voiture en stock");
	else
	{
		printf("Donner identifiant type :  ");
		scanf("%s",&rech);

		supp=RechercheTypeVoiture(l,rech);

		if(supp==NULL)			//Voiture non trouver
			MessageUrgence("Voiture non trouver");
		else
		{
			if(l==supp)
			{
				l=l->suivant;
				free(supp);
			}
			else
				l=SupprimerPosition(l,supp);
			MessageUrgence("Voiture supprimer");
		}
	}

	return l;
}


void AfficheType(voiture voit)
{
	mono();

	printf("\tIdentifiant   :  %s",voit.identit);
	printf("\n\nMarque          :  %s",voit.marque);
	printf("\nNom             :  %s",voit.nom);
	printf("\nNb place        :  %d",voit.nbplace);
	printf("\nCouleur         :  %s",voit.couleur);


	printf("\nTarif par jour  :  %d",voit.prixJour);
	printf("\nTarif par Km    :  %d",voit.prixKilo);


	printf("\n\n");
	system("pause");

}


void AfficheVoiture(matriculVoiture mt)
{
	mono();

	printf("\n\nType            :  %s",mt.type);
	printf("\n\nMatricul        :  %d MAR %d",mt.matricule/10000,mt.matricule%10000);
	printf("\n\nKilometrage     :  %d",mt.kilometrage);

	if(mt.stats=='l')
		printf("\n\nStatut          :  Louee");
	if(mt.stats=='n')
		printf("\n\nStatut          :  Non-louee");

	printf("\n\n");
	system("pause");

}


