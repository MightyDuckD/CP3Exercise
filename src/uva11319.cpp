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

typedef unsigned long long int ull;

void doit(ull F[1501]) {
	
	int A[7] = {0};
	ull v = F[1000];
	int i = 6;
	
	for(ull x = 1006015020015006001L; x > 0; x /= 1001,i--) {
		A[i] = v / x;
		v = v % x;
	}
	
	bool result = true;
	REPN(i,1500) {
		ull u = 0;
		int j = 0;
		for(ull x = 1; j < 7; x *= i,j++) {
			u += A[j] * x;
		}
		if(u != F[i-1]) {
			result = false;
			break;
		}
	}
	
	if(result)
		REP(i,7)
			printf("%d%c",A[i],i==6?'\n':' ');
	else printf("This is a smart sequence!\n");
}


int main() {
/*
	cout << 2 << endl;

	REPN(i,1500) {
		ull val = 1;
		cout << " " << val;
	}
	cout << endl;
	
	REPN(i,1500) {
		ull val = i + i*i;
		cout << " " << val;
	}
	cout << endl;
	
return 0;
*/
	int N;
	cin >> N;
	REP(n,N) {
		ull input[1500];
		REP(i,1500)
			cin >> input[i];
		doit(input);
	}
	
	return 0;
}










































