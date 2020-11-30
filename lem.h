/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:31:07 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 21:59:53 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft.h"

/*
**		Структура для комнат
**
**		name - название комнаты
**		coord_x, coord_y - координаты комнаты
**		steps - 
**		ants - наличие муравьев в комнате
*/

typedef struct		s_room {
	char			*name;
	int				coord_x;
	int				coord_y;
	int				steps;
	int				ant;
}					t_room;

/*
**		Структура для оценки графа
**		(проверка валидности входных данных)
**
**		a - проверка первичных данных
**		s - старт графа
**		r - количество комнат
**		e - конец графа
**		l - соединение между комнатами
**		c - комментарий
**		o - комментарии, не доступные к выводу	
*/

typedef struct		s_lst {
	char			*cont;
	char			a;
	char			s;
	char			r;
	char			e;
	char			l;
	char			c;
	char			o;
	struct s_lst	*next;
}					t_lst;

/*
**		Структура для прохождения пути
**		
**		len - длина пути
**		rooms - комнаты графа
**		ants_num - кол-во муравьев
*/

typedef struct		s_path {
	int				len;
	t_room			**rooms;
	int				ants_num;
}					t_path;

/*
**		Структура для списка путей
**		
**		next - ссылка следующий путь
*/

typedef struct		s_lst_paths {
	t_path				*path;
	struct s_lst_paths	*next;
}					t_lst_paths;

/*
**		Основная структура для работы проекта lem-in
**
**		num_of_ants - количество муравьев на начале графа
**		num_of_rooms - количество комнат (нод) в графе
**		rooms - массив комнат графа (см. t_room)
**		matrix - массив (????)
**		paths - пути графа (см. t_lst_paths)
**		list - оценка графа (см. t_lst)
*/


typedef struct		s_lem {
	int				num_of_ants;
	int				num_of_rooms;
	t_room			**rooms;
	int				**matrix;
	t_lst_paths		*paths;
	t_lst			*list;
}					t_lem;

/*
**		Структура для проверки валидности входных данных
**				(карты)
**
**		(???)
**
**
**
*/

typedef struct		s_valid_info {
	int				s;
	int				e;
	int				l;
	int				c;
	int				o;
	int				rs;
	int				re;
}					t_valid_info;

/*
** 					______________Функции парсинга проекта______________
*/

t_lem				*parse();
t_lst				*preparse();
char				*parsename(char *s);
void				markup(t_lst *list);
void				parseroom(t_room *room, char *info);
t_room				**get_rooms(t_lst *list, int len);

/*
**					______________Функции инициализации проекта_________
*/

t_lst				*newlst(char *cont);
t_lem				*newlem();
t_room				**newarr(int len);
t_room				*newroom(char *info);
int					**newmatrix(int size);

/*
**					______________Функции валидности графа______________
*/

int					is_room(char *s);
int					is_link(char *s);
int					is_number_of_ants(char *s);
int					check_rooms(char *a, char *b, t_lem *lem);
int					postvalid(t_lst *list);

/*
**					______________Функции отчиски памяти________________
*/

void				rmlst(t_lst *list);
void				rmlem(t_lem *lem);
void				rmpath(t_path *path);
void				rmpaths(t_lst_paths *paths);

/*
**					_____________Функции алгоритма програмы_____________
*/

int					bfs(t_lem *lem);
t_path				*get_path(t_lem *lem);
void				step(t_path **ants, int number_of_ants, int *finished,
															t_room *end);
void				run_ants(int number_of_ants, t_lst_paths *paths);

/*
**					____Функции вывода информации о решении задачи______
**					________или об ошибке на экран______________________
*/

void				print_info(t_lst *list);
void				print_step(int id, char *name);
void				error();

/*
** 					____________Функция заполнения матрицы_______________
*/

int					fill_matrix(t_lem *lem, t_lst *list);

/*
**					___________Функции выстраивания путей в графе________
*/

t_path				*get_path(t_lem *lem);
void				restore_path(t_lem *lem, t_path *path);
t_lst_paths			*get_paths(t_lem *lem);

/*
**					__________Функции высраивания очереди для основ-_____
**					__________ного алгоритма проекта_____________________
*/

t_room				**newqueue(int size);
int					qin(t_room **queue, int size, t_room *room);
void				qrm(t_room **queue, int size);
void				qfree(t_room **queue, int size);

/*
**					__________Впомогательные функции для проекта__________
*/

int					ft_isspace(int c);

#endif
