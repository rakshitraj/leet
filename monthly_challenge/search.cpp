/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int idx = 1, OUT = 2147483647;
        
        while(1)
        {
            int val = reader.get(idx);
            if(val == OUT || val > target)
                break;
            idx *= 2;
        }
        
        int low = idx/2, high = idx, mid;
        
        while(low <= high)
        {
            mid = low + (high-low)/2;
            int val = reader.get(mid);
            
            if(val == target)
                return mid;
            if(val == OUT || val > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
        
    }
};

static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr); return 0;
}();