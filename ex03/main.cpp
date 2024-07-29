/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:40:13 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/29 11:21:12 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(1.0f, 0.0f);
	Point	c(1.0f, 1.0f);
	Point	point(0.5f, 0.2f);

	bsp(a, b, c, point) ? std::cout << "Point is inside triangle" << std::endl 
		: std::cout << "Point is outside triangle" << std::endl;
}
