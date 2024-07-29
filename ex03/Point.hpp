/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:17 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/29 11:35:02 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;
	public:
		Point();
		Point(const Point &cpy);
		Point(const float x, const float y);
		~Point();
		Point	&operator= (const Point &cpy);
		float	get_x() const;
		float	get_y() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
float	area(Point p1, Point p2, Point p3);

#endif