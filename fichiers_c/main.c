#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Cellule A;
	Cellule *liste = &A;
	liste = insererFin(liste);
	afficherListe(liste);
}