// CS20B1107 SRIRAM REDDY CHEERLA
// LAB  - 7
 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ip;
    cout << "Enter the IP Address: ";
    cin >> ip;

    // Stores each byte in decimal
    vector<int> bit, bit_d;
    int j = 0;
    string str = "";

    // Finding entered IP is Valid or not
    for (int i = 0; i < ip.size(); i++)
    {
        if ((int(ip[i]) >= 48 && int(ip[i]) <= 57) || (int(ip[i]) == 46))
        {
            continue;
        }
        else{
            cout << "Not valid IP" << '\n';
            exit(0);
        }
    }
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            if(str[0] == '0'){
                if(str.size() > 1)
                {
                    cout << "Not valid IP" << '\n';
                    exit(0);
                }
            }
            else if(stoi(str) < 0 || stoi(str) > 255){
                cout << "Not valid IP" << '\n';
                exit(0);
            }
            str = "";
            j++;
        }
        else
        {
            str += ip[i];
        }
    }
    if (str[0] == '0')
    {
        if (str.size() > 1)
        {
            cout << "Not valid IP" << '\n';
            exit(0);
        }
    }
    else if (stoi(str) < 0 && stoi(str) > 255)
    {
        cout << "Not valid IP" << '\n';
        exit(0);
    }

    // Extracting the 
    str = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if(ip[i] == '.'){
            bit.push_back(stoi(str));
            bit_d.push_back(stoi(str));
            str = "";
            j++;
        }
        else{
            str += ip[i];
        }
    }
    bit.push_back(stoi(str));
    bit_d.push_back(stoi(str));

    // Stores Binary of IP
    vector<string> bitS;
    str = "";
    for (int i = 0; i < 4; i++)
    {
        while(bit[i] != 0){
            str += to_string(bit[i]%2);
            bit[i] /= 2;
        }
        if(str.size() < 8){
            int n = str.size();
            for (int i = 0; i < (8 - n); i++)
            {
                str += '0';
            }
        }
        reverse(str.begin(), str.end());
        bitS.push_back(str);
        str = "";
    }
    cout << "IP address in binary" << '\n';
    for (int i = 0; i < 4; i++)
    {
        cout << bitS[i] << " ";
    }
    cout << '\n';

    int cls;
    if (bitS[0][0] == '0')
    {
        cout << "Class A" << '\n';
        cls = 1;
    }
    else if (bitS[0][0] == '1' && bitS[0][1] == '0')
    {
        cout << "Class B" << '\n';
        cls = 2;
    }
    else if (bitS[0][0] == '1' && bitS[0][1] == '1' && bitS[0][2] == '0')
    {
        cout << "Class C" << '\n';
        cls = 3;
    }
    else if (bitS[0][0] == '1' && bitS[0][1] == '1' && bitS[0][2] == '1' && bitS[0][3] == '0')
    {
        cout << "Class D" << '\n';
    }
    else if (bitS[0][0] == '1' && bitS[0][1] == '1' && bitS[0][2] == '1' && bitS[0][3] == '1')
    {
        cout << "Class E" << '\n';
    }

    if(bit[3] != 0){
        cout << "Invalid\n";
        exit(0);
    }
    // Dividing into subnets
    int subnet;
    cout << "Enter the number of subnets you want: ";
    cin >> subnet;
    double log_2_c = ceil(log2(subnet));
    double log_2_f = floor(log2(subnet));
    if(log_2_c != log_2_f)
    {
        cout << "Invalid\n";
        exit(0);
    }

    // Printing IP address
    int range = 0;
    cout << "\nIP address in binary" << '\n';
    for (int j = 0; j < subnet; j++){
        for (int i = 0; i < 4; i++)
        {
            if(i <= 2){
                cout << bitS[i] << " ";
            }
            else{
                int temp=range;
                string temp_s = "";
                while (temp != 0)
                {
                    temp_s += to_string(temp % 2);
                    temp /= 2;
                }
                for (int k = temp_s.size(); k < log_2_c; k++)
                {
                    temp_s += '0';
                }
                reverse(temp_s.begin(), temp_s.end());
                for (int k = log_2_c; k < 8; k++){
                    temp_s += '0';
                }
                cout << temp_s<<'\n';
            }
        }
        range++;
    }

    cout << "\nIP address in decimal" << '\n';
    range = 256;
    int t = (range / subnet);
    for (int j = 0; j < subnet; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i != cls)
            {
                cout << bit_d[i] << ".";
            }
            else
            {
                cout << (range - t);
                for (int k = i + 1; k < 4;k++)
                {
                    cout << "." << '0';
                }
                break;
            }
        }
        cout << '\n';
        range = range - t;
    }

    // cout << "Total number of Hosts in each sub-network: \n";
    // range = 256;
    // t = (range / subnet);
    // for (int j = 0; j < subnet; j++)
    // {
    //     cout << (t - 2) << '\n';
    // }

    cout << '\n';
}