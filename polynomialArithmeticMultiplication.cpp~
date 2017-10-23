#include<bits/stdc++.h>
#include<gmp.h>
#include<gmpxx.h>
using namespace std;
int main(){
	unsigned maxPower = 20;	
	mpz_t p;
	mpz_t f[maxPower];//f = malloc(sizeof(mpz_t) * maxPower);
	mpz_t g[maxPower];//g = malloc(sizeof(mpz_t) * maxPower);
	mpz_t res[2*maxPower];
	mpz_init(p);
	for(int i=0;i<maxPower;i++){
		mpz_init(f[i]);
		mpz_init(g[i]);
	}
	for(int i=0;i<2*maxPower;i++){
		mpz_init(res[i]);
	
	}
	cout<<"\n Enter the value of p:";
	cin>>p;
	cout<<"\nEnter the coeff, power of f(x). 0 to terminate \n";
	mpz_t coeff;mpz_init(coeff);
	int power;
	while((cin>>coeff)){
		if(mpz_sgn(coeff)==0)break;
		cin>>power;
		mpz_mod(f[power], coeff, p);
	}
	cout<<"\nEnter the coeff, power of g(x). 0 to terminate \n";
	while((cin>>coeff)){
		if(mpz_sgn(coeff)==0)break;
		cin>>power;
		mpz_mod(g[power], coeff, p);
	}
	mpz_t val; mpz_init(val);int index1=0,index2=0,isum;	
	while(index1<maxPower){
		index2=0;
		while(index2<maxPower){
			mpz_mul(val, f[index1], g[index2]);
			mpz_mod(val, val, p);
			isum=index1+index2;
			mpz_add(res[isum], res[isum], val);
			mpz_mod(res[isum], res[isum], p);
			index2++;
			//cout<<res[isum]<<"x^"<<isum<<"\n";		
		}
		index1++;			
	}
	for(int i=0;i<2*maxPower;i++){
		if(mpz_sgn(res[i])!=0)		
			cout<<res[i]<<"x^"<<i<<"+";
	}
	cout<<endl;	
}
