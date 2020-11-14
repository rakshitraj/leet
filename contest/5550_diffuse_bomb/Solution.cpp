#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int K) {
        
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        
        vector<int> enigma(code.size(), 0);
        
        if (K == 0) return enigma;
        
        for (int i=0; i<code.size(); i++) {
            int k = K;
            int sum = 0;
            
            if (k > 0)
            while(k != 0) {
                int index = i+(k--);
                if (index > code.size()) index = code.size() - index;
                sum += code[index];
            }
            
            else
            while(k != 0) {
                int index = i+(k++);
                if (index < 0) index = code.size() + index;
                sum += code[index];
            }
            enigma[i] = sum;
        }
        return enigma;
    }
};