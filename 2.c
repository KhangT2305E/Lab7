#include <stdio.h>
#include <string.h>

int binarySearch(char str[], char key);

int main() {
    char str[100];
    char key;

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Nhap ky tu: ");
    scanf("%c", &key);

    int index = binarySearch(str, key);
    if (index == -1) {
        printf("Khong tim thay ky tu '%c' trong chuoi.\n", key);
    } else {
        printf("Ky tu '%c' xuat hien tai vi tri %d trong chuoi.\n", key, index);
    }

    return 0;
}

int binarySearch(char str[], char key) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (str[mid] == key) {
            return mid;
        } else if (str[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
