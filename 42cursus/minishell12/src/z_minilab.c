typedef struct s_token
{
	char	*str;
	int		type;
	/*
	**	type
	**		0 : toeknstart
	**		1 : operator
	**		2 : word
	**		99 : tokenend
	*/


}t_token;



process_command(mp)
{
	tokenize(mp) -> tokenlist;
	//parse_structure(); 				for bonus
	pre_process_cmd(mp/*->runnable*/);
		// $ variable conversion
	cmd_to_structure(mp/*->runnable*/);
		//
	run_commands_in_order(mp/*->command*/)	
	
	post_process(mp/*->command*/)
		// heredoc << redirection x;
	//processing...
}



process_command(mp)
{
	tokenize(mp) -> tokenlist;
	make_structure(mp);
	expension(mp)
	redirect(mp)

}



void tokenize(t_mp *mp)
{
	t_mbox	trash_can;
	t_mbox	*token_box;
	char	**command;

	collector(trash_can, 0);

    trash_can.cur = 0;	
    *token_box.cur = 0;	

	command mp->command.text;
	while 



	collector(trash_can, 0);
}