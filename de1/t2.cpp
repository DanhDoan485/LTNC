#include<stdio.h>
#include<stdlib.h>
typedef struct ns
{
    char name[30],sdt[15];
    int catxe;
}ns;
int docfile(ns NS[], int *n)
{
    FILE *f = fopen("t2.txt", "r");
    if(f == NULL)
    {
        perror("ERROR");
        return -1;
    }
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) 
    {
        fscanf(f, "%s %s %d", NS[i].name, NS[i].sdt, &NS[i].catxe);
    }
    fclose(f);
    return 0;
}
void in_ds(ns NS[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s\t %s\t %d\n", NS[i].name, NS[i].sdt, NS[i].catxe);
    }
}
void selectionSort(ns NS[], int n)
{
    for(int i =0 ;i < n -1; i++)
    {
        for(int j = i+1; j < n ; j++)
        {
            if(NS[i].catxe < NS[j].catxe)
            {
                ns temp = NS[i];
                NS[i] = NS[j];
                NS[j] = temp;
            }
        }
    }
}
void catxe_giamdan(ns NS[], int n)
{
    selectionSort(NS, n);
   FILE*f = fopen("NS.txt", "w+");
   if(f == NULL)
   {
    perror("ERROR");
    return;
   }
   fprintf(f, "%d", n);
   for(int i = 0; i < n; i++)
   {
    fprintf(f,"%s\t%s\t%d\n", NS[i].name, NS[i].name, NS[i].catxe);
   }
   fclose(f);
}
int main()
{
        ns danhSach[100];  // Giả sử tối đa 100 phần tử
        int n;
    
        if (docfile(danhSach, &n) == 0) {
            printf("Danh sách từ file:\n");
            in_ds(danhSach, n);
        } else {
            printf("Không thể đọc file!\n");
        }
        catxe_giamdan(danhSach, n);
        return 0;
}