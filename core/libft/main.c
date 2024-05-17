
#include "libft.h"

void print_ls(t_list **lst) {
	t_list *current = *lst;
	size_t i = 0;

	while(current) {
		printf("digit: %i\n", *(int*) current->content);
		current = current->next;
	}
}

void del(void *val) {
	printf("VAL: %i\n", *(int *)val);
	free(val);
}


int main() {
	int *num = malloc(sizeof(int));
	*num = 0;
	t_list *headNode = ft_lstnew(num);
	for (int i = 1; i < 10000; i++) {
		num = malloc(sizeof(int));
		*num = i;
		ft_lstadd_back(&headNode, ft_lstnew(num));
	}

	// ft_lstadd_back(&headNode, headNode);
	print_ls(&headNode);
	ft_lstclear(&headNode, del);
	print_ls(&headNode);

	return (0);
}
