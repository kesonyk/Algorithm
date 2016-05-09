#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

vector<int> prices{0,1,5,8,9,10,17,17,20,24,30};

vector<int> steelCut(vector<int> &p,int n){
    vector<int> ret(n+1,0);
    for(int j=1;j<=n;j++){
        int q=INT_MIN;
        for(int i=1;i<=j;i++)
            q=std::max(q,p[i]+ret[j-i]);
        ret[j]=q;
    }
    return ret;
}

int main(){
    auto ret=steelCut(prices,10);
    for(auto v:ret)
        std::cout<<v<<std::endl;
}
