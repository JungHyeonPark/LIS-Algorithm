#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

vector<int> v;

void create_data(int siz)
{
    v.clear();
    v.resize(siz);
    for(int i=0; i<siz; i++) v[i]=rand()%10000;
}

void lis_n2()
{
    vector<int> dp(v.size());
    clock_t t=clock();
    dp[0]=1;
    int lis=1;
    for(int i=1; i<v.size(); i++){
        int maxl=0;
        for(int j=0; j<i; j++){
            if(v[j]<v[i]){
                maxl=max(maxl, dp[j]);
            }
        }
        dp[i]=maxl+1;
        lis=max(lis,dp[i]);
    }

    cout<<"====== N^2 LIS =====\n";
    cout<<"LIS 길이 : "<<lis<<"\n";
    cout<<"수행시간 : "<<(clock()-t)/(double)CLOCKS_PER_SEC<<"초\n";
    cout<<"====================\n";
}

void lis_nlogn()
{
    clock_t t=clock();

    vector<int> dp;
    for(int i=0; i<v.size(); i++){
        auto it=lower_bound(dp.begin(),dp.end(),v[i]);
        if(it==dp.end()) dp.push_back(v[i]);
        else *it=v[i];
    }

    cout<<"==== NlogN LIS =====\n";
    cout<<"LIS 길이 : "<<dp.size()<<"\n";
    cout<<"수행시간 : "<<(clock()-t)/(double)CLOCKS_PER_SEC<<"초\n";
    cout<<"====================\n";
}

int main()
{
    // cout 소수점 출력 설정
    cout.precision(8);
    cout<<fixed;

    // 랜덤 데이터 크기
    int data_siz = 100;
    // 랜덤 데이터 생성
    create_data(data_siz);

    // 결과 출력
    cout<<"< 데이터 길이 : "<<data_siz<<" >\n";
    // N^2 LIS
    lis_n2();
    cout<<"\n";
    // NlogN LIS
    lis_nlogn();

    return 0;
}