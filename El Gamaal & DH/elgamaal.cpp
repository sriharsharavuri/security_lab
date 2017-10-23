#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include <string.h>
using namespace std;

int main(){
  mpz_t q,alpha,random, Ya, Xa, k, K, C1, C2, KA, M, MA, numbits;
	mpz_inits(q, alpha, random, Xa, Ya, k, K, C1, C2, M, MA, KA, numbits, (mpz_ptr)0);
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
  mpz_sub_ui(numbits, q, 2);
  gmp_printf("%Zd \n", numbits);
  // User 1
	mpz_urandomm(Xa, state, numbits);
	gmp_printf("XA: %Zd", Xa);
	mpz_powm(Ya, alpha, Xa, q);
	gmp_printf("\n YA: %Zd", Ya);

  // User 2
  mpz_sub_ui(numbits, q, 1);
  //mpz_sqrt(numbits, numbits);
  mpz_urandomm(k, state, numbits);
  mpz_powm(K, Ya, k, q);
  mpz_powm(C1, alpha, k, q);
  mpz_set_ui(M, 112);
  mpz_mul(C2, K, M);
  mpz_mod(C2, C2, q);

  // Back to User 1
  mpz_powm(KA, C1, Xa, q);
  mpz_invert(MA, KA, q);
  mpz_mul(MA, C2, MA);
  mpz_mod(MA, MA, q);
  gmp_printf("\n Sent Message: %Zd", M);
	gmp_printf("\n Received Message: %Zd", MA);
}
