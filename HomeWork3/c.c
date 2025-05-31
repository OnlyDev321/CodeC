#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_ENGWORD_LEN 16    // 영어 길이 15문자 + 1 null
#define MAX_KORMEANING_LEN 11 // 한글 길이 10문자 + 1 null

typedef struct Word
{
    char english[MAX_ENGWORD_LEN];
    char korean[MAX_KORMEANING_LEN];
    struct Word *next; // link_list 자기 참조 구조체
} Word;

Word *load_dictionary(const char *filename, int *count);
Word *insert_sorted(Word *head, Word *new_node); //*head:pointer to the first element of linked list, *new_node: pointer to the new node
void play_game(Word *head);
int getch(void);

Word *load_dictionary(const char *filename, int *count)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) // if file 없으면
    {
        return NULL;
    }

    Word *head = NULL;
    *count = 0; //  0부터 세기 시작
    while (1)
    {
        Word *new_word = (Word *)malloc(sizeof(Word));
        if (fscanf(fp, "%s %s", new_word->english, new_word->korean) != 2)
        {
            free(new_word);
            break;
        }
        new_word->next = NULL; // undefined memory에 access void기 위해 초기화된 모두 node will have .next =NULL
        head = insert_sorted(head, new_word);
        (*count)++;
    }

    fclose(fp);
    return head;
}

Word *insert_sorted(Word *head, Word *new_node)
{
    if (head == NULL || strcmp(new_node->english, head->english) < 0)
    {
        new_node->next = head; // ex: apple -> banana (ASCKEY a < b)
        return new_node;       // head new is apple
    }

    Word *current = head; // 현재 포인터는 리스트의 첫 element부터 시작
    while (current->next && strcmp(current->next->english, new_node->english) < 0)
    {
        current = current->next; // 다음 노드 음직임
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

void play_game(Word *head)
{
    int correct = 0, total = 0;
    char answer[MAX_ENGWORD_LEN];
    Word *current = head;

    printf(">> 영어 단어 맞추기 <<\n");

    while (current)
    {
        printf("%s -> ", current->korean);
        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF && i < MAX_ENGWORD_LEN - 1)
        {
            answer[i++] = ch;
        }
        answer[i] = '\0';

        if (strcmp(answer, ".quit") == 0)
        {
            break;
        }

        if (strcmp(answer, current->english) == 0)
        {
            printf("correct!\n");
            correct++;
        }
        else
        {
            printf("incorrect!\n");
        }

        current = current->next;
        total++;
    }

    double score = (double)correct / total * 100.0;
    printf("당신의 점수는 %.2f 점입니다.\n\n", score);
    printf("초기 메뉴로 이동하려면 esc 키를 누르세요.\n");
    printf("(화면 클리어 후 초기 메뉴로 이동)");

    while (1)
    {
        // int ch = getchar(); // 여기 getchar() 쓰면 바로 esc 못 받습니다.(enter 입력해야 됨)
        int ch = getch(); // 바로 esc 받을 수 있습니다.
        if (ch == 27)     // ESC key
        {
            break;
        }
    }
}

int getch(void)
{
    int ch;
    struct termios buf;
    struct termios save;
    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

int main()
{
    Word *dictionary = NULL;
    int word_count = 0;
    int choice;

    while (1)
    {
        system("clear");
        printf(">> 영어 단어 맞추기 프로그램 <<\n");
        printf("1. 영어 단어 맞추기\t\t2. 프로그램 종료\n\n");
        printf("번호를 선택하세요: ");
        scanf("%d", &choice);
        getchar(); // remote '\n'

        if (choice == 1)
        {
            printf("사전을 로딩 중입니다.\n");
            printf("(2초 후 화면 클리어)\n");
            sleep(2);
            system("clear");
            dictionary = load_dictionary("dic.txt", &word_count);
            if (!dictionary || word_count < 100)
            {
                printf("사전이 없거나 사전에 100개 이상의 단어가 없습니다. 프로그램 종료.\n");
                exit(1);
            }
            system("clear");
            play_game(dictionary);
        }
        else if (choice == 2)
        {
            printf("\n");
            printf("2초 후에 프로그램을 종료할 겁니다.\n");
            sleep(2);
            system("clear");
            break;
        }
        else
        {
            printf("\n");
            printf("잘못된 입력입니다. 2초 후에 다시 시도하세요.\n");
            sleep(2);
        }
    }

    return 0;
}
