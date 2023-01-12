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
void resend_gb(void);
void goback(void);



int main()
{
        int c;
        do
        {
                printf("\n\n1.GoBackN ARQ\n2.Exit");
                printf("\nEnter your Choice:");
                scanf("%d", &c); /* code */
                switch (c)
                {
                case 1:
                        goback();
                        break;
                case 2:
                        exit(0);
                        break;
                }
        } while (c >= 3);
}
void goback()
{
        sender();
        recvack();
        resend_gb();
        printf("\n all frames sent successfully\n");
}

int sender()
{
        int i;
        printf("\nEnter the no.of frames to be sent:"); // USER INPUT
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
                printf("\nEnter data for frames[%d]", i); // TAKING DATA OF THE FRAMES
                scanf("%d", &frm[i].data);                // STORING THE DATA OF THE FRAMES
                frm[i].ack = 'y';               // BY DEFAULT WE ARE ASSIGNING THE ALL FRAMES TO BE ACK AS YES.
        }
        return 0;
    
}
void recvack()
{
        int i;
        rand();         // RANDOM FUNCTION GENERATOR
        r = rand() % n; // IT TAKES ONE OF THE RANDOM VALUE IN THE GIVEN DATA.

        frm[r].ack = 'n'; // IT SETS THAT RANDOM VALUE ACK IS NOT RECIEVED AS NO
        for (i = 1; i <= n; i++)
        {
                if (frm[i].ack == 'n')
                        printf("\nThe frame number %d is not receieved\n", r); // PRINTING THAT VALUE
        }
}
void resend_gb()
{
        int i;
        printf("\n Resending from frame %d", r);
        for (i = r; i <= n; i++) // RESENDING THE FRAMES FROM THAT PACKET TO ALL MAKING ACK RECIEVED
        {

                frm[i].ack = 'y';
                printf("\nReceived data of frame %d is %d", i, frm[i].data);
        }
}
