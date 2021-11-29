#ifndef __LISTE__H__
#define __LISTE__H__

typedef struct Cellule
{
	int valeur;
	struct Cellule *suivant;
}Cellule, *Liste;

Cellule *creeListe(int valeur, Liste L);
int estVide(Liste L);
int tete(Liste L);
Cellule *queue(Liste L);
void afficherListe(Liste L);

Cellule *insererFin(Liste L);
Cellule *plusGrandNombre(Liste L1, Liste L2);

#endif