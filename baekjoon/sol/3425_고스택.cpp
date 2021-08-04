
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>

using namespace std;
bool mulError(long long secondNum, long long firstNum)
{
    if (secondNum * firstNum > 1000000000)
    {
        cout << "ERROR"
             << "\n";
        return true;
    }
    else
        return false;
}
bool addError(long long secondNum, long long firstNum)
{
    if (secondNum + firstNum > 1000000000)
    {
        cout << "ERROR"
             << "\n";
        return true;
    }
    else
        return false;
}
bool divizeroError(long long firstNum)
{
    if (firstNum == 0)
    {
        cout << "ERROR"
             << "\n";
        return true;
    }
    else
        return false;
}
void modPush(long long &secondNum, long long &firstNum, stack<long long> &_s)
{
    if (secondNum < 0 && firstNum < 0)
    {
        secondNum *= -1;
        firstNum *= -1;
        _s.push(-1 * (secondNum % firstNum));
    }
    else if (secondNum < 0 && firstNum > 0)
    {
        secondNum *= -1;
        _s.push(-1 * (secondNum % firstNum));
    }
    else if (secondNum > 0 && firstNum < 0)
    {
        firstNum *= -1;
        _s.push((secondNum % firstNum));
    }
    else
    {
        _s.push((secondNum % firstNum));
    }
}
bool negativeError(long long secondNum, long long firstNum)
{
    if (secondNum - firstNum < -1000000000)
    {
        cout << "ERROR"
             << "\n";
        return true;
    }
    else
        return false;
}
bool emptyError(stack<long long> &_s)
{
    if (_s.empty())
    {
        cout << "ERROR"
             << "\n";
        return true;
    }
    else
        return false;
}
void logic(queue<string> _q, stack<long long> _s)
{
    while (!_q.empty())
    {
        string oper = _q.front();
        _q.pop();

        if (oper == "NUM")
        {
            string num = _q.front();
            _q.pop();
            _s.push(stoi(num));
        }
        else if (oper == "POP")
        {
            if (emptyError(_s))
                return;
            _s.pop();
        }
        else if (oper == "INV")
        {
            if (emptyError(_s))
                return;
            long long num = _s.top();
            _s.pop();
            num *= -1;
            _s.push(num);
        }
        else if (oper == "DUP")
        {
            if (emptyError(_s))
                return;
            long long num = _s.top();
            _s.push(num);
        }
        else if (oper == "SWP")
        {
            if (emptyError(_s))
                return;
            long long firstNum = _s.top();
            _s.pop();

            if (emptyError(_s))
                return;
            long long secondNum = _s.top();
            _s.pop();
            _s.push(firstNum);
            _s.push(secondNum);
        }
        else if (oper == "ADD")
        {
            if (emptyError(_s))
                return;
            long long firstNum = _s.top();
            _s.pop();

            if (emptyError(_s))
                return;
            long long secondNum = _s.top();
            _s.pop();

            if (addError(secondNum, firstNum))
                return;
            _s.push(secondNum + firstNum);
        }
        else if (oper == "SUB")
        {
            bool retflag;
            if (emptyError(_s))
                return;
            long long firstNum = _s.top();
            _s.pop();

            if (emptyError(_s))
                return;
            long long secondNum = _s.top();
            _s.pop();

            if (negativeError(secondNum, firstNum))
                return;
            _s.push(secondNum - firstNum);
        }
        else if (oper == "MUL")
        {
            if (emptyError(_s))
                return;
            long long firstNum = _s.top();
            _s.pop();

            if (emptyError(_s))
                return;
            long long secondNum = _s.top();
            _s.pop();

            if (mulError(secondNum, firstNum))
                return;
            _s.push(firstNum * secondNum);
        }
        else if (oper == "DIV")
        {
            if (emptyError(_s))
                return;
            long long firstNum = _s.top();
            _s.pop();

            if (emptyError(_s))
                return;
            long long secondNum = _s.top();
            _s.pop();

            if (divizeroError(firstNum))
                return;

            _s.push(secondNum / firstNum);
        }
        else if (oper == "MOD")
        {
            if (emptyError(_s))
                return;
            long long firstNum = _s.top();
            _s.pop();

            if (emptyError(_s))
                return;
            long long secondNum = _s.top();
            _s.pop();

            if (divizeroError(firstNum))
                return;

            modPush(secondNum, firstNum, _s);
        }
    }

    if (_s.size() != 1)
    {
        cout << "ERROR\n";
        return;
    }

    long long num = _s.top();
    _s.pop();
    cout << num << "\n";
    return;
}

int main()
{

    string input;
    queue<string> q;
    stack<long long> s;
    while (1)
    {
        cin >> input;
        q.push(input);
        if (input == "END")
        {
            int testCase;
            cin >> testCase;
            long long inNum;
            for (int i = 0; i < testCase; i++)
            {
                cin >> inNum;
                s = stack<long long>();
                s.push(inNum);
                try
                {
                    logic(q, s);
                }
                catch (int er)
                {
                    cout << "ERROR\n";
                }
            }
            cout << "\n";
            q = queue<string>();
        }
        else if (input == "QUIT")
        {
            break;
        }
    }

    return 0;
}