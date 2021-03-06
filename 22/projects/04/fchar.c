#include <stdio.h>
#include <stdlib.h> /* exit */

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned long long int count = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: fchar filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error: %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getc(fp) != EOF)
        count++;
    fclose(fp);

    printf("Characters in %s: %llu\n", argv[1], count);
    exit(EXIT_SUCCESS);
}
