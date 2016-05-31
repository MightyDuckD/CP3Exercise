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
#define fi              first
#define se              second
#define sz(x)           ((int)((x).size()))
#define pb              push_back 
#define mp              make_pair 

void process(int a[],int b[], int r[]) {
	
		
	
		
}

string process(string strA, string strB) {
	int a[105] = {0};
	int b[105] = {0};
	int r[105] = {0};
	int SZ = 105;
	for(int i = 0; i < sz(strA); i++) {
		a[i] = *(strA.rbegin() + i) == '1';
	}
	for(int i = 0; i < sz(strB); i++) {
		b[i] = *(strB.rbegin() + i) == '1';
	}

	
	process(a,b,r);
	
	r[0]  = 1;
	r[10] = 1;
	string ret = "";
	for(int i = SZ-1; i >= 0; i--) {
		cout << ret.compare("") << r[i] << "|";
		if(ret.compare("") == 0) {
			if(r[i])
				ret = "1";
		} else if(r[i]) 
			ret += "1";
		else 
			ret += "0";
	}
	cout << endl;
	return ret;
}

int main() {
	string a,b;
	while(true) {
		cin >> a;
		cin >> b;
		cin.ignore();
		if(cin.eof())
			break;
		cout << "result " << process(a,b) << endl;
	}
	return 0;
}










































