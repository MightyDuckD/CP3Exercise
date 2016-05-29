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

#define r first
#define c second


pair<int,int> indexOf(int a,int field[5][5]) {
	REP(r,5) {
		REP(c,5) {
			if(!(r==2 && c==2))
				if(a == field[r][c])
					return mp(r,c);
		}
	}
	return mp(-1,-1);
}


int when(int field[5][5], int input[75]) {
	
	int rows[5] = {0,0,1,0,0};
	int cols[5] = {0,0,1,0,0};
	int diag[2] = {1,1};
	
	REP(i, 75) {
		pair<int,int> pos = indexOf(input[i],field);
		if(pos.r != -1) {
			rows[pos.r]++;
			cols[pos.c]++;
			if(pos.r == pos.c)
				diag[0]++;
			if(pos.r == 4-pos.c)
				diag[1]++;
		}
		for(auto a : rows) if(a == 5) return i+1;
		for(auto a : cols) if(a == 5) return i+1;
		for(auto a : diag) if(a == 5) return i+1;
		
	}
	return 76;
}



int main() {

	int N;
	int field[5][5];
	int input[75];
	scanf("%d",&N);
	REP(n,N) {
		
		field[2][2] = 0;
		REP(r,5) {
			REP(c,5) {
				if(!(r == 2 && c == 2))
					scanf("%d",&field[r][c]);
			}
		}
		REP(i,75) scanf("%d",&input[i]);
		
		printf("BINGO after %d numbers announced\n",when(field,input));
	}
	
	return 0;
}










































