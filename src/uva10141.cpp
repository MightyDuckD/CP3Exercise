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

#define all(c) ALL(c)

#define fi              first
#define se              second
#define sz(x)           ((int)((x).size()))
#define pb              push_back 
#define mp              make_pair 

#define contains(data,value) (find(all(data),value) != data.end())

struct proposal {
	string name;
	double price;
	int compliance;
};

string doit(vector<proposal> proposals) {
	proposal best;
	best.price = -1;
	best.compliance = -1;
	
	for(auto &p : proposals) {
		if(p.compliance > best.compliance) {
			best = p;
		} else if(p.compliance == best.compliance) {
			if(p.price < best.price) {
				best = p;
			}
		}
	}
	return best.name;
}

int main() {
	string str;
	int N,P;
	
	for(int rfp = 1;true;rfp++) {
		cin>>N>>P;
		
		if(N == 0)
			break;

			
		REP(n,N) {
			cin.ignore();
			getline(cin, str);
		}
		
		vector<proposal> proposals;
		REP(p,P) {
			proposal prop;
			getline(cin, prop.name);
			cin >> prop.price >> prop.compliance; cin.ignore();
			
			REP(c,prop.compliance) {
				getline(cin, str);
			}
			
			proposals.pb(prop);
		}
		
		if(rfp > 1) 
			cout << endl;
		cout << "RFP #" << rfp << endl;
		cout << doit(proposals) << endl;
	}
	return 0;
}










































