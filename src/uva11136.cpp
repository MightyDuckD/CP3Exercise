/*
 * Author: Simon Lehner-Dittenberger <simon.lehnerd@gmail.com>
 */

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#define D(args...)                printf(args)
#else
#define debug(args...)            // Just strip off all debug tokens
#define D(args...)
#endif

struct debugger {

    template<typename T> debugger& operator,(const T& v) {
        cerr << v << " ";
        return *this;
    }
} dbg;

#define FORIT(i,obj)    for(auto i = (obj).begin(); i != (obj).end(); ++i)
#define FORITD(i,obj)   for(auto i = (obj).rbegin(); i != (obj).rend(); ++i)
#define FOR(i,a,b)      for(int (i) = (a); (i) < (b); (i)++)
#define FORN(i,a,b)     for(int (i) = (a); (i) <= (b); (i)++)
#define FORD(i,a,b)     for(int (i) = (a); (i) >= (b); (i)--)
#define REP(i,n)        FOR(i,0,n)
#define REPN(i,n)       FORN(i,1,n)
#define REPD(i,n)       FORD(i,n,1)

#define ALL(c)          (c).begin(), (c).end()  
#define SIZE(c)         ((int)(c).size())
#define LEN(c)          ((int)(c).length())

#define fi              first
#define se              second
#define sz(x)           ((int)((x).size()))
#define pb              push_back 
#define mp              make_pair 

#define all(c)          (c).begin(), (c).end()  

multiset<int> urn;

int main() {
	
	while(true) {
		int N;
		scanf("%d",&N);
		if(N == 0)
			break;
		urn.clear();
		long long res = 0;
		REP(n,N) {
			int K;
			scanf("%d",&K);
			
			REP(k,K) {
				int t;
				scanf("%d",&t);
				urn.insert(t);
			}
		
			int small = *(urn.begin());
			int big = *(urn.rbegin());
	
			urn.erase(urn.begin());
			urn.erase(--urn.end());
			
			res += big - small;
		}	
		printf("%lld\n",res);
	}
	
	return 0;
}










































