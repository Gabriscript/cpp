/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:47:05 by ggargani          #+#    #+#             */
/*   Updated: 2025/08/11 10:40:14 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"Fixed.hpp"




Fixed::Fixed():fixedPoint(0)
{
	//std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &copy) : fixedPoint(copy.fixedPoint)
{
	//std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
//	std::cout << "Int Constructor called" << std::endl;
	fixedPoint = num << numberBits;
}
Fixed::Fixed(const float num)
{
//	std::cout << "Float Constructor called" << std::endl;
	fixedPoint = roundf(num * (1 << numberBits));
	
}
Fixed&	Fixed::operator=(Fixed const &other) {

//	std::cout << "Copy assignent operator called" << std::endl;
	
	if (this != &other)
		fixedPoint = other.getRawBits();

	return *this;		
}

int Fixed::getRawBits(void)const
{
	
//	std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
		this->fixedPoint = raw;
}

int Fixed::toInt( void ) const
{
	return fixedPoint / (1 << numberBits);
}

float Fixed::toFloat( void ) const
{
	return (float)fixedPoint / (1 << numberBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}

bool  Fixed::operator>(Fixed const &fix)const 
{ 
	return getRawBits() > fix.getRawBits();
}
bool  Fixed::operator<(Fixed const &fix)const
{
	return getRawBits() < fix.getRawBits();
}

bool  Fixed::operator>=(Fixed const &fix)const
{
	return getRawBits() >= fix.getRawBits();
}
bool  Fixed::operator<=(Fixed  const &fix)const
{
	return getRawBits() <= fix.getRawBits();
}
bool  Fixed::operator==(Fixed const &fix)const
{
	return getRawBits() == fix.getRawBits();
}

bool  Fixed::operator!=(Fixed const &fix)const
{
	return getRawBits() != fix.getRawBits();
}

Fixed Fixed:: operator+(Fixed const &fix)const
{
	Fixed fixed;
	
	fixed.setRawBits(getRawBits() + fix.getRawBits());
	return fixed;
}
Fixed Fixed:: operator-(Fixed const &fix)const
{
	Fixed fixed;
	
	fixed.setRawBits(getRawBits() - fix.getRawBits());
	return fixed;
}
Fixed Fixed::operator*(Fixed const &fix) const
{
    Fixed fixed;
 
    fixed.setRawBits((getRawBits() * fix.getRawBits()) >> numberBits);
    return fixed;
}

Fixed Fixed::operator/(Fixed const &fix) const
{
    Fixed fixed;

    fixed.setRawBits((getRawBits() << numberBits) / fix.getRawBits());
    return fixed;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first <= second) ? first : second;
}

const Fixed &Fixed::min(Fixed const &first, Fixed const &second)
{
	return (first <= second) ? first : second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first >= second) ? first : second;
}

const Fixed &Fixed::max(Fixed const &first, const Fixed &second)
{
	return (first >= second) ? first : second;
}

Fixed Fixed::operator++()
{
	fixedPoint++;
	return *this;
}
Fixed Fixed::operator--()
{
	    fixedPoint--;
		return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	
	++(*this);
	return tmp;
}
Fixed Fixed::operator--(int)
{	
	Fixed tmp(*this);
	
	--(*this);
	return tmp;
}