#include<bits/stdc++.h>
using namespace std;
int n;
int extendedGcd(int a, int b, int& x, int& y){
	if(a==0){
		x=0;
		y=1;
		return b;
	}
	int x1,y1;
	int gcd = extendedGcd(b%a, a, x1, y1);
	x = y1-(b/a)*x1;
	y = x1;
	return gcd;
}

int modularAdd(int a, int b){
	int val = (a%n+b%n)%n;
	return val;
}
int modularMul(int a, int b){
	int val = (a%n)*(b%n);
	val = val%n;
	return val;
}

int modularDiv(int a, int b){
	if(a<0 || b<0){
		cout<<"GCD does not exist for negative numbers";
		return 0;
	}
	if(a>b){
		swap(a,b);
	}
	int x,y;
	int gcd = extendedGcd(a,n,x,y);
	if(gcd!=1){
		cout<<"Extended GCD doesn't exist for these numbers";
		return -1;
	}
	cout<<endl<<"Inverse is "<<x<<endl;
	x=x%n;
	return (a*x)%n;
}
int main(){
	int a,b;
	cout<<"Enter the a,b,n \n";
	cin>>a>>b>>n;
	cout<<modularAdd(a,b)<<endl;
	cout<<modularMul(a,b)<<endl;
	cout<<modularDiv(a,b)<<endl;
}
