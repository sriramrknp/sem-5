// CS20B1107, SRIRAM REDDY CHEERLA

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int frame, send = 0, ackowldge, i;

    cout<<"Enter num of frames to be transmitted: ";
    cin>>frame;

    while (1)
    {
        for (int i = 0; i < frame; i++)
        {
            cout<<"Frame %d has transmitted\n", send;
            send++;
            if (send == frame)
            {
                break;
            }
        }
        cout<<"\nEnter the ackowldg received: ";
        cin>>ackowldge;

        if (ackowldge >= frame){
            break;
        }
        else{
            send = ackowldge;
        }
    }
    cout<<"Total frames Transmitted\n";
}