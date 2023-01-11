G++						=	g++
###############################################
PART0_PATH 				= 	./part0_federation
PART0_SRC_PATH			=	./part0_federation/sources
PART0_TST_PATH			=	./part0_federation/tests
PART0_INC_PATH			=	./part0_federation/includes
NAME_FEDERATION			=	Federation

PART0_SRC				=	$(PART0_SRC_PATH)/Federation.cpp \
							$(PART0_SRC_PATH)/WarpSystem.cpp
PART0_SRC_TEST			=	$(PART0_TST_PATH)/$(NAME_FEDERATION)_test.cpp
TEST_NAME_FEDERATION 	= 	test_$(NAME_FEDERATION)
###############################################
PART1_PATH 				= 	./part1_borg
PART1_SRC_PATH			=	./part1_borg/sources
PART1_TST_PATH			=	./part1_borg/tests
PART1_INC_PATH			=	./part1_borg/includes
NAME_BORG				=	Borg

PART1_SRC				=	$(PART1_SRC_PATH)/Borg.cpp
PART1_SRC_TEST			=	$(PART1_TST_PATH)/$(NAME_BORG)_test.cpp
TEST_NAME_BORG 			= 	test_$(NAME_BORG)

###############################################
PART2_PATH 				= 	./part2_move
PART2_SRC_PATH			=	./part2_move/sources
PART2_TST_PATH			=	./part2_move/tests
PART2_INC_PATH			=	./part2_move/includes
NAME_MOVE				=	Move

PART2_SRC				=	$(PART2_SRC_PATH)/Federation.cpp \
							$(PART2_SRC_PATH)/WarpSystem.cpp \
							$(PART2_SRC_PATH)/Borg.cpp
PART2_SRC_TEST			=	$(PART1_TST_PATH)/$(NAME_MOVE)_test.cpp
TEST_NAME_MOVE 			= 	test_$(NAME_MOVE)

###############################################
PART3_PATH 				= 	./part3_war
PART3_SRC_PATH			=	./part3_war/sources
PART3_TST_PATH			=	./part3_war/tests
PART3_INC_PATH			=	./part3_war/includes
NAME_WAR				=	War

PART3_SRC				=	$(PART3_SRC_PATH)/Federation.cpp \
							$(PART3_SRC_PATH)/WarpSystem.cpp \
							$(PART3_SRC_PATH)/Borg.cpp
PART3_SRC_TEST			=	$(PART3_TST_PATH)/$(NAME_WAR)_test.cpp
TEST_NAME_WAR 			= 	test_$(NAME_WAR)

###############################################
PART4_PATH 				= 	./part4_commander
PART4_SRC_PATH			=	./part4_commander/sources
PART4_TST_PATH			=	./part4_commander/tests
PART4_INC_PATH			=	./part4_commander/includes
NAME_COMMANDER			=	Commander

PART4_SRC				=	$(PART4_SRC_PATH)/Federation.cpp \
							$(PART4_SRC_PATH)/WarpSystem.cpp \
							$(PART4_SRC_PATH)/Borg.cpp
PART4_SRC_TEST			=	$(PART4_TST_PATH)/$(NAME_COMMANDER)_test.cpp
TEST_NAME_COMMANDER 	= 	test_$(NAME_COMMANDER)

###############################################
PART5_PATH 				= 	./part5_exam
PART5_SRC_PATH			=	./part5_exam/sources
PART5_TST_PATH			=	./part5_exam/tests
PART5_INC_PATH			=	./part5_exam/includes
NAME_EXAM				=	Exam

PART5_SRC				=	$(PART4_SRC_PATH)/exam.cpp

PART5_SRC_TEST			=	$(PART4_TST_PATH)/$(NAME_EXAM)_test.cpp
TEST_NAME_EXAM 			= 	test_$(NAME_EXAM)

