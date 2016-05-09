#include <iostream>
#include <vector>
using std::vector;

int lis(vector<int> &nums){
    vector<int> rets(nums.size(),1);
    for(int i=1;i!=nums.size();i++){
        for(int j=0;j!=i;j++){
            if(nums[j]<nums[i])
                rets[i]=std::max(rets[i],rets[j]+1);
        }
    }
    return rets[nums.size()-1];
}

int main(){
    vector<int> nums{5,3,4,8,6,7};
    std::cout<<lis(nums)<<std::endl;
    return 0;
}
