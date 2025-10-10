# File name
NAME = libftprintf.a

# Directories
SRCDIR = srcs
INCDIR = include
LIBFTDIR = libft
OBJDIR = obj

# Source files
SRCS = 	$(SRCDIR)/ft_printf.c		\
		$(SRCDIR)/parse.c 			\
		$(SRCDIR)/ft_print_char.c	\
		$(SRCDIR)/ft_print_int.c	\
		$(SRCDIR)/ft_print_void.c

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# libft library
LIBFT = $(LIBFTDIR)/libft.a

# Chromatic gradient colors
C1 = \033[38;5;196m
C2 = \033[38;5;202m
C3 = \033[38;5;208m
C4 = \033[38;5;214m
C5 = \033[38;5;220m
C6 = \033[38;5;226m
C7 = \033[38;5;190m
C8 = \033[38;5;154m
C9 = \033[38;5;118m
C10 = \033[38;5;82m
C11 = \033[38;5;46m
C12 = \033[38;5;51m
C13 = \033[38;5;45m
C14 = \033[38;5;39m
C15 = \033[38;5;33m
C16 = \033[38;5;27m
C17 = \033[38;5;21m
C18 = \033[38;5;57m
C19 = \033[38;5;93m
C20 = \033[38;5;129m
RESET = \033[0m
GREEN = \033[0;32m
CYAN = \033[0;36m

CC = gcc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I$(INCDIR) -I$(LIBFTDIR)

all: $(LIBFT) $(NAME)
	@echo ""
	@echo "$(GREEN) ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄$(RESET)"
	@echo "$(GREEN)█  ✓✓ $(C2)C$(C3)o$(C4)m$(C5)p$(C6)i$(C7)l$(C8)a$(C9)t$(C10)i$(C11)o$(C12)n $(C13)s$(C14)u$(C15)c$(C16)c$(C17)e$(C18)s$(C19)s$(C20)f$(C1)u$(C2)l$(C3): $(C5)l$(C7)i$(C9)b$(C11)f$(C13)t$(C15)p$(C17)r$(C19)i$(C1)n$(C3)t$(C5)f$(C7).$(C9)a $(GREEN)✓✓  █$(RESET)"
	@echo "$(GREEN) ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀$(RESET)"
	@echo ""
# Compilation of libft
$(LIBFT):
	@echo "$(CYAN)⚙ Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFTDIR) all --no-print-directory
	@echo "$(GREEN)✓ libft compiled successfully$(RESET)"

# Creating the obj folder
$(OBJDIR):
	@echo "$(CYAN)⚙ Creating object directory...$(RESET)"
	@mkdir -p $(OBJDIR)

# Compilation of object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "$(CYAN)⚙ Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Creating the static library
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(CYAN)⚙ Creating archive $(NAME)...$(RESET)"
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)

clean:
	@echo "$(CYAN)⚙ Cleaning libft...$(RESET)"
	@$(MAKE) -C $(LIBFTDIR) clean --no-print-directory
	@echo "$(CYAN)⚙ Removing object files...$(RESET)"
	@$(RM) $(OBJDIR)
	@echo "$(GREEN)✓ Clean successful$(RESET)"

fclean: clean
	@echo "$(CYAN)⚙ Full clean libft...$(RESET)"
	@$(MAKE) -C $(LIBFTDIR) fclean --no-print-directory
	@echo "$(CYAN)⚙ Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Fclean successful$(RESET)"

re: fclean all

# Include dependency files
-include $(OBJS:.o=.d)

.PHONY: all clean fclean re