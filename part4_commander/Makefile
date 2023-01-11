G++			=	g++
##############################################
CORE_PATH	=	./core_commander
SRC_PATH	=	./sources
TST_PATH	=	./tests
INC_PATH	=	./includes

NAME		=	Commander
TEST_NAME 	= 	test_$(NAME)
##############################################
# CORE_PATH_FEDERATION	=	../part0_federation/core_federation
# SRC_PATH_FEDERATION		=	../part0_federation/sources
# TST_PATH_FEDERATION		=	../part0_federation/tests
# INC_PATH_FEDERATION		=	../part0_federation/includes
#############################################

INCFLAGS	+=	-I $(INC_PATH)
# -I $(INC_PATH_FEDERATION)
#LIBFLAG 	+=	-L

CPPFLAGS	+= -Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z


SRCS		=	$(SRC_PATH)/Federation.cpp \
				$(SRC_PATH)/WarpSystem.cpp \
				$(SRC_PATH)/Borg.cpp \
				$(CORE_PATH)/main_commander.cpp

SRC_TEST	=	$(TST_PATH)/$(NAME)_test.cpp

OBJS		=	$(SRCS:.cpp=.o)

CLEAN		=	clean
FCLEAN		=	fclean


all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM			=	rm -rf

clean		:
				$(RM) $(OBJS)
				@$(MAKE) $(CLEAN) -C $(TST_PATH)

fclean		:	clean
				$(RM) $(NAME) $(TEST_NAME)
				@$(MAKE) $(FCLEAN) -C $(TST_PATH)

re			: 	fclean all

tests_run	:	fclean
				@$(MAKE) -C $(TST_PATH)
				$(TST_PATH)/$(TEST_NAME)

.PHONY		: 	all clean fclean re tests_run

# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct