	while (stack_b->size != 0)
	{
		p_max = find_greater_pos(stack_a);
		p_min = find_smaller_pos(stack_a);
		if (stack_b->first->data < stack_a->first->data && stack_a->first->data > p_min.value)
			ft_rotate(stack_a, 'a');
		else if (stack_b->first->data > p_max.value)
			ft_pa(stack_a, stack_b);

	}




		if (stack_b->first->data > p_max.value || stack_b->first->data < p_min.value)
		{
			if ((p_max.pos == stack_a->size) && (p_min.pos == 1))
				ft_pa(stack_a, stack_b);
			else if (p_max.pos < (stack_a->size / 2) + 1)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}
		else
		{
			p_max = find_position(stack_a, stack_b->first->data);
			if (p_max.pos == 1)
			{
				ft_pa(stack_a, stack_b);
				if (stack_b->first->data < stack_b->first->next->data)
					ft_double_swap(stack_a, stack_b);
				else
					ft_swap(stack_a, 'a');
			}
			else if (p_max.pos == stack_a->size)
				ft_pa(stack_a, stack_b);
			else if (p_max.pos < (stack_a->size / 2) + 1)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}