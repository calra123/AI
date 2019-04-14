#include<iostream>
using namespace std;
int box[10][10];
int n;

int isSafe(int i,int j)                             //Check if it is safe to place a queen at box[i][j]
{
	for(int x=i-1;x>=0;x--)                           //Check North
	if(box[x][j]==1)
	return 0;

	for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--)         //Check North-East
	if(box[x][y]==1)
	return 0;
	
	for(int x=i-1,y=j+1;x>=0 && y<n;x--,y++)          //Check North-West
	if(box[x][y]==1)
	return 0;
	
return 1;                                           //If no problem arised, return 1(i.e. Safe)
}


bool Nqueen(int r)                   
{
	if(r==n)                            //Base case. Problem completed. Start the series of true.
	return true;
	
	for(int i=0;i<n;i++)
	{
		if(isSafe(r,i))         //If safe to place at box[r][i]
		{
			box[r][i]=1;          //Place the queen there
			if(Nqueen(r+1))         //Call for next row. If everything is alright from below
			return true;            //Return true above, so that rest of the loop is not executed.
			else
			{
				box[r][i]=0;        //Else, remove the queen and check for other positions in the row. (Backtracking)
			}
		}
		
	}

	return false;           //When queen can't be placed in the entire row, return false.
}


int main()
{
	cout<<"ENter n\n";
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			box[i][j]=0;	
	bool result=Nqueen(0);
	
  for(int i=0;i<n;i++){           //Printing the box
		for(int j=0;j<n;j++)
		cout<<box[i][j]<<" ";
	cout<<endl;
	}
return 0;}
