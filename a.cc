#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;

typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef long long ll;
#define LSOne(S) ((S) & -(S))

#include<bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

#define INF 1061109567
//#define INF 1000000000
//          1061109567


enum{UNVISITED=-1,VISITED=-2,EXPLORED=-3};



int main() {
    int n,t;
    long double p;

    while(1){
        cin >> n;
        if(n==0) break;
        vector<long double> profit(1440,-0.08);
        vector<long double> pre_sum(1440,0);
        for(int i=0;i<n;++i){
            cin >> t >> p;
            //size_t pos = p.find('.');
            //long a = stoi(p.substr(0,pos))*1000000;
            //a += stoi(p.substr(pos+1))*10000;
            profit[t] += p;
        }

        pre_sum[0] = profit[0];
        for(int i=1;i<1440;++i) pre_sum[i] = profit[i]+pre_sum[i-1];

        //int m = t_stamp.size();

        long double tmp;
        long double res = 0;
        int beg,end;
        int min_len = 1440;
        for(int len=0;len<1440;++len)
            for(int i=0;i+len<1440;++i){
                tmp = i==0 ? pre_sum[i+len] : pre_sum[i+len]-pre_sum[i-1];
                

                if(tmp>res){
                    res = tmp;
                    beg = i;
                    end = i+len;
                    min_len = len;
                }
            }

        if(res<=0)
            cout << "no profit" << endl;
        else
            printf("%.2Lf %d %d\n", res, beg, end);
            //printf("%ld.%ld %d %d\n", res/1000000, (res%1000000)/10000, beg, end);
    }
    return 0;
}
