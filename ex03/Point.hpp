/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:17 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/26 12:41:46 by lbohm            ###   ########.fr       */
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
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif