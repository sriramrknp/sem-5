// CS20B1107, SRIRAM REDDY CHEERLA
// char count 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int temp, len, inp, temp1;
    vector<int> arr, arrAns;
    vector<int> pos;
    cout << "Enter the data length: ";
    cin >> inp;
    cout << "Enter the data: " << '\n';
    for (int i = 0; i < inp; i++)
    {
        cin >> temp1;
        arr.push_back(temp1);
    }

    cout << "Enter number of frames: ";
    cin >> len;
    cout << "Each frame length: ";

    int fLen = inp / len, k = 0;
    for (int i = 0; i < len; i++)
    {
        if(i != len-1){
            cout << (fLen)<<" ";
            arrAns.push_back(fLen+1);
            for (int j = 0; j < fLen;j++)
            {
                arrAns.push_back(arr[k]);
                k++;
            }
        }

        else{
            cout << (inp - ((fLen)*(len-1)))<<" ";
            arrAns.push_back((inp - ((fLen) * (len - 1)))+1);
            for (int j = 0; j < (inp - ((fLen) * (len - 1))); j++)
            {
                arrAns.push_back(arr[k]);
                k++;
            }
        }
    }
    cout << '\n';

    cout << "Data after insertion\n";
    for (auto i : arrAns)
    {
        cout << i<<" ";
    }
    cout << '\n';
}