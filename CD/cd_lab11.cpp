// CS20B1107, SRIRAM REDDDY CHEERLA
// SHIFT REDUCE PARSING

#include <bits/stdc++.h>

using namespace std;

stack<string> stack_buf;
stack<string> inp_buf;

void print_stack(stack<string> p_stack_buf)
{
    stack<string> stack_buf_temp = p_stack_buf;
    while (!stack_buf_temp.empty())
    {
        cout << stack_buf_temp.top() << " ";
        stack_buf_temp.pop();
    }
    cout << '\n';
}

void fill(stack<string> &temp_stack_buf)
{
    temp_stack_buf = stack_buf;
}

int check(vector<string> &pro_rt, vector<string> &pro)
{
    int ret = -1;
    string temp = "";
    while (stack_buf.top() != "$")
    {
        temp += stack_buf.top();
        stack_buf.pop();
        for (int i = 0; i < pro_rt.size(); i++)
        {
            if (temp == pro_rt[i])
            {
                return i;
            }
        }
    }
    return ret;
}

int main()
{
    int num_of_prod;
    vector<string> inp_str;
    cout << "Number of Productions ";
    cin >> num_of_prod;

    vector<string> productions;
    cout << "Enter Productions ";
    cout << "\nNote: S-S+S of this type\n";
    for (int i = 0; i < num_of_prod; i++)
    {
        string temp;
        cin >> temp;
        productions.push_back(temp);
    }

    vector<string> productions_rt;
    for (int i = 0; i < num_of_prod; i++)
    {
        string temp = "";
        for (int j = 2; j < productions[i].size(); j++)
        {
            temp += productions[i][j];
        }
        productions_rt.push_back(temp);
    }

    // Initializing the stack and input buffer
    stack_buf.push("$");
    inp_buf.push("$");

    cout << "Enter the input string(with spaces)\n";
    cout << "Note: Eg: id + id * id\n";
    string temp_inp;
    string temp1 = "";
    getline(cin >> ws, temp_inp);

    for (int i = 0; i < temp_inp.size(); i++)
    {
        if (temp_inp[i] == ' ')
        {
            inp_str.push_back(temp1);
            temp1 = "";
        }
        else
        {
            temp1 += temp_inp[i];
        }
    }
    inp_str.push_back(temp1);
    temp1 = "";

    // pushing input to the input buffer
    for (int i = inp_str.size() - 1; i >= 0; i--)
    {
        inp_buf.push(inp_str[i]);
    }
    
    cout << "\nBefore Parsing: \n";
    cout << "Input Buffer\n";
    print_stack(inp_buf);
    cout << "Stack Buffer\n";
    print_stack(stack_buf);

    cout << "Stack Buffer during parsing\n";
    int ind = -1;

    // performing parsing
    while (inp_buf.top() != "$")
    {
        string shift;

        stack<string> temp_stack_buff;
        fill(temp_stack_buff);
        ind = check(productions_rt, productions);
        if (ind != -1)
        {
            string temp = "";
            temp = productions[ind][0];
            stack_buf.push(temp);
            print_stack(stack_buf);
        }
        else
        {
            stack_buf = temp_stack_buff;
            print_stack(stack_buf);
        }

        shift = inp_buf.top();
        inp_buf.pop();
        stack_buf.push(shift);

        stack<string> temp_stack_buf;
        fill(temp_stack_buf);
        ind = check(productions_rt, productions);
        if (ind != -1)
        {
            string temp = "";
            temp = productions[ind][0];
            stack_buf.push(temp);
            print_stack(stack_buf);
        }
        else
        {
            stack_buf = temp_stack_buf;
            print_stack(stack_buf);
        }
    }
    stack<string> temp_stack_buff;
    fill(temp_stack_buff);
    ind = check(productions_rt, productions);
    if (ind != -1)
    {
        string temp = "";
        temp = productions[ind][0];
        stack_buf.push(temp);
        print_stack(stack_buf);
    }
    else
    {
        stack_buf = temp_stack_buff;
        print_stack(stack_buf);
    }
    cout << "\n";

    cout << "\nAfter Parsing: \n";
    cout << "Input Buffer\n";
    print_stack(inp_buf);
    cout << "Stack Buffer\n";
    print_stack(stack_buf);

    if(stack_buf.size() == 2)
    {
        string temp = "";
        temp = stack_buf.top();
        for (int i = 0; i < productions.size();i++)
        {
            string temp_st="";
            temp_st += productions[i][0];
            if (temp_st == temp)
            {
                cout << "\nString is accepted\n";
                return 0;
            }
        }
    }
    cout << "\nString is rejected\n";
    return 0;
}