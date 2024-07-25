/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:44:30 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/25 16:55:42 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &cpy)
{
	*this = cpy;
}

Fixed::Fixed(const int value)
{
	this->value = (value * int(1 << fractional));
}

Fixed::Fixed(const float value)
{
	this->value = std::roundf((value * float(1 << fractional)));
}

// Destructor

Fixed::~Fixed(){}

// Member Functions

int	Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

int	Fixed::toInt(void)const
{
	return (value / int(1 << fractional));
}

float	Fixed::toFloat(void)const
{
	return (value / float(1 << fractional));
}

Fixed	&Fixed::min(Fixed &s1, Fixed &s2)
{
	return (s1 > s2 ? s1 : s2);
}

const Fixed	&Fixed::min(const Fixed &s1, const Fixed &s2)
{
	return (s1.toFloat() > s2.toFloat() ? s1 : s2);
}

Fixed	&Fixed::max(Fixed &s1, Fixed &s2)
{
	return (s1 > s2 ? s1 : s2);
}

const Fixed	&Fixed::max(const Fixed &s1, const Fixed &s2)
{
	return (s1.toFloat() > s2.toFloat() ? s1 : s2);
}

// Operators

Fixed	&Fixed::operator= (const Fixed &cpy)
{
	if (this != &cpy)
		value = cpy.getRawBits();
	return (*this);
}

std::ostream	&operator<< (std::ostream &stream, const Fixed &test)
{
	stream << test.toFloat();
	return (stream);
}

bool	Fixed::operator> (const Fixed &cmp)
{
	return (this->toFloat() > cmp.toFloat() ? true : false);
}

bool	Fixed::operator< (const Fixed &cmp)
{
	return (this->toFloat() < cmp.toFloat() ? true : false);
}

bool	Fixed::operator>= (const Fixed &cmp)
{
	return (this->toFloat() >= cmp.toFloat() ? true : false);
}

bool	Fixed::operator<= (const Fixed &cmp)
{
	return (this->toFloat() <= cmp.toFloat() ? true : false);
}

bool	Fixed::operator== (const Fixed &cmp)
{
	return (this->toFloat() == cmp.toFloat() ? true : false);
}

bool	Fixed::operator!= (const Fixed &cmp)
{
	return (this->toFloat() != cmp.toFloat() ? true : false);
}

Fixed	Fixed::operator* (const Fixed &cmp)
{
	Fixed	a(this->toFloat() * cmp.toFloat());

	return (a);
}

Fixed	Fixed::operator/ (const Fixed &cmp)
{
	Fixed	a(this->toFloat() / cmp.toFloat());

	return (a);
}

Fixed	Fixed::operator+ (const Fixed &cmp)
{
	Fixed	a(this->toFloat() + cmp.toFloat());

	return (a);
}

Fixed	Fixed::operator- (const Fixed &cmp)
{
	Fixed	a(this->toFloat() - cmp.toFloat());

	return (a);
}

Fixed	&Fixed::operator++ ()
{
	value++;
	return (*this);
}

Fixed	Fixed::operator++ (int value)
{
	Fixed	tmp = *this;

	this->value++;
	return (tmp);
}

Fixed	Fixed::operator-- (int value)
{
	Fixed	tmp = *this;

	value--;
	return (tmp);
}

Fixed	&Fixed::operator-- ()
{
	value--;
	return (*this);
}
