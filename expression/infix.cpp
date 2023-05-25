#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/*calculate the infix expression*/
/*
main idea:
1. use two stacks for saving numbers and operators
2. different situations:
    2.0 number larger than ten
    2.1 negative number with minus sign & positive number with plus sign
    2.2 pairs
    2.3 same priority op
    
*/

int calInfixExpression(string exp){
    stack<int> nums; // save numbers
    stack<char> ops; // save operators
    unordered_map<char, int> priority {{'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}, {'}', 1}, {')', 1}, {')', 1}};
    unordered_map<char, char> pairs {{')', '('}, {']', '['}, {'}', '{'}};
    unordered_map<char, char> r_pairs{{'(', ')'}, {'[', ']'}, {'{', '}'}};
    char cur;
    int opNum1, opNum2, res, number;
    for (int i = 0; i < exp.size(); i++) {
        cur = exp[i];
        if ('0' <= cur && cur <= '9') {
            number = 0;
            while (i < exp.size() && '0' <= cur && cur <= '9') {
                if (!ops.empty() && ops.top() == '-') {
                    ops.pop();
                    if (i == 1 || r_pairs.find(exp[i - 2]) != r_pairs.end()) {
                        //this minus sign is for negative number
                        number = number * 10 + 0 - cur + '0';
                    } else {
                        ops.push('-');
                        number = number * 10 + cur - '0';
                    }
                } else if (!ops.empty() && ops.top() == '+') {
                    ops.pop();
                    if (i != 1 && r_pairs.find(exp[i - 2]) == r_pairs.end())
                        // this plus sign is not for positive number
                        ops.push('+');
                    number = number * 10 + cur - '0';
                } else {
                    number = number * 10 + cur - '0';
                }
                ++i;
                if (i == exp.size()) break;
                cur = exp[i];
            }
            nums.push(number);
        }
        if (i == exp.size()) break;
        if (cur == '(' || cur == '{' || cur == '[') {
            ops.push(cur);
            continue;
        }
        if (cur == ')' || cur == ']' || cur == '}') {
            while (ops.top() != pairs[cur]) {
                opNum1 = nums.top();
                nums.pop();
                opNum2 = nums.top();
                nums.pop();
                switch (ops.top()) {
                    case '+':
                        res = opNum2 + opNum1;
                        break;
                    case '-':
                        res = opNum2 - opNum1;
                        break;
                    case '*':
                        res = opNum2 * opNum1;
                        break;
                    case '/':
                        res = opNum2 / opNum1;
                        break;
                }
                ops.pop();
                nums.push(res);
            }
            ops.pop();
            continue;
        }
        while (!ops.empty() && priority[cur] <= priority[ops.top()]) {
            //meet the op with lower priority 
            opNum1 = nums.top();
            nums.pop();
            opNum2 = nums.top();
            nums.pop();
            switch (ops.top()) {
                case '+':
                    res = opNum2 + opNum1;
                    break;
                case '-':
                    res = opNum2 - opNum1;
                    break;
                case '*':
                    res = opNum2 * opNum1;
                    break;
                case '/':
                    res = opNum2 / opNum1;
                    break;
            }
            ops.pop();
            nums.push(res);
        }
        ops.push(cur);
    }
    // left in the stack need to solve
    while (!ops.empty()) {
        opNum1 = nums.top();
        nums.pop();
        opNum2 = nums.top();
        nums.pop();
        switch (ops.top()) {
            case '+':
                res = opNum2 + opNum1;
                break;
            case '-':
                res = opNum2 - opNum1;
                break;
            case '*':
                res = opNum2 * opNum1;
                break;
            case '/':
                res = opNum2 / opNum1;
                break;
        }
        ops.pop();
        nums.push(res);
    }
    return nums.top();
}