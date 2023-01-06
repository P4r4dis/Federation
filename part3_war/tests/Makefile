G++				=	g++
#############################################
SRC_PATH		=	../sources
INC_PATH		=	../includes/

TESTS_SRC_PATH	=	./tests_sources/
TESTS_INC_PATH	=	./tests_includes/

NAME			=	test_War
#############################################
# CORE_PATH_FEDERATION	=	../../part0_federation/core_federation
# SRC_PATH_FEDERATION		=	../../part0_federation/sources
# TST_PATH_FEDERATION		=	../../part0_federation/tests
# INC_PATH_FEDERATION		=	../../part0_federation/includes
###############################################################
INCFLAGS		+=	-I$(TESTS_INC_PATH) -I$(INC_PATH)
# -I$(INC_PATH_FEDERATION)
CRITFLAGS		+=	--coverage -lcriterion --verbose
CPPFLAGS		+=	-Wall -Wextra -Werror $(INCFLAGS) $(CRITFLAGS)


SRCS			=	test_war.cpp \
					$(TESTS_SRC_PATH)/test_sources.cpp


OBJS			=	$(SRCS:.cpp=.o)
OBJS_GCDA		=	$(SRCS:.cpp=.gcda)
OBJS_GCNO		=	$(SRCS:.cpp=.gcno)


all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM				=	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO)
					$(RM) $(TESTS_SRC_PATH)$(OBJS) $(TESTS_SRC_PATH)$(OBJS_GCDA) $(TESTS_SRC_PATH)$(OBJS_GCNO)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re