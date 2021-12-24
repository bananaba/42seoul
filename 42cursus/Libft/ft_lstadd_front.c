void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!new || !lst)
        return ;
    else if (*lst)
        new->next = *lst;
    else
        new->next = 0;
    *lst = new;
}