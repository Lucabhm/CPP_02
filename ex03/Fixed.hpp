/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:11 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/26 11:16:23 by lbohm            ###   ########.fr       */
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
		bool	operator> (const Fixed &cmp);
		bool	operator< (const Fixed &cmp);
		bool	operator>= (const Fixed &cmp);
		bool	operator<= (const Fixed &cmp);
		bool	operator== (const Fixed &cmp);
		bool	operator!= (const Fixed &cmp);
		Fixed	operator* (const Fixed &mpy);
		Fixed	operator/ (const Fixed &dev);
		Fixed	operator+ (const Fixed &add);
		Fixed	operator- (const Fixed &sub);
		Fixed	&operator++ ();
		Fixed	operator++ (int value);
		Fixed	&operator-- ();
		Fixed	operator-- (int value);
		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		static Fixed	&min(Fixed &s1, Fixed&s2);
		static const Fixed	&min(const Fixed &s1, const Fixed&s2);
		static Fixed	&max(Fixed &s1, Fixed&s2);
		static const Fixed	&max(const Fixed &s1, const Fixed&s2);
};

std::ostream	&operator<< (std::ostream &stream, const Fixed &test);

#endif