#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef NANO
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	#ifdef NANO
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	const int MAXN = 1'000'010;
	const int inf = 1e9;
	int n,m;
	cin>>n>>m;
	vector<ll> a(n),b(n),c(m);
	forn(i,n) cin>>a[i];
	forn(i,n) cin>>b[i];
	forn(i,m) cin>>c[i];
	
	vector<ll> vd(MAXN+1,inf);
	
	
	forn(i,n) vd[abs(a[i] - b[i])] = min(a[i],vd[abs(a[i] - b[i])]);
	
	vector<pair<ll,int>> vp;
	
	forn(i,MAXN+1){
		if(vd[i] == inf) continue;
		if(vp.empty()) vp.pb({vd[i],i});
		else if(vd[i] < vp.back().fst) vp.pb({vd[i],i});
	}
 	reverse(vp.begin(),vp.end());
	vector<pair<ll,int>> vc(MAXN+1,make_pair(-1,-1));
	for(auto [anow,cost]: vp) vc[anow] = {anow,cost};
	
	for(int i = 1; i<MAXN+1; i++) if(vc[i].fst == -1 and vc[i-1].fst != -1) vc[i] = vc[i-1]; 
	
	ll ans = 0;
	
	unordered_map<ll,ll> dp;
	
	for(auto & e: c){
		
		vector<ll> ve,vans;	
		
		while(e >= vp[0].fst){
			
			if(dp.count(e)){
				ans+=dp[e];
				vans.pb(dp[e]);
				ve.pb(e);
				break;
			}
			
			pair<ll,int> p = {-1LL,-1};
			if(e > MAXN) p = vc.back();
			else p = vc[e];
			auto [anow,cost] = p; 
			//~ cout<<e<<' '<<anow<<' '<<cost<<endl;
			assert(e >= anow);
			ll can = (e - anow)/ cost + 1;
			ans += 2 * can;
			vans.pb(2 * can);
			ve.pb(e);
			e -= can * cost;
		}
		for(int i = sz(ve)-2; i>=0; i--) vans[i] += vans[i+1];
		forn(i,sz(ve)){
			 if(dp.count(ve[i])) assert(dp[ve[i]] == vans[i]);
			 dp[ve[i]] = vans[i];
		}
	}
	
	cout<<ans<<'\n';
	return 0;
}
