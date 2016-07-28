#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 1000

int getline_c(char **array, int maxlines, char *buf, int lim);

int main(int argc, char *argv[])
{
        char *array[MAXLINES], nlines = 10, buffer[MAXLINES];

        if (argc > 1) {
                if ((*++argv)[0] == '-') {
                        char buf[100];
                        char *buf_ptr = buf;

                        while ((*buf_ptr++ = *++(*argv)))
                                ;

                        argc = (nlines = atof(buf)) ? argc : 0;
                } else
                        argc = 0;
        }

        if (argc != 0) {
                int lines = getline_c(array, MAXLINES, buffer, MAXLINES);

                printf("Output:\n");

                char **array_ptr = (lines >= nlines) ? array + lines - nlines : array;

                while (array_ptr < array + lines)
                        printf("%s", *array_ptr++);
        } else
                printf("Usage: Error parsing flags\n");

        return 0;
}

int getline_c(char **array, int maxlines, char *buf, int lim)
{
        char *buf_ptr = buf;
        int c, max = maxlines;

        while (maxlines > 0 && --lim > 0 && (c=getchar()) != EOF) {
                *buf_ptr++ = c;
                if (c == '\n') {
                        *buf_ptr++ = '\0';
                        *array++ = buf;
                        buf += buf_ptr - buf;
                        maxlines--;
                }
        }
        return max - maxlines;
}
