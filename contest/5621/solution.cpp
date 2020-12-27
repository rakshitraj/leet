#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int count = 0;
        //Stack of sandwich
        std::stack<int> stack;
        for (auto el: sandwiches){
            stack.emplace(el);
        }
        // queue of students
        std::queue<int> q;
        for (auto el: students){
            q.emplace(el);
        }

        while (true) {
            if (stack.top() == q.front()){
                stack.pop();
                q.pop();
            }
            else{
                if (count == q.size() || q.size() == 0) return (int)q.size();
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return (int)q.size();
    }
};