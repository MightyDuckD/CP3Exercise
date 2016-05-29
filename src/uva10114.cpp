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


int run(int D,double downpay, double amount,double rates[]) {
	double car = amount + downpay;
	double loan = amount;
	REP(d,D) {
		car *= 1 - rates[d];
		if(loan < car)
			return d;
		loan -= amount/D;
	}
	return D;
}


int main() {

	int D,R,M;
	double downpay,amount,rate,rates[105];
	
	while(true) {
		scanf("%d%lf%lf%d",&D,&downpay,&amount,&R);
		if(D < 0)
			break;
		int o = -1;
		REP(r,R) {
			scanf("%d%lf",&M,&rate);
			rates[M] = rate;
			for(int i = o+1; i < M; i++)
				rates[i] = rates[o];
			o = M;
		}
		for(int i = o+1; i <= D; i++)
			rates[i] = rates[o];
		int days = run(D,downpay,amount,rates);
		printf("%d month%s\n",days,(days==1)?"":"s");
	}
	return 0;
}










































