#include <bits/stdc++.h>
using namespace std;

#define lop(i,end) for(int i=0; i<end; i++)

char board[16],play[2] = {'x','o'};

bool isWin(char p){
    int f;
    lop(i,4){
        f = 1;
        lop(j,4) if(board[i*4 + j] != p) f = 0;
        if(f) return true;
    }

    lop(i,4){
        f = 1;
        lop(j,4) if(board[j*4 + i] != p) f = 0;
        if(f) return true;
    }

    f = 1;
    lop(i,4) if(board[i*4 + i] != p) f = 0;
    if(f) return true;

    return board[3] == p && board[6] == p && board[9] == p && board[12] == p;
}

map<string, int> forced;
int solve(int turn){
    if(forced[board]) return forced[board];

    if(isWin('x')) return forced[board] = 16;
    if(isWin('o')) return forced[board] = -1;

    int ret = -1;
    bool sureWin = true;
    lop(i,16){
        if(board[i] == '.'){
            board[i] = play[turn];
            int an = solve(!turn);
            sureWin &= (an != -1);
            board[i] = '.';
            if(!turn && (an != -1)){
                ret = i;
                break;
            }
            if(!sureWin && turn) break;
        }
    }
    if(sureWin && turn) ret = 16;

    return forced[board] = ret;
}

int main()
{
    char c;
    cin>>c;
    while(c != '$'){
        lop(i,16) cin>>board[i];
        int ans = solve(0);
        if(ans == -1) cout<<"#####\n";
        else printf("(%d,%d)\n", ans/4, ans%4);
        cin>>c;
    }

    return 0;
}
