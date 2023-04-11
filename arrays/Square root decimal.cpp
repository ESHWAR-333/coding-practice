link=[https://www.codingninjas.com/codestudio/problems/square-root-decimal_1095655?leftPanelTab=0]



#include <bits/stdc++.h> 

long long tempSol(long long n)
{
	int s=1,e=n;
	long long  mid=s+(e-s)/2;
	long long ans;
	while(s<=e)
	{
		long long  square=mid*mid;
		if(square==n)
		{
			return mid;
		}
		if(square<n)
		{
			ans=mid;
			s=mid+1;
		}else{
			e=mid-1;
		}
		mid=s+(e-s)/2;
	}
	return ans;
}

double precisionSquare(long long n,int d,long long ans)
{
	double precision=1;
	double a=ans;
	for(int i=0;i<d;i++)
	{
		precision=precision/10;
		for(double j=a;(j*j)<n;j=j+precision)
		{
			a=j;
		}
	}
	return a;
}

double squareRoot(long long n, int d) 
{	
	// Write your code here.
	long long ans=tempSol(n);
	double actual=precisionSquare(n,d,ans);
	return actual;
}
