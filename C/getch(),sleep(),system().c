#include <stdio.h>
#include <unistd.h>  // sleep()
#include <termios.h> // getch()
#include <stdlib.h>  // system()

// Hàm getch() không cần nhấn Enter
int getch(void)
{
    int ch;
    struct termios old, new;

    tcgetattr(0, &old); // Lưu cấu hình terminal hiện tại
    new = old;
    new.c_lflag &= ~(ICANON | ECHO); // Tắt chế độ nhập chuẩn và ẩn ký tự
    tcsetattr(0, TCSANOW, &new);     // Áp dụng cấu hình mới

    ch = getchar(); // Đọc 1 ký tự

    tcsetattr(0, TCSANOW, &old); // Khôi phục cấu hình cũ
    return ch;
}

int main(void)
{
    // Hiển thị danh sách file
    system("ls");

    // Hỏi người dùng
    printf("\n몇 초 후에 화면을 지울까요? : ");

    // Đọc 1 ký tự từ người dùng (dạng số)
    int ch = getch();
    putchar(ch); // In ra ký tự vừa nhập (cho giống yêu cầu)
    putchar('\n');

    // Chuyển ký tự thành số (giả sử người dùng chỉ nhập 1 chữ số)
    int seconds = ch - '0';

    // Đợi số giây tương ứng
    sleep(seconds);

    // Xóa màn hình
    system("clear");

    return 0;
}