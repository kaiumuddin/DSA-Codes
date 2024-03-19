#include<stdio.h>
#include<stdlib.h>

int* resize_list(int* list, int n, int k)
{
    int* tmp = malloc(k * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < k; i++)
    {
        if (i < n)
            tmp[i] = list[i];
        else
            tmp[i] = 0;
    }

    free(list);
    list = tmp;

    return list;
}

int main(void)
{
    int n = 3;
    int k = 5;

    int* list = malloc(n * sizeof(int));
    if (list == NULL)
        return 1;

    list[0] = 10;
    list[1] = 20;
    list[2] = 30;
    list = resize_list(list, n, k);

    for (int i = 0; i < k; i++)
    {
        printf("%d\n", list[i]);
    }

}