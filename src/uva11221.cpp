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
#define all(x) 			ALL(x)

bool palindrome(string test) {
	for(int i = 0, j = sz(test)-1; i < j; i++,j--) {
		if(test[i] != test[j])
			return false;
	}
	return true;
}

int squaresize(int size) {
	for(int i = 1; i*i < 10005; i++) {
		if(i*i == size)
			return i;
	}
	return 0;
}

int main() {
	int T;
	scanf("%d\n",&T);
	REP(t,T) {
		string line;
		getline(cin,line);
		string copy = line;
		copy.erase(
			remove_if(all(copy),[](char c) {
				return !isalpha(c);
			}),
			copy.end()
		);
		printf("Case #%d:\n",t+1);
		if(palindrome(copy) && squaresize(sz(copy)))
			cout << squaresize(sz(copy)) << endl;
		else cout << "No magic :(" << endl;
	}

	return 0;
}










































