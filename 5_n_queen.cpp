#include <iostream>
using namespace std;

class Queen
{
    public:
        int NQueen(int r ,int n);
        int x[20],count=0;
        int place(int  r,int c);
        int display(int n);
};

int Queen:: place(int  r,int c)
{   
    int i;
	for(i=1;i<=r-1;i++)
	{
		if(x[i]==c)//column
		{
            // cout<<"\ncolx[i]"<<x[i];
			return 0;
		}
		else
		{
			if(abs(x[i]-c)==abs(i-r))//diagonal
			{
			return 0;
			}
		}
	}
	return 1;
}

int Queen:: NQueen(int r,int n)
{
	int c,i;
    for(c=1;c<=n;c++)
    {
        //    cout<<"\n c:"<<c;
    	   if(place(r,c))
    	   {
    		   x[r]=c;
            //    cout<<"\nx:"<<x[r];
            //    cout<<"\nrow:"<<r;
    		   if(r==n)
    		   {
    			   display(n);
    		   }
    		   else
    		   {
    			   NQueen(r+1,n);
    		   }
    	   }
   }
    return 0;
}

int Queen::display(int n)
{
    int i,j;
    cout<<"\n\nSolution\n\n"<<++count;
    for(i=1;i<=n;i++)
    {
        cout<<"\t"<<i;
    }
    for(i=1;i<=n;i++)
    {
        cout<<"\n"<<i;
                for(j=1;j<=n;j++)
                {
                    if(x[i]==j)
                        cout<<"\tQ";
                    else
                        cout<<"\t-";
                }

    }
    return 0;
}

int main() 
{
    Queen q1;
	int n;
    cout<<"------------------\n";
    cout<<" N-Queen Solution \n";
    cout<<"------------------\n";
    cout<<" Enter the Queen: ";
    cin>>n;
    q1.NQueen(1,n);

	return(0);
}

