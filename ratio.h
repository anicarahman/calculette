typedef struct ratio_t  ratio_t;
struct  ratio_t {
  int p, q;
};
#define ratio_signe(p, q) ((p) * (q) < 0 ? -1 : 1)
#define ratio_num(r) ((r).p)
#define ratio_denom(r) ((r).q)
extern int ratio_pgcd(int p, int q);
extern ratio_t ratio_red(ratio_t r);
extern ratio_t ratio_neg(ratio_t r);
extern ratio_t ratio_moins(ratio_t r1, ratio_t r2);
extern ratio_t ratio_plus(ratio_t r1, ratio_t r2);
extern ratio_t ratio_mul(ratio_t r1, ratio_t r2);
extern ratio_t ratio_div(ratio_t r1, ratio_t r2);

