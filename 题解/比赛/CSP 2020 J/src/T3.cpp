#include<bits/stdc++.h>
using namespace std;
struct Node{
	int dp[2],val;
	string op;
	vector<Node*>son;
	Node(){
		dp[0] = dp[1] = val = 0;
		op = "";
		son = vector<Node*>();
	}
};
const int N = 100100; 
Node* ptr[N];
stack<Node*>st;
// 第一次dfs求默认值
void dfs(Node*cur){
	if(cur->op=="")return;
	for(int i = 0;i<cur->son.size();i++){
		dfs(cur->son[i]);
	}
	if(cur->op == "!"){
		cur->val = !cur->son[0]->val;
	}else if(cur->op=="&"){
		cur->val = cur->son[0]->val & cur->son[1]->val;
	} else{
		cur->val = cur->son[0]->val | cur->son[1]->val;
	} 
}
// 第二次dfs求dp值
void ddfs(Node*cur,Node*fa){
	if(fa == NULL){
		cur->dp[0] = 0;
		cur->dp[1] = 1;
	}else if(fa->op == "!"){
		for(int i = 0;i<2;i++){
			cur->dp[i] = fa->dp[!i];
		}
	}else if(fa->op == "&"){
		Node*other;
		for(int i = 0;i<2;i++){
			if(fa->son[i] != cur)other = fa->son[i];
		}
		for(int i = 0;i<2;i++){
			cur->dp[i] = fa->dp[i & other->val];
		}
	}else if(fa->op == "|"){
		Node*other;
		for(int i = 0;i<2;i++){
			if(fa->son[i] != cur)other = fa->son[i];
		}
		for(int i = 0;i<2;i++){
			cur->dp[i] = fa->dp[i | other->val];
		}
	}
	for(int i = 0;i<cur->son.size();i++){
		ddfs(cur->son[i],cur);
	}
}
int main(){
	string s;
	while(cin>>s){
		if(s=="!"){
			Node*a = st.top();
			st.pop();
			Node*c = new Node();
			c->op = s;
			c->son.push_back(a); 
			st.push(c);
		}else if(s=="&" or s == "|"){
			Node*a = st.top();
			st.pop();
			Node*b = st.top();
			st.pop();
			Node*c = new Node();
			c->op = s;
			c->son.push_back(a); 
			c->son.push_back(b);
			st.push(c); 
		}else if(s[0]=='x'){
			int id = 0;
			for(int i = 1;i<s.size();i++)id = id*10 + s[i]-'0';
			ptr[id] = new Node();
			st.push(ptr[id]); 
		}else{
			int n = 0;
			for(int i = 0;i<s.size();i++)n = n*10 + s[i]-'0';
			for(int i = 1;i<=n;i++){
				cin>>ptr[i]->val;
			}
			break;
		}
	}
	Node*root = st.top();
	dfs(root);
	ddfs(root,NULL);
	int q;cin>>q;
	while(q--){
		int id;cin>>id;
		cout<<ptr[id]->dp[!ptr[id]->val]<<"\n";
	}
	return 0;
}
