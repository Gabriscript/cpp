/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:42:40 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/08 13:41:13 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>
#include <cmath>


class Fixed
{
private:
	int fixedPoint;
	static const int numberBits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed &src);
	~Fixed();
	
	Fixed(const int num);
	Fixed(const float num);

	bool operator>(Fixed const &fix)const;
	bool operator<(Fixed const  &fix)const;
	bool operator>=(Fixed const &fix)const;
	bool operator<=(Fixed const &fix)const;
	bool operator==(Fixed const &fix)const;
	bool operator!=(Fixed const &fix)const;
	
	Fixed operator+(Fixed const &fix)const;
	Fixed operator-(Fixed const &fix)const;
	Fixed operator*(Fixed const &fix)const;
	Fixed operator/(Fixed const &fix)const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void)const;	
	void setRawBits(int const raw);
	
	float toFloat( void ) const;
	int toInt( void ) const;
	
	static Fixed &min(Fixed &first, Fixed &second);
	static Fixed &max(Fixed &first, Fixed &second);
	const static  Fixed &min(Fixed const &first, Fixed const &second);
	const static  Fixed &max(Fixed const &first, const Fixed &second);
};

std::ostream  &operator<<(std::ostream &o, Fixed const &fixed);


