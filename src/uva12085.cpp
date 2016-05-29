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


string diff(string a, string b) {

	for(int i = 0; i < sz(a); i++) {
		if(a[i] != b[i])
			return "-" + b.substr(i,sz(a)-i);
	}
	return "";

	/*
	int i;
	for(i = sz(a) - 1; i >= 0; i--) {
		if(a[i] == b[i])
			break;
	}
	if(i == sz(a) - 1)
		return "";
	else return "-" + b.substr(i + 1,sz(a) - i - 1);
	*/
}

void test(vector<string> num) {
	int j = 0;
	for(int i = 0; i < sz(num);i+=j) {
		for(j = 1; i + j < sz(num); j++) {
			if(stoi(num[i+j]) != j + stoi(num[i]))
				break;
		}
		cout << num[i] << diff(num[i],num[i+j-1]) << endl;
	}
}


int main() {

	for(int T = 1; true; T++) {
		int N;
		cin >> N;cin.ignore();
		if(N == 0)
			break;
		
		vector<string> numbers;	
		string str;
		REP(n,N) {
			getline(cin,str);
			numbers.pb(str);
		}
		printf("Case %d:\n",T);
		
		sort(ALL(numbers));
		test(numbers);
		printf("\n");
	}
	
	return 0;
}










































