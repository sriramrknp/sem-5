// CS20B1107, SRIRAM REDDY CHEERLA
// bit stuffing 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int temp, count = 0;
    string arr;
    vector<int> pos;
    cout << "Enter the data: ";
    cin >> arr;
    cout << arr.size() << '\n';
    for (int i = 0; i < (arr.size()); i++)
    {
        if(arr[i] == '1')
            count++;
        else
            count = 0;
        if (count == 5){
            count = 0;
            pos.push_back(i);
            if(i != (arr.size()-1))
                arr.insert(arr.begin() + i + 1, '0');
            else
                arr[i + 1] += '0';
            i--;
        }
    }
    cout << "Inserted at positions\n";
    for (auto i : pos)
    {
        cout << i << " ";
    }
    cout << '\n';

    cout << "Data after insertion\n";
    for (auto i : arr)
    {
        cout << i;
    }
    cout << '\n';
    cout << arr.size()<<'\n';
}
