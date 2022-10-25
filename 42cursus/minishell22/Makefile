############ PRESET #############

	############ PARAMETER #############

		PRESET_CFLAGS_FOR_SUBMIT	= -Wall -Wextra -Werror
		PRESET_CFLAGS_FOR_DEBUG		= -Wall -Wextra -Werror -g
		PRESET_CFLAGS_FOR_ASAN		= -Wall -Wextra -Werror -g -g3 -fsanitize=address
		PRESET_CFLAGS_FOR_MSAN		= -Wall -Wextra -Werror -o -g3 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
		PRESET_CFLAGS_FOR_TESTING	= -g
		PRESET_CFLAGS_FOR_TEST_MSAN	=  -g -g3 -fsanitize=address


############ CONTROLS #############

	############ DIRECTORISES AND LIBRARYS #############

		SOURCE_DIR		= ./src
		OBJECT_DIR		= ./obj
		SCR_BNS_DIR		= ./src_bonus
		INCLUDE_DIR		= ./include
		INC_BNS_DIR		= ./include_bonus
		LIBRARY_DIR		= ./lib

		############ LIBRARYS AND FRAMEWORK #############

			LIBFT_DIR	= libft
			LIBFT_NAME	= ftprintf
			LIBFT_TYPE	= .a
			LIBFT_FRWK	= 

			LIBRD_DIR	= $(shell brew --prefix readline)
			LIBRD_NAME	= readline
			LIBRD_TYPE	= 
			LIBRD_FRWK	= 



	############ PARAMETER #############

		CC			:= gcc
		CFLAGS		:= $(PRESET_CFLAGS_FOR_DEBUG)
		INCLUDE		:= -I$(INCLUDE_DIR) -I$(LIBRARY_DIR) -I$(LIBRARY_DIR)/$(LIBFT_DIR)  -I$(LIBRD_DIR)/include/
		INCLUDE_B	:= -I$(INC_BNS_DIR) -I$(LIBRARY_DIR) -I$(LIBRARY_DIR)/$(LIBFT_DIR)  -I$(LIBRD_DIR)/include/
		AR			= ar
		ARFLAGS		= -rcv
		DB			= lldb
		DBFLAGS		= 
		MAKE		= make


	############ NAME FOR OUTCOMES #############

		SERVER_NAME = checker_not_use
		CLIENT_NAME = minishell
		TEST_NAME	= test
		
		BONUS_SERVER_NAME = checker
		BONUS_CLIENT_NAME = minishell_bonus

		############ SUBMISSION #############

			SUBMISSION_NAME =	$(CLIENT_NAME)
			
			SUB4_BONUS_NAME =	$(BONUS_SERVER_NAME)	\

			
			NOT_SUBMIT_NAME	=	$(TEST_NAME)			\
								$(SERVER_NAME)			\
								$(BONUS_CLIENT_NAME)
								#$(BONUS_SERVER_NAME)	\


	############ SOURCES #############

		SERVER =	checker
		CLIENT =	a_0_minishell		\
					

		TEST   =	test 			\
					n_1				\
					n_2				\
					n_3				\
					c_assets			\
					c_memory_manage		\
					c_const_dest		\
					

		ASSET  =	a_1_initialize		\
					a_2_prompt			\
					a_3_parse			\
					m_1					\
					n_1					\
					n_1_util1			\
					n_1_util2			\
					n_2					\
					n_2_util			\
					n_3					\
					n_4					\
					n_4_util			\
					c_assets			\
					c_assets_util		\
					c_memory_manage		\
					c_const_dest		\
					c_const_dest_util	\
					exec				\
					exec_util			\
					ft_cd				\
					ft_echo				\
					ft_env				\
					ft_export			\
					ft_pwd				\
					ft_unset			\
					ft_exit				\
					pipes				\
					pipes_util			\
					set_exec			\

		#ASSET  =	a_initialize		\
					a_prompt			\
					b0_parse			\
					b1_split_into_excutables			\
					b2_parse_excutables			\
					b3_expansion			\
					c_memory_manage	\
					c_const_dest		\
					c_assets			\
					c_exit_by_error	\
					x_excutable_tokenize\
					x_variable_expansion	\
					x_path_list_interpret	\
				 

				 
