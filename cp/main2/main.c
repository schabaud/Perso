/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:40 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/12 14:29:07 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define QUIT "quit"
#define HELP "help"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 < *s2)
			return (*s1 - *s2);
		if (*s1 > *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int		ft_strlen(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

void	help()
{
	printf("usage : - file source\n\t- file dest\n\t- quit \"exit\"\n");
}

int		error(int sets, int exit)
{
	if (exit == sets)
		return (1);
	if (exit != sets)
		return (2);
	return (0);
}

int		main_file(char *file, char *dest)
{
	FILE *f_in, *f_out;
	int c;
	int mao;
	int	sets;

	mao = 0;
	sets = 0;
	while(file[sets] == QUIT[sets] && sets != ft_strlen(QUIT))
		sets++;
	while(file[mao] == HELP[mao] && mao != ft_strlen(HELP))
		mao++;
	if (sets == ft_strlen(QUIT))
		return (EXIT_SUCCESS);
	if (mao == ft_strlen(HELP))
		help();
	if (sets != ft_strlen(file) && mao != ft_strlen(file))
	{
		if ((f_in = fopen(file,"r")) == NULL)
		{
			fprintf(stderr, "Erreur: Impossible de trouver le fichier %s\n", file);
			return (EXIT_FAILURE);
		}
		if ((f_out = fopen(dest,"w")) == NULL)
		{
			fprintf(stderr, "\nErreur: Impossible de creer le fichier %s\n", \
					dest);
			return(EXIT_FAILURE);
		}
		while ((c = fgetc(f_in)) != EOF)
			fputc(c, f_out);
		fclose(f_in);
		fclose(f_out);
		return(EXIT_SUCCESS);
	}
	if (sets != ft_strlen(QUIT) && sets != ft_strlen(file))
	{
		if ((error(sets, ft_strlen(QUIT))) == 2)
			return (0);
		else
			return (0);
	}
	return(EXIT_SUCCESS);
}

void	options(char *str, char *str2)
{
	int index;

	index = 1;
	while (str[index] != '\0')
	{
		if (str[index] == 'f')
		{
			remove(str2);	
		}
		if (str[index] == 'R')
		{

		}
		if (str[index] == 'i')
		{
		}
		index++;
	}
	write(1, "6", 1);
}

int		main(int ac, char **av)
{
	if (ac != 3 && av[1][0] != '-')
		help();
	else
	{
		if (av[1][0] == '-')
		{
			options(av[1], av[3]);
			main_file(av[2], av[3]);
		}
		else
			main_file(av[1], av[2]);
	}
	return (0);
}
