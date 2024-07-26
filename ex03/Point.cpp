/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/26 12:36:21 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructor

Point::Point(): x(0), y(0){}

Point::Point(const Point &cpy)
{
	*this = cpy;
}

Point::Point(const float x, const float y): x(x) , y(y){}

// Destructor

Point::~Point(){}

// Operators

Point	&Point::operator= (const Point &cpy)
{
	if (this != &cpy)
	{
	}
	return (*this);
}