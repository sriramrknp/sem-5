// CS20B1107, SRIRAM REDDY CHEERLA
// CD lab-8

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter any operator: ";
    cin >> s;

    if(s.size() >= 1 && s.size() <= 2)
    {
        switch (s[0])
        {
            case '>':
                if (s.size() > 1)
                {
                    if (s[1] == '=')
                        cout << "Greater than or equal" << '\n';
                    else if (s[1] == '>')
                        cout << "Extraction operator" << '\n';
                    else
                        cout << "Not a operator" << '\n';
                }
                else
                    cout << "Greater than" << '\n';
                break;
            case '<':
                if (s.size() > 1)
                {
                    if (s[1] == '=')
                        cout << "Less than or equal" << '\n';
                    else if (s[1] == '<')
                        cout << "Insertion operator" << '\n';
                    else
                        cout << "Not a operator" << '\n';
                }
                else
                    cout << "Less than" << '\n';
                break;
            case '=':
                if (s.size() > 1)
                {
                    if (s[1] == '=')
                        cout << "Equal to" << '\n';
                    else
                        cout << "Not a operator" << '\n';
                }
                else
                    cout << "Assignment" << '\n';
                break;
            case '!':
                if (s.size() > 1)
                {
                    if (s[1] == '=')
                        cout << "Not Equal" << '\n';
                    else
                        cout << "Not a operator" << '\n';
                }
                else
                    cout << "Bit Not" << '\n';
                break;
            case '&':
                if (s.size() > 1)
                {
                    if (s[1] == '&')
                        cout << "Logical AND" << '\n';
                    else
                        cout << "Not a operator" << '\n';
                }
                else
                    cout << "Bitwise AND" << '\n';
                break;
            case '|':
                if (s.size() > 1)
                {
                    if (s[1] == '|')
                        cout << "Logical OR" << '\n';
                    else
                        cout << "Not a operator" << '\n';
                }
                else
                    cout << "Bitwise OR" << '\n';
                break;
            case '+':
                if (s.size() > 1){
                    cout << "Not a operator" << '\n';
                }
                else
                    cout << "Addition" << '\n';
                break;
            case '-':
                if (s.size() > 1){
                    cout << "Not a operator" << '\n';
                }
                else
                    cout << "Substraction" << '\n';
                break;
            case '*':
                if (s.size() > 1){
                    cout << "Not a operator" << '\n';
                }
                else
                    cout << "Multiplication" << '\n';
                break;
            case '/':
                if (s.size() > 1)
                {
                    cout << "Not a operator" << '\n';
                }
                else
                    cout << "Division" << '\n';
                break;
            case '%':
                if (s.size() > 1)
                {
                    cout << "Not a operator" << '\n';
                }
                else
                    cout << "Modulus" << '\n';
                break;
            default:
                cout << "Not a operator" << '\n';
        }
    }
    else if(s.size() > 2)
        cout << "Not a operator" << '\n';
}