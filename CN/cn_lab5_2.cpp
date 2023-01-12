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
void resend_sr(void);
void selective(void);

int main()
{
    int c;
    cout << "Enter the choice\n";
    cout << "    1. Selective Repeat\n";
    cout << "    2. Exit\n";
    cin >> c;

    if(c == 1)
        selective();
    else
        exit(1);
}

void selective()
{
    sender();
    recv_ack();
    resend_sr();
    cout << "\nAll frame sent successfully\n";
    exit(1);
}
int sender()
{
    int i;
    cout << "\nEnter window size: ";
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
    rand();
    r = rand() % (n+1);

    frame[r].ack = 'n';
    for (i = 1; i <= n; i++)
    {
        if (frame[i].ack == 'n')
            cout << "\nThe frame number " << i << " is not received\n";
    }
}
void resend_sr()
{
    cout << "\nResending the frame " << r << "\n";

    frame[r].ack = 'y';
    cout << "\nReceived data of frame " << r << " is " << frame[r].data << "\n";
}
