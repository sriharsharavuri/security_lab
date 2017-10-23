#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include <string.h>
using namespace std;

int main(){
  mpz_t q,alpha,random, Ya, Yb, Xa, Xb, numbits, K1, K2;
	mpz_inits(q, alpha, random, Xa, Xb, Ya, Yb, K1, K2, numbits, (mpz_ptr)0);
	/*gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state, time(NULL));
	mpz_urandomb(random, state, 10);
	mpz_nextprime(q, random);*/

	mpz_set_ui(q, 353);
	mpz_set_ui(alpha, 3);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state, time(NULL));
	mpz_sub_ui(numbits, q, 1);

	mpz_urandomm(Xa, state, numbits);
	mpz_urandomm(Xb, state, numbits);
  gmp_printf("XA: %Zd", Xa);
	gmp_printf("\n XB: %Zd", Xb);
	mpz_powm(Ya, alpha, Xa, q);
	mpz_powm(Yb, alpha, Xb, q);
	gmp_printf("\n YA: %Zd", Ya);
	gmp_printf("\n YB: %Zd", Yb);
  mpz_powm(K1, Yb, Xa, q);
	mpz_powm(K2, Ya, Xb, q);
	gmp_printf("\n Key 1: %Zd", K1);
	gmp_printf("\n Key 2: %Zd", K1);
}
