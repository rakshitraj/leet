#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {

        std::vector<int> collision;

        collision.push_back(asteroids[0]);
        for (int i = 1; i< asteroids.size(); i++) {
            int curr = asteroids[i];
            if (collision.empty()) collision.push_back(curr);
            else {
                int boom = curr + collision.back();
                if (boom < collision.back() && collision.back() > 0) {
                    if (boom == 0 ) {
                        collision.pop_back();
                    }
                    else if (boom < 0){
                        collision.pop_back();
                        i--;
                    }
                }
                else collision.push_back(curr);
            }
        }
        return collision;
    }
};