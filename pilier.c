#include "pilier.h"

struct pilier newPilier(unsigned int nombre_disques_max)
{
	struct pilier p;
	p.nombre_disques_max = nombre_disques_max;
	p.tableau = malloc(nombre_disques_max * sizeof(unsigned int));
	for (int i = 0; i < p.nombre_disques_max; i++)
		p.tableau[i] = 0;
	return p;
}

unsigned int hauteur(struct pilier X)
{
	unsigned int h = 0;
	for (unsigned int i = 0; i < X.nombre_disques_max; i++)
		if (X.tableau[i] != 0)
			h++;
	return h;
}

unsigned int est_vide(struct pilier X)
{
	return hauteur(X) == 0;
}

unsigned int est_plein(struct pilier X)
{
	return hauteur(X) == X.nombre_disques_max;
}

unsigned int disque_au_sommet(struct pilier X)
{
	unsigned int h = hauteur(X);
	return (h == 0 ? 0 : X.tableau[h - 1]);
}

void afficher_socle()
{
	printf("_____________________");
}

void affiche_anneau(unsigned int taille)
{
	for (int i = 0; i < 10 - taille; i++)
		printf(" ");
	for (int i = 0; i < taille * 2; i++)
		printf("=");
	printf("=");
	for (int i = 0; i < 10 - taille; i++)
		printf(" ");
}

void afficher_central(struct pilier X)
{
	printf("          |          \n");
	for (int i = X.nombre_disques_max - 1; i >= 0; i--)
	{
		if (X.tableau[i] == 0)
			printf("          |          \n");
		else
		{
			affiche_anneau(X.tableau[i]);
			printf("\n");
		}
		printf("          |          \n");
	}
}

void afficher_pilier(struct pilier X)
{
	afficher_central(X);
	afficher_socle();
	printf("\n");
}

void ajouter_disque_au_sommet(struct pilier X, int taille)
{
	unsigned int h = hauteur(X);
	X.tableau[h] = taille;
}

struct pilier copier_pilier(struct pilier X)
{
	struct pilier new_p = newPilier(X.nombre_disques_max);
	for (int i = 0; i < hauteur(X); i++)
		ajouter_disque_au_sommet(new_p, X.tableau[i]);
	return new_p;
}

void pilier_A_initial(struct pilier X, int taille)
{
	for (int i = taille; i >= 0; i--)
		ajouter_disque_au_sommet(X, i);
}

void affiche_colonne()
{
	printf("          |          ");
}

void affiche_disque(int taille)
{
	if (taille == 0)
		printf("          |          ");
	else
		affiche_anneau(taille);
}

struct tours newTours(unsigned int tailleA, unsigned int tailleB, unsigned int tailleC)
{
	struct tours t;
	t.pilier_A = newPilier(tailleA);
	t.pilier_B = newPilier(tailleB);
	t.pilier_C = newPilier(tailleC);
	return t;
}
void afficher_tours(struct tours t)
{
	printf("\n");
	affiche_colonne();
	affiche_colonne();
	affiche_colonne();
	printf("\n");

	for (int i = t.pilier_A.nombre_disques_max - 1; i >= 0; i--)
	{
		affiche_disque(t.pilier_A.tableau[i]);
		affiche_disque(t.pilier_B.tableau[i]);
		affiche_disque(t.pilier_C.tableau[i]);
		printf("\n");
		affiche_colonne();
		affiche_colonne();
		affiche_colonne();
		printf("\n");
	}
	afficher_socle();
	afficher_socle();
	afficher_socle();
	printf("\n");
}

void etat_initial(struct tours t, int taille)
{
	pilier_A_initial(t.pilier_A, taille);
}

struct tours copier_tours(struct tours t)
{
	struct tours t2 = newTours(t.pilier_A.nombre_disques_max, t.pilier_B.nombre_disques_max, t.pilier_C.nombre_disques_max);
	t2.pilier_A = copier_pilier(t.pilier_A);
	t2.pilier_B = copier_pilier(t.pilier_B);
	t2.pilier_C = copier_pilier(t.pilier_C);
	return t2;
}

int est_final(struct tours t)
{
	if (!(est_vide(t.pilier_A) && est_vide(t.pilier_B) && est_plein(t.pilier_C)))
		return 0;
	else
	{
		for (int i = 0; i < t.pilier_C.nombre_disques_max; i++)
			if (t.pilier_C.tableau[i] != t.pilier_C.nombre_disques_max - i)
				return 0;
		return 1;
	}
}

void lance_jeu(unsigned int taille)
{
	struct tours jeu = newTours(taille, taille, taille);
	pilier_A_initial(jeu.pilier_A, taille);
	afficher_tours(jeu);
	if(jouer_par_machine()){
		machine_jouer(jeu, hauteur_char(jeu, 'a'), 'a', 'c');
		afficher_tours(jeu);
		printf(">>> Voici des étapes joués par la machines !\n");
	}
	else
	{
		afficher_tours(jeu);
		char *choix = obtenir_choix(jeu);
		while (!interrompre_par_joueur(choix))
		{
			deplacer_un(jeu, choix[0], choix[1]);
			afficher_tours(jeu);
			if (est_final(jeu))
				break;
			choix = obtenir_choix(jeu);
		}

		if (est_final(jeu))
			printf(">>> Félicitation !\n");
		else
			printf(">>> Bye !");
	}
	
	
}

