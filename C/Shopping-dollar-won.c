#include <stdio.h>

#define PRODUCT_COUNT 6 // 제품 개수

// 공용체: 가격을 원화 또는 달러로 저장
union Price
{
    int won;       // 원화 가격
    double dollar; // 달러 가격
};

// 구조체: 제품 정보
struct Product
{
    char name[20];     // 제품 이름
    union Price price; // 가격 정보
    int isDollar;      // 가격 단위 (1: 달러, 0: 원)
};

// 제품 목록 (상수 배열로 초기화)
const struct Product products[PRODUCT_COUNT] = {
    {"PMP", {600000}, 0},
    {"MP3", {153000}, 0},
    {"SmartPhone", {.dollar = 520.40}, 1},
    {"TV", {.dollar = 430.20}, 1},
    {"Navigator", {350000}, 0},
    {"Laptop", {.dollar = 1950.00}, 1}};

int main()
{
    int money;       // 보유 금액 (원)
    double exchange; // 환율 (1달러 = ? 원)

    // 사용자 입력
    printf("보유금액과 환율을 입력하세요.\n");
    printf("보유금액 : ");
    scanf("%d", &money);
    printf("환율 : ");
    scanf("%lf", &exchange);

    // 구매 가능한 제품 출력
    printf("\n구매 가능한 제품은 다음과 같습니다.\n");
    for (int i = 0; i < PRODUCT_COUNT; i++)
    {
        int price_in_won = (products[i].isDollar) ? (int)(products[i].price.dollar * exchange) : products[i].price.won;

        if (money >= price_in_won)
        {
            if (products[i].isDollar)
                printf("%s %d원\n", products[i].name, price_in_won);
            else
                printf("%s %d원\n", products[i].name, products[i].price.won);
        }
    }

    return 0;
}