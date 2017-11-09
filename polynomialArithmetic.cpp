#include <gmpxx.h>
#include <bits/stdc++.h>
using namespace std;

class poly{
	public:
	int prime;
	int degree;
	vector<int> coeffs;
	poly(){
		prime=0;degree=0;
	}
	poly(int p,int d){
		prime = p;
		degree = d;
	}
	void input(){
		cout<<"Enter the polynomial and coefficient \n";
		int a, b;cin>>a>>b;
		prime=a;degree=b;
		coeffs.resize(degree+1);
		cout<<"Enter the coefficients from highest degree to constant \n";
		for(int i=degree;i>=0;i--){
			int inp;cin>>inp;
			coeffs[i]=inp;
		}
	}
	void initCoeffs(){
		for(int i=0;i<degree+1;i++)coeffs[i]=0;
	}
	void print(){
		for(int i=degree;i>=0;i--){
			cout<<coeffs[i]<<"x"<<i<<"+";	
		}
		cout<<endl;
	}
};

poly add(poly a, poly b){
	poly result;
	if(a.prime!=b.prime){cout<<"Not Possible \n";return result;}
	result.prime = a.prime;result.degree=max(a.degree, b.degree);
	result.coeffs.resize(result.degree+1);
	int i;
	for(i=0;i<min(a.degree, b.degree);i++){
		result.coeffs[i] = (a.coeffs[i]+b.coeffs[i])%a.prime;
	}
	for(;i<a.degree;i++){
		result.coeffs[i] =a.coeffs[i];
	}
	for(;i<b.degree;i++){
		result.coeffs[i] = b.coeffs[i];
	}
	for(int i=0;i<=result.degree;i++){
		result.coeffs[i] = result.coeffs[i]%a.prime;
	}
	return result;
}

poly sub(poly a, poly b){
	poly result;
	if(a.prime!=b.prime){cout<<"Not Possible \n";return result;}
	result.prime = a.prime;result.degree=max(a.degree, b.degree);
	result.coeffs.resize(result.degree+1);
	int i;
	for(i=0;i<min(a.degree, b.degree);i++){
		result.coeffs[i] = (a.coeffs[i]-b.coeffs[i])%a.prime;
	}
	for(;i<a.degree;i++){
		result.coeffs[i] =a.coeffs[i];
	}
	for(;i<b.degree;i++){
		result.coeffs[i] = b.coeffs[i];
	}
	for(int i=0;i<=result.degree;i++){
		result.coeffs[i] = result.coeffs[i]%a.prime;
	}
	for(int i=0;i<=result.degree;i++){
		result.coeffs[i] = (result.coeffs[i]+a.prime)%a.prime;
	}
	return result;
}

poly iteradd(poly result, poly temp, int i){
	while(i--){
		bool flag;
		if(result.coeffs[result.degree]==1)flag = true;
		for(int i=0;i<result.degree;i++)result.coeffs[i+1]=result.coeffs[i];
		
		if(flag){
			result = add(result, temp);
		}
		
	}
	return result;
}

poly mul(poly a, poly b){
	poly ir, result, temp;
	ir.prime=a.prime;
	temp.prime=a.prime;
	result.prime=a.prime;
	result.degree = max(a.degree, b.degree);
	ir.degree = max(a.degree, b.degree)+1;
	temp.degree = max(a.degree, b.degree)+1;
	temp.initCoeffs();result.initCoeffs();
	temp.coeffs[temp.degree]=1;
	temp = sub(temp, ir);
	if(a.prime!=b.prime){
		cout<<"Not Possible \n";
	}
	ir.input();
	for(int i=b.degree;i>=0;i--){
		int j = i;
		if(b.coeffs[i]==0)continue;
		result = add(iteradd(a, temp, j), result);
	}
}

int main(){
	poly a(2, 3);
	poly b(2, 3);
	a.input();b.input();
	poly result = add(a, b);
	result.print();
}