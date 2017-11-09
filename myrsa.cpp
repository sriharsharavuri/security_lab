#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;
int main(){
	mpz_class p,q, temp, d, e, p1, q1, phin, n;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed;
	gmp_randseed_ui(state, seed);
	mpz_urandomb(temp.get_mpz_t(), state, 30);
	mpz_nextprime(p.get_mpz_t(), temp.get_mpz_t());
	do{
		mpz_urandomb(temp.get_mpz_t(), state, 30);
		mpz_nextprime(q.get_mpz_t(), temp.get_mpz_t());
	}while(p==q);
	n = p*q;
	p1 = p-1;q1=q-1;phin = p1*q1;
	do{
		mpz_urandomm(e.get_mpz_t(), state, phin.get_mpz_t());
		mpz_gcd(temp.get_mpz_t(), e.get_mpz_t(), phin.get_mpz_t());
	}while(temp!=1);
	cout<<"Public Key:"<<e<<endl;
	mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phin.get_mpz_t());
	cout<<"Private Key:"<<d<<endl;
	cout<<"Enter a number: ";
	mpz_class msg, en, dn;cin>>msg;
	mpz_powm(en.get_mpz_t(), msg.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
	cout<<"Encrypted Message: "<<en<<endl;
	mpz_powm(dn.get_mpz_t(), en.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
	cout<<"Decrypted Message: "<<dn<<endl;
}