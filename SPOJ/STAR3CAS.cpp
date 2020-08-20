/*STAR3CAS - THE WEIRD STAIRCASE  SPOJ  Recursion*/
#include <iostream>
using namespace std;

int min_val,n,stairs[100];

void count_steps(int count,int index){
	
	//cout<<"count is : "<<count<<" index is "<<index<<" n value is :"<<n<<" new index "<<index+stairs[index]<<endl;
	
	if(index==n)
	{
		if(count<min_val) min_val=count;
	}
	
	else if (count>n)
	{
	}
	
	else
	{
		if(index+stairs[index]<=n && index+stairs[index]>=0) 
			count_steps(count+1,index+stairs[index]);
		count_steps(count+1,index+1);
	}
}	

int main() {
	
	int t,count;
	
	cin>>t;
	
	for (int i=0;i<t;i++)
	{
		cin>>n;
		
		min_val=n+1;
		
		count=0;
		
		for (int j=0;j<n;j++)
		{
			cin>>stairs[j];
		}
		
		
		count_steps(count,0);
		
		cout<<min_val<<endl;
	}
	
	
	return 0;
}