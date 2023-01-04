#include "libs.h"

USER *Find_end_u(USER *head)
{
    while (head->next)
    {
        head = head->next;
    }
    return head;
}
POST *Find_end_p(POST *head)
{
    while (head->next)
    {
        head = head->next;
    }
    return head;
}
int command(char *comm)
{

    //                             0.      1.       2.     3.      4.         5.        6.     7.          8.
    char *commandlist[9] = {"signup", "login", "post", "like", "logout", "delete", "info", "find_user", "cls"};
    for (int i = 0; i < 9; i++)
    {
        if (!strcmp(comm, commandlist[i]))
        {
            switch (i)
            {
            case 0:

                if (signup())
                    printf("SUCCESSFULLY DONE!\n");
                else
                    printf("THERE IS ANOTHER ACCOUNT WITH THE SAME USERNAME!\n");
                break;
            case 1:
                login();

                break;
            case 2:
                post_content();
                break;
            case 3:
                if (like() + 1)
                    printf("POST LIKED!\n");
                break;
            case 4:
                logout();
                break;
            case 5:
                if (isLoggedIn(2, NULL))
                    delete ();
                else
                    printf("YOU ARE NOT LOGGED IN!\n");
                break;
            case 6:
                if (isLoggedIn(2, NULL))
                    info(isLoggedIn(2, NULL));
                else
                    printf("YOU ARE NOT LOGGED IN!\n");
                break;

            case 7:
                print_info_of_user();
                break;

            case 8:
                system("cls");
                PrintLogo();
                break;
            }
            return 1;
        }
    }
    return -1;
}
int signup()
{
    char username[20];
    char password[20];
    scanf("%s", username);
    scanf("%s", password);
    if (find_user(username))
        return 0;
    USER *end = (Find_end_u(users(NULL)))->next = (USER *)malloc(sizeof(USER));
    strcpy(end->username, username);
    strcpy(end->password, password);
    end->posts = initial_posts();
    end->next = NULL;
    return 1;
}
int login()
{
    char username[20];
    char password[20];
    scanf("%s", username);
    scanf("%s", password);

    if (!isLoggedIn(2, NULL))
    {
        if (isLoggedIn(1, search(username, password)))
        {
            printf("YOU ARE NOW LOGGED IN!\n");
            return 1;
        }
    }
    else
    {
        printf("YOU ARE ALREADY LOGGED IN!\n");
        return 1;
    }
    return -1;
}
int logout()
{
    if (isLoggedIn(2, NULL))
    {
        isLoggedIn(0, NULL);
        printf("YOU ARE NOW LOGGED OUT!\n");
        return 1;
    }
    else
        printf("YOU ARE ALREADY LOGGED OUT\n");
    return 1;
}
USER *search(char *username, char *password) // with username and password
{

    USER *searched_u = find_user(username);
    if (!searched_u)
    {
        printf("USER NOT FOUND!\n");
        return NULL;
    }
    if (strcmp(password, searched_u->password))
    {
        printf("PASSWORD NOT CORRECT!\n");
        return NULL;
    }
    return searched_u;
}
int post_content()
{
    char content[100];
    fgets(content, 100, stdin);

    POST *end; // the last post.
    if (isLoggedIn(2, NULL))
    {
        end = Find_end_p(isLoggedIn(2, NULL)->posts);
        end->next = (POST *)malloc(sizeof(POST));
        strcpy(end->next->content, content);
        end->next->id = (end->id) + 1;
        end->next->likes = (int)(0);
        end->next->next = NULL;
        end->next->likers = initial_likers();
        printf("POSTED!\n");
        return 1;
    }
    else
    {
        printf("YOU ARE NOT LOGGED IN!\n");
        return -1;
    }
}
int info(USER *this) // input : user address   output : prints info of desired user
{
    printf("------------\nuser  : %s\n", this->username);
    if (isLoggedIn(2, NULL) == this)
        printf("password : %s \n", this->password);
    POST *post = this->posts->next;
    if (!post)
        printf("\nno post fo this user!\n");
    printf("POSTS:\n");
    while (post)
    {
        printf("\nid:%d : %s likes:%d\n\n", post->id, post->content, post->likes);
        post = post->next;
    }
    printf("------------\n");
    return 1;
}
int delete()
{
    int id_p;
    scanf("%d", &id_p);
    POST *PER = isLoggedIn(2, NULL)->posts;
    POST *CUR = isLoggedIn(2, NULL)->posts->next;
    while (CUR)
    {
        if (CUR && CUR->id == id_p)
        {
            PER->next = CUR->next;
            free(CUR);
            printf("\nS POST HAS BEEN SUCCESSFULLY DELETED!\n");
            return 1;
        }
        PER = CUR;
        CUR = CUR->next;
    }
    printf("\nS THERE IS NO SUCH POST!\n");
    return -1;
}
int like()
{
    char user[20];
    int id;
    scanf("%s %d", user, &id);
    USER *liker_user = isLoggedIn(2, NULL);
    if (!liker_user) // check if logged in
    {
        printf("YOU SHOULD LOG IN TO LIKE A POST!\n");
        return -1;
    }
    POST *post = find_post(find_user(user)->posts, id);
    LIKERS *likers_list = post->likers; // bring liker list of post of user
    while (likers_list)                 // check if user liked before?
    {
        if (likers_list->liker == liker_user)
        {
            printf("S YOU HAVE LIKED THIS BEFORE!\n");
            return -1;
        }
        if (likers_list->next == NULL)
            break;
        likers_list = likers_list->next;
    }
    likers_list = likers_list->next = (LIKERS *)malloc(sizeof(LIKERS));
    likers_list->liker = liker_user; //
    likers_list->next = NULL;
    post->likes++;
    return 1;
}
USER *find_user(char username[20]) // without password
{
    USER *list_u = users(NULL);
    while (list_u)
    {
        if (!strcmp(list_u->username, username))
            return list_u;
        list_u = list_u->next;
    }
    return NULL;
}
POST *find_post(POST *post, int id)
{
    while (post) // find post
    {
        if (id == post->id)
            return post;
        post = post->next;
    }
    return NULL;
}
int print_info_of_user()
{
    char username[20];
    scanf("%s", username);
    info(find_user(username));
    return 1;
}