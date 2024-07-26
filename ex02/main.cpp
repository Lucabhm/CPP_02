/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:44:35 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/26 10:38:46 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	a > b ? std::cout << "a is bigger" << std::endl : std::cout << "b ist bigger" << std::endl;
	a != b ? std::cout << "a and b are not equal" << std::endl : std::cout << "a and b are equal" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed(10) + Fixed(5) << std::endl;
	std::cout << Fixed(10.5f) - Fixed(5) << std::endl;
	std::cout << Fixed(10.25f) / Fixed(2) << std::endl;
	a.setRawBits(5 * 256);
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	
	return 0;
}