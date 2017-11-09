#include <gmpxx.h>
#include <gmp.h>
#include <iostream>
#include <vector>
using namespace std;
vector<mpf_class> EulersTotient(mpz_class a, mpz_class* totient){
	vector<mpf_class> primes;
	mpz_class prime, start = 1;
	mpz_class temp = a;

	mpz_nextprime(prime.get_mpz_t(), start.get_mpz_t());
	for(mpz_class i=2;i*i<=a;i++){
		if(a%i==0){
			primes.push_back(i);
			while(a%i==0)a=a/i;
		}
	}
	if(a>1){
		primes.push_back(a);
	}
	mpf_class result=temp;
	for(vector<mpf_class>::iterator it = primes.begin(); it!=primes.end();it++){
		result = result*(1-1/(*it));
	}
	*totient=result;
	return primes;
}

void print(vector<mpf_class> primes){
	for(vector<mpf_class>::iterator it = primes.begin(); it!=primes.end();it++){
		cout<<*it<<" ";
	}
}

int getGenerator(mpz_class n, vector<mpf_class> primes, mpz_class totient){
	mpz_class gcd;
	for(mpz_class i=2;i<n;i++){
		bool val = true;
		mpz_gcd(gcd.get_mpz_t(), i.get_mpz_t(), n.get_mpz_t());
		if(gcd!=1)continue;

		for(vector<mpf_class>::iterator it = primes.begin(); it!=primes.end();it++){
			mpz_class temp1, temp2;
			temp2 = totient/(*it);
			mpz_powm(temp1.get_mpz_t(), i.get_mpz_t(), temp2.get_mpz_t(), n.get_mpz_t());
			if(temp1==1){
				val=false;break;
			}
		}
		if(val){
			cout<<i<<" is a generator"<<endl;
		}
	}
}

int main(){
	mpz_class a, totient, temp;vector<mpf_class> primes;
	cout<<"Enter the number of which the totient has to be calculated:";
	cin>>a;
	primes = EulersTotient(a, &totient);
	primes = EulersTotient(totient, &temp);
	getGenerator(a, primes, totient);
}