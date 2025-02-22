/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:08 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/02 07:42:31 by lbohm            ###   ########.fr       */
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
	if (value <= (1 << 23) && value >= -1 * (1 << 23))
		this->value = (value * int(1 << fractional));
	else
	{
		std::cout << "Number will overflow" << std::endl;
		std::exit(1);
	}
}

Fixed::Fixed(const float value)
{
	if (value <= (3.40282347e+38F / float(1 << fractional)) && value >= (-3.40282347e+38F / float(1 << fractional)))
		this->value = std::roundf((value * float(1 << fractional)));
	else
	{
		std::cerr << "Number will overflow" << std::endl;
		std::exit(1);
	}
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
	return (s1 < s2 ? s1 : s2);
}

const Fixed	&Fixed::min(const Fixed &s1, const Fixed &s2)
{
	return (s1.toFloat() < s2.toFloat() ? s1 : s2);
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

Fixed	Fixed::operator* (const Fixed &mpy)
{
	Fixed	a(this->toFloat() * mpy.toFloat());

	return (a);
}

Fixed	Fixed::operator/ (const Fixed &dev)
{
	if (this->toFloat() != 0 && dev.toFloat() != 0)
	{
		Fixed	a(this->toFloat() / dev.toFloat());

		return (a);
	}
	else
		std::cerr << "Division by zero" << std::endl;
	return (dev);
}

Fixed	Fixed::operator+ (const Fixed &add)
{
	Fixed	a(this->toFloat() + add.toFloat());

	return (a);
}

Fixed	Fixed::operator- (const Fixed &sub)
{
	Fixed	a(this->toFloat() - sub.toFloat());

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

	this->value--;
	return (tmp);
}

Fixed	&Fixed::operator-- ()
{
	value--;
	return (*this);
}
