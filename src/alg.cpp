// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"
int getPr(char d) {
  switch (d) {
    case '(':
      return 0;
      break;
    case ')':
      return 1;
      break;
    case '+':
      return 2;
      break;
    case '-':
      return 2;
      break;
    case '*':
      return 3;
      break;
    case '/':
      return 3;
      break;
    default:
      return -1;
      break;
  }
}
int len(std::string str) {
    char ch = str[0];
    int res = 0;
    while (ch != '\0')
        ch = str[++res];
    return res;
}

int toInt(char ch) {
    char key[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++) {
        if (ch == key[i])
            return i;
    }
    return -1;
}

std::string infx2pstfx(std::string inf) {
    std::string rezult;
    TStack<char, 100> stack11;
    for (auto& d : inf) {
        int priori = getPr(d);
        if (priori == -1) {
            rezult += d;
        } else {
            if (stack11.get() < priori || priori == 0 || stack11.isEmpty()) {
                stack11.push(d);
                stack11.push(d);
            } else if (d == ')') {
                char summa = stack11.get();
                while (getPr(summa) >= priori) {
                    rezult += summa;
                    stack11.pop();
                    summa = stack11.get();
                }
                stack11.pop();
            } else {
                char summa = stack11.get();
                while (getPr(summa) >= priori) {
                    rezult += summa;
                    stack11.pop();
                    summa = stack11.get();
                }
                stack11.push(d);
            }
        }
    }
    while (!stack11.isEmpty()) {
        rezult += stack11.get();
        stack11.pop();
    }
    rezult = spases(rezult);
    return rezult;
}
int vashislenia(const int& x, const int& y, const int& op) {
    switch (op) {
    case'+': return x + y;
    case'-': return x - y;
    case'*': return x * y;
    case'/': return x / y;
    default:
        break;
    }
    return 0;
}
int eval(std::string post) {
    TStack<int, 100> stack12;
    std::string number = "";
    for (int i = 0; i < post.size(); i++) {
        if (getPr(post[i]) == -1) {Ц
            if (post[i] == ' ') {
                continue;
            } else if (isdigit(post[i + 1])) {
                number += post[i];
                continue;
            } else {
                number += post[i];
                stack12.push(atoi(number.c_str()));
                number = "";
            }
        } else {
            int y = stack12.get();
            stack12.pop();
            int x = stack12.get();
            stack12.pop();
            stack12.push(vashislenia(x, y, post[i]));
        }
    }
    return stack12.get();
}
