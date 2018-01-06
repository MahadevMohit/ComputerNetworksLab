#include<iostream>
using namespace std;

int min(int x,int y)
{
	return (x>y)?y:x;
}

int main()
{
	int orate,count=0,drop=0,cap,x,inp[10]={0},i=0,nsec,ch;
	cout<<"Enter the capacity of the bucket:"<<endl;
	cin>>cap;
	cout<<"Enter the output rate:"<<endl;
	cin>>orate;
	do
	{
		cout<<"Enter the number of packets coming at second: "<<i+1<<endl;
		cin>>inp[i];
		i++;
		cout<<"Press 1 to continue 0 to quit"<<endl;
		cin>>ch;
	}while(ch!=0);
	nsec=i;
	cout<<endl<<"Time"<<" \t "<<"Recieved"<<" \t "<<"Sent"<<" \t "<<"Dropped"<<" \t "<<"Remaining\n";
	for(i=0;count||i<nsec;i++)
	{
		cout<<i+1;
		cout<<" \t "<<inp[i];
		cout<<" \t "<<min(inp[i]+count,orate);
		if((x=inp[i]+count-orate)>0)
		{
			if(x>cap)
			{
				count=cap;
				drop=x-cap;
			}
			else
			{
				count=x;
				drop=0;
			}
		}
		else
		{
			count=0;
			drop=0;
		}
		cout<<" \t "<<drop<<" \t "<<count<<endl;
	}
return 0;
}