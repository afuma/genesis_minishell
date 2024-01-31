/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:25:56 by blax              #+#    #+#             */
/*   Updated: 2024/02/01 00:05:11 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_valid_varname_expand(char c)
{
		return (ft_isalpha(c) || c == '?');
}

char* expand_variables(t_env *env, char *str)
{
	char *result;

	result = ft_strdup("");
	while (*str)
	{
		if (*str == '$')
		{
			if (*(str + 1) == '\0')
			{
				free(result);
				return (ft_strdup("$"));
			}
			if (is_valid_varname_expand(*(str + 1)))
				result = process_dollar_sign(env, &str, result);
			else
				return (result);
		}
		else
			result = process_text_until_next_dollar(&str, result);
	}

	return (result);
}

char* process_dollar_sign(t_env *env, char **str, char *result)
{
		char *temp;
		char *var_name;

		(*str)++;
		var_name = extract_var_name(str);
		temp = append_variable_value(env, result, var_name);
		free(result);
		result = NULL;
		free(var_name);
		var_name = NULL;

		return (temp);
}

char* process_text_until_next_dollar(char **str, char *result)
{
	char *next_dollar;
	char *temp;

	if (**str == '$')
		next_dollar = ft_strchr(*(str + 1), '$');
	else
		next_dollar = ft_strchr(*str, '$');
	if (!next_dollar)
		next_dollar = *str + ft_strlen(*str);
	temp = copy_until_char(result, *str, *next_dollar);
	free(result);
	result = NULL;
	*str = next_dollar;

	return (temp);
}
