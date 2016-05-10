#include <iostream>
#include <vector>
using std::vector;

int longestZigZag(vector<int> &nums){
    int N=nums.size();
    vector<int> states(N,0);
    vector<int> rets(N,1);
    for(int i=1;i!=N;i++){
        for(int j=0;j!=i;j++){
            if((states[j]==0)||(states[j]==-1&&nums[i]>nums[j])||(states[j]==1&&nums[i]<nums[j]))
                if(rets[j]+1>rets[i]){
                    rets[i]=rets[j]+1;
                    if(nums[i]>nums[j])
                        states[i]=1;
                    if(nums[i]<nums[j])
                        states[i]=-1;
                }
        //std::cout<<i<<": "<<rets[i]<<"states: "<<states[i]<<std::endl;
        }
    }
    return rets[N-1];
}

int main(){
    vector<int> nums{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
        600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
        67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
        477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
        249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
    std::cout<<longestZigZag(nums)<<std::endl;
    return 0;
}
