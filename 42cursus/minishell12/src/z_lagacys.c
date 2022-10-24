
/*
void lagacy_split_into_excutables(t_mp *mp, t_r *runnable)
{
	t_mbox	trash_can;
	char	**pipe_split;
	
    trash_can.cur = 0;	
	
	collector(&trash_can, 0);//initialize
	
	pipe_split = ft_split(runnable->text, '|'); // malloc 예외처리
	if (pipe_split == 0)
	{
		runnable->state = 100;
		return (0);
	}


	//job을 받아서 그 텍스트 내용을 토대로
	// excutable을 만들고 그안에 텍스트 구겨담기
	int i = -1;
	runnable->num_of_excutables = 0;

	while (pipe_split[runnable->num_of_excutables])
		runnable->num_of_excutables++;

	while (pipe_split[++i])//job 만들고 그 안에 excutable 옮겨담기 (excutable 만들기)
	{
		runnable->excutables[i] = ft_calloc(sizeof(s_excutable), num_of_excutables + 1);
		if (collector(runnable->mbox, runnable->excutables) == 0) // malloc 예외처리
			return (0);
		runnable->excutables[i].text = pipe_split[i]; // 자 할일 다 했다 다음으로 넘어가자
		runnable->excutables[i].envp[] = mp->envp;

	}
	free (pipe_split); // 여기까지 excutable 만들어서 text 옮겨닯기 끝, envp 주소도 넘겨줌

	// 그 다음은 excutable 마다 리디렉션을 들어내서 저장하는 것
	// 리디렉션을 들어낼 때에는 따옴표에 주의하여 들어내야 한다.


	// 이름을 뭘로 지을까 excutable_text_2_names
	// 토그나이저? 텍스트2토근? 명령어 분리? 
	i = -1;
	while (runnable->excutables[i])//excutable을 하나씩 순회하면서
	{
		struct s_excutable	*exc;
		// text를 읽고 거기에 있는 리다이렉션 부분을 인식해서 리다이렉션 부분으로 보내야 한다.
		// text를 읽을 때에는 따옴표를 주의하면서 읽는다.

		// while은 하나의 excutable 씩 던져준다.
		exc = &runnable->excutables[i];
		// 그럼 어떻게 해야 하는가
		// 따옴표는 시작부터 끝까지 하나의 단어라고 생각하고 달린다.
		// 달리다가 리다이렉션 연산자가 보이면 저장한다.(띄어쓰기 상관없이 발견되면 저장한다.)
		// 리다이렉션 연산자 다음에 있는것도 같이 저장한다
		// 저장한 것은 text에서 삭제한다.
		// 리다이렉션 연산자가 아닌 단어를 발견하면 excutable_path 에 저장한다.
		// 만약 excutable_path에 저장된 것이 있는데, 그런 것을 또 발견하면 무시한다.

	}



	//스플릿으로 나눈거 구겨담기 (공백문자 트림도 해서 구겨담자)
	//그리고 스플릿 목록은 이제 필요없으니 free
	
	while()





	//	collector(&trash_can, pipe_split);
	process_text(pipe_split);
		//$ variable conversion


	if 
}
*/


void find_quote(t_t2n t)
{
	t.j = 0;
	if (t.t[i] == '"')
		t.j = '"'
	else if (t.t[i] == '\'')
		t.j = '\''
	else
		return;
	while (t.t[++i])
	{
		if (t.t[i] == t.j)
			return;
	}
}

void find_redirection(t_t2n t)
{
		t.j = 0;
	if (ft_strcmp(&t.t[i], ">>", 2))

	else if (ft_strcmp(&t.t[i], "<<", 2))

	else if (ft_strcmp(&t.t[i], ">", 1))

	else if (ft_strcmp(&t.t[i], "<", 1))



}





