#include<bits/stdc++.h>
using namespace std;

/*
string reverseString(string x)
{
	if(x.length()==0)
	{
		return " ";
	}
	
	return reverseString(x.substr(1))+x[0];
}



bool isPalindrome(string x)
{
	if(x.length()==0 || x.length()==1)
	{
		return true;
	}
	int n=x.length();
	
	if(x[0]==x[n-1])
	{
		return isPalindrome(x.substr(1,n-1));
		
	}
	
	return false;
	
	
}



int main()
{
	string x;
	cin>>x;
	
	// cout<<reverseString(x);
	
	
	cout<<isPalindrome(x);
}

*/


int binary(int decimal)
{
	if(decimal==0)
	{
	
		return 0;
	}
	
	
	return (decimal%2+10*binary(decimal/2));
	
	
}



int main()
{
	int decimal;
	cin>>decimal;
	

	
	cout<<binary(decimal);
	
	
}


