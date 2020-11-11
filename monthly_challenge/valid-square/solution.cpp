#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int dist(vector<int>& p, vector<int>& q) {
        return pow((p[0]-q[0]),2) + pow((p[1]-q[1]),2);
    }

    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        // parallegram
        if ((p1[0] + p2[0]) != (p3[0] + p4[0]) || (p1[1] + p2[1]) != (p3[1] + p4[1])) return false;
        // Rectangle then square
        if (dist(p1, p2) != dist(p3, p4) || dist(p1,p4) != dist(p2, p4)) return false;
        // points are distinct
        if (p1[0] == p2[0] && p1[1]==p2[1]) return false;
        // valid square
        return true;
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        if (check(p1,p2,p3,p4) || check(p1,p3,p2,p4) || check(p1,p4,p2, p3)) return true;
        return false; 
    }
};