#include <iostream>
#include <gmpxx.h>
using namespace std;
void generateQA(mpz_class& q, mpz_class& a){
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	gmp_randseed_ui(state, seed);
	mpz_class temp,t;
	do{
		mpz_urandomb(temp.get_mpz_t(), state, 20);
		mpz_nextprime(q.get_mpz_t(), temp.get_mpz_t());
		q = 2*q+1;
	}while(!mpz_probab_prime_p(q.get_mpz_t(),20));
	bool flag = true;
	do{
		flag = true;
		mpz_urandomm(a.get_mpz_t(), state, q.get_mpz_t());
		temp = (q-1)/2;
		mpz_powm(t.get_mpz_t(),a.get_mpz_t(),temp.get_mpz_t(),q.get_mpz_t());
		if(t==1)flag=false;
		temp = 2;
		mpz_powm(t.get_mpz_t(),a.get_mpz_t(),temp.get_mpz_t(),q.get_mpz_t());
		if(t==1)flag=false;
	}while(!flag);
	cout<<q<<" is the prime number and "<<a<<" is the generator "<<endl;
}

int main(){
	mpz_class q, a, xa, xb, ya, yb, Ka, Kb;
	generateQA(q, a);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	gmp_randseed_ui(state, seed);
	mpz_urandomm(xa.get_mpz_t(), state, q.get_mpz_t());
	mpz_urandomm(xb.get_mpz_t(), state, q.get_mpz_t());
	mpz_powm(ya.get_mpz_t(), a.get_mpz_t(), xa.get_mpz_t(), q.get_mpz_t());
	mpz_powm(yb.get_mpz_t(), a.get_mpz_t(), xb.get_mpz_t(), q.get_mpz_t());
	mpz_powm(Kb.get_mpz_t(), ya.get_mpz_t(), xb.get_mpz_t(), q.get_mpz_t());
	mpz_powm(Ka.get_mpz_t(), yb.get_mpz_t(), xa.get_mpz_t(), q.get_mpz_t());
	cout<<"Keys on both sides: \n";
	cout<<Ka<<endl<<Kb;
}