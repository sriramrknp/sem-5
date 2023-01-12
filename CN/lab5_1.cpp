#include <bits/stdc++.h>
using namespace std;

int n, r;

struct frame_str
{
    char ack; 
    int data;
} frame[10];

int sender(void);
void recv_ack(void);
void resend_gb(void);
void go_back(void);

int main()
{
    int c;
    cout << "Enter the choice\n";
    cout << "    1. GoBack N ARQ\n";
    cout << "    2. Exit\n";
    cin >> c;

    while (c < 3)
    {
        switch (c)
        {
            case 1:
                go_back();
                break;
            case 2:
                exit(0);
                break;
        }
    }
}

void go_back()
{
    sender();
    recv_ack();
    resend_gb();
    cout << "\nAll frames sent successfully\n";
    exit(1);
}

int sender()
{
    int i;
    int sze;

    cout << "\nEnter the window size:";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        frame[i].data = rand() % 100;
        frame[i].ack = 'y';
    }
    return 0;
}

void recv_ack()
{
    int i;             
    r = rand() % (n);

    frame[r].ack = 'n'; 
    for (i = 1; i <= n; i++)
    {
        if (frame[i].ack == 'n')
            cout << "\nThe frame number "<< i << " is not received\n";
    }
}

void resend_gb()
{
    int i;
    cout << "\nResending from frame "<< r <<" \n";

    for (i = r; i <= n; i++) 
    {
        frame[i].ack = 'y';
        cout << "\nReceived data of frame "<< i <<" is "<<frame[i].data<<"\n";
    }
}
