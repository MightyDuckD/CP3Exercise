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

void doit(vector<string> data) {
	REP(i,sz(data)) {
		FOR(j,i+1,sz(data)) {
			string sorti = data[i];
			string sortj = data[j];
			sort(ALL(sorti));
			sort(ALL(sortj));
			sorti.erase(remove(ALL(sorti), ' '), sorti.end());
			sortj.erase(remove(ALL(sortj), ' '), sortj.end());
			if(sorti == sortj) {
				cout << data[i] << " = " << data[j] << endl;	
			}
		}
	}
}

int main() {

	int T;
	string tmp;
	cin >> T;cin.ignore();
	getline(cin,tmp);
	
	REP(t,T) {
		vector<string> data;
		string empty = "";
		while(true) {
		
			getline(cin,tmp);
		
			if(tmp == empty)
				break;
		
			data.pb(tmp);
		}

		sort(ALL(data));
		if(t) 
			cout << endl;
		doit(data);
	}
	
	
	
	
	return 0;
}










































