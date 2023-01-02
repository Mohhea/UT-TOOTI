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

    int command; //              0.      1.       2.     3.      4.         5.        6.     7
    char *commandlist[8] = {"signup", "login", "post", "like", "logout", "delete", "info", "find_user"};
    for (int i = 0; i < 8; i++)
    {
        if (!strcmp(comm, commandlist[i]))
        {
            switch (i)
            {
            case 0:

                if (signup())

                    printf("SUCCE$$FULLY DONE!\n");
                break;
            case 1:
                login();

                break;
            case 2:
                post_content();
                break;
            case 3:
                like();
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
            }
            return 1;
        }
    }
}

int signup()
{
    // is there same username?
    // return -1;
    char username[20];
    char password[20];
    scanf("%s", username);
    scanf("%s", password);

    USER *end = (Find_end_u(users(NULL)))->next = (USER *)malloc(sizeof(USER));
    strcpy(end->username, username);
    strcpy(end->password, password);
    end->posts = initial_posts();
    end->next = NULL;
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
    }
    else
        printf("YOU ARE ALREADY LOGGED OUT\n");
}

USER *search(char *username, char *password)
{
    USER *head = users(NULL);
    while (head)
    {
        if (!strcmp(username, head->username))
        {
            if (strcmp(password, head->password))
            {
                printf("PA$$WORD NOT CORRECT!\n");
                return NULL;
            }
            // info();
            return head;
        }
        head = head->next;
    }
    printf("U$ER NOT FOUND!\n");
    return NULL;
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
        end->next->username = isLoggedIn(2, NULL);
        end->next->next = NULL;
        end->next->likes = 0;
        end->next->likers = initial_likers();
        printf("PO$TED!");
    }
    else
    {
        printf("YOU ARE NOT LOGGED IN!\n");
        return -1;
    }
}

int info(USER *this)
{
    printf("------------\nuser  : %s\n", this->username);
    if (isLoggedIn(2, NULL))
        printf("password : %s \n", this->password);
    POST *post = this->posts->next;
    if (!post)
        printf("\nno post fo this user!\n");
    printf("POSTS:");
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
            printf("\n$ POST HAS BEEN SUCCESSFULLY DELETED!\n");
            return 1;
        }
        PER = CUR;
        CUR = CUR->next;
    }
    printf("\n$ THERE IS NO SUCH POST!\n");
    return -1;
}
int like()
{
    char user[20];
    int id;
    scanf("%s %d", user, &id);
    USER *liker_user = isLoggedIn(2, NULL);
    if (!liker_user) // check if logged in
        return -1;
    USER *head = users(NULL);
    while (head) // find account
    {
        if (!strcmp(user, head->username))
            break;

        head = head->next;
    }

    POST *post = head->posts;

    while (post) // find post
    {
        if (id == post->id)
            break;

        post = post->next;
    }
    LIKERS *likers_list = post->likers;
    while (likers_list) // check if user liked before?
    {
        if (likers_list->liker == liker_user)
        {
            printf("$ YOU HAVE LIKED THIS BEFORE!\n");
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
int find_user()
{
    char username[20];
    scanf("%s", username);
    USER *list_u = users(NULL);
    while (list_u)
    {
        if (!strcmp(list_u->username, username))
        {
            info(list_u);
            return 1;
        }
        list_u = list_u->next;
    }
    printf("$ THERE I$ NO $UCH USERNAME!\n");
}