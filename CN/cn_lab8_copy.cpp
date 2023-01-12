// CS20B1107 SRIRAM REDDY CHEERLA
// LAB  - 7

#include <bits/stdc++.h> 
using namespace std;

int binaryToDeci(string bina)
{
    int ex = 0, dec = 0;
    for (int i = bina.size() - 1; i >= 0; i--)
    {
        if (bina[i] == '1')
            dec += (1) * (int)pow(2, ex);
        ex++;
    }
    return dec;
}

int main()
{
    string ip;
    cout << "Enter the IP Address: ";
    cin >> ip;

    vector<int> bit, bit_d;
    int j = 0;
    string str = "";

    // Extracting the
    str = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            bit.push_back(stoi(str));
            bit_d.push_back(stoi(str));
            str = "";
            j++;
        }
        else
        {
            str += ip[i];
        }
    }
    bit.push_back(stoi(str));
    bit_d.push_back(stoi(str));

    // Class A
    if (bit[0] >= 0 && bit[0] <= 127)
    {
        cout << "Class A\n";
        int div;
        cout << "Enter the number of subnets you want to divide: ";
        cin >> div;
        if (ceil(log2(div)) != floor(log2(div)))
        {
            cout << "Invalid\n";
            exit(1);
        }
        int digits = log2(div) + 1;
        int ip_digits = 24 - digits;
        int ips_per_id = ((int)pow(2, ip_digits));
        int total_ips = div * ips_per_id;
        int hosts_total = div * (ips_per_id - 2);

        cout << "Total number of IP Address: " << total_ips << endl;
        cout << "Total number of Hosts: " << hosts_total << endl;

        vector<vector<string> > subnet, subnetLast;
    
        vector<vector<int> > subnet_i, subnetLast_i;
        int temp_div = div - 1;
        string temp_div_s = "";

        int temp_vai = temp_div;

        while (temp_div >= 0)
        {
            string last_ip = "000000000000000000000000";
            int k = digits;
            while (temp_div != 0)
            {
                temp_div_s += to_string(temp_div % 2);
                temp_div /= 2;
            }
            if (temp_div_s.size() < digits)
            {
                for (int i = temp_div_s.size(); i < digits - 1; i++)
                    temp_div_s += '0';
            }
            reverse(temp_div_s.begin(), temp_div_s.end());
            for (int i = 0; i < digits - 1; i++)
            {
                last_ip[i] = temp_div_s[i];
            }

            vector<string> temp_ind, temp_indl;
            for (int i = 0; i < 24; i += 8)
            {
                string temp_indi = "";
                for (int j = i; j < (i + 8); j++)
                {
                    temp_indi += last_ip[j];
                }
                temp_ind.push_back(temp_indi);
            }
            subnet.push_back(temp_ind);

            for (int i = digits - 1; i < 24; i++)
            {
                last_ip[i] = '1';
            }
            for (int i = 0; i < 24; i += 8)
            {
                string temp_indi = "";
                for (int j = i; j < (i + 8); j++)
                {
                    temp_indi += last_ip[j];
                }
                temp_indl.push_back(temp_indi);
            }
            subnetLast.push_back(temp_indl);

            temp_div_s = "";
            temp_div = --temp_vai;
        }


        cout << "First and Last of each IP\n";
        for (int i = 0; i < subnet.size(); i++)
        {
            vector<int> temp_ind_i, temp_indl_i;
            for (int j = 0; j < subnet[i].size(); j++)
            {
                temp_ind_i.push_back(binaryToDeci(subnet[i][j]));
            }
            subnet_i.push_back(temp_ind_i);
            for (int j = 0; j < subnetLast[i].size(); j++)
            {
                temp_indl_i.push_back(binaryToDeci(subnetLast[i][j]));
            }
            subnetLast_i.push_back(temp_indl_i);
        }

        for (int i = 0; i < subnet.size(); i++)
        {
            for (int j = 0; j < subnet[i].size(); j++)
            {
                cout << subnet[i][j] << " ";
            }
            cout << '\n';
            for (int j = 0; j < subnetLast[i].size(); j++)
            {
                cout << subnetLast[i][j] << " ";
            }
            cout << "\n\n";
        }

        cout << "Final :\n";
        for (int i = 0; i < subnet_i.size(); i++)
        {
            cout << bit[0] << ".";
            for (int j = 0; j < subnet_i[i].size(); j++)
            {
                cout << subnet_i[i][j];
                if(j <= 1)
                    cout << ".";
            }
            cout << '\n';
            cout << bit[0] << ".";
            for (int j = 0; j < subnetLast_i[i].size(); j++)
            {
                cout << subnetLast_i[i][j];
                if (j <= 1)
                    cout << ".";
            }
            cout << "\n\n";
        }
    }

    // Class B
    else if (bit[0] >= 128 && bit[0] <= 191)
    {
        cout << "Class B\n";
        int div;
        cout << "Enter the number of subnets you want to divide: ";
        cin >> div;
        if (ceil(log2(div)) != floor(log2(div)))
        {
            cout << "Invalid\n";
            exit(1);
        }
        int digits = log2(div) + 1;
        int ip_digits = 24 - digits;
        int ips_per_id = ((int)pow(2, ip_digits));
        int total_ips = div * ips_per_id;
        int hosts_total = div * (ips_per_id - 2);

        cout << "Total number of IP Address: " << total_ips << endl;
        cout << "Total number of Hosts: " << hosts_total << endl;

        vector<vector<string> > subnet, subnetLast;
        vector<vector<int> > subnet_i, subnetLast_i;
        int temp_div = div - 1;
        string temp_div_s = "";

        int temp_vai = temp_div;

        while (temp_div >= 0)
        {
            string last_ip = "0000000000000000";
            int k = digits;
            while (temp_div != 0)
            {
                temp_div_s += to_string(temp_div % 2);
                temp_div /= 2;
            }
            if (temp_div_s.size() < digits)
            {
                for (int i = temp_div_s.size(); i < digits - 1; i++)
                    temp_div_s += '0';
            }
            reverse(temp_div_s.begin(), temp_div_s.end());
            for (int i = 0; i < digits - 1; i++)
            {
                last_ip[i] = temp_div_s[i];
            }

            vector<string> temp_ind, temp_indl;
            for (int i = 0; i < 16; i += 8)
            {
                string temp_indi = "";
                for (int j = i; j < (i + 8); j++)
                {
                    temp_indi += last_ip[j];
                }
                temp_ind.push_back(temp_indi);
            }
            subnet.push_back(temp_ind);

            for (int i = digits - 1; i < 16; i++)
            {
                last_ip[i] = '1';
            }
            for (int i = 0; i < 16; i += 8)
            {
                string temp_indi = "";
                for (int j = i; j < (i + 8); j++)
                {
                    temp_indi += last_ip[j];
                }
                temp_indl.push_back(temp_indi);
            }
            subnetLast.push_back(temp_indl);

            temp_div_s = "";
            temp_div = --temp_vai;
        }

        cout << "First and Last of each IP\n";
        for (int i = 0; i < subnet.size(); i++)
        {
            vector<int> temp_ind_i, temp_indl_i;
            for (int j = 0; j < subnet[i].size(); j++)
            {
                temp_ind_i.push_back(binaryToDeci(subnet[i][j]));
            }
            subnet_i.push_back(temp_ind_i);
            for (int j = 0; j < subnetLast[i].size(); j++)
            {
                temp_indl_i.push_back(binaryToDeci(subnetLast[i][j]));
            }
            subnetLast_i.push_back(temp_indl_i);
        }

        for (int i = 0; i < subnet.size(); i++)
        {
            for (int j = 0; j < subnet[i].size(); j++)
            {
                cout << subnet[i][j] << " ";
            }
            cout << '\n';
            for (int j = 0; j < subnetLast[i].size(); j++)
            {
                cout << subnetLast[i][j] << " ";
            }
            cout << "\n\n";
        }

        for (int i = 0; i < subnet_i.size(); i++)
        {
            cout << bit[0] << "." << bit[1] << ".";
            for (int j = 0; j < subnet_i[i].size(); j++)
            {
                cout << subnet_i[i][j];
                if (j <= 0)
                    cout << ".";
            }
            cout << '\n';
            cout << bit[0] << "." << bit[1] << ".";
            for (int j = 0; j < subnetLast_i[i].size(); j++)
            {
                cout << subnetLast_i[i][j];
                if (j <= 0)
                    cout << ".";
            }
            cout << "\n\n";
        }

        cout << "\nRouting Table: \n";
        cout << "Network ID\tSubnetmask\tInterface\n";
        for (int i = 0; i < subnet_i.size(); i++)
        {
            cout << bit[0] << "." << bit[1] << "." << bit[2] << ".";
            for (int j = 0; j < subnet_i[i].size(); j++)
            {
                cout << subnet_i[i][j] << " ";
            }
            cout << " ";
            cout << "255"<< "."<< "255"<< ".";
            for (int j = 0; j < subnetLast_i[i].size(); j++)
            {
                cout << subnetLast_i[i][j] << "\t";
            }
            cout << "Eth " << i;
            cout << "\n\n";
        }
    }

    // Class C
    else if (bit[0] >= 192 && bit[0] <= 223)
    {
        cout << "Class C\n";
        int div;
        cout << "Enter the number of subnets you want to divide: ";
        cin >> div;
        if (ceil(log2(div)) != floor(log2(div)))
        {
            cout << "Invalid\n";
            exit(1);
        }

        int digits = log2(div) + 1;
        int ip_digits = 24 - digits;
        int ips_per_id = ((int)pow(2, ip_digits));
        int total_ips = div * ips_per_id;
        int hosts_total = div * (ips_per_id - 2);

        cout << "Total number of IP Address: " << total_ips << endl;
        cout << "Total number of Hosts: " << hosts_total << endl;

        vector<vector<string> > subnet, subnetLast;
        vector<vector<int> > subnet_i, subnetLast_i;
        int temp_div = div - 1;
        string temp_div_s = "";

        int temp_vai = temp_div;

        while (temp_div >= 0)
        {
            string last_ip = "00000000";
            int k = digits;
            while (temp_div != 0)
            {
                temp_div_s += to_string(temp_div % 2);
                temp_div /= 2;
            }
            if (temp_div_s.size() < digits)
            {
                for (int i = temp_div_s.size(); i < digits - 1; i++)
                    temp_div_s += '0';
            }
            reverse(temp_div_s.begin(), temp_div_s.end());
            for (int i = 0; i < digits - 1; i++)
            {
                last_ip[i] = temp_div_s[i];
            }

            vector<string> temp_ind, temp_indl;
            for (int i = 0; i < 8; i += 8)
            {
                string temp_indi = "";
                for (int j = i; j < (i + 8); j++)
                {
                    temp_indi += last_ip[j];
                }
                temp_ind.push_back(temp_indi);
            }
            subnet.push_back(temp_ind);

            for (int i = digits - 1; i < 8; i++)
            {
                last_ip[i] = '1';
            }
            for (int i = 0; i < 8; i += 8)
            {
                string temp_indi = "";
                for (int j = i; j < (i + 8); j++)
                {
                    temp_indi += last_ip[j];
                }
                temp_indl.push_back(temp_indi);
            }
            subnetLast.push_back(temp_indl);

            temp_div_s = "";
            temp_div = --temp_vai;
        }

        cout << "First and Last of each IP\n";
        for (int i = 0; i < subnet.size(); i++)
        {
            vector<int> temp_ind_i, temp_indl_i;
            for (int j = 0; j < subnet[i].size(); j++)
            {
                temp_ind_i.push_back(binaryToDeci(subnet[i][j]));
            }
            subnet_i.push_back(temp_ind_i);
            for (int j = 0; j < subnetLast[i].size(); j++)
            {
                temp_indl_i.push_back(binaryToDeci(subnetLast[i][j]));
            }
            subnetLast_i.push_back(temp_indl_i);
        }

        for (int i = 0; i < subnet.size(); i++)
        {
            for (int j = 0; j < subnet[i].size(); j++)
            {
                cout << subnet[i][j] << " ";
            }
            cout << '\n';
            for (int j = 0; j < subnetLast[i].size(); j++)
            {
                cout << subnetLast[i][j] << " ";
            }
            cout << "\n\n";
        }

        for (int i = 0; i < subnet_i.size(); i++)
        {
            cout << bit[0] << "." << bit[1] << "." << bit[2] << ".";
            for (int j = 0; j < subnet_i[i].size(); j++)
            {
                cout << subnet_i[i][j] << " ";
            }
            cout << '\n';
            cout << bit[0] << "." << bit[1] << "." << bit[2] << ".";
            for (int j = 0; j < subnetLast_i[i].size(); j++)
            {
                cout << subnetLast_i[i][j] << " ";
            }
            cout << "\n\n";
        }

        cout << "\nRouting Table: \n";
        cout << "Network ID\tSubnetmask\tInterface\n";
        for (int i = 0; i < subnet_i.size(); i++)
        {
            cout << bit[0] << "." << bit[1] << "." << bit[2] << ".";
            for (int j = 0; j < subnet_i[i].size(); j++)
            {
                cout << subnet_i[i][j] << " ";
            }
            cout << " ";
            cout << "255" << "." << "255" << "." << "255" << ".";
            for (int j = 0; j < subnetLast_i[i].size(); j++)
            {
                cout << subnetLast_i[i][j] << "\t";
            }
            cout << "Eth "<<i;
            cout << "\n\n";
        }

    }

    cout << '\n';
}