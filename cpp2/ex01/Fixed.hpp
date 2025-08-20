/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:42:40 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/06 10:13:33 by ggargani         ###   ########.fr       */
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

	int getRawBits(void)const;	
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream  &operator<<(std::ostream &o, Fixed const &fixed);


