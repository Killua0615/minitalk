/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 05:27:30 by nateshim          #+#    #+#             */
/*   Updated: 2024/10/28 12:07:07 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numwords(char const *s, char c)
{
	int	i;
	int	word_num;

	i = 0;
	word_num = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			word_num++;
		i++;
	}
	return (word_num);
}

static void	free_all(char **result, int word)
{
	while (word > 0)
	{
		word--;
		free(result[word]);
	}
	free(result);
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int	start_cur;
	int	end_cur;

	end_cur = 0;
	start_cur = 0;
	while (s[end_cur])
	{
		if (s[end_cur] == c || s[end_cur] == 0)
			start_cur = end_cur + 1;
		if (s[end_cur] != c && (s[end_cur + 1] == c || s[end_cur + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (end_cur - start_cur + 2));
			if (!result[word])
			{
				free_all(result, word);
				return (0);
			}
			ft_strlcpy(result[word], (s + start_cur), end_cur - start_cur + 2);
			word++;
		}
		end_cur++;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

// int	main(void)
// {
// 	char *s = "hello world this is C";
// 	char delimiter = ' ';
// 	char **words = ft_split(s, delimiter);
// 	int i = 0;

// 	// 分割結果を表示
// 	printf("String split by delimiter '%c':\n", delimiter);
// 	while (words[i] != NULL)
// 	{
// 		printf("words[%d]: %s\n", i, words[i]);
// 		free(words[i]); // 各分割結果を解放
// 		i++;
// 	}
// 	free(words); // 配列全体を解放

// 	return (0);
// }