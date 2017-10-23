#include<gmp.h>
#include <gmpxx.h>
#include<iostream>
using namespace std;
void result(mpz_t x, mpz_t y, mpz_t res){
	mpz_t oldr,nr,os,ns,ot,nt,q,temp;
	mpz_init(oldr);mpz_init(nr);mpz_init(os);mpz_init(ns);mpz_init(ot);mpz_init(nt);mpz_init(q);mpz_init(temp);
	mpz_set(oldr,x);mpz_set(nr, y);mpz_set_si(os,1);mpz_set_si(ns,0);mpz_set_si(ot,0);mpz_set_si(nt,1);
	while(mpz_sgn(nr)!=0){
		mpz_tdiv_q(q,oldr,nr);
		mpz_set(temp, nr);
		mpz_mul(nr, q, temp);
		mpz_sub(nr,oldr,nr);		
		mpz_set(oldr, temp);
		mpz_set(temp, ns);
		mpz_mul(ns, q, temp);
		mpz_sub(ns,os,ns);		
		mpz_set(os, temp);
		mpz_set(temp, nt);
		mpz_mul(nt, q, temp);
		mpz_sub(nt,ot,nt);		
		mpz_set(ot, temp);
	}
	mpz_set(res,oldr);
	cout<<endl<<os<<" "<<ot<<endl;
}


int main(int argc, char* argv[]){
	mpz_t x,y,r;
	mpz_init(x);mpz_init(y);mpz_init(r);
	cin>>x>>y;
	if(mpz_sgn(x)<0)mpz_mul_si(x,x,-1);
	if(mpz_sgn(y)<0)mpz_mul_si(y,y,-1);	
	result(x,y,r);
	cout<<r<<endl;
	cout<<x<<endl;
}