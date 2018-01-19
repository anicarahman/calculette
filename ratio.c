#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ratio.h"
extern int ratio_pgcd(int p, int q) {
  int t;
  while(q != 0) {
    t = q;
    q = p % q;
    p = t;
  }
  return p;
}
extern ratio_t ratio_red(ratio_t r) {
  int pgcd;
  if(ratio_denom(r) < 0) {
    ratio_denom(r) = - ratio_denom(r);
    ratio_num(r) = - ratio_num(r);
  }
  if(ratio_denom(r) > 1 && ratio_num(r) && (pgcd = ratio_pgcd(abs(ratio_num(r)), ratio_denom(r)))) {
    r.p = ratio_num(r) / pgcd;
    r.q = ratio_denom(r) / pgcd;
  }
  return r;
}
extern ratio_t ratio_neg(ratio_t r) {
  ratio_t n = {-ratio_num(r), ratio_denom(r)};
  return n;
}
extern ratio_t ratio_moins(ratio_t r1, ratio_t r2) {
  ratio_t r = {ratio_num(r1) * ratio_denom(r2) - ratio_num(r2) * ratio_denom(r1), 
	       ratio_denom(r1) * ratio_denom(r2)};
  return ratio_red(r);
}
extern ratio_t ratio_plus(ratio_t r1, ratio_t r2) {
  ratio_t r = {ratio_num(r1) * ratio_denom(r2) + ratio_num(r2) * ratio_denom(r1), 
	       ratio_denom(r1) * ratio_denom(r2)};
  return ratio_red(r);
}
extern ratio_t ratio_mul(ratio_t r1, ratio_t r2) {
  ratio_t r = {ratio_num(r1) * ratio_num(r2), 
	       ratio_denom(r1) * ratio_denom(r2)};
  return ratio_red(r);
}
extern ratio_t ratio_div(ratio_t r1, ratio_t r2) {
  ratio_t r = {ratio_num(r1) * ratio_denom(r2), 
	       ratio_denom(r1) * ratio_num(r2)};
  return ratio_red(r);
}

