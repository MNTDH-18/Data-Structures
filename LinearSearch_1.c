#include <stdio.h>
int main()
{
    int i = 0, n, z;

    printf("Enter the size of array:\n");

    scanf("%d", &n);

    int a[n];

    printf("Enter the elements of array:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); // taking arrays as user input 1 by 1
    }

    printf("\nEnter the integer you want to search\n");

    scanf("%d", &z);

    while (i < n && a[i] != z)
    {
        i++; // increasing the value of i by 1
    }

    if (i < n)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
    return 0;
}