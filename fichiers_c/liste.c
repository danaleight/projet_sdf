#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

Cellule *creeListe(int valeur, Liste L)
{
	Liste p = malloc(sizeof(Liste));
	p->valeur = valeur;
	p->suivant = L;
	return p;
}

int estVide(Liste L)
{
	if(L == NULL)
		return 1;
	else
		return 0;
}

int tete(Liste L)
{
	if(estVide(L) != 1)
		return L->valeur;
}

Cellule *queue(Liste L)
{
	if(estVide(L) != 1)
		return L->suivant;
}

void afficherListe(Liste L)
{
	while(!estVide(L))
	{
		printf("%d ", tete(L));
		L = queue(L);
	}
	printf("\n");
}

Cellule *insererFin(Liste L)
{
	Liste p = L;
	int choix = -1;
	printf("Quel chiffre voulez-vous ajouter ? ");
	scanf("%d", &choix);
	p->valeur = choix;
	
	do
	{
		printf("Quel chiffre voulez-vous ajouter ? ");
		scanf("%d", &choix);
		if(choix >= 0 && choix <= 9)
		{
			p->suivant = creeListe(choix, NULL);
			p = queue(p);
		}
	}while(choix >= 0 && choix <= 9);
	return L;
}

Cellule *plusGrandNombre(Liste L1, Liste L2)
{
	while (tete(L1) == 0) // si les listes commences par des 0
		L1 = queue(L1);
	while (tete(L2) == 0)
		L2 = queue(L2);

	Liste cl1 = L1;
	Liste cl2 = L2;
	
	int max = -1;
	while (!estVide(cl1) && !estVide(cl2))
	{
		if (tete(cl1) >= tete(cl2))
			max = 1;
		else
			max = 2;
		
		cl1 = queue(cl1);
		cl2 = queue(cl2);
	}
	
	if (estVide(cl1) && !estVide(cl2))
		return L2;
	else if (!estVide(cl1) && estVide(cl2))
		return L1;
	else
		if (max == 1)
			return L1;
		else 
			return L2;
}