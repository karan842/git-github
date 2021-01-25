#include <stdio.h>
#include <string.h>
#include <string.h>
typedef struct emp
{
    int age;
    char name[20];
} data;
data emp[50];
int readfile(data *arr)
{
    FILE *fp;
    int i = 0;
    if ((fp = fopen("employee.txt", "r")) != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d%s", &arr[i].age, &arr[i].name);
            i++;
        }
    }
    return i;
}
void countsort(data *arr, int size)
{
    int i;
    int max = arr[0].age;
    int op[size];
    char op2[size][20];
    for (i = 1; i < size; i++)
    {
        if (max < arr[i].age)
            max = arr[i].age;
    }
    int count[max];
    for (i = 0; i <= max; i++)
        count[i] = 0;
    for (i = 0; i < size; i++)
        count[arr[i].age]++;
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--)
    {
        op[count[arr[i].age] - 1] = arr[i].age;
        strcpy(op2[count[arr[i].age] - 1], arr[i].name);
        count[arr[i].age]--;
    }
    for (i = 0; i < size; i++)
    {
        arr[i].age = op[i];
        strcpy(arr[i].name, op[i]);
    }
}
void writefile(data *arr, int size)
{
    FILE *fp;
    if ((fp = fopen("sortedemponage.txt", "w")) != NULL)
    {
        for (int i = 0; i < size; i++)
            fprintf(fp, "%d %s\n", arr[i].age, arr[i].name);
    }
}
int main()
{
    int size = readfile(emp);
    countsort(emp, size);
    writefile(emp, size);
    return 0;
}