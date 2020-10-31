#include <iostream>
#include <vector>

class Solution {
private:
    double findMedian(std::vector<int>& arr) {
        double median = 0.00000;
        int size = arr.size();

        if (size == 0) return median;

        if ( size%2 == 0 ) {
           median =  0.50000 *(arr[size/2] + arr[(size/2) -1]);
        }
        else{
            return 1.00000 * arr[size/2];
        }
        return median;
    }

    double mergeTwo(std::vector<int>& arr1,std::vector<int>& arr2, int size1, int size2){
        int i = 0;
        int j = 0;
        int k = 0;

        std::vector<int> temp;
        temp.reserve(size1+size2);

        while(i<size1 && j<size2) {
            if (arr1[i] < arr2[j]) {
                temp.push_back(arr1[i++]);
            }
            else {
                temp.push_back(arr2[j++]);
            }
        }

        while (i<size1) {
            temp.push_back(arr1[i++]);
        }
        while (j<size2) {
            temp.push_back(arr2[j++]);
        }

        return findMedian(temp);
    }

    void merge(std::vector<int>& arr,std::vector<int>& temp, int left, int mid, int right){
        if (left > right) return;

        int i = left;
        int j = mid+1;
        int k = left;

        while ((i<=mid) && (j<=right)) {
            if (arr[i] < arr[j]){
                temp[k++] = arr[i++]; 
            }
            else{
                temp[k++] = arr[j++];
            }
        }

        while (i<= mid) temp[k++] = arr[i++];
        while (j<= right) temp[k++] = arr[j++];

        for (k= left; k<=right; k++){
            arr[k] = temp[k];
        }
    }

    void mergeSort(std::vector<int>& arr, int left, int right) {
        std::vector<int> temp;
        temp.reserve(arr.size());
        temp.assign(arr.size(), 0);

        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, temp, left, mid, right);
    }

public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        return mergeTwo(nums1, nums2, nums1.size(), nums2.size());
    }
    
};