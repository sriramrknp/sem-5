#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n, r;
struct frame
{
        char ack; // storing data and the acknoeledgment in the structure.
        int data;
} frm[10];
int sender(void);
void recvack(void);
void resend_sr(void);
void selective(void);

int main()
{
        int c;
        do
        {
                printf("\n\n1.Selective repeat\n2.Exit");
                printf("\nEnter your Choice:");
                scanf("%d", &c); /* code */
                switch (c)
                {
                case 1:
                        selective();
                        break;
                case 2:
                        exit(0);
                        break;
                }
        } while (c >= 3);
}

void selective()
{
        sender();
        recvack();
        resend_sr();
        printf("\nAll frames sent successfully\n");
}
int sender()
{
        int i;
        printf("\nEnter the no.of frames to be sent:");
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
                printf("\nEnter data for frames[%d]", i); // TAKING DATA OF THE FRAMES
                scanf("%d", &frm[i].data);
                frm[i].ack = 'y';
        }
        return 0;
}
void recvack()
{
        int i;
        rand();
        r = rand() % n;

        frm[r].ack = 'n';
        for (i = 1; i <= n; i++)
        {
                if (frm[i].ack == 'n')
                        printf("\nThe frame number %d is not receieved\n", r);
        }
}
void resend_sr()
{
        printf("\nResending frame %d", r);

        frm[r].ack = 'y'; // RESENDING THE ONLY DROPPED PACKET IN THE DATA BY MAKING ACK IS RECIEVED.
        printf("\nThe recieved frame is %d", frm[r].data);
}
