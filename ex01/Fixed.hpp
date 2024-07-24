/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:24:10 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/24 17:05:56 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{
	private:
		int					value;
		static const int	fractional = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const Fixed &cpy);
		Fixed(const float value);
		~Fixed();
		Fixed	&operator= (const Fixed &cpy);
		int toInt( void ) const;
		float toFloat( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream	&operator<< (std::ostream &stream, const Fixed &test);

#endif