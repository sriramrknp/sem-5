// CS20B1107, SRIRAM REDDY CHEERLA
// LAB - 6

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int x;
    cout << "Enter the input string \n";
    getline(cin, s);
    int sze = s.size();
    for (int i = 0; i < sze; i++)
    {
        if ((s[i] != 'a') && (s[i] != 'b'))
        {
            cout << i << " " << '\n';
            cout << "String is not accepted under 'a*'" << '\n';
            cout << "String is not accepted under 'a*b+'" << '\n';
            cout << "String is not accepted under 'abb'" << '\n';
            exit(1);
        }
    }

    while (1)
    {
        cout << "Enter option \n";
        cout << "   1. to check 'a*'\n";
        cout << "   2. to check 'a*b+'\n";
        cout << "   3. to check 'abb'\n";
        cin >> x;
        switch (x)
        {
        case 1:
            if (sze == 0)
                cout << "string is accepted under 'a*'" << '\n';
            else if (sze == 1)
            {
                if (s[0] == 'a')
                    cout << "String is accepted under 'a*'" << '\n';
                else
                    cout << "String is not accepted under 'a*'" << '\n';
            }
            else
            {
                int i = 0;
                for (i = i; i < s.size(); i++)
                {
                    if (s[i] == 'b')
                    {
                        cout << "String is not accepted under 'a*'" << '\n';
                        break;
                    }
                }
                if (s[i] == 'b')
                    break;
                cout << "String is accepted under 'a*'" << '\n';
            }
            break;
        case 2:
            if (sze == 0)
                cout << "String is not accepted under 'a*b+'" << '\n';
            else if (sze == 1)
            {
                if (s[0] == 'b')
                    cout << "String is accepted under 'a*b+" << '\n';
                else
                    cout << "String is not accepted under 'a*b+'" << '\n';
            }
            else
            {
                int countA = 0, countB = 0, i = 0;
                for (i = 0; s[i] != 'b'; i++)
                {
                    continue;
                }
                for (i = i; i < sze; i++)
                {
                    if (s[i] == 'a'){
                        cout << "String is not accepted under 'a*b+'" << '\n';
                        break;
                    }
                }
                if (s[i] != 'a' || i == sze)
                    cout << "String is accepted under'a*b+'" << '\n';
            }
            break;
        case 3:
            if (sze == 0)
                cout << "String is accepted under 'abb'" << '\n';
            else if (sze == 3)
            {
                if (s[0] == 'a' && s[1] == 'b' && s[2] == 'b')
                    cout << "String is accepted under 'abb'" << '\n';
                else
                    cout << "String is not accepted under 'abb'" << '\n';
            }
            else
                cout << "String is not accepted under 'abb'" << '\n';
            break;

        default:
            cout << "Invalid option selected\n";
            exit(1);
            break;
        }
    }
}