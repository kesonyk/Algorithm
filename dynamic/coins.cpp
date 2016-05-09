#include <iostream>
#include <vector>

using std::vector;

vector<int> coins{1,3,5};

/*given the coins and n
 *return the least number of coins whose sum is n
 */
vector<int> num_coins(vector<int> &coins,int n){
    vector<int> rets(n+1,0);
    for(int i=1;i<=n;i++){
        int q=INT_MAX;
        for(auto val:coins){
            if(val<=i){
                q=std::min(q,rets[i-val]+1);
            }
        }
        rets[i]=q;
    }
    //返回的是小于n的左右结果，方便验证，也可直接返回rets[n]
    return rets;
}

int main(){
    auto rets=num_coins(coins,11);
    for(auto v:rets)
        std::cout<<v<<std::endl;
    return 0;
}


