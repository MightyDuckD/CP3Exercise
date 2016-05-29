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

#define PRIME 131071

int val;
int result;

void print(int size, int val) {
	char txt[1024];
	int i;
	for(i = 0; val; i++)
		txt[i] = (val&1) + '0',val/=2;
	txt[i] = 0;
	i--;
	for(int j = 0; j < i; i--,j++) {
		char tmp = txt[i];
		txt[i] = txt[j];
		txt[j] = tmp;
	}
	printf("%*s",size,txt);
}

void init() {
	val = result = 0;
}

int next(int a) {
	val = (val << 1) | a;
	result << 1;
	if(val >= PRIME)
		val -= PRIME, result |= 1;
}

void done() {
	//cout << " res:" << result << " rem:" << val << endl;
	cout << (val?"NO":"YES") << endl;
}


int main() {

	bool doinit = true;
	while(true) {
		char c;
		cin >> c;
		if(cin.eof())
			break;
		if(doinit)
			doinit = false,init();
		if(c == '#')
			doinit = true,done();
		else next(c-'0');
	}

	return 0;
}










































