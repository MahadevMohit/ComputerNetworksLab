#include<iostream>
#include<string.h>
using namespace std;

int checksum(int fl)
{
	char in[100];
	int temp,sum=0,n,i;
	cin>>in;

	if(strlen(in)%2!=0)
		n=(strlen(in)+1)/2;
	else
		n=strlen(in)/2;

	for(i=0;i<n;i++)
	{
		temp=in[i*2];
		temp=temp*256+in[(i*2)+1];
		sum=sum+temp;
	}

	if(fl==1)
	{
		cout<<"Enter checksum"<<endl;
		cin>>temp;
		sum=sum+temp;
	}

	if(sum%65536!=0)
	{
		n=sum%65536;
		sum=(sum/65536)+n;
	}
	sum=65535-sum;
	cout<<sum;
	return sum;

}
int main()
{
	int ch,sum;
	do
	{
		cout<<"1.Encode 2.Decode 3.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"Enter a string"<<endl;
			sum=checksum(0);
			cout<<"Checksum is: "<<sum;
			break;
			case 2:
			cout<<"Enter string"<<endl;
			sum=checksum(1);
			if(sum!=0)
				cout<<"The data has been tampered with"<<endl;
			else
				cout<<"No errors"<<endl;
			break;
			case 3:
			break;
		}
	}while(ch!=3);
return 0;
}
