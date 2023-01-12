// CS20B1107 SRIRAM REDDY CHEERLA
// CD Lab Ex - 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stk[100];
int k = -1;

void push(char dt)
{
    k++;
    stk[k] = dt;
}

char pop()
{
    char item;
    item = stk[k];
    k--;
    return item;
}

int isEmpty()
{
    if (k == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char inp[100], ans[100];
    printf("Enter the expression: ");
    scanf("%s", inp);
    int len = strlen(inp);
    char pref[100];
    int i = 0, a =0;

    push(')');
    char item = ' ';
    for (int j = len - 1; j >= i; j--)
    {
        if (((int)inp[j] >= 65 && (int)inp[j] <= 90) || ((int)inp[j] >= 97 && (int)inp[j] <= 122))
        {
            pref[a] = inp[j];
            a++;
        }
        else if (inp[j] == ')' || inp[j] == '+' || inp[j] == '-' || inp[j] == '*' || inp[j] == '/')
        {
            push(inp[j]);
        }
        else if (inp[j] == '(')
        {
            item = ' ';
            while (item != ')')
            {
                item = pop();
                if(item != ')'){
                    pref[a] = item;
                    a++;
                }
            }
        }
    }

    item = ' ';
    while (item != ')')
    {
        item = pop();
        if (item != ')')
        {
            pref[a] = item;
            a++;
        }
    }

    for (int i = a-1; i >= 0; i--)
    {
        printf("%c", pref[i]);
    }
    printf("\n");
}
