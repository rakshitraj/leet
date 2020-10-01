#include<iostream>
#include<cassert>

class solution{
public:
    int reverse(int x) {
        long long rev = 0;
        bool isneg = false;
        if (x<0) {
            isneg = !isneg;
            x = abs(x);
        }
        while (x>0){
            rev = rev*10 + x%10;
            x /= 10;
        }
        // Check if reverse is in range [-2^31, 2^31 -1]
        int result;
        if (rev > 2147483647){
            result = 0;
        }
        else{
            result = rev;
        }
        if (isneg) {
            result *= -1;
        }
        return result;
    }
};

void test(solution obj){
    int num=0, op=0, ans=0;
    //Test1
    num = 23456;
    ans = 65432;
    op = obj.reverse(num);
    assert(ans == op);
    //Test2
    num = 764758;
    ans = 857467;
    op = obj.reverse(num);
    assert(ans == op);
    //Test3
    num = 2147483646;
    ans = 0;
    op = obj.reverse(num);
    assert(ans == op);
}

int main()
{
    solution obj;
    test(obj);
    return 0;
}