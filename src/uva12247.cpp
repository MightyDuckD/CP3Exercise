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


int max(int a, int b, int c) {
	return max(a,max(b,c));
}
int min(int a, int b, int c) {
	return min(a,min(b,c));
}
int mid(int a, int b, int c) {
	int mx = max(a,b,c);
	int mn = min(a,b,c);
	if(a != mx && a != mn) 	return a;
	if(b != mx && b != mn) 	return b;
	if(c != mx && c != mn) 	return c;
}

int main() {

	while(true) {
		int A,B,C,X,Y,Z;
		scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);
		if(A == 0)
			break;
		//BEGIN TESTCASE
		for(Z = 1; Z <= 52; Z++) {
			if(mid(X,Y,Z) > max(A,B,C) || mid(A,B,C) < min(X,Y,Z)) {
				if(Z != A && Z != B && Z != C && Z != X && Z != Y)
					break;
			}
		}
		if(Z == 53) 
			Z = -1;
		//END TESTCASE
		printf("%d\n",Z);
	}

	return 0;
}









/* OLD - WRONG ANSWER

		int md = mid(A,B,C);
		int mx = max(A,B,C);
		
		if(X < md || Y < md) {
			if(mx < max(X,Y))
				Z = max(X,Y) + 1;
			else Z = -1;
		} else {
			Z = md + 1;
		}
		
		if(Z != -1) 
			while(Z == mx || Z == X || Z == Y)
				Z++;
		if(Z > 52)
			Z = -1;

*/
































