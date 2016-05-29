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

void setTrue(int r, int c, bool field[8][8]) {
	if(r < 0 || c < 0 || r >= 8 || c >= 8)
		return;
	field[r][c] = true;
}

bool isEmpty(int r, int c, char field[8][8]) {
	if(r < 0 || c < 0 || r >= 8 || c >= 8)
		return false;
	return field[r][c] == ' ';
}

void setTrue(int r,int c,char field[8][8],bool attk[8][8]) {
	if(field[r][c] != ' ')
		setTrue(r,c,attk);
	switch(field[r][c]) {
		case 'P':
			setTrue(r-1,c+1,attk);
			setTrue(r-1,c-1,attk);
			return;
		case 'p':
			setTrue(r+1,c+1,attk);
			setTrue(r+1,c-1,attk);
			return;	
		case 'r':
		case 'R':
			
			FOR(i,r+1,8) {
				if(field[i][c] != ' ')
					break; 
				setTrue(i,c,attk);
			}
			FORD(i,r-1,0) {
				if(field[i][c] != ' ')
					break; 
				setTrue(i,c,attk);
			}
			
			FOR(i,c+1,8) {
				if(field[r][i] != ' ')
					break; 
				setTrue(r,i,attk);
			}
			FORD(i,c-1,0) {
				if(field[r][i] != ' ')
					break; 
				setTrue(r,i,attk);
			}
			
			return;
		case 'n':
		case 'N':
			setTrue(r+2,c+1,attk);
			setTrue(r+2,c-1,attk);
			setTrue(r-2,c+1,attk);
			setTrue(r-2,c-1,attk);
			
			setTrue(r+1,c+2,attk);
			setTrue(r+1,c-2,attk);
			setTrue(r-1,c+2,attk);
			setTrue(r-1,c-2,attk);
			return;
		case 'Q':
		case 'q':
			
			FOR(i,r+1,8) {
				if(field[i][c] != ' ')
					break; 
				setTrue(i,c,attk);
			}
			FORD(i,r-1,0) {
				if(field[i][c] != ' ')
					break; 
				setTrue(i,c,attk);
			}
			
			FOR(i,c+1,8) {
				if(field[r][i] != ' ')
					break; 
				setTrue(r,i,attk);
			}
			FORD(i,c-1,0) {
				if(field[r][i] != ' ')
					break; 
				setTrue(r,i,attk);
			}
			
			//falltrough
		case 'b':
		case 'B':
		
			
			REPN(i,7) {
				if(!isEmpty(r+i,c+i,field))
					break;
				setTrue(r+i,c+i,attk);
			}
			REPN(i,7) {
				if(!isEmpty(r-i,c-i,field))
					break;
				setTrue(r-i,c-i,attk);
			}
			
			REPN(i,7) {
				if(!isEmpty(r-i,c+i,field))
					break;
				setTrue(r-i,c+i,attk);
			}
			REPN(i,7) {
				if(!isEmpty(r+i,c-i,field))
					break;
				setTrue(r+i,c-i,attk);
			}
			
			return;
		case 'k':
		case 'K':
			FORN(i,-1,1)
				FORN(j,-1,1)
					setTrue(r+i,c+j,attk);
			return;
		case ' ':
			return;
	}

}

int process(string line) {

	char field[8][8];
	memset(field,' ',sizeof(field[0][0]) * 8 * 8);

	int r = 0, c = 0;
	for(char ch : line) {
		if(isalpha(ch)) {
			field[r][c] = ch;
			c++;
		} else if(isdigit(ch)) {
			c += ch - '0';
		} else {// -> '/'
			r++;
			c = 0;
		}
	}
	
	bool attk[8][8] = {{false}};
	memset(attk,false,sizeof(attk[0][0]) * 8 * 8);
	
	REP(i,8) {
		REP(j,8) {
		
			setTrue(i,j,field,attk);
			if(false) {
				printf("\n");
				REP(x,8) {
					REP(y,8) {
						printf("[%c%d]",field[x][y],attk[x][y]);
					}
					printf("\n");
				}
			}
		
		}
	}
	
	int cnt = 0;
	REP(i,8) REP(j,8) if(!attk[i][j]) cnt++;
	return cnt;
}

int main() {

	while(true) {
		string line;
		getline(cin,line);
		if(cin.eof())
			break;
		cout << process(line) << endl;
	}
	return 0;
}










































