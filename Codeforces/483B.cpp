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
#define rall(v) (v).begin(),(v).end()
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
	ll c1,c2,x,y;
	cin >> c1 >> c2 >>x >> y;
	ll L = c1+c2,R = 1000000000000000000;
	while(L<R){
		ll v = L +(R-L)/2;
		//cout << "L: " << L << " R: " << R << " v: " << v << endl;
		ll a= c1,b = c2;
		ll l = 1ll*x*y;
		ll both = v/l;
		ll f1 = v/x;
		ll f2 = v/y;
		ll rem =v-f1-f2+both;
		a-=f2-both;b-=f1-both;
		if(a<0) a=0;
		if(b<0) b=0;
		if(a+b <= rem)
			R = v;
		else L = v+1;
	}
	cout << R << endl;
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