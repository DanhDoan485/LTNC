#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char diaChi[100];
    char maCan[10];
    float gia;
    int soPhongNgu;
    int huong;
    int trangThai;
} CanHo;

typedef struct {
    char soBaoDanh[10];
    char hoTen[50];
    char truong[50];
    float diem;
} ThiSinh;

void docCanHo(FILE *f, CanHo *c) {
    fscanf(f, "%[^,],%[^,],%f,%d,%d,%d\n", c->diaChi, c->maCan, &c->gia, &c->soPhongNgu, &c->huong, &c->trangThai);
}

void inCanHo(CanHo c) {
    printf("Dia chi: %s\nMa can: %s\nGia: %.2f\nSo phong: %d\nHuong: %d\nTrang thai: %d\n", 
           c.diaChi, c.maCan, c.gia, c.soPhongNgu, c.huong, c.trangThai);
}

void docDanhSachCanHo(const char *filename, CanHo ds[], int *n) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Khong mo duoc file!\n");
        return;
    }
    *n = 0;
    while (!feof(f) && *n < MAX) {
        docCanHo(f, &ds[(*n)++]);
    }
    fclose(f);
}

void inDanhSachCanHo(CanHo ds[], int n) {
    for (int i = 0; i < n; i++) {
        inCanHo(ds[i]);
        printf("----------------------\n");
    }
}

void timCanHo(CanHo ds[], int n, int huong, int soPhong, float gia) {
    for (int i = 0; i < n; i++) {
        if (ds[i].huong == huong && ds[i].soPhongNgu == soPhong && ds[i].gia <= gia) {
            inCanHo(ds[i]);
        }
    }
}

void canHoDaCoc(CanHo ds[], int n) {
    printf("Danh sach can ho da dat coc:\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].trangThai == 1) {
            inCanHo(ds[i]);
        }
    }
}

void docThiSinh(FILE *f, ThiSinh *ts) {
    fscanf(f, "%[^,],%[^,],%[^,],%f\n", ts->soBaoDanh, ts->hoTen, ts->truong, &ts->diem);
}

void docDanhSachThiSinh(const char *filename, ThiSinh ds[], int *n) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Khong mo duoc file!\n");
        return;
    }
    *n = 0;
    while (!feof(f) && *n < MAX) {
        docThiSinh(f, &ds[(*n)++]);
    }
    fclose(f);
}

void inThiSinh(ThiSinh ts) {
    printf("SBD: %s\nHo ten: %s\nTruong: %s\nDiem: %.2f\n", ts.soBaoDanh, ts.hoTen, ts.truong, ts.diem);
}

void inDanhSachThiSinh(ThiSinh ds[], int n) {
    for (int i = 0; i < n; i++) {
        inThiSinh(ds[i]);
        printf("----------------------\n");
    }
}

int soSanhDiem(const void *a, const void *b) {
    return ((ThiSinh *)b)->diem - ((ThiSinh *)a)->diem;
}

void sapXepThiSinh(ThiSinh ds[], int n) {
    qsort(ds, n, sizeof(ThiSinh), soSanhDiem);
}

void timThiSinhTheoTruong(ThiSinh ds[], int n, char truong[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].truong, truong) == 0) {
            inThiSinh(ds[i]);
        }
    }
}

void timThiSinhTheoSBD(ThiSinh ds[], int n, char sbd[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].soBaoDanh, sbd) == 0) {
            inThiSinh(ds[i]);
            return;
        }
    }
    printf("Khong tim thay thi sinh!\n");
}

int main() {
    CanHo dsCanHo[MAX];
    ThiSinh dsThiSinh[MAX];
    int nCanHo, nThiSinh;
    
    docDanhSachCanHo("canho.txt", dsCanHo, &nCanHo);
    docDanhSachThiSinh("thisinh.txt", dsThiSinh, &nThiSinh);
    
    printf("\nDanh sach can ho:\n");
    inDanhSachCanHo(dsCanHo, nCanHo);
    
    printf("\nDanh sach thi sinh:\n");
    sapXepThiSinh(dsThiSinh, nThiSinh);
    inDanhSachThiSinh(dsThiSinh, nThiSinh);
    
    printf("\nCan ho da dat coc:\n");
    canHoDaCoc(dsCanHo, nCanHo);
    
    printf("\nTim thi sinh theo truong: \n");
    timThiSinhTheoTruong(dsThiSinh, nThiSinh, "Dai hoc ABC");
    
    printf("\nTim thi sinh theo SBD:\n");
    timThiSinhTheoSBD(dsThiSinh, nThiSinh, "12345");
    
    return 0;
}
