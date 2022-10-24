#include "minishell.h"

int splited_2_strlist(t_list **list, char **splited)
{
    t_mbox  mbox;
    t_list  *new_node;
    int     cnt;
    
    cnt = 0;
    mbox.cur = 0;
    *list = 0;
    while (splited[cnt])
    {
        new_node = ft_lstnew(splited[cnt]);
        if (collector(&mbox, new_node) == 0)
            {
                *list = 0;
                return (1);
            }
        collector(&mbox, new_node->content);
        ft_lstadd_back(list, new_node);
        cnt++;
    }
    return (0);
}


char **strlist_2_splited(t_list **list)
{
    t_mbox  mbox;
    t_list  *p;
    int i;
    char **r;

    mbox.cur = 0;
    if (!list)
        return (0);

    r = ft_calloc(sizeof(char *) , ft_lstsize(*list) + 1);
    if (collector(&mbox, r) == 0)
        return (0);
    p = *list;
    i = 0;
    while (p)
    {
        r[i] = ft_strdup(p->content);
        if (collector(&mbox, r[i++]) == 0)
            return (0);
        p = p->next;
    }
    r[i] = 0;
    return (r);
}



char **strlist_2_splited_fast(t_list **list)
{
    t_mbox  mbox;
    t_list  *p;
    int i;
    char **r;

    if (!list)
        return (0);
    mbox.cur = 0;
    r = ft_calloc(sizeof(char *) , ft_lstsize(*list) + 1);
    if (collector(&mbox, r) == 0)
        return (0);
    p = *list;
    i = 0;
    while (p)
    {
        r[i++] = (p->content);
        p->content = 0;
        p = p->next;
    }
    r[i] = 0;
    ft_lstclear(list, free);
    return (r);

}


int int_min(int a, int b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

int int_max(int a, int b)
{
    if (a < b)
        return (b);
    else
        return (a);
}


int ft_is_assign(char * str)
{
    int i;

    i = 0;

    while(ft_isspace(str[i]))
        i++;
    if (ft_isalpha(str[i]))
    {
        while (ft_isalnum(str[i]) || str[i] == '_')
            i++;
        if (str[i] == '=')
            return (1); 
    }
    else
    {
        return (0);
    }
    return (0);
}











