#include "libs.h"

POST *initial_posts();
void PrintLogo(void);

// initial_data_structure
USER *initial_users()
{
    USER *head = (USER *)malloc(sizeof(USER));
    users(head);
    head->posts = initial_posts();
    head->next = NULL;
    return head;
}

POST *initial_posts()
{
    POST *head = (POST *)malloc(sizeof(POST));
    posts(head);
    head->likers = initial_likers();
    head->likes = -1;
    head->id = -1;
    head->next = NULL;

    return head;
}
LIKERS *initial_likers()
{
    LIKERS *head = (LIKERS *)malloc(sizeof(LIKERS));
    head->liker = NULL;
    head->next = NULL;
    return head;
}
int main(int argc, char const *argv[])
{
    PrintLogo();
    USER *list_u = initial_users();

    while (1)
    {
        char comm[10];
        scanf("%s", comm);
        command(comm);
    }
    return 0;
}
void PrintLogo(void)
{
    FILE *logo = fopen("logo.b", "r");

    char point = 10;
    while (point != 0)
    {
        point = getc(logo);
        switch (point)
        {
        case '0':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
            printf("#");

            break;
        case '1':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            printf("#");

            break;
        case '2':
            printf("\n");

            break;
        case '3':
            point = 0;
            break;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    printf("\n");
}