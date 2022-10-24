
#include "libftprintf.h"


void skip_space(char *str, int *i)
{
	while (str[*i] && ft_isspace(str[*i]))//공백 문자일 때에만 공백 문자 끝날떄까지 이동
		(*i)++;
}

void skip_quote(char *cmd, int *r)
{
	int i;
	char c;

	i = *r;
	if (cmd[i] == '\"' || cmd[i] == '\'')
		{
			c = cmd[i++];
			while (cmd[i] && cmd[i] != c)
				i++;
			//if (cmd[i] == c) // cmd가 [0]으로 탈출한 것이 아닌 경우 따옴표 다음으로 이동
			//	i++;
			//else
			//	c = 1 + 1;//handle_error()// 이 경우는 따옴표가 안 닫힌 것;
			if (cmd[i] != c)
				i--;
		}
	*r = i;
}

void excutable_text_2_names(char *cmdd)
{
	int i;

	i = 0;

	char *cmd;
	char *redirection;
	char *excutable;
	char *nullstr;
	char *add;
	char *t;

	char c;
	cmd = ft_mprintf("%s ", cmdd);
	redirection = ft_calloc(sizeof(char), 10000);
	excutable = ft_calloc(sizeof(char), 10000);
	nullstr = ft_calloc(sizeof(char), 10000);


	int cut_start;
	int cut_end;
	int cut_len;

	cut_start = 0;
	cut_len = 0;



	while(cmd[i])
	{

		c = cmd[i];

		// cut_end 부분 찾으면 잘라서 저장하기
		if (i == 0 || c == '>' || c == '<' || c == ' ')
		{
			if (0 < i)
			{
				if (ft_strlen(add))
					ft_strlcat(add, "|", ft_strlen(add) + 2);
				ft_strlcat(add, &cmd[cut_start], ft_strlen(add) + (i - cut_start) + 1);	
			}
			skip_space(cmd, &i);
			if (cmd[i] && (cmd[i] == '>' || cmd[i] == '<')) // >> or << 이면
			{
				cut_start = i++;
				if (cmd[i] && cmd[i - 1] == cmd[i])
					i++;
				add = redirection;
				skip_space(cmd, &i);
			}
			else
			{
				cut_start = i;
				skip_quote(cmd, &i);
				i++;
				if (ft_strlen(excutable) && add != excutable)
					add = nullstr;
				else
					add = excutable;

			}

		}
		else
		{
			skip_quote(cmd, &i);
			i++;
		}


		{
			ft_printf("now on      :%s\n", &cmd[i]);
			ft_printf("str temp    :%s\n", t = ft_substr(cmd, cut_start, i - cut_start));
			ft_printf("redirection :%s\n", redirection);
			ft_printf("excutable   :%s\n", excutable);
			ft_printf("nullstr     :%s\n", nullstr);		
			ft_printf("\n");
			free(t);
		}

	}

	ft_printf("redirection : %s \n", redirection);
	ft_printf("excutable   : %s \n", excutable);
}


int main(int argc, char **argv)
{
	if (argc == 2)
		excutable_text_2_names(argv[1]);

	return 0;
}