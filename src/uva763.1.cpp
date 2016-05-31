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

int cache[105];
int fib(int a) {
	if(a <= 0)
		return 1;
	if(!cache[a])
		cache[a] = fib(a-1) + fib(a-2);
	return cache[a];
}

string process(string a, string b) {
	//align both numbers
	while(sz(a) < sz(b))
		a = "0" + a;
	while(sz(b) < sz(a))
		b = "0" + b;
	//add them -> overflow from '1' + '1' = '2'
	string c = "";
	for(int i = 0; i < sz(a); i++) {
		c += (char)(a[i] + b[i] - '0');
	}
	
	size_t pos;
	//as long as the result was modified a new case could have become true
	for(bool run = true;run;) {
		run = false;
		//cout << "step " << c << endl;
		
		//fib[n] = fib[n-1] + fib[n-2]
		while((pos = c.find("011")) != string::npos) {
			c.replace(pos,3,"100");
			run = true;
		}
		//2*fib[n] = fib[n] + fib[n-1] + fib[n-2]
		while((pos = c.find("200")) != string::npos) {
			c.replace(pos,3,"111");
			run = true;
		}
		while((pos = c.find("012")) != string::npos) {
			c.replace(pos,3,"101");
			run = true;
		}
		
		while((pos = c.find("021")) != string::npos) {
			c.replace(pos,3,"110");
			run = true;
		}
		//because of replace "011" the first character has to be a 0
		if(c[0] == '1') {
			c = "0" + c;
			run = true;
		}
		
		//special cases
		//2 * fib[0] = 2 = fib[1]
		if(sz(c) >= 2 && c[sz(c)-1] == '2') {
			c[sz(c)-1] -= 2;
			c[sz(c)-2] += 1;
			run = true;
		}
		//2 * fib[1] = 2 * 2 = fib[2] + fib[0] = 3 + 1 = 4
		if(sz(c) >= 3 && c[sz(c)-2] == '2') {
			c[sz(c)-2] -= 2;
			c[sz(c)-1] += 1;
			c[sz(c)-3] += 1;
			run = true;
		}
		
	}
	
	//removes 0 from the front
	pos = c.find("1");
	if(pos != string::npos)
		c = c.substr(pos,sz(c)-pos);
	
	return c;
}	

int main() {

	while(true) {
		string a,b;
		getline(cin,a);
		getline(cin,b);
		if(cin.eof())
			break;
		cin.ignore();
		cout << process(a,b) << endl;
	}
	
	return 0;
}










































