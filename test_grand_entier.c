#include "grands_entiers.c"

#include <stdlib.h>


void question2 ()
{
    printf("Test Q2: afficher_grand_entier\n");
    liste L = cons(5, cons(9, cons(6, cons(8, cons(0, cons(0, l_vide()))))));
    afficher_grand_entier(L);
    printf("\n\n");
}

void question3()
{
    printf("Test Q3: succ\n");
    liste L = cons(9, cons(9, cons(6, cons(8, cons(0, cons(0, l_vide()))))));
    printf("chiffre origin:");
    afficher_grand_entier(L);
    printf("\nchiffre succ:");
    afficher_grand_entier(succ(L));
    printf("\n\n");
}

void question4()
{
    printf("Test Q4: entier vers grand entier\n");
    printf("entier: 12345\ngrand entier:");
    afficher_grand_entier(entier_vers_grand_entier(12345));
    printf("\n\n");
}

void question5()
{
    printf("Test Q5: grand entier vers entier\n");
    printf("grand entier:");
    liste L = cons(9, cons(9, cons(6, cons(8, cons(0, cons(0, l_vide()))))));
    afficher_grand_entier(L);
    printf("\nentier: %d", grand_entier_vers_entier(L));
    printf("\n\n");
}

void question6()
{
    printf("Test Q6: somme\n");
    printf("grand entier1:");
    liste L1 = cons(9, cons(3, cons(6, cons(8, cons(0, cons(0, l_vide()))))));
    liste L2 = cons(0, cons(9, cons(7, cons(4, cons(0, cons(0, l_vide()))))));
    afficher_grand_entier(L1);
    printf("\ngrand entier2:");
    afficher_grand_entier(L2);
    printf("\nsomme:");
    afficher_grand_entier(somme(L1, L2));
    printf("\n\n");
}

void question7()
{
    printf("Test Q7:\n");
    printf("grand entier1:");
    liste L1 = cons(9, cons(3, cons(6, cons(8, cons(0, cons(0, l_vide()))))));
    liste L2 = cons(0, cons(9, cons(7, cons(4, cons(0, cons(0, l_vide()))))));
    afficher_grand_entier(L1);
    printf("\ngrand entier2:");
    afficher_grand_entier(L2);
    printf("\ndiff:");
    afficher_grand_entier(diff(L1, L2));
    printf("\n\n");
}

void question8()
{
    printf("Test Q8:\n");
    printf("grand entier1:");
    liste L1 = cons(0, cons(2, cons(0, l_vide())));
    liste L2 = cons(0, cons(8, cons(0, l_vide())));
    afficher_grand_entier(L1);
    printf("\ngrand entier2:");
    afficher_grand_entier(L2);
    printf("\nproduit:");
    afficher_grand_entier(produitR(L1, L2));
    printf("\n\n");
}
void question9()
{
    printf("Test Q9:\n");
    printf("grand entier:");
    liste L1 = cons(5, cons(0, l_vide()));
    afficher_grand_entier(L1);;
    printf("\nfactoriel:");
    afficher_grand_entier(factoriel(L1));
    printf("\n\n");
}

int main (int argc, char** argv)
{
    question2();
    question3();
    question4();
    question5();
    question6();
    question7();
    question8();
    question9();
    return 0;
} 