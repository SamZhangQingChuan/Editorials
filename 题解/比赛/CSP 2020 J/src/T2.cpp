#include<bits/stdc++.h>
using namespace std;
int n,w,cnt[601];
int main()
{
	cin>>n>>w;
	for(int i = 1;i<=n;i++){
		int c;cin>>c;
		cnt[c]++;
		int tot = max(1,i*w/100);
		for(int j = 600;j>=0;j--){
			tot -= cnt[j];
			if(tot <= 0){
				cout<<j<<" ";
				break;
			}
		}
	}
	return 0;
}
