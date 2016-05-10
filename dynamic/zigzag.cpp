#include <iostream>
#include <vector>
using std::vector;

/****
A sequence of numbers is called a zig-zag sequence if 
the differences between successive numbers strictly 
alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative.
 A sequence with fewer than two elements is trivially a zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences 
(6,-3,5,-7,3) are alternately positive and negative. 
In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, 
the first because its first two differences are positive and the s
econd because its last difference is zero.

Given a sequence of integers, sequence, return the length of the 
longest subsequence of sequence that is a zig-zag sequence. 
A subsequence is obtained by deleting some number of elements (possibly zero) 
from the original sequence, leaving the remaining elements in their 
original order.
****/

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
