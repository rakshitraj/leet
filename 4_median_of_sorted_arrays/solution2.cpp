#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int tot = m+n;
        
        if(tot % 2 == 0){
            int l = kth(nums1,0,m-1,nums2,0,n-1,tot/2);
            
            int r = kth(nums1,0,m-1,nums2,0,n-1,tot/2+1);
           
            return (l+r)/2.0;
        }else{
            return kth(nums1,0,m-1,nums2,0,n-1,tot/2+1);
        }
        
    }
    
    
    int kth(vector<int>&nums1, int st1, int ed1, vector<int>&nums2, int st2, int ed2, int k){
        int m = ed1-st1+1;
        int n = ed2-st2+1;
        
        //keep the nums2 as the shorter one, so the base case can work correctly.
        if(n > m) return kth(nums2,st2,ed2,nums1,st1,ed1,k);
        //two base case, if shorter one with 0 size, return it directly.
        if(n == 0) return nums1[st1+k-1];
        //if kth smaller is 1, then it must be the min of the st1 or st2 ele.
        if(k == 1) return min(nums1[st1],nums2[st2]);
        
    
        int j = min(n,k/2);
        int i = k - j;
        
        if(nums1[st1+i-1] > nums2[st2+j-1]){
            
            //k-j, since nums2's left part is the smallest and removed, so kth smallest need to remove this section, since it must be within the current k smallest section.
            return kth(nums1,st1,st1+i-1,nums2,st2+j,ed2,k-j);
        }else{
           
           //k-i, since nums1's left part is the smallest and removed, so kth smallest need to remove this section, since it must be within the current k smallest section. 
            return kth(nums1,st1+i,ed1,nums2,st2,st2+j-1,k-i);
        }
    }
};