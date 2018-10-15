//SRM 330 div1 1000

#include <bits/stdc++.h>
using namespace std;

class LongLongNim{

public:
    int numberOfWins(int maxN, vector<int> moves){
        int sz = moves.size();
        map<int,int> Iwin,Ilose;
        for(int i = 0; i < moves[0]; i++) Ilose[i] = 1;
        int mx = moves[sz-1];
        vector<int> memo(1<<(mx+1),-1);
        int start = -1, finish = -1, flag, mask;
        for(int i = 1; ; i++){
            flag = 0;
            for(int j = 0; j < sz && i >= moves[j] && !flag; j++){
                if(Ilose[i - moves[j]]){
                    Iwin[i] = 1;
                    flag = 1;
                }
            }
            if(!flag) Ilose[i] = 1;
            mask = 0;
            for(int j = 1; j <= mx; j++) if(Ilose[i - j]) mask |= (1 << j);
            if(memo[mask] == -1) memo[mask] = i;
            else {
                start = memo[mask], finish = i-1;
                break;
            }
        }
        int cnt = 0, lengthOfCycle = finish - start + 1, ans = 0;
        int div = (maxN - start + 1)/lengthOfCycle;
        for(int i = 1; i < start; i++) if(Ilose[i]) ans++;
        for(int i = start; i <= finish; i++) if(Ilose[i]) cnt++;
        ans += div*cnt;
        for(int i = start + div*lengthOfCycle; i <= maxN; i++) if(Ilose[i - div*lengthOfCycle]) ans++;

        return ans;
    }
};
