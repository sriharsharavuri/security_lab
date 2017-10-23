#include<bits/stdc++.h>
using namespace std;
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

int main(){
	int a,b;
	cout<<"Enter the numbers for which extended GCD has to be calculated \n";
	cin>>a>>b;
	if(a<0 || b<0){
		cout<<"GCD does not exist for negative numbers";
		return 0;
	}
	if(a>b){
		swap(a, b);
	}
	int x,y;
	int gcd = extendedGcd(a,b,x,y);
	cout<<gcd<<" "<<x<<" "<<y<<endl;
}
