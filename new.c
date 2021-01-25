#include <stdio.h>
typedef struct employee
{
    char name[10];
    int age;
} data;
data employee[100];
int readfile(data *a)
{
    int i = 0;
    FILE *fp;
    if ((fp = fopen("employee.txt", "r")) != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d%s", &a[i].age, &a[i].name);
            i++;
        }
    }
    return i;
}
void writefile(data *a, int n)
{
    int i = 0;
    FILE *fp;
    if ((fp = fopen("sorted_empage_merge.txt", "w")) != NULL)
    {
        for (i = 0; i < n; i++)
            fprintf(fp, "%d %s\n", a[i].age, a[i].name);
    }
}
void merge(data *a, int l, int m, int n)
{
    data c[10];
    int i, j, k;
    i = l;
    j = m + 1;
    k = 0;
    while (i <= m && j <= n)
    {
        if (a[i].age < a[j].age)
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j <= n)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = l, j = 0; i <= n; i++, j++)
        a[i] = c[j];
}
void mergesort(data *a, int lb, int ub)
{
    int mid = 0;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
int main()
{
    int n;
    n = readfile(employee);
    mergesort(employee, 0, n - 1);
    writefile(employee, n);
    return 0;
}