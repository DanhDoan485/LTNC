#include<stdio.h>
int main()
{
    FILE *f;
    f = fopen("danh16.txt", "w+");
    if(f == NULL)
    {
        perror("ERROR");
        return 1;
    }
    for(int i = 1; i < 21; i++)
    {
        fprintf(f, "%d\n", i);
    }
    fclose(f);


}