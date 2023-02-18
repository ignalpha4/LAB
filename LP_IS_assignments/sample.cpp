#include<bits/stdc++.h>
using namespace std;


int andFunc(string s,int n)
{

	string tand[n];

	for(int i=0;i<n;i++)
	{
		tand[i]=s[i]&127;
	}

	for(int i=0;i<n;i++)
	{
		cout<<tand[i];
	}

	return 0;
}


int xorFunc(string s,int n)
{
	string txor[n];

	for(int i=0;i<n;i++)
	{
		txor[i]=s[i]^127;
	}

	for(int i=0;i<n;i++)
	{
		cout<<txor[i];
	}
		
		return 0;
}

int main()
{
	
	string s;
	cin>>s;
	
	int n=s.length();
	

	cout<<"-----------------output-----------"<<endl;
	
	
	cout<<"-------------AND operation--------"<<endl;
	
	andFunc(s,n);
	cout<<endl;

	
	
	cout<<"-------------XOR operation----------"<<endl;;
	
	xorFunc(s,n);
	
}

