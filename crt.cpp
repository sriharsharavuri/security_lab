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
	if(gcd!=1){
		cout<<"Not possible \n";
		return -1;
	}
	return gcd;
}
int main(){
	cout<<"Enter the number, n: ";
	cin>>n;
	int m[n],a[n];
	cout<<"Enter the m[i], a[i] values from 0 to n \n";
	int prod=1, sum=0;	
	for(int i=0;i<n;i++){
		cin>>m[i];
		prod=prod*m[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int pp = prod/m[i];
		int x,y;
		int val = extendedGcd(pp, m[i],x,y);
		if(val!=1){
			return 0;
		}		
		int inv = ((x%m[i])+m[i])%m[i];
		cout<<endl<<pp<<" "<<inv;
		sum = sum+a[i]*pp*inv;
	}
	sum = sum%prod;
	cout<<endl<<sum;	
}
