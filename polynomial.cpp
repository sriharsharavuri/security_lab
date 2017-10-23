#include <bits/stdc++.h>
#include <stdint.h>
#define max_degree 1024
using namespace std;
class polynomial: public vector<int8_t>{
	private:
		int prime;
		int degree;
		vector<int8_t> inv;
	public:
	polynomial(){
		prime=2;
		degree=max_degree;
		resize(max_degree+1,0);
		makeInv();
	}
	
	polynomial(int p,int n){
		if(p!=2&&p!=3&&p!=5&&p!=7)error(1);
		if(n<=0||n>max_degree)error(2);
		prime=p;
		degree=n;
		resize(max_degree+1,0);
		makeInv();
	}
	
	polynomial(int p,int n,string coeffs){
		if(p!=2&&p!=3&&p!=5&&p!=7)error(1);
		if(n<=0||n>max_degree)error(2);
		prime=p;
		degree=n;
		resize(max_degree+1,0);
		for(int i=coeffs.size()-1;i>=0;i--)
			at(coeffs.size()-1-i)=int(coeffs[i]-'0');
		makeInv();
	}
	
	void makeInv(){
		inv.resize(prime,0);
		for(int i=1;i<prime;i++){
			for(int j=1;j<prime;j++){
				if((i*j)%prime==1){
					inv[i]=j;
					break;	
				}
			}
		}
	}
	
	void trim(){
        for(int i=size()-1;i>=0;i--)
            if(at(i)>0){
                resize(i+1,0);
                return; 
            }
        resize(1,0);
    }
    
	void operator=(string coeffs){
		resize(coeffs.size(),0);
		for(int i=coeffs.size()-1;i>=0;i--)
			at(coeffs.size()-1-i)=int(coeffs[i]-'0');
	}

	string numtostr(int num)
	{
		stringstream ss;
		ss << num;
		return ss.str();
	}
	
	string to_string(){
		string res="( p="+ numtostr(prime) +" n=" + numtostr(degree) + " f(x)=";
		for(int i=min(degree,int(size()))-1;i>=0;i--)
			res=res+" "+ numtostr(at(i)) +"x^"+ numtostr(i) ;
		res=res+" ) ";
		return res;
	}
	
	friend istream &operator>>( istream  &input, polynomial &lint) { 
        string number;
        input>>number;
        lint=number;
        return input;
    }
    
    friend ostream &operator<<( ostream &output, polynomial &lint ) { 
        output<<lint.to_string();
        return output;
    }
    
	void error(int err){
		switch(err){
			case 1:
				cout<<"prime number <8 should be passed as first argument!!\n";
				exit(1);
			case 2:
				cout<<"n is invaid value!!\n";
				exit(2);
			case 3:
				cout<<"primes does not match!!\n";
				exit(3);
			case 4:
				cout<<"degrees does not match!!\n";
				exit(4);
			case 5:
				cout<<"This operation is only for p=2!!\n";
				exit(4);
		}
	}
	
	void checkErrors(polynomial y){
		if(prime!=y.prime)error(3);
		if(degree!=y.degree)error(4);
	}
	
	polynomial operator+(polynomial y){
		checkErrors(y);
		resize(max_degree+1,0);
		y.resize(max_degree+1,0);
		polynomial res(prime,degree);
		if(prime==2){
			for(int i=0;i<res.size();i++)
				res[i]=at(i)^y[i];
		}
		else{
			for(int i=0;i<res.size();i++)
				res[i]=(at(i)+y[i])%prime;
		}
		return res;
	}
	
	polynomial operator-(polynomial y){
		checkErrors(y);
		resize(max_degree+1,0);
		y.resize(max_degree+1,0);
		polynomial res(prime,degree);
		if(prime==2){
			for(int i=0;i<res.size();i++)
				res[i]=at(i)^y[i];
		}
		else{
			for(int i=0;i<res.size();i++)
				res[i]=(at(i)-y[i]+prime)%prime;
		}
		return res;
	}
	
	polynomial operator*(polynomial y){
		checkErrors(y);
		polynomial res(prime,degree);
		for(int i=0;i<size();i++)
			for(int j=0;j<y.size();j++){
				if(degree==0||i+j<res.size())res[i+j]=(res[i+j]+at(i)*y[j])%prime;
			}
		return res;
	}
	
	polynomial operator/(polynomial y){
		polynomial r=*this,q(prime,degree);
		r.trim();
		y.trim();
		while(r.size()>=y.size()){
			q[r.size()-y.size()]=(r.back()*inv[y.back()])%prime;
			polynomial tmp(prime,degree);
			tmp[r.size()-y.size()]=q[r.size()-y.size()];
			r=r-(y*tmp);
			r.trim();
		}
		return q;
	}
	
	polynomial operator%(polynomial y){
		polynomial r=*this,q(prime,degree);
		r.trim();
		y.trim();
		while(r.size()>=y.size()){
			q[r.size()-y.size()]=(r.back()*inv[y.back()])%prime;
			polynomial tmp(prime,degree);
			tmp[r.size()-y.size()]=q[r.size()-y.size()];
			r=r-(y*tmp);
			r.trim();
		}
		return r;
	}
	
	polynomial operator<<(int x){
		if(prime!=2)error(5);
		polynomial res(prime,degree);
		res.resize(size()+1,0);
		for(int i=1;i<res.size();i++)
			res[i]=at(i-1);
		return res;
	}
	
	polynomial mod_mul(polynomial y,polynomial m){
		if(prime==2){
			checkErrors(y);
			polynomial res(prime,degree);
			vector<polynomial>x_multi(degree);
			x_multi[0]=*this;
			for(int i=1;i<degree;i++){
				x_multi[i]=x_multi[i-1]<<1;
				if(x_multi[i][degree]>0)x_multi[i]=x_multi[i]+m;
			}
			for(int i=0;i<y.size();i++)
				if(y[i])res=res+x_multi[i];
			return res;
		}
		else error(5);
		polynomial res;
		return res;
	}
};
int main(int argc,char* argv[])
{
	polynomial a(7,max_degree,"546"),b(7,max_degree,"21");
	a.trim();b.trim();
	cout<<"a(x) : "<<a.to_string()<<endl;
	cout<<"b(x) : "<<b.to_string()<<endl;		
	
	polynomial c;

	c=a+b;c.trim();
	cout<<"a(x) + b(x) = ";cout<<c<<endl;

	c=a-b;c.trim();
	cout<<"a(x) - b(x) = ";cout<<c<<endl;

	c=a*b;c.trim();
	cout<<"a(x) * b(x) = ";cout<<c<<endl;

	c=a/b;c.trim();
	cout<<"a(x) / b(x) = ";cout<<c<<endl;

	c=a%b;c.trim();
	cout<<"a(x) % b(x) = ";cout<<c<<endl;

	
	polynomial x(2,8,"1010111"),y(2,8,"10000011"),m(2,8,"00011011");
	cout<<"X(x) : "<<x.to_string()<<endl;
	cout<<"Y(x) : "<<y.to_string()<<endl;
	cout<<"M(x) : "<<m.to_string()<<endl;

	polynomial res=x.mod_mul(y,m);
	cout<<"( X(x) * Y(x) )% M(x) = ";cout<<res<<endl;
	
	return 0;
}