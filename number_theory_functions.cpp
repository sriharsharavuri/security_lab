#include <gmpxx.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned long seed;
	mpz_t gcd;
	mpz_inits(gcd, (mpz_ptr)0);
	mpz_class a, b, c, d;
	cin>>a>>b;
	mpz_gcd(c.get_mpz_t(),a.get_mpz_t(),b.get_mpz_t());
	mpz_set(gcd, c.get_mpz_t());
	cout<<"GCD: "<<c<<endl;
	mpz_invert(c.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
	cout<<"Invert: "<<c<<endl;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state, seed);
	//mpz_urandomb(c.get_mpz_t(), state, 10);
	//mpz_urandomb(c.get_mpz_t(), state, 10);
	mpz_gcdext(gcd, c.get_mpz_t(), d.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
	cout<<"Extended GCD coefficients are: ";
	cout<<c<<" "<<d<<endl;
	
}