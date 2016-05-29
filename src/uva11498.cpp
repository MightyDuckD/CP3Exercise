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

int K,N,M,X,Y;

int sign(int x) {
	return (x > 0) - (x < 0);
}

int x[] = {1,-1, 1,-1,0, 0,1,-1,0};
int y[] = {1, 1,-1,-1,1,-1,0, 0,0};
string ans[] = {"NE","NO","SE","SO","divisa","divisa","divisa","divisa","divisa"};

int main() {
	while(true) {
		scanf("%d",&K);	
		if(K == 0)
			break;
		scanf("%d%d",&N,&M);
		REP(k,K) {
			scanf("%d%d",&X,&Y);
			//translate point
			X -= N, Y -= M;
			REP(i,9) {
				if(sign(X) == x[i] && sign(Y) == y[i])
					cout << ans[i] << endl;
			}
		}
	}
	return 0;
}










































