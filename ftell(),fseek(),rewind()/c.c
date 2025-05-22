#include <stdio.h>

int main()
{
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("Không thể mở file.\n");
        return 1;
    }

    // Đọc một ký tự
    char ch = fgetc(fp);
    printf("Ký tự đầu tiên: %c\n", ch);

    // Lấy vị trí hiện tại
    long pos = ftell(fp);
    printf("Vị trí hiện tại (sau 1 ký tự): %ld\n", pos);

    // Di chuyển tới byte thứ 6 (vị trí bắt đầu của từ 'World')
    fseek(fp, 6, 0);
    ch = fgetc(fp);
    printf("Ký tự ở vị trí thứ 6: %c\n", ch);

    // Trở về đầu file
    rewind(fp);
    ch = fgetc(fp);
    printf("Ký tự đầu tiên sau rewind: %c\n", ch);

    fclose(fp);
    return 0;
}