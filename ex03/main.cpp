/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:40:13 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/31 13:34:02 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(0, 0);
	Point	b(1, 0);
	Point	c(1, 1);
	Point	point(0.5f, 0.2f);

	bsp(a, b, c, point) ? std::cout << "Point is inside triangle" << std::endl 
		: std::cout << "Point is outside triangle" << std::endl;
}
