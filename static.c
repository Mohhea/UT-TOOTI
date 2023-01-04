#include "libs.h"

USER *users(USER *data)
{
#ifndef enter1
#define enter1
    static int enters = 0;
    static USER *users;

#endif
    enters++;
    if (enters == 1)
    {
        users = data;
    }

    return users;
}
POST *posts(POST *data)
{
#ifndef enter2
#define enter2
    static POST *head = NULL;
    static int enters = 0;
#endif
    enters++;

    if (!(enters - 1))
        head = data;

    return head;
}

USER *isLoggedIn(int i, USER *loggedinuser) // in:1 out : 0 anyother thing to see statue.
{
#ifndef enter3
#define enter3
    static USER *user = NULL;
#endif
    switch (i)
    {
    case 0:

        return (user = NULL);
        break;

    case 1:
        if (loggedinuser)
            return (user = loggedinuser);
        else
            return NULL;
        break;

    default:
        return user;
        break;
    }
}