// 이건 excutable을 하나 받아서 거기에 들어있는 text를 인식해서
// 명령어 부분이랑, 리다이렉션 부분을 나누어 준다. 리다이렉션은 가장 나중에 있는것을 사용한다.) + 리다이렉션이 있으면 파이프는 인풋은 무시한다.
int excutable_text_2_names(struct s_excutable excutables)
{
	excutables->text;
	excutables->excutables_path;
	excutables->argv;

	int i;
	int state;
	int word_start;
	char c;

	i = -1;
	state = 0;
	// state는 10의 자리별로 상태를 달리 정의하자
	// 0 == 그냥 달리면 되는 상태
	// 1 == 작은 따옴표 ' 가 인식된 상태 -> 다시 작은따옴표 ' 를 만날 떄 까지 공백문자 무시
	// 2 == 큰 따옴표 " 가 인식된 상태 -> 다시 큰 따옴표 ' 를 만날 때 까지 공백문자 무시
	// 00 == 그냥 달리면 되는 상태
	// 10 == >  가 인식된 상태 다음 단어는 >  와 함꼐 output_redirect로 옮겨간다.
	//			만약 바로 다음에 >를 만나면 상태를 30으로 바꾼다.
	// 20 == <  가 인식된 상태 다음 단어는 <  와 함꼐 input_redirect 로 옮겨간다.
	//			만약 바로 다음에 <를 만나면 상태를 40으로 바꾼다.
	// 30 == >> 가 인식된 상태 다음 단어는 >> 와 함꼐 output_redirect로 옮겨간다.
	// 40 == << 가 인식된 상태 다음 단어는 << 와 함꼐 input_redirect 로 옮겨간다.
	// 다른거 더 볼꺼 있나?
	// 000 == 평상시???
	// 100 == word 가 시작됨, word가 끝날 부분을 만나면 거기까지 해서 끝낸다.
	//	-> 시작부분은 어떻게 기록하지, 필요한 구조체를 하나 만들어서 사용할까?
	//	-> word 가 끝나야 하는지, 아닌지를 먼저 구분하는게 좋을까?
	//		-> 그럼 가장 먼저 구분해야 하는 것은 따옴표 안에 있는지 밖에 있는지이네
	//		-> 그 다음 따옴표 밖에 있으면 구분해야 하는 것이 예약어 정도겠군 "> >> < <<" 같은거 (이거뿐이지?)
	//		-> 음 시작하면 그게 바로 word의 시작부분이기도 하지 않을까?
	//		-> 아마 ft_substr함수를 자주 사용하게 되겠네
	// 그냥 100의 자리부터 통채로 startword의 위치를 기록하는 용도로 사용할까? 그럼 0부터 시작일때에는?
	// 간닷
	// word 가 끝나면 그건 어떻게 해야 하지? 그냥 표시만 하고 끝내?
	//	 -> 만약 그게 생  word이면 excutable_path에 넣은 다음에 확장하고 나눠서 argv에 담아야겠고
	//	 -> 생 word인데 이미 excutable_path가 차 있다면, 그건 무시해야겠고
	//	-> redirection word 였다면, input_redirect나 output_redirect에 들어가야겠지
	// 	-> 이 경우에 만약 존재하던게 있다면, 그건 무시하고 들어가야겠지
	// 음 단어 단위로 구분해서 split 하는 대신 단어와 단어 사이에 구분자를 넣어 놓을까?
	// 그럼 모든 단어는 일단 구분자로 구분되는거지, 그럼 결국은 재할당 해야 하나??
	// 그냥 split 해서 다룰까? 진짜 진빠지는데, word split/...


	struct s_text_2_name t;
	t.s = 0;
	t.ws = 0;

	while (excutables->text[++i])
	{
		t.c = excutables->text[i];
		if (t.s/10%10 == 0)//따옴표 상태가 아닌 상태
		{
			if (t.c == '>' || if t.c == '<')//화살표를 만난 상태, 다음 word와 함꼐, redirection으로 간다.
											//redirection인 것은 state로 표시, word의 시작은 ws로 표시, 지금까지 이어오던 word는 여기서 끝난다.
		}
		else//따옴표인 상태
		{
			
		}

	}









	while (excutables->text[++i])
	{
		c = excutables->text[i];
		if (!(state % 10 == 1 || state % 10 == 2) )
		// 작은 따옴표가 인식된 상태도 아니고, 큰 따옴표가 인식된 상태 (쿼트 안에 들어와 있지 않음)
		{
			// 그럼 이제 <, ", ', 새로운 word의 시작 같은것을 인식해야겠군
			// 그래 공백문자가 나오면 그게 word의 끝이지 word의 끝도 여기서 인식해야겟군
			if (c == '\'' || c == '\"')// 이것은 케릭터가 작은 따옴표이거나 큰 따옴표일떄
			{}
			if (c == '>' || c == '<')
			// 이것은 케릭터가 꺽쇠일때 (다음 케릭터가 꺽쇠이면 바로 처리할까? -> 그게 좋겟다.)
			{
				if (!(state/10%10 == 0))//이건 꺽쇠 처리중이라는 이야기잖아 -> 그럼 여기서 단어 끊어서 주고 


				if (c == excutables->text[i + 1])
				{
					state 
				}
			}
			if (state/10%10 == 1 || state/10%10 == 2)// 이건 > 또는 >> 상태인 것이군 (이건 리다이렉션을 만났을 떄 처리 안에 넣어야겠다.)
			{}

		}	
		else
		// 작은 따옴표 또는 큰 따옴표 내부에 있는 상태 (쿼트 상태인 경우)
		{
			if (state % 10 == 1 && excutables->text[i] == '\'')
				state -= 1;
			if (state % 10 == 2 && excutables->text[i] == '\"')
				state -= 2;
		}
		// 이게 word의 끝이면 < 이나 > 한테 넘겨야 하는거 아니야?
	}



	while

}

