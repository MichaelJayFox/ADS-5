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

int num (char x) {
    return (x >= '0' && x <= '9');
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
    TStack<char>  stack1;
    std::string str = "";
    for (int i = 0; i < inf.length(); i++) {
        if (num(inf[i])) {
            str += inf[i];
            str += " ";
        } else if (inf[i] == '(') {
            stack1.push(inf[i]);
        } else if (inf[i] == ')') {
            while (!stack1.isEmpty() && stack1.get() != '(') {
                str += stack1.get();
                str += " ";
                stack1.pop();
            }
            stack1.pop();
        } else if (op(inf[i])) {
            while (!stack1.isEmpty() && pr(stack1.get()) \
                   >= pr(inf[i])) {
                str += stack1.get();
                str += " ";
                stack1.pop();
            }
            stack1.push(inf[i]);
        }
    }
    while (!stack1.isEmpty()) {
        str += stack1.get();
        str += " ";
        stack1.pop();
    }
    str.erase(str.length() - 1, 1);
    return str;
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
