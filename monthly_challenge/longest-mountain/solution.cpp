#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        vector<int> gradient(A.size(), 0);
        int prev = A[0];

        for (int i=1; i<A.size(); i++){
            if (A[i] > A[i-1]){
                gradient[i] = 1;
            }
        }

        int len = 0;
        for (int i=0; i<gradient.size()-1; i++) {
            if (gradient[i] == 0 && gradient[i+1] == 1){
                do {
                    
                }while( gradient[i]);
            }

        }
    }
}; 