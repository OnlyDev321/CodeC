#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int id;
    char name[10];
    int grade[3];
    float avg;
} student;

int main(int argc, char *argv[])
{
    FILE *fp;
    student st;

    // Mở file nhị phân để đọc
    fp = fopen("test.txt", "rb");

    printf("ID\tTên\tToán\tAnh\tKhoa\t\n");
    printf("--------------------------------------------------\n");

    // Đọc từng struct từ file
    while (fread(&st, sizeof(student), 1, fp) == 1)
    {
        printf("%d\t%s\t%d\t%d\t%d\n",
               st.id, st.name, st.grade[0], st.grade[1], st.grade[2]);
    }

    fclose(fp);
    return 0;
}