#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
ll dp[N][N],a[N][N],n,m;
int main(){
	memset(dp,0xcf,sizeof dp);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	dp[0][0] = a[0][0];
	for(int i = 1;i<n;i++){
		dp[i][0] = dp[i-1][0] + a[i][0];
	}
	for(int j = 1;j<m;j++){
		ll v = -1e15;
		for(int i = 0;i<n;i++){
			v = max(v,dp[i][j-1]);
			v += a[i][j];
			dp[i][j] = max(v,dp[i][j]);
		}
		v = -1e15;
		for(int i = n-1;i>=0;i--){
			v = max(v,dp[i][j-1]);
			v += a[i][j];
			dp[i][j] = max(v,dp[i][j]);
		}	
	}
	cout<<dp[n-1][m-1]<<endl;
	return 0;
}
