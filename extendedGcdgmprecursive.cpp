#include<bits/stdc++.h>
#include<gmpxx.h>
#include<gmp.h>
using namespace std;
mpz_class extendedGcd(mpz_class a, mpz_class b, mpz_class &x, mpz_class &y){
	if(a==0){
		x=0;y=1;
		return b;
	}
	mpz_class tempx,tempy,gcd;
	gcd = extendedGcd(b%a,a,tempx,tempy);
	y = tempx;
	x = tempy - (b/a)*tempx;
	return gcd;
}
int main(){
	mpz_class a,b,gcd;
	cout<<"Enter the two numbers \n";
	cin>>a>>b;
	if(a<0 || b<0){
		cout<<"Not possible for negative numbers \n";
	}
	if(a>b)swap(a,b);
	mpz_class x,y;
	gcd = extendedGcd(a,b,x,y);
	cout<<endl<<gcd<<" "<<a<<"*"<<x<<"+"<<b<<"*"<<y<<endl;
}
