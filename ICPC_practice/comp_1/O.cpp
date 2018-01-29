/****************************************************************************
*					Author: Deepak Nathani									*
*					hackerrank:- savager									*
*					codeforces:- deepak54354								*
*					Spoj:- deepak54354										*
*					Github:- deeplearning10									*
*****************************************************************************/					


#include <bits/stdc++.h>
using namespace std;

// Math
#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
#define SQR(n) ((n)*(n))

// memory 
#define MEM(a,val) memset(a,val,sizeof(a))

// Data types and related macros
#define ll long long
#define ul unsigned long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SS stringstream

//loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)

// I/O
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

// useful functions
template <typename T>
T mod(T a, T b) // calculates a%b, not remainder
{
	T ans;
	if(b == 0)
		return -1;
	else
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	return ans;
}

ll fast_exp(ll base,ll n, ll M)
{
	ll ans = 1;
	while(n)
	{
		if(n%2==1)
		ans = (ans*base)%M;
		base = (base*base)%M;
		n = n>>1;
	}
	return ans%M;
}

//splits a string according to a given delimiter
template<typename Out>
void split(const string &s, char delim, Out result) {
	SS ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}
//function ends

//declare question related constants here 
const int N = 510;
vii grid(N, vi(N,-1));
vector<string> mat(N);
vector<vector<bool>> adj(N, vector<bool> (N,0));
int dis[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
//functions specific to question

// solution here 
void solve(){
	int m,n;
	cin >> m >> n;
	FOR(i,0,m){
		cin >> mat[i];
		//cout << mat[i][0] << endl;
	}
	queue<pii> q;
	q.push({0,0});
	grid[0][0]=0;
	adj[0][0]=1;
	while(!q.empty()){
		pii top = q.front();
		//cout << top.F << " " << top.S << endl;
		q.pop();
		int k = mat[top.F][top.S];
		//cout << "k " << k << endl;
		FOR(i,0,4){
			pii curr = {top.F+ (k -'0')*dis[i][0],top.S+(k-'0')*dis[i][1]};
			if(curr.F >= m or curr.S >= n or curr.F < 0 or curr.S <0 or adj[curr.F][curr.S]) continue;
			else{
				q.push(curr);
				grid[curr.F][curr.S]=grid[top.F][top.S]+1;
				adj[curr.F][curr.S]=1;
			}
		}
	}
	if(grid[m-1][n-1]==-1) cout << "IMPOSSIBLE" << endl;
	else cout << grid[m-1][n-1] << endl;
}

//driver function
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