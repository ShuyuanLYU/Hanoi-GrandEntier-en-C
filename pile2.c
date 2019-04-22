/*
 TP2 : Exercice 7
 Auteur : Alexis Kohler
 Date : 14/02/2019
*/

#include <stdio.h>
#include <stdlib.h>

/* Structures */

struct pilier {
  
  unsigned int nombre_disques_max;
  unsigned int tableau[nombre_disques_max];
};

/* Prototypes */

unsigned int hauteur(struct pilier X);
void est_vide(struct pilier X);
void est_plein(struct pilier X);
unsigned int disque_au_sommet(struct pilier X);

/* Fonctions et Procédures */

unsigned int hauteur(struct pilier X){

  unsigned int h;
  
  for(unsigned int i = 0 ; i < X.nombre_disques_max ; i++){
    
    if(X.tableau[i] != 0){
    
      h++;
    }
  }
  
  return h;
}

unsigned int est_vide(struct pilier X){
  
  unsigned int res = 0;
  
  unsigned int v = hauteur(pilier X);

  if(v == 0){
  
    printf("Le pilier est vide");
    
    res = 1;
  }
  
  return res;
}

unsigned int est_plein(struct pilier X){
  
  unsigned int res = 0;

  unsigned int p = hauteur(pilier X);
  
  if(p == X.nombre_disques_max){
  
    printf("Le pilier est plein !");
    
    res = 1;
  }
  
  return res;
}

unsigned int disque_au_sommet(struct pilier X){

  unsigned int haut = hauteur(pilier X);
  
  return (haut == 0 ? 0 : X.tableau[haut-1]);
}

void afficher_pilier(){

  /*
   * 
   * 1) Socle :
   * 
   * ________________________
   * 
   * 
   * 2) Pilier central :
   * 
   * |
   * |
   * |
   * |
   * |
   * |
   * |
   * |
   * | 
   * 
   * 3) Anneau :
   * 
   * ===================
   * 
   * 
   * ex :
   * 
   * 
   * 	       |
   * 	    =======
   * 	       |
   * 	  ===========
   *           |
   *    ===============
   *   __________________
   * 
   * environ 2 '=' de diff pour etre lisible
   * 
   * utiliser de la couleur pour les anneaux
   */
}

void ajouter_disque_au_sommet(unsigned int d, struct pilier X){

  unsigned int h = hauteur(pilier X);
  
  unsigned int verif = est_plein(pilier X);
  
  if(verif == 1){
    
    printf("On ne peut plus ajouter de disque !\n");
  }
}


struct pilier copier_pilier(struct pilier X){

   struct pilier* cp = malloc(sizeof(struct pilier));
   
   cp->nombre_disques_max = X.nombre_disques_max;
   
   for(int i = 0 ; i < cp->nombre_disques_max ; i++){
   
     cp->tableau[i] = X.tableau[i];
   }
   
   return cp;
}



/* Main */



int main(){
 

  return EXIT_SUCCESS;
}

/*Resultat de l'execution :

1)


*/