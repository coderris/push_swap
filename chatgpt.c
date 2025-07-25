void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
void	s(t_stack *stack, char *c)
{
	if (stack->next)
		swap(&stack->content, &stack->next->content);
	ft_printf("s%c\n",c);
}
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->next)
		swap(&stack_a->content, &stack_a->next->content);
	if (stack_b->next)
		swap(&stack_b->content, &stack_b->next->content);
	ft_printf("ss\n");
}
void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	if (stack_b && *stack_b)
	{
		aux = *stack_b;
		*stack_b = (*stack_b)->next;
		aux->next = *stack_a;
		*stack_a = aux;
	}
}
void	p(t_stack **stack_1, t_stack **stack_2, char *c)
{
	push(stack_1, stack_2);
	ft_printf("p%c\n", c);
}
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}
void 	r(t_stack **stack, char *c)
{
	rotate(stack);
	ft_printf("r%c\n", c);
}
void 	rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
void	reverse_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	prev = NULL;	
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
void 	rr(t_stack **stack, char *c)
{
	reverse_stack(stack);
	ft_printf("rr%c\n", c);
}
void	reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	reverse_stack(stack_a);
	reverse_stack(stack_b);
	ft_printf("rrr\n");
}

void	sort_three(t_stack **stack)
{
	int	a = (*stack)->content;
	int	b = (*stack)->next->content;
	int	c = (*stack)->next->next->content;

	if (a > b && b < c && a < c)
		s(*stack, "a");
	else if (a > b && b > c)
	{
		s(*stack, "a");
		r(stack, "a");
	}
	else if (a > b && b < c && a > c)
		r(stack, "a");
	else if (a < b && b > c && a < c)
	{
		s(*stack, "a");
		r(stack, "a");
	}
	else if (a < b && b > c && a > c)
		rr(stack, "a");
}
void	sort_five(t_stack **a, t_stack **b)
{
    int size;
    
    size = ft_stacksize(*a);
	while (size > 3)
	{
		move_min_to_top(a);
		p(b, a, "b");
	}
	sort_three(a);
	p(a, b, "a");
	p(a, b, "a");
}
void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	max_bits = 0;
	int	i = 0;
	int	j;


	while ((size - 1) >> max_bits)
		max_bits++;

	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->idx >> i) & 1)
				r(a, "a");
			else
				p(b, a, "b");
			j++;
		}
		while (*b)
			p(a, b, "a");
		i++;
	}
}

int		ft_valid_input(char **splited_values)
{
	int	i;

	i = 0;
	while (splited_values[i])
	{
		if (ft_valid_int(splited_values[i]))
			return (1);
		i++;
	}
	return (0);
}
int	ft_valid_int(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}
int	ft_duplicates(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_val_size(char **values)
{
	int	i;

	i = 0;
	while (values[i])
		i++;
	return (i);
}
void	fast_ord(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 1)
		exit(1);
	else if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			s(*stack_a, "a");
	}
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, stack_b);
}
void	assign_indexes(t_stack *stack, int *values, int size)
{
	int		*sorted;
	int		i;
	int		j;
	int		k;
	int		temp;
	t_stack	*tmp;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		exit(1);
	i = 0;
	while (i < size)
	{
		sorted[i] = values[i];
		i++;
	}
	j = 0;
	while (j < size - 1)
	{
		k = 0;
		while (k < size - j - 1)
		{
			if (sorted[k] > sorted[k + 1])
			{
				temp = sorted[k];
				sorted[k] = sorted[k + 1];
				sorted[k + 1] = temp;
			}
			k++;
		}
		j++;
	}
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == sorted[i])
			{
				tmp->idx = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(sorted);
}


int	main(int argc, char** argv)
{
	char	**splited_values;
	int		*values;
	int		values_size;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	splited_values = ft_fill_stack(argc - 1, argv + 1);
	values_size = ft_val_size(splited_values);
	if(argc >= 2)
	{
		if (ft_valid_input(splited_values) == 1)
			ft_error_exit();
		values = (int *)ft_to_int(splited_values, values_size);
		ft_free_split(splited_values);
		if (ft_duplicates(values, values_size))
			ft_error_exit();
		stack_creation(values, values_size, &stack_a);
		assign_indexes(stack_a, values, values_size);
		if(its_ordered(stack_a))
			exit(1);
		size = ft_stacksize(stack_a);
		if (size <= 5)
			fast_ord(&stack_a, &stack_b, size);
		else
			radix_sort(&stack_a, &stack_b, size);
	}
	return (0);
}

char	**ft_fill_stack(int arguments, char **values)
{
	int	i;
	char	**list;
	char	**result;

	i = 0;
	result = NULL;
	while (i < arguments)
	{
		list = ft_split(values[i], ' ');
		if (!list)
			exit (1);
		result = ft_strjoin_array(result, list);
		ft_free_split(list);
		i++;
	}
	return (result);
}
char	**ft_strjoin_array(char **old_result, char **list)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	**result;

	i = 0;
	j = 0;
	len1 = ft_count_strings(old_result);
	len2 = ft_count_strings(list);
	result = (char **)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!result)
		exit(1);
	while (i < len1)
	{
		result[i] = ft_strdup(old_result[i]);
		i++;
	}
	while (j < len2)
	{
		result[i + j] = ft_strdup(list[j]);
		j++;
	}
	result[i + j] = NULL;
	ft_free_split(old_result);
	return (result);
}
t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->idx = -1;
	new->next = NULL;
	return (new);
}
void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
void	stack_creation(int *values, int	size, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_stackadd_back(stack_a, ft_stacknew(values[i]));
		i++;
	}
}

int		ft_count_strings(char **arr)
{
	int	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
long	ft_atoi_safe(char *str)
{
	long	sign;
	long	result;
	long	final;

	result = 0;
	sign = 1;
	if (!str)
		exit(1);
	if (*str == '-')
	{
		sign = (-1) * sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	final = result * sign;
	if (final > INT_MAX || final < INT_MIN)
		ft_error_exit();
	return (final);
}
int		*ft_to_int(char **values, int size)
{
	int	i;
	int	*result;

	i = 0;
	result = (int *)malloc(sizeof(int) * (size + 1));
	if (!result)
		exit(1);
	while(values[i])
	{
		result[i] = ft_atoi_safe(values[i]);
		i++;
	}
	return (result);
}
void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
int		its_ordered(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int		ft_stacksize(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
void	move_min_to_top(t_stack **a)
{
	int		pos;
	int		min_pos;
	int		size;

	size = ft_stacksize(*a);
	min_pos = get_min_position(*a);
	pos = 0;

	if (min_pos <= size / 2)
	{
		while (pos++ < min_pos)
			r(a, "a");
	}
	else
	{
		while (pos++ < size - min_pos)
			rr(a, "a");
	}
}

int get_min_position(t_stack *stack)
{
	int pos = 0;
	int min_pos = 0;
	int min_index;

	if (!stack)
		return -1;

	min_index = stack->idx;
	while (stack)
	{
		if (stack->idx < min_index)
		{
			min_index = stack->idx;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return min_pos;
}

