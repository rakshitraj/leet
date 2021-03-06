#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
           
        std::vector<int> duration;
     
        duration.push_back(releaseTimes[0]);
        char longest = keysPressed[0];
        int longPress = releaseTimes[0];
        
        for (int i=1; i < releaseTimes.size(); i++) {
            duration.push_back(releaseTimes[i] - releaseTimes[i-1]);
            if (duration[i] >= longPress){
                if (duration[i] > longPress) longest = keysPressed[i];
                else if (duration[i] == longPress) longest = std::max(keysPressed[i], keysPressed[i-1]);
                longPress = duration[i];
            }
        }
        return longest;
    }
};

void test(Solution& obj){
    vector<int> releaseTimes = {12,23,36,46,62};
    string keysPressed = "spuda";
    char longest = obj.slowestKey(releaseTimes, keysPressed);
    std::cout << "Output: " << longest;
}

int main(){
    Solution obj;
    test(obj);
    return 0;
}