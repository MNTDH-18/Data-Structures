#include <stdio.h>
#include <windows.h>
#include <conio.h>

void Sorted();
void Unsorted();

int LinSearch(int a[], int n, int z);
int SorBinSearch(int a[], int n, int z);
int UnsorBinSearch(int a[], int n, int z);

void main()
{
    system("cls");

    // int countBin, countLin;

    int opn;

    printf("Which type of data you want to check?\n");
    printf(" \n 1. Sorted \n 2. Unsorted ");
    printf(" \n\nChoose one from above options: ");
    scanf("%d", &opn);

    switch (opn)
    {

    case 1:
        Sorted();
        break;
    case 2:
        Unsorted();
        break;
    default:
        printf(" \n \n \t \t \t \t \t \t \t     Invalid choice! \n\n\t \t \t \t \t \t \tPress any key to continue");
        getch();
        main();
        break;
    }
}

void Sorted()
{
    system("cls");

    int i, n, z;

    printf("Enter the size of array: (1 to 100)\n");

    scanf("%d", &n);

    int a[n];

    printf("Enter the elements (sorted) of array:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); // taking arrays as user input 1 by 1
    }

    printf("\nEnter the integer you want to search\n");

    scanf("%d", &z);

    int countBin1, countLin1;

    countLin1 = LinSearch(a, n, z);
    countBin1 = SorBinSearch(a, n, z);

    printf("\nSteps needed:\n\n");
    printf("Linear Search - %d \nBinary Search - %d\n", countLin1, countBin1);
}

void Unsorted()
{
    system("cls");

    int i, n, z;

    printf("Enter the size of array: (1 to 100)\n");

    scanf("%d", &n);

    int a[n];

    printf("Enter the elements (unsorted) of array:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); // taking arrays as user input 1 by 1
    }

    printf("\nEnter the integer you want to search\n");

    scanf("%d", &z);

    int countBin2, countLin2;

    countLin2 = LinSearch(a, n, z);
    countBin2 = UnsorBinSearch(a, n, z);

    printf("\nSteps needed:\n\n");
    printf("Linear Search - %d \nBinary Search - %d\n", countLin2, countBin2);
}

int LinSearch(int a[], int n, int z)
{
    int i = 0;

    while (i < n && a[i] != z)
    {
        i++; // increasing the value of i by 1
    }

    if (i < n)
    {
        printf("\nFound in linear search.\n");
        if (i <= n - 1)
        {
            return i + 1;
        }
        else
        {
            return i;
        }
    }
    else
    {
        printf("\nNot Found in linear search.\n");

        return i;
    }
}

int SorBinSearch(int a[], int n, int z)
{
    int lowS, highS, midS, iS = 0, jS = 0;

    lowS = 0;
    highS = n - 1;

    while (lowS <= highS)
    {
        iS++;
        midS = (lowS + highS) / 2;

        if (a[midS] == z)
        {
            jS = 1;
            break;
        }
        else if (a[midS] < z)
        {
            lowS = midS + 1;
        }
        else
        {
            highS = midS - 1;
        }
    }

    if (jS == 1)
    {
        printf("\nFound in binary search.\n");
    }
    else
    {
        printf("\nNot found in binary search.\n");
    }

    return iS;
}

int UnsorBinSearch(int a[], int n, int z)
{
    int low, high, mid, i = 0, j = 0, k, l, temp;

    for (k = 0; k < n; k++)
    {
        for (l = 0; l < n - 1; l++)
        {
            if (a[l] > a[l + 1])
            {
                temp = a[l];
                a[l] = a[l + 1];
                a[l + 1] = temp;
            }
        }
    }

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        i++;
        mid = (low + high) / 2;

        if (a[mid] == z)
        {
            j = 1;
            break;
        }
        else if (a[mid] < z)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (j == 1)
    {
        printf("\nFound in binary search.\n");
    }
    else
    {
        printf("\nNot found in binary search.\n");
    }

    i += (k * l);

    return i;
}