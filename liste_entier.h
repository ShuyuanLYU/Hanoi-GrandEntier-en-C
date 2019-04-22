#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Liste *liste ;

struct Liste
{
  int premier ;
  liste suivant ;
} ;


liste l_vide () ;
liste cons (int x, liste L) ;
int est_vide (liste L) ;
int prem (liste L) ;
liste reste (liste L) ;
unsigned int longueurR (liste L);
// void liberer_liste (liste L) ;
// void ecrire_prem (int x, liste L) ;
// void ecrire_reste (liste R, liste L) ;