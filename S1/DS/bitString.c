#include <stdio.h>

int n, n1, n2;
void clearset(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

int ispresent(int arr[], int size, int ele)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == ele)
        {
            flag = 1;
            return 1;
        }
    }
    if (flag == 0)
        return 0;
}

void display(int set[], int size)
{
    printf("set:{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", set[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("}\n");
}

void makeSet(int uniset[], int set[], int n, int bitstr[])
{
    clearset(bitstr, n);

    for (int i = 0; i < n; i++)
    {
        if (ispresent(set, n, uniset[i]) == 1)
        {
            bitstr[i] = 1;
        }
        else
        {
            bitstr[i] = 0;
        }
    }
}

void Union(int set1[], int set2[], int n)
{
    int uni[n];
    for (int i = 0; i < n; i++)
    {
        if (set1[i] == 0 && set2[i] == 0)
        {
            uni[i] = 0;
        }
        else
        {
            uni[i] = 1;
        }
    }
    display(uni, n);
}

void Intersec(int set1[], int set2[], int n, int inter[n])
{
    for (int i = 0; i < n; i++)
    {
        if (set1[i] == 1 && set2[i] == 1)
        {
            inter[i] = 1;
        }
        else
        {
            inter[i] = 0;
        }
    }
}

void Diff(int set1[], int n, int inter[])
{
    int diff[n];
    for (int i = 0; i < n; i++)
    {
        if (set1[i] == inter[i])
        {
            diff[i] = 0;
        }
        else
        {
            diff[i] = 1;
        }
    }
    display(diff, n);
}

void createset(int universal[], int set[], int element, int n1)
{
    clearset(set, n1);
    if (n1 > n || n1 < 0)
        printf("size of set1 in greater than universal set! or invalid size \n");
    else
    {
        for (int i = 0; i < n1; i++)
        {
            printf("Enter your %dth element : ", i + 1);
            scanf("%d", &element);

            if (ispresent(set, n1, element) == 0 && ispresent(universal, n, element) == 1)
                set[i] = element;
            else
            {
                printf("Sorry, Cant allow Duplicated values!\n");
                i--;
            }
        }
    }
}

int main()
{
    int element;
    printf("Enter No of elements in Universal Set : ");
    scanf("%d", &n);
    int universal[n], bitstr1[n], bitstr2[n];
    clearset(universal, n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter your %dth element : ", i + 1);
        scanf("%d", &element);

        if (ispresent(universal, n, element) == 0)
            universal[i] = element;
        else
        {
            printf("Sorry, Cant allow Duplicated values!\n");
            i--;
        }
    }

    printf("Enter No of elements in your Set 1 : ");
    scanf("%d", &n1);
    int Set1[n];
    clearset(Set1, n);
    createset(universal, Set1, element, n1);

    printf("Enter No of elements in your Set 2 : ");
    scanf("%d", &n2);
    int Set2[n];
    clearset(Set2, n);
    createset(universal, Set2, element, n2);

    printf("Universal ");
    display(universal, n);
    printf("\n1st ");
    display(Set1, n1);
    printf("2nd ");
    display(Set2, n2);

    printf("\nBistring of 1st ");
    makeSet(universal, Set1, n, bitstr1);
    display(bitstr1, n);

    printf("Bitstring of 2nd ");
    makeSet(universal, Set2, n, bitstr2);
    display(bitstr2, n);

    int inter[n];
    printf("\nUNION ");
    Union(bitstr1, bitstr2, n);
    Intersec(bitstr1, bitstr2, n, inter);
    printf("INTERSECTION ");
    display(inter, n);
    printf("\nSet1 on Set2 DIFFERENCE ");
    Diff(bitstr1, n, inter);
    printf("Set2 on Set1 DIFFERENCE ");
    Diff(bitstr2, n, inter);
}