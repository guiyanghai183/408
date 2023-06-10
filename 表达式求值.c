#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
/*背过就行，408未考过大题，但是代码也要背过
设置两个栈： 数栈 符号栈
遍历整个字符串
1. "(" 直接进栈
2. ")" 操作(eval)到遇到"(",再把"("出栈
3. 数字   直接进栈
4. +-*/   操作到遇到"(" 或 栈顶优先级 < 当前优先级 
*/
using namespace std;

stack <char> op;
stack <int> num;

void eval()
{
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    
    if(c == '+') num.push(a + b);
    else if(c == '-') num.push(a - b);
    else if(c == '*') num.push(a * b);
    else num.push(a / b);
}


int main()
{
    string s;
    cin >> s;
    
    unordered_map <char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    
    for(int i = 0; i < s.size(); i ++ )
    {
        if(isdigit(s[i]))
        {
            int j = i, x = 0;
            while(isdigit(s[j]) && j < s.size())
                x = x * 10 + s[j ++ ] - '0';
            num.push(x);
            i = j - 1;
        }
        else if(s[i] == '(') op.push(s[i]);
        else if(s[i] == ')')
        {
            while(op.top() !='(') eval();
            op.pop();
        }
        else
        {
            while(op.size() && op.top() != '(' && pr[op.top()] >= pr[s[i]]) eval();
            op.push(s[i]);
        }
    }
    
    while(op.size()) eval();
    cout << num.top() << endl;
    
    return 0;
}
