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

#define all(c)          (c).begin(), (c).end()  
#define SIZE(c)         ((int)(c).size())
#define LEN(c)          ((int)(c).length())

#define fi              first
#define se              second
#define sz(x)           ((int)((x).size()))
#define pb              push_back 
#define mp              make_pair 

int gcd(int a, int b) {
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
int lcm(int a, int b) {
	return (a*b)/gcd(a,b);
}

int process(vector<int> data) {
	int result = abs(data[0]-data[1]);
	for(int i = 1; i < sz(data)-1; i++) {
		result = gcd(result,abs(data[i]-data[i+1]));
	}
	return result;
}


int main() {
	int T;
	while(true) {
		vector<int> data;
		do {
			cin >> T;
			data.pb(T);
		} while(T);
		data.pop_back();
		if(data.empty())
			break;
		cout << process(data) << endl;
	}
	return 0;
}










































