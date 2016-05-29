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

#define all(x) ALL(x)
#define indexOf(container,value) (find(all(container),value) - (container).begin())

struct vec3i {
	int x,y,z;
	
	bool operator==(const vec3i& v) {
		return x == v.x && y == v.y && z == v.z;
	}
	int (&operator[](const int i)) {
		switch(i) {
			case 0: return x;
			case 1: return y;
			case 2: return z;
		}
		throw std::runtime_error("vec3 out of bounds");
	}
};
struct mat3x3i {
	int m[3][3];
	int (&operator[](const int i)) [3] {
		return m[i];
	}
};

vector<string> name = {"No","+x","-x","+y","-y","+z","-z"};
//axis vectors aligned to name
vector<vec3i> dir = {
	{0,0,0},
	{ 1,0,0},
	{-1,0,0},
	{0, 1,0},
	{0,-1,0},
	{0,0, 1},
	{0,0,-1},
};
//simplified 3d rotation matrices @ see https://en.wikipedia.org/wiki/Rotation_matrix#Basic_rotations
vector<mat3x3i> rot = {
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0}},//invalid
	{{ 1, 0, 0, 0, 0,-1, 0, 1, 0}},//x clockwise
	{{ 1, 0, 0, 0, 0, 1, 0,-1, 0}},//  counter
	{{ 0, 0, 1, 0, 1, 0,-1, 0, 0}},//y clockwise
	{{ 0, 0,-1, 0, 1, 0, 1, 0, 0}},//  counter
	{{ 0,-1, 0, 1, 0, 0, 0, 0, 1}},//z clockwise
	{{ 0, 1, 0,-1, 0, 0, 0, 0, 1}},//  counter
};

vec3i mul(mat3x3i &m, vec3i& b) {
	vec3i res = {0,0,0};
	REP(i,3) {
		REP(j,3) {
			res[i] += m[i][j] * b[j];
		}
	}
	return res;
}

int sign(int a) {
	return (a==0)?0:(a<0?-1:1);
}

vec3i current;
int init(int L) {
	current = {1,0,0};
}
int bend(int command) {
	int map[] = {0,1,2,5,6,4,3};
	if(command != 0)
		current = mul(rot[map[command]],current);
	return indexOf(dir,current);
}

int main() {
	while(true) {
		int L;
		scanf("%d",&L);
		if(L == 0)
			break;
		init(L);
		int res = 0;
		REP(l,L-1) {
			char a,b;
			scanf(" %c%c",&a,&b);
			string test = {a,b};
			res = bend(indexOf(name,test));
		}
		cout << name[res] << endl;
	}
	return 0;
}










































