#include "libs.h"

// initial_data_structure
USER *initial_users() // output: a USER data type
{
    USER *head = (USER *)malloc(sizeof(USER));
    users(head);
    head->posts = initial_posts();
    head->next = NULL;
    return head;
}

POST *initial_posts() // output : a post dynamic array
{
    POST *head = (POST *)malloc(sizeof(POST));
    posts(head);
    head->likers = initial_likers();
    head->likes = -1;
    head->id = -1;
    head->next = NULL;

    return head;
}
LIKERS *initial_likers() // LIKERS is a data type for storing each post likers.
{
    LIKERS *head = (LIKERS *)malloc(sizeof(LIKERS));
    head->liker = NULL;
    head->next = NULL;
    return head;
}


int main()
{
    PrintLogo();
    initial_users();

    while (1)
    {
        char comm[10];
        scanf("%s", comm);
        command(comm);
    }
    return 0;
}
