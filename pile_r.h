#ifndef _PILE__R_H
#define _PILE__R_H
#define MAX 256
#include "ratio.h"
extern void push_r(ratio_t v);
extern ratio_t pop_r(void);
extern int vide_r(void);
#endif

#ifndef _PILE_H
#define _PILE_H
/* taille de la pile (statique) */
#define PILE_MAX 256
#ifdef __cplusplus
extern "C" {
#endif
  extern void push(int v);
  extern int pop(void);
  extern int vide(void);
#ifdef __cplusplus
}
#endif
#endif
