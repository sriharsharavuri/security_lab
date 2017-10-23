#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include <string.h>
using namespace std;

int main(){
	mpz_t p,q,d,e,n,phi,random,phip,phiq, tempx, tempy, temp, r;
	mpz_inits(p,q,d,e,n,phi,random,tempx,tempy,temp, r, phip, phiq, (mpz_ptr)0);
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state, time(NULL));
	mpz_urandomb(random, state, 10);
	mpz_nextprime(p, random);
	mpz_urandomb(random, state, 10);
	mpz_nextprime(q, random);	
	while(mpz_cmp(p,q)==0){
		mpz_urandomb(random, state, 20);
		mpz_nextprime(q, random);
	}
	mpz_mul(n, p, q);
	mpz_sub_ui(phip,p,1);
	mpz_sub_ui(phiq,q,1);
	mpz_mul(phi, phip, phiq);
	gmp_printf("Prime numbers: %Zd %Zd \n", p, q);
	gmp_printf("N and phi(N): %Zd %Zd\n", n, phi);		
	unsigned long int i;
	for(i=2; i < mpz_get_ui(phi); i++) {
		mpz_set_ui(tempx, i);
		mpz_set(tempy, phi);
		mpz_gcd(r, tempx, tempy);		
		//gcd(tempx, tempy, r);
		if(mpz_cmp_ui(r, 1) == 0) {
			mpz_set_ui(e, i);

			mpz_set(tempx, e);
			mpz_set(tempy, phi);
			mpz_gcdext(r,d,temp,tempx, tempy); 
			if (mpz_cmp_ui(r, 1) == 0){
				break;
			}
		}
	}
	gmp_printf("e:%Zd d:%Zd\n",e,d);
	unsigned char input[128], decipher[128];
	unsigned long int cipher[128];		
	printf("Enter Text: ");
	cin>>input;
	unsigned int len = 0;
	//Ciphering	
	for(int i=0;input[i]!='\0';i++){
		mpz_set_ui(temp, input[i]);
		mpz_powm(temp, temp, e, n);
		cipher[i] = mpz_get_ui(temp);
		len++;
	}
	for(int i=0;i<len;i++){printf("%lX ", cipher[i]);}
	//Deciphering
	for(int i=0;i<len;i++){
		mpz_set_ui(temp, cipher[i]);
		mpz_powm(temp, temp, d, n);
		cout<<(unsigned char)mpz_get_ui(temp);	
	}
	cout<<endl;
}
