#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#pragma warn -rvl /* return value */
#pragma warn -par /* parameter never used */
#pragma warn -rch /*unreachable code */

typedef struct USER user;
typedef struct POST post;
int command(char *comm);

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

int signup();
USER *search(char *username, char *password);
int login();
int logout();
USER *users(USER *data);
POST *posts(USER *data);
USER *isLoggedIn(int i, USER *loggedinuser); // in:1 out : 0 anyother thing to see statue.

USER *Find_end(USER *head);
int post_content();
LIKERS *initial_likers();