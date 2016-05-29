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

int N,B,H,W;
int p[20];//price per person
int a[20][20];//beds

void doit() {
	
	int mn = INT_MAX;
	REP(h,H) {
		REP(w,W) {
			if(a[h][w] >= N) {
				mn = min(mn, N * p[h]);
			}
		}
	}
	if(mn > B)
		printf("stay home\n");
	else 
		printf("%d\n",mn);
}

int main() {

	while(true) {
	
		int ret = scanf("%d%d%d%d",&N,&B,&H,&W);
		if(ret != 4)
			break;
	
		REP(h,H) {
			scanf("%d",&p[h]);
			REP(w,W) {
				scanf("%d",&a[h][w]);
			}
		}
		
		doit();
	}
	
	return 0;
}










































