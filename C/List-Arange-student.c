#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Size 20

// 선언
struct inFormation
{
    char name[20];
    int id;
    double height;
};

// 명단
struct inFormation stuDents[Size] = {
    {"Sophia", 20220001, 153.1}, {"Olivia", 20220010, 158.5}, {"Riley", 20220002, (int)163}, {"Emma", 20220015, 160.3}, {"Ava", 20220009, 155.6}, {"Isabella", 20220014, 168.8}, {"Aria", 20220020, 150.2}, {"Amelia", 20220005, 162.5}, {"Mia", 20220016, 170.2}, {"Liam", 20220008, 180.9}, {"Noah", 20220012, 174.9}, {"Jackson", 20220004, 191.1}, {"Aiden", 20220018, 188.8}, {"Elijah", 20220017, 169.7}, {"Grayson", 20220003, 174.2}, {"Lucas", 20220013, 188.7}, {"Oliver", 20220007, 170.5}, {"Caden", 20220019, 173.3}, {"Mateo", 20220011, 169.9}, {"David", 20220006, 188.8}};

// 명단을 가르키는 포인터 배열
struct inFormation *ptrs[Size];

// 이름 오름차순(비교)
int cmp_name(const void *a, const void *b)
{
    struct inFormation *pa = *(struct inFormation **)a;
    struct inFormation *pb = *(struct inFormation **)b;
    return strcmp(pa->name, pb->name);
}

// ID 오름차순
int cmp_id(const void *a, const void *b)
{
    struct inFormation *pa = *(struct inFormation **)a;
    struct inFormation *pb = *(struct inFormation **)b;
    return pa->id - pb->id;
}

// 키 내림차순
int cmp_height_desc(const void *a, const void *b)
{
    struct inFormation *pa = *(struct inFormation **)a;
    struct inFormation *pb = *(struct inFormation **)b;
    if (pb->height > pa->height)
        return 1;
    else if (pb->height < pa->height)
        return -1;
    else
        return 0;
} // 왜 id함수에 비해 height 함수 다르게 코딩? height 함수에서 data type: double 이기 때문에 strcmp() return 1 , -1 , 0(interger) 이니까 오류 발생

// 명단 출력
void print_list()
{
    printf("%-10s \t%-10s \t%-10s\n", "이름", "아이디", "키");
    for (int i = 0; i < Size; i++)
    {
        if (strcmp(ptrs[i]->name, "Riley") == 0)
        {
            printf("%-10s \t%-10d \t%-10d\n", ptrs[i]->name, ptrs[i]->id, (int)(ptrs[i]->height));
            continue;
        }
        printf("%-10s \t%-10d \t%-10.1f\n", ptrs[i]->name, ptrs[i]->id, ptrs[i]->height);
    }
    printf("\n");
}

// Search by name
void search_by_name()
{
    char key[20];
    printf("이름을 입력하세요: ");
    scanf("%s", key);
    printf("\n");
    int found = 0;
    for (int i = 0; i < Size; i++)
    {
        if (strcmp(ptrs[i]->name, key) == 0)
        {
            printf("%-10s \t%-10s \t%-10s\n", "이름", "아이디", "키");
            if (strcmp(ptrs[i]->name, "Riley") == 0)
            {
                printf("%-10s \t%-10d \t%-10d\n", ptrs[i]->name, ptrs[i]->id, (int)(ptrs[i]->height));
                found = 1;
                continue;
            }
            printf("%-10s \t%-10d \t%-10.1f\n", ptrs[i]->name, ptrs[i]->id, ptrs[i]->height);
            found = 1;
        }
    }
    printf("\n");
    if (!found)
    {
        printf("해당 이름의 학생이 없습니다.\n");
    }
}

int main()
{
    // pointer array에 주소를 해당
    for (int i = 0; i < Size; i++)
    {
        ptrs[i] = &stuDents[i];
    }

    int choice;

    while (1)
    {
        printf("1. 이름 오름차순 출력\t2. 아이디 오름차순 출력\n");
        printf("3. 키 내림차순 출력\t4. 이름 검색\n5. 종료\n\n");
        printf("번호를 선택하세요 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            qsort(ptrs, Size, sizeof(struct inFormation *), cmp_name);
            print_list();
            break;
        case 2:
            qsort(ptrs, Size, sizeof(struct inFormation *), cmp_id);
            print_list();
            break;
        case 3:
            qsort(ptrs, Size, sizeof(struct inFormation *), cmp_height_desc);
            print_list();
            break;
        case 4:
            search_by_name();
            break;
        case 5:
            printf("\n프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 변호입니다. 다시 선택하세요.\n\n");
        }
    }
    return 0;
}