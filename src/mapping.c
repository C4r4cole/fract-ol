/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:56:51 by fmoulin           #+#    #+#             */
/*   Updated: 2025/08/01 18:05:17 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, t_min_max limits)
{
	return ((limits.new_max - limits.new_min)
		* (unscaled_num - limits.old_min)
		/ (limits.old_max - limits.old_min) + limits.new_min);
}
