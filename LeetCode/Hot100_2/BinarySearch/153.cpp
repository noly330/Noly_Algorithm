#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int l = -1;
        int r = n;
        int ans = INT_MAX;
        while(l + 1 < r){
            int mid = l + (r-l)/2;
            
            //左边有序
            //如果左边有序，就是递增，取nums[l+1]为可能的最小点，然后就能抛弃l+2~mid上的所有
            if(nums[l+1]<= nums[mid]){
                ans = min(ans,nums[l+1]);
                l = mid;
            }
            else{  //右边有序，和上面同理，mid~r的数字都比nums[mid]大，就抛弃
                ans = min(ans,nums[mid]);
                r = mid;
            }
            cout<<"此时的l和r分别为"<<l<<" "<<r<<endl;
        }
        
        return ans;
    }
};

int main(){
    Solution s;

    vector<int> nums = {2,1};
    cout<<s.findMin(nums)<<endl;
}