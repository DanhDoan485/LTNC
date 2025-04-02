#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char MSV[100];
    char hoTen[100];
    float diem;
} sv;

void svNhap(sv *s) {
    printf("Nhap MSV: ");
    fgets(s->MSV, sizeof(s->MSV), stdin);
    s->MSV[strcspn(s->MSV, "\n")] = 0;
    
    printf("Nhap ho ten: ");
    fgets(s->hoTen, sizeof(s->hoTen), stdin);
    s->hoTen[strcspn(s->hoTen, "\n")] = 0;
    
    printf("Nhap diem: ");
    scanf("%f", &s->diem);
    getchar();
}

void svIn(sv s) {
    printf("MSV: %s\nHo ten: %s\nDiem: %.2f\n", s.MSV, s.hoTen, s.diem);
}

void ghiFile(const char *filename, sv ds[], int n) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Loi mo file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s\n%s\n%.2f\n", ds[i].MSV, ds[i].hoTen, ds[i].diem);
    }
    fclose(f);
}

int docFile(const char *filename, sv ds[], int *n) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo file!\n");
        return 0;
    }
    *n = 0;
    while (fgets(ds[*n].MSV, sizeof(ds[*n].MSV), f) &&
           fgets(ds[*n].hoTen, sizeof(ds[*n].hoTen), f) &&
           fscanf(f, "%f\n", &ds[*n].diem) == 1) {
        ds[*n].MSV[strcspn(ds[*n].MSV, "\n")] = 0;
        ds[*n].hoTen[strcspn(ds[*n].hoTen, "\n")] = 0;
        (*n)++;
    }
    fclose(f);
    return 1;
}

void ghiHocSinhGioi(const char *filename, sv ds[], int n) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diem >= 8.5) { 
            fprintf(f, "%s\n%s\n%.2f\n", ds[i].MSV, ds[i].hoTen, ds[i].diem);
            count++;
        }
    }
    fclose(f);
    if (count == 0) {
        printf("\nKhong co hoc sinh gioi de ghi vao file!\n");
    } else {
        printf("\nDa ghi danh sach hoc sinh gioi vao file '%s'\n", filename);
    }
}

int main() {
    sv ds[100];
    int n;

    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    getchar();  

    for (int i = 0; i < n; i++) {
        printf("Nhap sinh vien thu %d:\n", i + 1);
        svNhap(&ds[i]);
    }


    ghiFile("danh14.txt", ds, n);

  
    int m;
    if (docFile("danh14.txt", ds, &m)) {
        printf("\nDanh sach sinh vien doc tu file:\n");
        for (int i = 0; i < m; i++) {
            svIn(ds[i]);
        }

        ghiHocSinhGioi("danh14_gioi.txt", ds, m);
    }

    return 0;
}
