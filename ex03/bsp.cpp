/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:06 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/29 11:49:48 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	a1;
	float	a2;
	float	a3;
	float	a4;
	
	a1 = area(a, b, c);
	a2 = area(point, a, b);
	a3 = area(point, b, c);
	a4 = area(point, a, c);
	return (!a2 || !a3 || !a4 || a2 + a3 + a4 != a1 ? false : true);
}

float	area(Point p1, Point p2, Point p3)
{
	float	area;

	area = 0.5 * (p1.get_x() * (p2.get_y() - p3.get_y()) + p2.get_x() * (p3.get_y() - p1.get_y()) + p3.get_x() * (p1.get_y() - p2.get_y()));
	return (area < 0 ? area * -1 : area);
}