char *obtenir_choix(struct tours jeu)
{
	char choix[100];
	printf(">>> Tapez votre choix :  ");
	scanf("%s", choix);
	while ((!verifier_choix(choix) || !verifier_action(choix, jeu)) && !interrompre_par_joueur(choix))
	{
		printf(">>> Mauvais choix !\n");
		printf(">>> Tapez un autre choix :  ");
		scanf("%s", choix);
	};
	return choix;
}

int verifier_action(char *choix, struct tours jeu)
{
	int pilier_1 = 0;
	int pilier_2 = 0;
	unsigned int disque = -1;
	switch (choix[0])
	{
	case 'A':
	case 'a':
		if (!est_vide(jeu.pilier_A))
			disque = disque_au_sommet(jeu.pilier_A);
		break;
	case 'B':
	case 'b':
		if (!est_vide(jeu.pilier_B))
			disque = disque_au_sommet(jeu.pilier_B);
		break;
	case 'C':
	case 'c':
		if (!est_vide(jeu.pilier_C))
			disque = disque_au_sommet(jeu.pilier_C);
		break;
	default:
		break;
	}
	if (disque == -1)
		return 0;
	else
	{
		switch (choix[1])
		{
		case 'A':
		case 'a':
			if (est_vide(jeu.pilier_A))
				return 1;
			else if (est_plein(jeu.pilier_A))
				return 0;
			else
				return disque_au_sommet(jeu.pilier_A) > disque;
			break;
		case 'B':
		case 'b':
			if (est_vide(jeu.pilier_B))
				return 1;
			else if (est_plein(jeu.pilier_B))
				return 0;
			else
				return disque_au_sommet(jeu.pilier_B) > disque;
			break;
		case 'C':
		case 'c':
			if (est_vide(jeu.pilier_C))
				return 1;
			else if (est_plein(jeu.pilier_C))
				return 0;
			else
				return disque_au_sommet(jeu.pilier_C) > disque;
			break;
		default:
			break;
		}
	}
}

int verifier_choix(char *choix)
{
	return ((choix[0] >= 'A' && choix[0] <= 'C') || (choix[0] >= 'a' && choix[0] <= 'c')) && ((choix[1] >= 'A' && choix[1] <= 'C') || (choix[1] >= 'a' && choix[1] <= 'c'));
}

int interrompre_par_joueur(char *choix)
{
	return (choix[0] == 'S') || (choix[0] == 's');
}

void retirer_disque(struct pilier p)
{
	p.tableau[hauteur(p) - 1] = 0;
}

void machine_jouer(struct tours jeu, unsigned int taille, char de, char vers)
{
	if (taille == 1)
		deplacer_un(jeu, de, vers);
	else
	{
		machine_jouer(jeu, taille - 1, de, autre_colonne(de, vers));
		deplacer_un(jeu, de, vers);
		machine_jouer(jeu, taille - 1, autre_colonne(de, vers), vers);
	}
}


void deplacer_un(struct tours jeu, char de, char vers)
{
	int disque;
	switch (de)
	{
	case 'A':
	case 'a':
		disque = disque_au_sommet(jeu.pilier_A);
		retirer_disque(jeu.pilier_A);
		break;
	case 'B':
	case 'b':
		disque = disque_au_sommet(jeu.pilier_B);
		retirer_disque(jeu.pilier_B);
		break;
	case 'C':
	case 'c':
		disque = disque_au_sommet(jeu.pilier_C);
		retirer_disque(jeu.pilier_C);
		break;
	default:
		break;
	}
	switch (vers)
	{
	case 'A':
	case 'a':
		ajouter_disque_au_sommet(jeu.pilier_A, disque);
		break;
	case 'B':
	case 'b':
		ajouter_disque_au_sommet(jeu.pilier_B, disque);
		break;
	case 'C':
	case 'c':
		ajouter_disque_au_sommet(jeu.pilier_C, disque);
		break;
	default:
		break;
	}
	printf("TRACE :  déplacer de %c ves %c\n", de, vers);
}

unsigned int hauteur_char(struct tours jeu, char c)
{
	switch (c)
	{
	case 'A':
	case 'a':
		return hauteur(jeu.pilier_A);
		break;
	case 'B':
	case 'b':
		return hauteur(jeu.pilier_B);
		break;
	case 'C':
	case 'c':
		return hauteur(jeu.pilier_C);
		break;
	default:
		break;
	}
}

char autre_colonne(char de, char vers)
{
	if (de != 'a' && vers != 'a')
		return 'a';
	else if (de != 'b' && vers != 'b')
		return 'b';
	else if (de != 'c' && vers != 'c')
		return 'c';
}

int jouer_par_machine(){
	char choix;
	printf(">>> Jouer par la machine?[Y/N]");
	scanf("%c", &choix);
	if(choix == 'Y' || choix == 'y')
		return 1;
	else
		return 0;
}

