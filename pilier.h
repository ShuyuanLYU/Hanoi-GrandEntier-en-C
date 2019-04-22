#include <stdio.h>
#include <stdlib.h>
#include<regex.h>

/* Structures */
struct pilier {
  unsigned int nombre_disques_max;
  unsigned int* tableau;
};

// q1.3
unsigned int hauteur(struct pilier X);
unsigned int est_vide(struct pilier X);
unsigned int est_plein(struct pilier X);
unsigned int disque_au_sommet(struct pilier X);
void afficher_socle();
void affiche_anneau(unsigned int taille);
void afficher_central(struct pilier X);
void afficher_pilier(struct pilier X);
void ajouter_disque_au_sommet(struct pilier X, int taille);
struct pilier copier_pilier(struct pilier X);
void pilier_A_initial(struct pilier X, int taille);

// q1.4
struct tours
{
  struct pilier pilier_A;
  struct pilier pilier_B;
  struct pilier pilier_C;
};
struct tours newTours(unsigned int tailleA, unsigned int tailleB, unsigned int tailleC);
void affiche_colonne();
void afficher_tours(struct tours t);
void etat_initial(struct tours t, int taille);
struct tours copier_tours(struct tours t);
int est_final(struct tours t);
// Q2
void lance_jeu(unsigned int taille);
char* obtenir_choix(struct tours jeu);
void retirer_disque(struct pilier p);
int interrompre_par_joueur(char* s);
int verifier_choix(char* choix);
int verifier_action(char *choix, struct tours jeu);
void machine_jouer(struct tours jeu, unsigned int taille, char de, char vers);
void deplacer_un(struct tours jeu, char de, char vers);
char autre_colonne(char de, char vers);
unsigned int hauteur_char(struct tours jeu, char c);
int jouer_par_machine();