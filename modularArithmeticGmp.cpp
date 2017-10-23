#include<bits/stdc++.h>
#include<gmpxx.h>
#include<gmp.h>
using namespace std;
int n;
mpz_class extendedGcd(mpz_class a, mpz_class b, mpz_class& x, mpz_class& y){
	if(a==0){
		x=0;
		y=1;
		return b;
	}
	mpz_class x1,y1;
	mpz_class gcd = extendedGcd(b%a, a, x1, y1);
	x = y1-(b/a)*x1;
	y = x1;
	return gcd;
}

mpz_class modularAdd(mpz_class a, mpz_class b){
	mpz_class val = (a%n+b%n)%n;
	return val;
}
mpz_class modularMul(mpz_class a, mpz_class b){
	mpz_class val = (a%n)*(b%n);
	val = val%n;
	return val;
}

mpz_class modularDiv(mpz_class a, mpz_class b){
	if(a<0 || b<0){
		cout<<"GCD does not exist for negative numbers";
		return 0;
	}
	if(a>b){
		swap(a,b);
	}
	mpz_class x,y;
	mpz_class gcd = extendedGcd(a,n,x,y);
	if(gcd!=1){
		cout<<"Extended GCD doesn't exist for these numbers";
		return -1;
	}
	x=(x%n + n)%n;;
	cout<<endl<<"Inverse is "<<x<<endl;
	return (a*x)%n;
}
int main(){
	mpz_class a,b;
	cout<<"Enter the a,b,n \n";
	cin>>a>>b>>n;
	cout<<"Modular addition:"<<modularAdd(a,b)<<endl;
	cout<<"Modular Multiplication:"<<modularMul(a,b)<<endl;
	mpz_class moddiv = modularDiv(a,b);
	if(moddiv!=-1){cout<<"Modular Division:"<<moddiv<<endl;}
	return 0;
}
