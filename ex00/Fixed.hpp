/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:39:55 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/29 10:50:00 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	fractional = 8;
	public:
		Fixed();
		Fixed(const Fixed &cpy);
		~Fixed();
		Fixed	&operator = (const Fixed &cpy);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif