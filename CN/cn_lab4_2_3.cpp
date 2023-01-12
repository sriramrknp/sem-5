// CS20B1107, SRIRAM REDDY CHEERLA
// byte stuffing 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int temp, len, inp, temp1;
    string arr, flag, esc;
    cout << "Enter the data: ";
    cin >> arr;
    cout << "Enter the flag: ";
    cin >> flag;
    cout << "Enter the esc: ";
    cin >> esc;

    // size_t found1 = arr.find(esc);
    // cout << found1 << endl;
    // if (found1 != string::npos)
    //     arr.insert(found1, esc);
    // char arr2[esc.size()];

    // for (int j = 0; j < esc.size(); j++)
    // {
    //     arr2[j] = esc[j];
    // }
    // while (found1 != string::npos)
    // {
    //     found1 = arr.find(arr2, found1 + esc.size() + esc.size());

    //     if (found1 != string::npos)
    //     {
    //         arr.insert(found1, esc);
    //     }
    // }

    size_t found = arr.find(flag);
    if (found != string::npos)
        arr.insert(found, esc);
    char arr1[flag.size()];

    for (int j = 0; j < flag.size(); j++)
    {
        arr1[j] = flag[j];
    }
    while (found != string::npos)
    {
        found = arr.find(arr1, found + esc.size() + flag.size());

        if (found != string::npos)
        {
            arr.insert(found, esc);
        }
    }

    cout << '\n';
    cout << "After inserting the ESC into the data\n";
    cout << arr;
}