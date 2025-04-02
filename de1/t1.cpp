#include<stdio.h>
#include<stdlib.h>
typedef struct sv
{
    int age;
    float point;
}sv;
int docFile(sv SV[], int *n)
{
    FILE * f = fopen("Sinhvien.txt", "r");
    if( f == NULL)
    {
        perror("ERROR");
        return -1;
    }
    fscanf(f, "%d", n); // Đọc số lượng sinh viên

    for (int i = 0; i < *n; i++) {
        fscanf(f, "%d\t%f", &SV[i].age, &SV[i].point);
    }

    fclose(f);
    return 0;
}
void selectionSort(sv SV[], int n)
{
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n ; j ++){
            if(SV[i].point < SV[j].point){
                sv temp = SV[i];
                SV[i] = SV[j];
                SV[j] = temp;
            }
        }
    }
}
void sv_caodiem(sv SV[], int n)
{
    int soluong;
    selectionSort(SV, n);
    if(n < 5){
        int soluong = n;
    }else{
        int soluong = 5;
    }
    for(int i = 0; i < soluong; i ++){
        printf("tuoi: %d\t %.2f", SV[i].age, SV[i].point);
    }
}
int diem_TB(sv SV[], int n, int t)
{
    int dem = 0, tong =0;
    for(int i = 0; i < n; i++)
    {
        if(t == SV[i].age)
        {
        dem ++;
         tong +=SV[i].point;
        }
    }
    if( dem > 0)
    {
        float tb = tong / dem;
        printf("diem tb= %.2f", tb); 
    }else{
        return -1;
    }
}
int main()
{
    sv SV[100];
    int t;
    scanf("%d", &t);
    float diemtb = diem_TB(SV, 3, 2);

}