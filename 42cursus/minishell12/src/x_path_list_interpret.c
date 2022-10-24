#include "minishell.h"

//path 리스트를 받아서 argv로 사용할 수 있는 형태로 변환한다.
// 띄어쓰기 단위로 나누고, 쿼트를 지운다.
// 
/* path_list의 맨 위 문자열부터, 시작한다
** 그냥 줄에서는 만약 띄어쓰기가 보이면, 거기서 나눈다.
** 만약 새 줄이 쿼트 줄인데, 이전 줄(이 있고) 에 맨 마지막이 공백이 아니면, 붙인다.
** 쿼트 줄에서는 쿼트만 지운다.
** 
**
** 쭉 가다가, 스페이스가 있다 -> 스페이스를 지우고 스페이스 다음부터 나눈다.
** 쭉 가다가, 줄 끝이다 -> 다음 줄을 붙이고 이어간다. -> 다음줄이 쿼트 줄이다 -> 쿼트를 지우고, 커서를 옮기고 한번 더 붙인다.
**
*/
int combine_str_list(t_list *first_node);
void divide_str_list(t_list *node, int index);
static int is_quote_line(t_list *node);
static int is_quote(int c);
static int delete_quote(t_list *node);
int path_list_organize(t_list *path_list);


int path_list_interpret(t_e *excutable, t_list *path_list)
{

	path_list_organize(path_list);
	
	excutable->argv = strlist_2_splited_fast(&path_list);

	return(0);
}


int path_list_organize(t_list *path_list)
{
	int 	i;
	int 	j;
	t_list	*node;

	i = 0;
	j = 0;
	while (1)
	{
		print_strlist(path_list, " now organizing");
		ft_printf("i = %d  j = %d \n", i, j);

		node = ft_lstnth(path_list, i);

		//ft_printf("debug17 :%p\n", ((char *) node->content));
		//ft_printf("debug17 :%s\n", ((char *) node->content));
		//ft_printf("debug17 :%p\n", ((char *) ft_lstnth(path_list, j)->content));
		//ft_printf("debug17 :%i\n", j);

		if (((char *) node->content)[j] == 0)// 마지막 null 문자
		{
			if (node->next && delete_quote(node->next) == 0)// 다음 줄이 쿼트이면 지우기, 그리고 다음줄 실행
			{
				if (combine_str_list(node))
					return (0);
				j = ft_strlen(node->content);
			}
			if (combine_str_list(node))
				return (0);
		}
		else if (ft_isspace(((char *) node->content)[j]))//스페이스바 발견
		{
			((char *) node->content)[j] = 0;
			divide_str_list(ft_lstnth(path_list, i++), j + 1);
			j = 0;
		}
		else
		{
			j++;
		}
	}	
	return (0);
}

static int delete_quote(t_list *node)
{
	char *str;

	if (node && node->content)
	{
		if (is_quote_line(node))
		{
			str = node->content;
			ft_strlcpy(str, str + 1, ft_strlen(str + 1));
			return (0);
		}
	}
	return (1);
}


static int is_quote(int c)
{
	if (c == '\'' || c == '\"')
		return (1);
	else
		return (0);
}
/*
static char	back_of_strnode(t_list *node)
{
	int i;

	if (node && node->content)
	{
		i = 0;
		while(node->content[i])
			i++;
		return(node->content[i - 1]);
	}
	return (0);
}
*/
// 쿼트가 맨 앞 그리고 맨 뒤에서 같은지 확인한다.
static int is_quote_line(t_list *node)
{
	int		i;
	char	c;

	if (node && node->content)
	{
		c = ((char *) node->content)[0];
		i = 0;
		while(((char *) node->content)[i])
			i++;
		if (c == ((char *) node->content)[--i] && is_quote(c))
			return (1);
	}
	return (0);
}
/*
// 이번 줄이 쿼트인데, 이전 줄이 공백 없이 끝나는 경우
static int is_it_need_to_glue(t_list *prev_node)
{
	int i;
	t_list *now_node;

	if (prev_node && prev_node->content)
	{
		now_node = prev_node->next;
		if (now_node && now_node->content && is_quote_line(now_node))
		{
			i = 0;
			while(node->content[i])
				i++;
			if (ft_isspace(node->content[i - 1]))
			{
				return (1);
			}
		}
	}
	return (0);
}
*/


//str_list의 노드와 index를 집어넣으면, 거기서 문자열을 끊어 두개의 노드로 만들어 준다.(인덱스가 가르키는 문자부터 새로운 칸이 된다.)
void divide_str_list(t_list *node, int index)
{
	t_mbox	mbox;
	char	*temp_str;
	t_list	*new_node;

	mbox.cur = 0;
	if (node && node->content && 0 < index)
	{
		temp_str = ft_strdup(&node->content[index]);
		if (collector(&mbox, temp_str))
		{
			new_node = ft_lstnew(temp_str);
			if (collector(&mbox, new_node))
			{
				ft_lstadd_next(node, new_node);
				((char *) node->content)[index] = 0;
			}
		}
	}
}

int combine_str_list(t_list *first_node)
{
	t_mbox	mbox;
	char	*temp_str;

    mbox.cur = 0;
	temp_str = 0;
	if (first_node && first_node->next && \
		first_node->content && first_node->next->content)
		temp_str = ft_calloc(sizeof(char), \
			ft_strlen(first_node->content) + \
			ft_strlen(first_node->next->content));
	if (temp_str)
	{
		ft_strlcat(temp_str, first_node->content, \
			ft_strlen(first_node->content) + 1);
		ft_strlcat(temp_str, first_node->next->content, \
			ft_strlen(first_node->content) +
			ft_strlen(first_node->next->content) + 1);
		free(first_node->content);
		free(first_node->next->content);
		first_node->content = first_node->next;
		first_node->next = first_node->next->next;
		free(first_node->content);
		first_node->content = temp_str;
		return (0);
	}
	return (1);
}




