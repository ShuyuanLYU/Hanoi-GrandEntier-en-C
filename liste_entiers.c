#include "liste_entier.h"

/* Constructeurs */
liste l_vide ()
{
  return NULL ;
}

liste cons (int x, liste L)
{
  liste M ;
  // Réservation de la place mémoire nécessaire pour une cellule :
  M = malloc (sizeof (*M)) ;
  M->premier = x ; // On peut aussi écrire " M->premier = x ; "
  M->suivant = L ;
  return M ;
}

int est_vide (liste L)
{
  return L == NULL ;
}

int prem (liste L)
{
  if (est_vide (L))
    {
      printf ("Calcul de prem sur liste vide !\n") ;
      exit (0) ;
    }
  return L->premier ;
}

liste reste (liste L)
{
  return L->suivant ;
}

/* OPERATIONS NON PRIMITIVES */
unsigned int longueurR (liste L)
{
    if (est_vide(L))
        return 0 ;
    else if(est_nul(reste(L)))
        return 1;
    else
        return 1 + longueurR (reste (L)) ;
}