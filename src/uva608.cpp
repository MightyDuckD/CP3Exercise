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

#define all(c) ALL(c)
#define contains(container,value) (find(all(container),value) != (container).end())

void dump(set<char> v) {
	cout << "c: ";
	for(auto c : v)
    	cout << ' ' << c;
  	cout << endl;
}

void dump(vector<char> v) {
	cout << "c: ";
	for (unsigned i=0; i<v.size(); ++i)
    	cout << ' ' << v[i];
  	cout << endl;
}


void dump(vector<int> v,string o) {
	cout << "v: ";
	for (unsigned i=0; i<v.size(); ++i)
    	cout << ' ' << v[i];
  	cout << ' ' << o << endl;
}

vector<int> eq(string a, string b) {
	vector<int> v(12,0);
	for(char c : a)
		v[c-'A']++;
	for(char c : b)
		v[c-'A']--;
	return v;
}

bool eval(char c,bool heavy,vector<int> eq,string d) {
	
	int normal = 1;
	int odd = (heavy?100:-100);
	int res = 0;
	REP(i,12) {
		res += eq[i] * ((c==(i+'A'))?odd:normal);
		//printf(" %d",eq[i]);
	}
	
	string up = "up";
	string down = "down";
	//printf(" - res %d\n",res);
	if(d == up)
		return res > 0;
	if(d == down)
		return res < 0;
	return res == 0;
}

bool isCounter(char c,bool checkHeavy,string str[9]) {
	
	bool res0 = eval(c,checkHeavy,eq(str[0],str[1]),str[2]);
	bool res1 = eval(c,checkHeavy,eq(str[3],str[4]),str[5]);
	bool res2 = eval(c,checkHeavy,eq(str[6],str[7]),str[8]);
	//printf("%c %d: %d %d %d\n",c,checkHeavy,res0,res1,res2); 
	return res0 && res1 && res2;
}

int main() {
	int N;
	scanf("%d\n",&N);
	REP(n,N) {
		string str[9];
		REP(i,9) cin >> str[i];
		for(char c = 'A'; c <= 'L'; c++) {
			if(isCounter(c,false,str))
				printf("%c is the counterfeit coin and it is light.\n",c);
			if(isCounter(c,true,str))
				printf("%c is the counterfeit coin and it is heavy.\n",c);
		}	
	}
	return 0;
}










