############ VARIABLES #############

	############ NAMES ############# : ALL CATEGRORY OF "CONTROLS / NAME FOR OUTCOMES / SUBMISSION"

		EVERYTHING_NAME = $(SUBMISSION_NAME) $(SUB4_BONUS_NAME) $(NOT_SUBMIT_NAME)

	############ DIRECTORISES AND LIBRARYS ############# : add '/' for post usage"

		SRC_DIR		= $(SOURCE_DIR)/
		OBJ_DIR		= $(OBJECT_DIR)/
		BNS_DIR		= $(SCR_BNS_DIR)/
		BIC_DIR		= $(INC_BNS_DIR)/
		LIB_DIR		= $(LIBRARY_DIR)/
		LIB_NAME	= $(LIBRARY_NAME)
		LIBS_NAME	= $(addprefix -l, $(LIBRARY_NAME))

	############ OBJECT & LIBRARY & FRAMEWORK ############# : every source for each target

		SERVER_OBJ	= $(addprefix $(OBJ_DIR),$(addsuffix .o,	$(SERVER)	$(ASSET)))
		CLIENT_OBJ	= $(addprefix $(OBJ_DIR),$(addsuffix .o,	$(CLIENT)	$(ASSET)))
		TEST_OBJ	= $(addprefix $(OBJ_DIR),$(addsuffix .o,	$(TEST)		$(ASSET)))

		SERVER_LIB	= $(addprefix -l,	$(LIBFT_NAME) $(LIBGNL_NAME))
		CLIENT_LIB	= $(addprefix -l,	$(LIBFT_NAME) $(LIBRD_NAME))
		TEST_LIB	= $(addprefix -l,	$(LIBFT_NAME) $(LIBRD_NAME))

		SERVER_FRW	= $(addprefix -framework ,	$(LIBFT_FRWK) $(LIBGNL_FRWK))
		CLIENT_FRW	= $(addprefix -framework ,	$(LIBFT_FRWK) $(LIBRD_FRWK))
		TEST_FRW	= $(addprefix -framework ,	$(LIBFT_FRWK) $(LIBGNL_FRWK)) 

		#--- BONUS ---#

		BONUS_SERVER_OBJ	= $(addprefix $(OBJ_DIR),$(addsuffix  _bonus.o,	$(SERVER)	$(ASSET)))
		BONUS_CLIENT_OBJ	= $(addprefix $(OBJ_DIR),$(addsuffix  _bonus.o,	$(CLIENT)	$(ASSET)))

	############ LIBRARY #############

		LIBFT	= $(LIB_DIR)$(LIBFT_DIR)/lib$(LIBFT_NAME)$(LIBFT_TYPE)
		LIBGNL	= $(LIB_DIR)$(LIBGNL_DIR)/lib$(LIBGNL_NAME)$(LIBGNL_TYPE)


#################### OUTPUT RULES ####################



#=============== TARGET RULES ===============#

#-------- Make want  --------#

all : mandatory

#-------- COMPILE AND RUN --------#

srun : $(SERVER_NAME)
	./$(SERVER_NAME)

crun : $(CLIENT_NAME)
	./$(CLIENT_NAME)

lldb : $(CLIENT_NAME)
	lldb ./$(CLIENT_NAME)

trun : $(TEST_NAME)
	./$(TEST_NAME)


#-------- COMPILE TARGET --------# : ALL MATCHES WITH "CONTROLS / NAME FOR OUTCOMES"

mandatory : $(SUBMISSION_NAME)

bonus : $(SUB4_BONUS_NAME)

$(SERVER_NAME) : $(LIB) $(SERVER_OBJ) $(LIBFT) $(LIBGNL)
	@ $(CC) $(CFLAGS) $(INCLUDE)	\
	-L./$(LIB_DIR)$(LIBFT_DIR) -L./$(LIB_DIR)$(LIBGNL_DIR) -L$(LIBRD_DIR)/lib/	\
	-o $@ $^		\
	$(SERVER_LIB)	\
	$(SERVER_FRW)	

$(CLIENT_NAME) : $(CLIENT_OBJ) $(LIBFT)
	@ $(CC) $(CFLAGS) $(INCLUDE)	\
	-L./$(LIB_DIR)$(LIBFT_DIR) -L$(LIBRD_DIR)/lib/	\
	-o $@ $^		\
	$(CLIENT_LIB)	\
	$(CLIENT_FRW)	
	

$(TEST_NAME) : $(LIB) $(TEST_OBJ)  $(LIBFT)
	@ $(CC) $(CFLAGS) $(INCLUDE)	\
	-L./$(LIB_DIR)$(LIBFT_DIR) -L$(LIBRD_DIR)/lib/	\
	-o $@ $^		\
	$(TEST_LIB)	\
	$(TEST_FRW)
	
#--- BONUS ---#

$(BONUS_SERVER_NAME) : $(LIB) $(BONUS_SERVER_OBJ) $(LIBFT)
	@ $(CC) $(CFLAGS) $(INCLUDE_B)	\
	-L./$(LIB_DIR)$(LIBFT_DIR) -L./$(LIB_DIR)$(LIBGNL_DIR) 	-L$(LIBRD_DIR)/lib/\
	-o $@ $^		\
	$(SERVER_LIB)	\
	$(SERVER_FRW)	

$(BONUS_CLIENT_NAME) : $(LIB) $(BONUS_CLIENT_OBJ)	
	$(CC) $(CFLAGS) $(INCLUDE_B) -L$(LIB_DIR) $(LIB_NAME) -o $@ $^


#=============== MAINTENANCE RULES ===============#

#-------- COMPILE LIBRARY --------#


$(LIBFT) : libft_check
	@echo 1 > /dev/null

libft_check : 
	make -C $(LIB_DIR)$(LIBFT_DIR) all


#-------- COMPILE OBJ_FILES --------#

$(OBJ_DIR)%_bonus.o : $(BNS_DIR)%_bonus.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_B) -c $< -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@



#=============== BASIC RULES ===============#

#-------- REQUIREMENT --------#

clean :
	rm -f $(OBJ_DIR)*
	make -C $(LIB_DIR)$(LIBFT_DIR) clean

fclean : clean
	make -C $(LIB_DIR)$(LIBFT_DIR) fclean
	rm -f $(EVERYTHING_NAME)

re : 
	$(MAKE) fclean
	@echo 1 > /dev/null
	$(MAKE) all

#=============== PHONY RULES ===============#

.PHONY :	all							\
			srun	crun	trun		\
			mandatory		bonus		\
			lib_check		libft_check			lldb	\
		 	clean	fclean	re			\
