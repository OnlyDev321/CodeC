#include <stdio.h>

// Hàm để in số nhị phân của 1 byte (8 bit)
void print_binary(unsigned char n)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }
}

int main()
{
    // 1-1: XOR giữa 10011101 và 10111101
    unsigned char a1 = 0b10011101;
    unsigned char b1 = 0b10111101;
    unsigned char result1 = a1 ^ b1;

    printf("1-1. Ket qua XOR (10011101 ^ 10111101): ");
    print_binary(result1);
    printf("\n");

    // 1-2: XOR kết quả trên với 10111101
    unsigned char result2 = result1 ^ b1;

    printf("1-2. Ket qua XOR (ket qua 1-1 ^ 10111101): ");
    print_binary(result2);
    printf("\n");

    // 1-3: XOR giữa 11101110 và 01011101
    unsigned char a3 = 0b11101110;
    unsigned char b3 = 0b01011101;
    unsigned char result3 = a3 ^ b3;

    printf("1-3. Ket qua XOR (11101110 ^ 01011101): ");
    print_binary(result3);
    printf("\n");

    // 1-4: XOR kết quả trên với 01011101
    unsigned char result4 = result3 ^ b3;

    printf("1-4. Ket qua XOR (ket qua 1-3 ^ 01011101): ");
    print_binary(result4);
    printf("\n");

    // 1-5: So sánh và kết luận
    printf("1-5. So sanh:\n");
    printf("Ket qua 1-2: ");
    print_binary(result2);
    printf(" va so ban dau a1: ");
    print_binary(a1);
    printf("\n");

    printf("Ket qua 1-4: ");
    print_binary(result4);
    printf(" va so ban dau a3: ");
    print_binary(a3);
    printf("\n");

    printf("==> Ket luan: (A ^ B) ^ B = A. Tinh chat giao hoan cua phep XOR\n");

    return 0;
}