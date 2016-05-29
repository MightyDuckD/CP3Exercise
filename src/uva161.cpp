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


//returns the seconds when the lights all turn green again
int doit(vector<int> cycles) {

	bool start = true;
	int time;
	for(time = 0; time <= (3600*5)+5; time++) {
		bool sync = true;
		//printf("%4d: ",time);
		for(int c : cycles) {
			int color = (time%(2*c));
			//printf("[%d,%d %d]",color,sync,start);
			if(color >= c-5) {//NOT GREEN
				if(start) {
					start = false;
					sync = false;
					break;
				} else {
					sync = false;
				}
			}
		}
		//printf("\n");
		if(sync && !start)
			break;
	}
	return time;
}

int main() {

	while(true) {
		
		vector<int> data;
		int a;
		do {
			scanf("%d",&a);
			data.pb(a);
		} while(a != 0);
		
		data.pop_back();//remove the 0 at the end
		if(data.empty())
			break;
		
		int seconds = doit(data);
		if(seconds > (3600*5))
			printf("Signals fail to synchronise in 5 hours\n");
		else
			printf("%02d:%02d:%02d\n",seconds/(60*60),(seconds/60)%60,seconds%(60));
	}

	return 0;
}










































