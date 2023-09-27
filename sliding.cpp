#include<bits/stdc++.h>
#define gap cout<<endl;
#define ll long long int
using namespace std;

long findminprice(int n ,int *price){
    unordered_map<int,int>m;
    int left=0;
    long long ans=1e12,sum=0;

    for(int right=0;right<n;right++){
        sum+=price[right];
        m[price[right]]++;

        while(m[price[right]]>1){
            ans = min(ans,sum);
            sum-=price[left];
            m[price[left]]--;
            left++;
        }
    }
    if(ans==1e12)
        return -1;
        
    return ans;
}

int main(){
    int price[] = {1,2,3,1,2,1};
    int n = sizeof(price)/sizeof(price[0]);
    auto it = findminprice(n,price);
    cout<<it;
    return 0;
}