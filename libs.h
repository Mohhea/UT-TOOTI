#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct user USER;
typedef struct post POST;
typedef struct likers LIKERS;
struct user
{
    char username[20];
    char password[20];
    POST *posts;
    USER *next;
};
struct post
{
    char *username;
    int id;
    char content[100];
    int likes;
    LIKERS *likers;
    POST *next;
};
struct likers
{
    USER *liker;
    LIKERS *next;
};
int command(char *);
int signup();
USER *search(char *, char *);
int login();
int logout();
USER *users(USER *);
POST *posts(POST *);
USER *isLoggedIn(int i, USER *);
USER *Find_end(USER *);
int post_content();
LIKERS *initial_likers();
void PrintLogo();
POST *find_post(POST *post, int id);
int print_info_of_user();
USER *find_user(char *);
POST *initial_posts();
int like();
int delete();
int info(USER *this);