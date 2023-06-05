// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"
#include <string>

int pr(char x) {
    if (x == '(') return 0;
    else if (x == ')') return 1;
    else if (x == '+' || x == '-') return 2;
    else if (x == '*' || x == '/') return 3;
    else return -1;
}

int let(std::string s) {
    int let = 0;
    char c = s[0];
    while (c != '\0')
        c = s[++l];
    return let;
}
int op (char x) {
    return (x == '+' || x == '-' \
            || x == '*' || x == '/');
}
int conv (char x) {
    char mas[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++) {
        if (x == mas[i])
            return i;
    }
    return -1;
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string result;
    char node;
    int i = 0;
    char ch = arr[0];
    while (ch != '\0') {
        if (ch >= '0' && ch <= '9') {
            result = result + ch + " ";
        } else if (ch == ')') {
            if (!stack1.isEmpty()) {
                node = stack1.pop();
                while (node != '(') {
                    result = result + node + " ";
                    node = stack1.pop();
                }
            }
        } else if ((stack1.isEmpty()) || ch == '(' || prior(ch) >\
                   prior(stack1.get())) {
            stack1.push(ch);
        } else if ((!stack1.isEmpty()) && (prior(ch) <= prior(stack1.get()))) {
            while ((!stack1.isEmpty()) && (prior(ch) <= prior(stack1.get()))) {
                node = stack1.pop();
                result = result + node + " ";
            }
            stack1.push(ch);
        }
        ++i;
        ch = arr[i];
    }
    while (!stack1.isEmpty()) {
        node = stack1.pop();
        if (stack1.isEmpty()) result = result + node;
        else
            result = result + node + " ";
    }
    return result;
}
int eval(std::string pref) {
    TStack<int> stack1_;
    for (int i = 0; i < pref.length(); i+=2) {
        if (num(pref[i])) {
            stack1_.push(conv(pref[i]));
        } else if (op(pref[i])) {
            int b = stack1_.get();
            stack1_.pop();
            int a = stack1_.get();
            stack1_.pop();
            if (pref[i] == '+') {
                stack1_.push(a + b);
            } else if (pref[i] == '-') {
                stack1_.push(a - b);
            } else if (pref[i] == '*') {
                stack1_.push(a * b);
            } else if (pref[i] == '/') {
                stack1_.push(a / b);
            }
        }
    }
    return stack1_.get();
}
