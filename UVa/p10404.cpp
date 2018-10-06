#include <bits/stdc++.h>
using namespace std;

#define sc(x)  scanf("%d",&x)
#define lop(i,end) for(int i=0; i<end; i++)

int nums[15]; 
bool win[1000010];

int main()
{
    int n,m;
    while(cin>>n){
        sc(m);
        lop(i,m) sc(nums[i]);
        sort(nums, nums+m);
        for(int i = 1; i <= n; i++){
            win[i] = false;
            for(int j = 0; j < m; j++){
                if(i - nums[j] >= 0){
                    if(!win[i-nums[j]] || i == nums[j]){
                        win[i] = true;
                        break;
                    }
                }
            }
        }
        if(win[n]) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }

    return 0;
}