#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<mpz_class> ni;
	vector<mpz_class> ri;
	vector<mpz_class> Ni;
	vector<mpz_class> Mi;
	mpz_class result=0;
	mpz_class N=1;
	cout<<"Enter the number of equations:";
	int size;cin>>size;
	ni.resize(size);
	ri.resize(size);
	Ni.resize(size);
	Mi.resize(size);
	cout<<"Enter the n's followed by r's: ";
	for(int i=0;i<size;i++){
		cin>>ni[i];
		N = N*ni[i];
	}
	for(int i=0;i<size;i++){
		cin>>ri[i];
		Ni[i]=N/ni[i];
		mpz_invert(Mi[i].get_mpz_t(), Ni[i].get_mpz_t(), ni[i].get_mpz_t());
		result = result+ri[i]*Ni[i]*Mi[i];
		cout<<ri[i]<<"*"<<Ni[i]<<"*"<<Mi[i]<<endl;
	}
	result = result%N;
	cout<<result<<endl;
}