#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n%2==1){
		cout<<-1;
	}else{
		for(int i = 1<<30;i>0;i/=2){
			if(n & i){
				cout<<i<<" ";
			}
		}
	}
	return 0;
}
