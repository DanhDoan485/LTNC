#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char ma[20];
    char hangSanXuat[50];
    float doCao;
    float gia;
    int thoiGianBaoHanh;
} GiayDep;

int main() {
    FILE *inputFile, *outputFile;
    GiayDep danhSach[MAX_ITEMS];
    int count = 0;

    // Mở tệp đầu vào để đọc
    inputFile = fopen("danhmuc.txt", "r");
    if (inputFile == NULL) {
        perror("Lỗi mở tệp danhmuc.txt");
        return 1;
    }

    // Đọc dữ liệu từ tệp
    while (fscanf(inputFile, "%s %s %f %f %d", danhSach[count].ma, danhSach[count].hangSanXuat,
                  &danhSach[count].doCao, &danhSach[count].gia, &danhSach[count].thoiGianBaoHanh) == 5 && count < MAX_ITEMS) {
        count++;
    }
    fclose(inputFile);

    // Mở tệp đầu ra để ghi
    outputFile = fopen("danhmucbackup.txt", "w");
    if (outputFile == NULL) {
        perror("Lỗi mở tệp danhmucbackup.txt");
        return 1;
    }

    // In danh sách giày dép ra màn hình và ghi vào tệp
    printf("Danh sách giày dép:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %.2f %.2f %d\n", danhSach[i].ma, danhSach[i].hangSanXuat,
               danhSach[i].doCao, danhSach[i].gia, danhSach[i].thoiGianBaoHanh);
        fprintf(outputFile, "%s %s %.2f %.2f %d\n", danhSach[i].ma, danhSach[i].hangSanXuat,
                danhSach[i].doCao, danhSach[i].gia, danhSach[i].thoiGianBaoHanh);
    }

    fclose(outputFile);
    return 0;
}
