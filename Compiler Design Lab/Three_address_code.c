#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pm();
void plus();
void div_op(); // renamed div to div_op to avoid conflict with standard div function

int i, ch, j, l, addr = 100;
char ex[10], expr[10], expr1[10], expr2[10], id1[5], op[5], id2[5];

// Function to reverse a string
void reverse_str(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main()
{
    while (1)
    {
        printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the expression with assignment operator:");
            scanf("%s", expr);
            l = strlen(expr);
            expr2[0] = '\0';
            i = 0;
            while (expr[i] != '=')
            {
                i++;
            }
            strncat(expr2, expr, i);
            reverse_str(expr);
            expr1[0] = '\0';
            strncat(expr1, expr, l - (i + 1));
            reverse_str(expr1);
            printf("Three address code:\ntemp=%s\n%s=temp\n", expr1, expr2);
            break;

        case 2:
            printf("\nEnter the expression with arithmetic operator:");
            scanf("%s", ex);
            strcpy(expr, ex);
            l = strlen(expr);
            expr1[0] = '\0';

            for (i = 0; i < l; i++)
            {
                if (expr[i] == '+' || expr[i] == '-')
                {
                    if (expr[i + 2] == '/' || expr[i + 2] == '*')
                    {
                        pm();
                        break;
                    }
                    else
                    {
                        plus();
                        break;
                    }
                }
                else if (expr[i] == '/' || expr[i] == '*')
                {
                    div_op();
                    break;
                }
            }
            break;

        case 3:
            printf("Enter the expression with relational operator: ");
            scanf("%s %s %s", id1, op, id2);
            if (!((strcmp(op, "<") == 0) || (strcmp(op, ">") == 0) || (strcmp(op, "<=") == 0) || (strcmp(op, ">=") == 0) || (strcmp(op, "==") == 0) || (strcmp(op, "!=") == 0)))
                printf("Expression is error");
            else
            {
                printf("\n%d\tif %s%s%s goto %d", addr, id1, op, id2, addr + 3);
                addr++;
                printf("\n%d\t T:=0", addr);
                addr++;
                printf("\n%d\t goto %d", addr, addr + 2);
                addr++;
                printf("\n%d\t T:=1", addr);
            }
            break;
        case 4:
            exit(0);
        }
    }
}

void pm()
{
    reverse_str(expr);
    j = l - i - 1;
    strncat(expr1, expr, j);
    reverse_str(expr1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", expr1, expr[j + 1], expr[j]);
}

void div_op()
{
    strncat(expr1, expr, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", expr1, expr[i + 2], expr[i + 3]);
}

void plus()
{
    strncat(expr1, expr, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", expr1, expr[i + 2], expr[i + 3]);
}

// ---------------------------*******************************************------------------------------

/*

use input as :

for assignment use : a=b or b = 5  anything you wish
for arithmatic operator use   : a+b*c or a/b*c anything you wish 
for relation use : a<=b or a> g or anything you  wish


*/