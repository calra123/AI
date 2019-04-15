#include<iostream>
using namespace std;
//n is equal to number of disks to be moved.
int a[4];
void pegPeg(int n,char from,char to, char via)
{
	if(n==1)            //Base case (for the smallest ring only)
	{
		cout<<"Move 1st ring from "<<from<<" peg to "<<to<<" peg\t";
		a[from-64]--;
		a[to-64]++;
		cout<<"peg "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		return ;
	}
	
	pegPeg(n-1,from,via,to);                                                  //Moving n-1 disks to "via" peg
	cout<<"Move "<<n<<"th ring from "<<from<<" peg to "<<to<<" peg\t";        //Moving nth disk of that call to "to" peg
		
    a[from-64]--; a[to-64]++; 
    cout<<"peg "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;

	pegPeg(n-1,via,to,from);                                                  //Moving n-1 disks from "via" to "to" peg
	

}

int main()
{

	int n;
	cout<<"Enter number of disks\n";
	cin>>n;
	
	a[1]=n;
	a[2]=0;
	a[3]=0;
	cout<<"\t\t\t\t\tpeg "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	pegPeg(n,'A','C','B');

}
