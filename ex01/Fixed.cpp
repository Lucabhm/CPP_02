/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:24:08 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/02 07:41:48 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
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
	std::cout << "Float constructor called" << std::endl;
	if (value <= (3.40282347e+38F / float(1 << fractional)) && value >= (-3.40282347e+38F / float(1 << fractional)))
		this->value = std::roundf((value * float(1 << fractional)));
	else
	{
		std::cerr << "Number will overflow" << std::endl;
		std::exit(1);
	}
}

// Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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

// Operators

Fixed	&Fixed::operator= (const Fixed &cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cpy)
		value = cpy.getRawBits();
	return (*this);
}

std::ostream	&operator<< (std::ostream &stream, const Fixed &test)
{
	stream << test.toFloat();
	return (stream);
}