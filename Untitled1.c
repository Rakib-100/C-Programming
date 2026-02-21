#include <stdio.h>

 typedef struct p

    {

        int x;

        char y;

        q ptr;

    }*q;

    int main()

    {

        struct p p = {1, 2, &p};

        printf("%d\n", p.ptr->x);

        return 0;

    }
