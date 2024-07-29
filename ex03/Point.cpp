/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/29 12:03:31 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructor

Point::Point(): x(0), y(0){}

Point::Point(const Point &cpy): x(cpy.get_x()), y(cpy.get_y()){}

Point::Point(const float x, const float y): x(x) , y(y){}

// Destructor

Point::~Point(){}

// Operators

Point	&Point::operator= (const Point &cpy)
{
	if (this != &cpy)
	{
		std::cerr << "You cant copy something" << std::endl;
	}
	return (*this);
}

float	Point::get_x() const{return (this->x.toFloat());}

float	Point::get_y() const{return (this->y.toFloat());}