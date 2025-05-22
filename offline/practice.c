#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str, char *out)
{
    int i,j,k;
    int size1 = strlen(str);
    int outsize=0;
    for(i = size1-1; i >= 0; i--)
    {
        if(str[i] == ' ') continue;

        j=i;
        while(str[j-1] != ' ' && j > 0)
        {
            j--;
        }

        for(k = j; str[k] != ' ' && str[k] != '\0'; k++)
        {
            out[outsize] = str[k];
            outsize++;
        }

        out[outsize] = ' ';
        outsize++;

        if(j > 0) i= (--j);
        else if(j == 0) break;
    }
    out[outsize] = '\0';   
}


int main()
{
    char str[200],out[200];
    gets(str);
    reverse(str,out);
    puts(out);
}