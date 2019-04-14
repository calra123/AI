#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//int ju1,ju2;
int fillwater(int ju1,int ju2,int w)
{
	int count=0;
	int flag=0;
	int m,n;
	m=n=0;
	int gcd=__gcd(ju1,ju2);
	if(w%gcd!=0)
	{
		cout<<"Not possible\n";
		return -1;
	}
	if(w%gcd==0)
	{
		m=ju1;
		count++;
		if(m==w || n==w)
			{
				flag=1;
			}
		else{
		while(1)
		{
			int temp;
			//m=m+ju1-m;
			//count++;
			
			temp=min(ju2-n,m);        //to fill according to either remaining capacity of jug2 or the capacity of jug1
			n=n+temp;                //Add the amount to Jug2
			count++;
			
			m=m-temp;               //Subtracted from Jug1
			if(m==w || n==w)
			{
				flag=1;break;
			}
			

			if(n==ju2)
			{n=0;count++;}
			if(m==0)
			{
				m=ju1;count++;
			}
			
		//cout<<"Hello\n";
			
		}}
	}


	//cout<<count<<" "<<endl;

return count;
			
	
}


int main()
{
	int ju1,ju2;
	int n,m,w;
	m=n=0;
	cout<<"Enter the level of 2 jugs\n";
	cin>>ju1>>ju2;
	cout<<"Enter the desired amount\n";
	cin>>w;

	cout<<min(fillwater(ju1,ju2,w),fillwater(ju2,ju1,w))<<endl;     //to get the both values, reverse the values in paramters


return 0;
}
	
