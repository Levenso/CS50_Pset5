#include <stdio.h>

struct pair{
    int value;
    int key;
};
void display(struct pair [], int size);

int main(void)
{
    int size, i, temp;
    printf("enter the size of the table");
    scanf("%d", &size);
    struct pair hash_table[size];
    printf("Enter the elements: ");
    for (i=0; i<size; i++)
    {
        scanf("%d", &temp );
        hash_table[temp % size].value = temp;
        hash_table[temp % size].key = temp%size;
    }
    printf("\n");
    display(hash_table, size);
    // int a = 0;

}

void display(struct pair ar[], int size)
{
    int i;

        printf("Value\tKey\n");

    for (i=0; i<size; i++)
    {
        printf("%d\t%d\n", ar[i].value, ar[i].key);
    }
}