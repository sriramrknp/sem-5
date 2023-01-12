//  CN-lab-2 sriram reddy CS20B1107
//  Finding CheckSum

#include<bits/stdc++.h>
using namespace std;

string addStr(string s, string p)
{
    int n = s.size(), car = 0;
    vector<string> ansF;
    reverse(s.begin(), s.end());
    reverse(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && p[i] == '0' && car == 0)
        {
            ansF.push_back("0");
            car = 0;
        }
        else if (s[i] == '0' && p[i] == '1' && car == 0 || p[i] == '0' && s[i] == '1' && car == 0 || s[i] == '0' && p[i] == '0' && car == 1)
        {
            ansF.push_back("1");
            car = 0;
        }
        else if (s[i] == '0' && p[i] == '1' && car == 1 || p[i] == '0' && s[i] == '1' && car == 1 || p[i] == '1' && s[i] == '1' && car == 0)
        {
            ansF.push_back("0");
            car = 1;
        }
        else
        {
            ansF.push_back("1");
            car = 1;
        }
    }
    string k = "";
    if (car == 1)
    {
        for (int i = 0; i < ansF.size(); i++)
        {
            if (ansF[i] == "1" && car == 1)
            {
                ansF[i] = "0";
                car = 1;
            }
            else if (ansF[i] == "0" && car == 1)
            {
                ansF[i] = "1";
                car = 0;
            }
        }
    }
    for (int i = ansF.size() - 1; i >= 0; i--)
    {
        k = k + ansF[i];
    }
    return (k);
}

int main()
{
    int i = 0, count = 0;
    int bitDiv;
    string s="";
    cin >> s;

    while (s.size() > pow(2, i))
        i++;
    int n = pow(2, i) - s.size();
    for (i = 0; i < n; i++)
    {
        s = '0' + s;
    }

    vector<string> str1;
    cout << "Enter num of bits to divide: ";
    cin >> bitDiv;
    string p = "";
    
    for (i = 0; i < s.size(); i++)
    {
        if (p.size() != bitDiv)
        {
            p = p + s[i];
        }
        else
        {
            str1.push_back(p);
            p = s[i];
        }
    }
    str1.push_back(p);

    cout << "The bits befor Check Sum: ";
    for (auto i : str1)
    {
        cout << i << "\n";
    }
    cout << "\n";

    string checkSum = "";
    for (i = 0; i < bitDiv; i++)
    {
        checkSum = checkSum + "0";
    }
    for (i = 0; i < str1.size(); i++)
    {
        checkSum = addStr(checkSum, str1[i]);
    }

    for (i = 0; i < checkSum.size(); i++)
    {
        if (checkSum[i] == '1')
            checkSum[i] = '0';
        else
            checkSum[i] = '1';
    }

    str1.push_back(checkSum);
    cout << "The bits after Check Sum: ";
    for (auto i : str1)
    {
        cout << i << "\n";
    }

    string recData = "";
    cout << "\nEnter Reciever side: ";
    cin >> recData;

    str1.clear();
    p = "";
    for (i = 0; i < recData.size(); i++)
    {
        if (p.size() != bitDiv)
        {
            p = p + recData[i];
        }
        else
        {
            str1.push_back(p);
            p = recData[i];
        }
    }
    str1.push_back(p);


    checkSum = "";
    for (i = 0; i < bitDiv; i++)
    {
        checkSum = checkSum + "0";
    }

    for (i = 0; i < str1.size(); i++)
    {
        checkSum = addStr(checkSum, str1[i]);
    }

    for (i = 0; i < checkSum.size(); i++)
    {
        if (checkSum[i] != '1')
        {
            cout << "Entered data is not Correct\n";
            return 0;
        }
    }
    cout << "Entered data is correct\n";

    return (0);
}