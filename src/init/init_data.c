/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:27:26 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/31 15:50:55 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// t_data *malloc_data(t_data *data)
// {
//     data = malloc (sizeof(t_data));
//     if (!data)
//         return (NULL);
//     return (data);
// }

// void init_data(t_data *data, char *str, t_env *env)
// {
//     data->start = 0;
//     data->end = 0;
//     data->node = NULL;
//     data->nb_tokens = 0;
//     data->nb_nodes = 0;
//     data->token = NULL;
//     data->is_space = false;
//     data->type_quote = '\0';
//     data->in_quote = 0;
//     data->str = trim_str(str);
//     data->env = env;
// }

t_data *malloc_and_init_data(char *str, t_env *env)
{
    t_data *data;
    
    data = malloc (sizeof(t_data));
    if (!data)
        return (NULL);
    data->start = 0;
    data->end = 0;
    data->node = NULL;
    data->nb_tokens = 0;
    data->nb_nodes = 0;
    data->token = NULL;
    data->is_space = false;
    data->type_quote = '\0';
    data->in_quote = 0;
    data->str = trim_str(str);
    data->env = env;
    return (data);
}