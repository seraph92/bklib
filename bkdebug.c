#include <stdio.h>

int
fprint_hex(FILE *stdiostream,unsigned char in[], int len)
{
    int     i = 0;

    for ( i = 0; i < len; i++ )
    {
        fprintf(stdiostream, "0x%02x ", in[i]);
    }
    fprintf(stdiostream,"\n");

    return 0;
}
