#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ul unsigned long
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

ll mod(ll a, ll b) // calculates a%b, not remainder
{
	ll ans;
	if(b == 0)
		return -1;
	else
	{
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	}
	return ans;
}
void solve(){
	int n,m;
	cin >> n >> m;
	int a[n+1] = {0};
	int l[m+1];
	FOR(i,0,m) cin >> l[i+1];
	vector<pair<bool,int> > visit(n+1);
	FOR(i,1,n+1){
		visit[i] = make_pair(0,0);
	}
	FOR(i,1,m){
		int j = l[i];
		if(l[i+1]==l[i]){
			a[j]=n;
		}
		else if(l[i+1] > l[i]){
			a[j] = l[i+1]-l[i];
		}
		else{
			a[j] = n-l[i]+l[i+1];
		}
		if(visit[a[j]].F==0){
			visit[a[j]]=make_pair(1,j);
		}
		else if(visit[a[j]].S != j){
			cout << -1 << endl;
			return;
		}
	}
	stack<int> s;
	int count=0;
	FOR(i,1,n+1){
		if(visit[i].F==0){
			s.push(i);count++;
		}
	}
	//cout << count << endl;
	//cout << "ji" << endl;
	FOR(i,1,n+1){
		if(a[i]==0){
			if(!s.empty()){
				a[i]=s.top();
				s.pop();
			}
			else{
				cout << -1 << endl;
				return;
			}
		}
		visit[a[i]]=make_pair(1,i);
	}
	bool f[n+1]={0};
	FOR(i,1,n+1){
		f[visit[i].S]=1;
	}
	FOR(i,1,n+1){
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}