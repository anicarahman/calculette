#include <stdio.h>
#include<stdlib.h>
#include "pile_r.h"
#define MAX 256



static void infixe2postfixe(char * s, char * d) {
  while(*s) {
    if(*s >= '0' && *s <= '9') {
      do {
        *d++ = *s++;
      }
      while( *s >= '0' && *s <= '9');
      *d++ = ' ';
      if(!*s) break;
    }
    if((*s == ')')  && !vide()){
      *d++ = (char)pop();
      *d++ = ' ';
    }
    else if(*s == '+') push((int) *s);
    else if(*s == '*') push((int) *s);
    else if(*s == '-') push((int) *s);
    else if(*s == '/') push((int) *s);
    s++;
  }
  while(!vide()){
    *d++ = (char)pop(); 
    *d++ = ' ';
  }
  *d = '\0';
}


void extraire_nombres (const char * str) {
  char tmp[256];
  int i, n;
  float RES = 0.0;
  float x = 0.0;
  float y = 0.0;
  ratio_t N;
  ratio_t res;
  ratio_t a;
  ratio_t b;
  while (*str) {
    if (*str >= '0' && *str <= '9') {
      i = 0;
      do {
        tmp[i++] = *str++;
      }
      while (*str >= '0' && *str <= '9');
      tmp[i] = '\0';
      n = atoi(tmp);
      ratio_num(N) = n;
      ratio_denom(N) = 1;
      push_r(N);
      //push(n);
      //printf("push n == %d \n",n);
      //printf("push_r N == p->%d et q->%d \n", N.p, N.q);
    }
    else{
      if (*str == '+') {
        /*ratio_num(a) = pop();
	  ratio_denom(a) = 1;
	  ratio_num(b) = pop();
	  ratio_denom(b) = 1;*/
        a = pop_r();
        b = pop_r();
        //printf("pop ++ a == p->%d et q->%d \n", a.p, a.q);    //verif avant calcul
        //printf("pop ++ b == p->%d et q->%d \n", b.p, b.q);    //verif avant calcul
        res = ratio_plus(b,a);
        push_r(res);
        //push(res.p);
        //printf("push ++ res == p->%d et q->%d \n", res.p, res.q);     ////Push du résultat de l'addition (verif)
      }
      if (*str == '-'){
        /*ratio_num(a) = pop();
	  ratio_denom(a) = 1;
	  ratio_num(b) = pop();
	  ratio_denom(b) = 1;*/
        a = pop_r();
        b = pop_r();
        //printf("pop -- a == p->%d et q->%d \n", a.p, a.q);    //verif avant calcul
        //printf("pop -- b == p->%d et q->%d \n", b.p, b.q);    //verif avant calcul
        res = ratio_moins(b,a);
        push_r(res);
        //push(res.p);
        //printf("push -- res == p->%d et q->%d \n", res.p, res.q);     //Push du résultat de la soustraction (verif)
      }
      if (*str == '/'){
        /*ratio_num(a) = pop();
	  ratio_denom(a) = 1;
	  ratio_num(b) = pop();
	  ratio_denom(b) = 1;*/
        a = pop_r();
        b = pop_r();
        //printf("pop // a == p->%d et q->%d \n", a.p, a.q);    //verif avant calcul
        //printf("pop // b == p->%d et q->%d \n", b.p, b.q);    //verif avant calcul
        res = ratio_div(b,a);
        push_r(res);
        //push(res.p);
        //printf("push // res == p->%d et q->%d \n", res.p, res.q);    //Push du résultat de la division (verif)
      }
      if (*str == '*'){
        /*ratio_num(a) = pop();
	  ratio_denom(a) = 1;
	  ratio_num(b) = pop();
	  ratio_denom(b) = 1;*/
        a = pop_r();
        b = pop_r();
        //printf("pop ** a == p->%d et q->%d \n", a.p, a.q);    //verif avant calcul
        //printf("pop ** b == p->%d et q->%d \n", b.p, b.q);    //verif avant calcul
        res = ratio_mul(b,a);
        push_r(res);
        //push(res.p);
        //printf("push ** res == p->%d et q->%d \n", res.p, res.q);     ////Push du résultat de la multiplication (verif)
      }
      str++;
    }
    str++;
  }
  //*str = '\0';
  x = res.p;
  y = res.q;
  RES = x / y;
  printf("%d / %d = %.3f \n",res.p, res.q, RES);
}



int main(void) {

  char source[MAX], destination[MAX<<1];
  do {
    if(!fgets(source, MAX, stdin)) break;
    infixe2postfixe(source, destination);
    //printf("l’expression infixee : %s\n", source);
    printf("%s\n", destination);
    extraire_nombres(destination);
  } while(1);

  return 0;
}

