/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:13 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/19 06:23:29 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        fixedPointValue = other.fixedPointValue;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    fixedPointValue = raw;
}