###############################################
CORE_PATH				=	./core
# SRCS_PATH				=	$(PART2_SRC)
# $(PART0_SRC_PATH)
# $(PART1_SRC_PATH)
# $(PART2_SRC_PATH)
# $(PART3_SRC_PATH)
# $(PART4_SRC_PATH)
# $(PART5_SRC_PATH)


# TST_PATH				=	$(PART0_TST_PATH)
# 							$(PART1_TST_PATH)
# 							$(PART2_TST_PATH)
# $(PART3_TST_PATH)
# $(PART4_TST_PATH)
# $(PART5_SRC_PATH)

NAME					=	a.out
TEST_NAME 				= 	test_$(NAME)

#INC_PATH 			= 	$(PART0_INC_PATH)
#$(PART2_INC_PATH)
INCFLAGS				+=	-I $(PART0_INC_PATH) -I $(PART1_INC_PATH) -I $(PART2_INC_PATH) -I $(PART3_INC_PATH) -I $(PART4_INC_PATH) -I $(PART5_INC_PATH)
# -I $(PART2_INC_PATH) -I $(PART3_INC_PATH) -I $(PART4_INC_PATH) -I $(PART5_INC_PATH)
#$(INC_PATH)

CPPFLAGS				+= 	-Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS 					= 	$(PART4_SRC) \
							$(CORE_PATH)/main.cpp
							


# $(PART0_SRC)
# $(PART1_SRC)
# $(PART2_SRC)
# $(PART3_SRC)
# $(PART4_SRC)
# $(PART5_SRC)
						
#$(PART2_SRC)

# SRC_TEST 				= 	$(PART0_SRC_TEST)
# $(PART2_SRC_TEST)
# $(PART3_SRC_TEST)
# $(PART4_SRC_TEST)
# $(PART5_SRC_TEST)

OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(G++) $(OBJS) $(CPPFLAGS)
#$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM						=	rm -rf

clean					:
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART2_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART3_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART4_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART5_TST_PATH)


fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART3_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART3_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART4_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART4_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART5_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART5_PATH)

re						: 	fclean all

part0 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_FEDERATION)

part1 					: 	fclean
							@$(MAKE) -C $(PART1_PATH)
							$(PART1_PATH)/$(NAME_BORG)

part2 					: 	fclean
							@$(MAKE) -C $(PART2_PATH)
							$(PART2_PATH)/$(NAME_MOVE)

part3 					: 	fclean
							@$(MAKE) -C $(PART3_PATH)
							$(PART3_PATH)/$(NAME_WAR)

part4 					: 	fclean
							@$(MAKE) -C $(PART4_PATH)
							$(PART4_PATH)/$(NAME_COMMANDER)

tests_run_part0			:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_FEDERATION)

tests_run_part1			:	fclean
							@$(MAKE) -C $(PART1_TST_PATH)
							$(PART1_TST_PATH)/$(TEST_NAME_BORG)

tests_run_part2			:	fclean
							@$(MAKE) -C $(PART2_TST_PATH)
							$(PART2_TST_PATH)/$(TEST_NAME_MOVE)

tests_run_part3			:	fclean
							@$(MAKE) -C $(PART3_TST_PATH)
							$(PART3_TST_PATH)/$(TEST_NAME_WAR)

tests_run_part4			:	fclean
							@$(MAKE) -C $(PART4_TST_PATH)
							$(PART4_TST_PATH)/$(TEST_NAME_COMMANDER)

tests_run				:	fclean
							@$(MAKE) tests_run_part0
							@$(MAKE) tests_run_part1
							@$(MAKE) tests_run_part2
							@$(MAKE) tests_run_part3
							@$(MAKE) tests_run_part4


.PHONY					: 	all clean fclean re part0 tests_run_part0 part1 tests_run_part1 part2 tests_run_part2 part3 tests_run_part3 part4 tests_run_part4 tests_run
#part2 tests_run_part2 part3 tests_run_part3 part4 tests_run_part4 tests_run

# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct