#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <array>
#include <queue>


using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;



class StackWithMax {
    vector<int> stack;
    vector<int> stack_max;

  public:

    void Push(int value) {
        stack.push_back(value);
        if (stack_max.empty())
            stack_max.push_back(value);
        else if(value >= stack_max.back())
            stack_max.push_back(value);
    }

    void Pop() {
        assert(stack.size());
        if(stack.back() == stack_max.back())
            stack_max.pop_back();
        stack.pop_back();
    }

    int Max() const {
        assert(stack_max.size());
        return stack_max.back();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
