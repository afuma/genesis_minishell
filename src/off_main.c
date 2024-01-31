/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   off_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:26:34 by blax              #+#    #+#             */
/*   Updated: 2024/01/31 22:54:16 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool ft_main(char *command, t_env *env)
{
	t_node *first_node;
	t_data *data;
	
    data = malloc_and_init_data(command, env);
    if (!data)
        return (perror("malloc failed"), false);
    if (!is_closed_quotes(data))
    	return (free_all(data), perror("unclosed quotes"), false);
    ft_lexer(data);
    if (!data->token)
		return (free_all(data), false);
    determine_token_types(data);
    if (!verif_syntax(data->token))
        return (free_all(data), perror("syntax_erreur"), false);
    if (!pass_on_filters(data))
		return (free_all(data), perror("filter_erreur"), false);
    parser(data);
	free_tokens(data->token);
	data->token = NULL;
	free(data->str);
	data->str = NULL;
	first_node = data->node;
	data->node = NULL;
	free(data);
	data = NULL;
	execute_command_node(first_node, env);
    return (true);
}

int	main(int argc, char *argv[], char **env)
{
	t_env	*my_env;
    char command[1024] = "";
    int i;
        
	if (argc > 500)
		return (printf("minishell : parameters : bad usage\n"), 0);
	my_env = NULL;
	argv[0] = '\0';
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	if (!env || !env[0])
		my_env = init_mini_env();
	else
		my_env = init_env(env);
	update_shlvl(my_env);
    for (i = 1; i < argc; i++)
    {
        if (i != 1)
            strcat(command, " ");
        strcat(command, argv[i]);
    }
	ft_main(command, my_env);
	free_env(my_env);
	return (0);
}