static	void	split_into_lists(t_list **lst, const char *format_string)
{
	const char	*cur;
	const char	*nxt;

	cur = format_string;
	while (cur[0])
	{
		nxt = ft_strchr(cur, '%');
		if (!nxt)
			return (ft_lstadd_back(lst, ft_lstnew(ft_strdup(cur))));
		if (nxt - cur != 0)
			ft_lstadd_back(lst, ft_lstnew(ft_substr(cur, 0, nxt - cur)));
		if (ft_strchr(g_cov_lst, nxt[1]) && nxt[1])
			ft_lstadd_back(lst, ft_lstnew(ft_substr(nxt, 0, 2)));
		else
			return (ft_lstclear(lst, free));
		cur = nxt + 2;
	}
}


int excutable_text_2_names(struct s_excutable excutables)
{
	t_list **lst;
	lst = &ft_lstnew(0);

	while()

	lst = &ft_lstnew(ft_substr(excutables->text, ws, ws-wn))



}




// 패턴 매칭 함수를 따로 만드는 것이 좋을까?
// 이거 만들어 놓으면, 파일 탐색할 때에도 쓸 수 있을까?


// char *패턴_리스트[] 를 만들어 놓고 
// char *패턴매칭(* char str) 을 한 다음에 패턴 리스트의 char 값을 주면
// 그러면 패턴 길이는 strlen해서 찾고
// 패턴 이름은 그냥 가져가서 쓰고 
// 그럼 그냥 찾을 때에도 패턴 리스트에서 찾아서 쓰지 그래
// char *패턴매칭(char ** 패턴리스트, char * str) 쓰면 되겠네
// 그럼 패턴 리스트랑 str가져다가 주면, 가장 가까운거 하나 넘기면 되겠다.
// 그럼 text_2_name에 사용할 패턴은 이렇게 만들면 되려나?
// 패턴 = {">", ">>", "<", "<<"}
// 이것만 매칭하면 되나?
// 그럼 파일 매칭하는거 조금 더 고민해서 만들어야겠다.
// text_2_name은 일단 패턴매칭 없이 그냥 짜 놓자
// 






int heardoc_manager(s_excutable excutables, int cmd);
{
	static int ()


}

//heredoc maker








t_e create_s_excutable();

int destroy_s_excutable();


t_r create_s_rannable();

int destroy_s_rannable();


t_c create_s_cammand();

int destroy_s_command();


t_mp create_s_minishell_program();

int destroy_s_minishell_program();










int excutable_text_2_names(struct s_excutable excutables)
{

	struct s_text_2_name *t;

	t = ft_calloc(sizeof(s_text_2_name), 1);
	t->t = excutables->text;
	t->i = -1;
	//excutables->argv;
	//excutables->input_redirect;
	//excutables->output_redirect;

	while(t->t[++i])
	{

	}


}





