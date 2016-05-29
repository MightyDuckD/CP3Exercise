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

//all numbers in range [1,100]
//H = height of the well
//U = initial climbing power
//D = slide distance for the night
//F = fatigue factor in percent
//return positive number = days until success
//		 negative number = days until failure
int doit(int H,int U,int D,int F) {
	double distance = 0;
	for(int day = 1; true; day++) {
		distance += max(0.0, U - (U * 0.01 * F * (day-1)));
		if(distance > H)
			return day;
		distance -= D;
		if(distance < 0)
			return -day;
	}
}


int main() {
	while(true) {
		int H,U,D,F;
		scanf("%d%d%d%d",&H,&U,&D,&F);
		if(H == 0)
			break;
		int r = doit(H,U,D,F);
		if(r > 0)
			printf("success on day %d\n",r);
		else printf("failure on day %d\n",-r);
	}
	return 0;
}










































