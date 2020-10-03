#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int check() {

    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            struct Bracket node = {next, (position+1)};
            opening_brackets_stack.push(node);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(!opening_brackets_stack.empty() && opening_brackets_stack.top().Matchc(next)) {
                opening_brackets_stack.pop();
            }
            else return position+1;
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.size() != 0) return opening_brackets_stack.top().position; 
    return 0;
}

int main()
{
    // test();

    // std::string text;
    // getline(std::cin, text);

    int valid = check();
    if (valid == 0) std::cout << "Success";
    else std::cout << valid;

    return 0;
}