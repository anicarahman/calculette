#include <stdlib.h>
#include <assert.h>
#include "pile_r.h"
static ratio_t pile[MAX];
static int haut = 0;
extern void push_r(ratio_t v) { /* Empiler */
  pile[haut++] = v;
}
extern ratio_t pop_r(void) { /* Depiler */
  return pile[--haut];
}
extern int vide_r(void) { /* Tester si la pile est vide */
  return !haut;
}




/* indice indiquant le haut de la pile.*/
static int hautE = -1;
/* tableau static utiliśe pour le stockage de la pile.*/
static int pileE[PILE_MAX];
/*Empiler la valeur v dans la pile.
  param v la valeur à empiler*/
void push(int v) {
  pileE[++hautE] = v;
}
/*d́epiler et renvoyer la valeur de l ́l ́ement en haut de la pile.
  return la valeur en haut de la pile.*/
int pop(void) {
  return pileE[hautE--];
}
/*Indique si la pile est vide.
  return vrai si la pile est vide, faux sinon.*/
int vide(void) {
  return hautE < 0;
}
