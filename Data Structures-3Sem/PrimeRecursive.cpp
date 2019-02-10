#include<iostream>


using namespace std;

int Isprime(int n ,int i=2) {
	
	if(n > i) {
		
		if(n%i!=0) {
			
			
			Isprime(n,++i);
			return 1;
			
			
		}
		
		else 
		{
			return 0;
		}

	}
}


void printPrimeRange(int n)
{
	
	for(int i = 1  ; i <= n; i++)
	{
		if(Isprime(i) == 1)
		{
			cout<<"Prime No- "<<i<<endl;
		}
		
		else
			continue;
		
	}
	
	
}

int main()
{
	printPrimeRange(10002);
	return 0;
}
