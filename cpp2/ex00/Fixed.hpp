/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:42:40 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/06 09:42:41 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<iostream>

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

	int getRawBits(void)const;	
	void setRawBits(int const raw);
};


