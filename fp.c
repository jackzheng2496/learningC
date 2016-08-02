#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 15

void addone(int *);
void multwo(int *);

void operation(int *array, int len, void (*op)(void *));

int main(int argc, char *argv[])
{
        int array[MAXLEN], elements = 0, *ptr = array, o_multwo = 0;
        char buf[100], *buf_ptr = NULL;

        while (*++argv != '\0') {
                if ((*argv)[0] == '-')
                        o_multwo = (*(++(*argv)) == 't') ? 1 : 0;
                else {
                        buf_ptr = buf;

                        while ((*buf_ptr++ = *((*argv)++)))
                                ;
                        *ptr++ = (int) atof(buf);
                        elements++;
                }
        }

        for (int i = 0; i < elements; i++)
                printf((i == elements-1) ? "%d\n" : "%d ", *(array+i));

        operation(array, elements, (void (*)(void *))(o_multwo ? multwo : addone));

        for (int i = 0; i < elements; i++)
                printf((i == elements-1) ? "%d\n" : "%d ", *(array+i));

        return 0;
}

void operation(int *array, int len, void (*op)(void *))
{
        for (int i = 0; i < len; i++) {
                (*op)(&(*(array+i)));
        }
}

void addone(int *i)
{
        ++*i;
}

void multwo(int *i)
{
        *i *= 2;
}
