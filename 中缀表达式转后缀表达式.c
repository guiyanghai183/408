#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>
/*
先看表达式求值，把有关num的操作删除即可
*/
using namespace std;

stack<char> op;
stack<int> num;

void eval()
{
    auto c = op.top(); op.pop();
    cout << c << ' ';
}

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    for (int i = 0; i < s.size(); i ++ )
    {
        if (isdigit(s[i]))
        {
            int j = i, x = 0;
            while (j < s.size() && isdigit(s[j]))
                x = x * 10 + s[j ++ ] - '0';
            cout << x << ' ';
            i = j - 1;
        }
        else if (s[i] == '(') op.push(s[i]);
        else if (s[i] == ')')
        {
            while (op.top() != '(') eval();
            op.pop();
        }
        else
        {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[s[i]])
                eval();
            op.push(s[i]);
        }
    }

    while (op.size()) eval();
    

    return 0;
}

