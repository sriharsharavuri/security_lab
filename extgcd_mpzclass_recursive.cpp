#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
using namespace std;
mpz_class ext_gcd(mpz_class a, mpz_class b){
	mpz_class sold, snew, told, tnew, yold, ynew, q, r, temp;
	yold = a;sold = 1;snew =0;
	ynew = b;told = 0;tnew = 1;
	while(1){
		q = yold/ynew;r = yold%ynew;
		temp = ynew;ynew = yold - q*ynew;yold = temp;
		temp = snew;snew = sold - q*snew;sold = temp;
		temp = tnew;tnew = told - q*tnew;told = temp;
		if(ynew == 0){
			cout<<"Coefficients are: "<<sold<<" "<<told<<endl;
			return yold;
		}
	} 
}
int main(){
	mpz_class a, b;
	cout<<"Enter a and b: ";
	cin>>a>>b;
	cout<<"GCD: "<<ext_gcd(a, b)<<endl;
}