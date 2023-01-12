class Solution
{
public:
    int myAtoi(string s)
    {
        string ans = "";
        bool sign = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (s[i] == '+' || s[i] == '-')
                {
                    if (s[i] == '-')
                        sign = true;
                    i++;
                }

                for (int j = i; j < s.size(); j++)
                {
                    if (s[j] == '+' || s[j] == '-')
                    {
                        ans += '0';
                        break;
                    }
                    else
                    {
                        for (int k = j; k < s.size(); k++)
                        {
                            if (s[i] < '0' && s[i] > '9')
                            {
                                break;
                            }
                            else
                            {
                                ans += s[k];
                            }
                        }
                        break;
                    }
                    break;
                }
                break;
            }
        }

        string temp = "";
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] != '0')
            {
                for (int j = i; j < ans.size(); j++)
                {
                    if (ans[j] >= '0' && ans[j] <= '9')
                        temp += ans[j];
                    else
                        break;
                }
                break;
            }
        }

        int ans_int = 0;
        cout << temp << '\n';
        if (temp < "-2147483648" && temp.size() >= 10)
            ans_int = -2147483648;
        else if (temp > "2147483647" && temp.size() >= 10)
            ans_int = 2147483647;

        if (temp != "" && ans_int != 0)
            ans_int = stoi(temp);

        if (sign)
            ans_int = (-1) * ans_int;

        return ans_int;
    }
};