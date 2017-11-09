#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;
class poly{
public:
	int degree;
int prime;
vector<mpz_class>coeffs;
	poly()
	{
		degree=0;prime=0;
		coeffs.clear();

	}
};
poly m;
void input(poly &a)
{
	cin>>a.degree;
	cin>>a.prime;

	a.coeffs.resize(max(a.degree+1,m.degree));
	for(int i=0;i<=a.degree;i++)
	{
		cin>>a.coeffs[i];
	}
	
}

void output(poly& a)
{
	cout<<"degree:"<<a.degree<<endl;
	for (int i = a.degree; i >=0; i--)
	{
		cout<<a.coeffs[i]<<" x"<<i<<" \n";
	}
	cout<<endl;
}
poly addition(poly& a,poly &b)
{

	poly c;
	if(a.prime!=b.prime)
	{
		cout<<"Addition not possible";return c;
	}
	c.degree=max(a.degree,b.degree);
	c.prime=a.prime;
	c.coeffs.resize(c.degree+1);
	int i;
	for (i = 0; i <= min(a.degree,b.degree); ++i)
	{
		c.coeffs[i]=(a.coeffs[i]+b.coeffs[i])%a.prime;
	}
	for(;i<=a.degree;++i)
	{
		c.coeffs[i]=(a.coeffs[i])%a.prime;
	}
	for(;i<=b.degree;++i)
	{
		c.coeffs[i]=(b.coeffs[i])%a.prime;
	}
	return c;
}
poly temp_add(poly temp,poly a,int times)
{
	for (int i = 0; i <=min(a.degree,temp.degree); ++i)
	{
		temp.coeffs[i]=a.coeffs[i];
		/* code */
	}
	for (int i = 0; i < times; ++i)
	{
		bool flag=false;
		if(temp.coeffs[temp.degree]==1)flag=true;
		for (int j=temp.degree-1;j>=0; j--)
		{
			temp.coeffs[j+1]=temp.coeffs[j];
			/* code */
		}
		temp.coeffs[0]=0;
	
		if(flag)
		{
			for (int j=0;j<=temp.degree; ++j)
			{
				temp.coeffs[j]=temp.coeffs[j]^m.coeffs[j];
			}
		}

	}
	return temp;
}
poly multiplication(poly& a,poly &b)
{

	poly c;
	if(a.prime!=b.prime)
	{
		cout<<"Multiplication not possible";return c;
	}
	poly temp;
	temp.degree=m.degree-1;
	temp.prime=2;
	temp.coeffs.resize(temp.degree+1);
	for (int i = 0; i <=temp.degree; ++i)
	{
		temp.coeffs[i]=0;
		/* code */
	}
	poly answer;
	answer.degree=m.degree-1;
	answer.prime=2;
	answer.coeffs.resize(answer.degree+1);
	for (int i = 0; i <=answer.degree; ++i)
	{
		answer.coeffs[i]=0;
	}
	for (int i = 0; i <=b.degree; ++i)
	{
		if(b.coeffs[i]==1)
		{
			
			poly temp2=temp_add(temp,a,i);
			answer=addition(answer,temp2);
		}
		/* code */
	}
	return answer;

}
void input_mx()
{
	cout<<"Enter m(x):\n";
	input(m);
}
int main(int argc, char const *argv[])
{

	cout<<"Multiplication over GF(2^n):"<<endl;
	poly pol1,pol2,pol3;
	cout<<"f(x):\n";
	input(pol1);
	cout<<"g(x):\n";
	input(pol2);
	input_mx();
	cout<<"Multiplication:\n";
	pol3=multiplication(pol1,pol2);
	cout<<"Final Answer:\n";
	output(pol3);
	return 0;
}