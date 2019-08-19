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

int main() {
    std::string text;

    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push({next,position});
        }

        if (next == ')' || next == ']' || next == '}') {
            if(!opening_brackets_stack.empty()){
                if(opening_brackets_stack.top().Matchc(next)){
                    opening_brackets_stack.pop();
                }
                else{
                    std::cout << position+1;
                    return 0;
                }
            }
            else{
                std::cout << position+1;
                return 0;
            }
        }
    }
    int temp{-1};
    while (!opening_brackets_stack.empty()){
        temp = opening_brackets_stack.top().position;
        opening_brackets_stack.pop();
    }
    if (temp != -1){
        std::cout << temp+1;
        return  0;
    }

    std::cout << "Success";

    return 0;
}
