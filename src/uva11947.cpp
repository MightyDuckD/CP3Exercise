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

bool leap(int y) {
	return ((y%4==0) && (y%100!=0)) || (y%400 == 0);
}

int days_[] = {-1,31,-1,31,30,31,30,31,31,30,31,30,31};
int days(int y, int m) {
	if(m == 2)
		return leap(y)?29:28;
	return days_[m];
}

string name[] ={
	"aquarius",
	"pisces",
	"aries",
	"taurus",
	
	"gemini",
	"cancer",
	"leo",
	"virgo",
	
	"libra",
	"scorpio",
	"sagittarius",
	"capricorn"
};
int range[][2][2] = {
 {{1,21},{2,19}},
 {{2,20},{3,20}},
 {{3,21},{4,20}},
 {{4,21},{5,21}},
 
 {{5,22},{6,21}},
 {{6,22},{7,22}},
 {{7,23},{8,21}},
 {{8,22},{9,23}},
 
 {{9,24},{10,23}},
 {{10,24},{11,22}},
 {{11,23},{12,22}},
 {{12,23},{1,20}}
};

string sign(int& y, int& m , int& d) {
	
	REP(i,40*7) {
		d++;
		if(d > days(y,m))
			d = 1,m++;
		if(m > 12)
			m=1,y++;
	}
	
	REP(j,12) {
		if(range[j][0][0] == m && range[j][0][1] <= d)
			return name[j];
		if(range[j][1][0] == m && range[j][1][1] >= d)
			return name[j];
	}
	
	return "fail";
}


int main() {

	int N,day,month,year;
	scanf("%d\n",&N);
	REPN(n,N) {
		scanf("%2d%2d%4d",&month,&day,&year);
		string s = sign(year,month,day);
		printf("%d %02d/%02d/%04d %s\n",n,month,day,year,s.c_str());
	}
	return 0;
}










































