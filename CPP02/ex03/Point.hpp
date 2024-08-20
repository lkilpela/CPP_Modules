/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:49:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 19:17:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;
public:
    Point() : x(0), y(0) {};
    Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}
    Point(const Point& other) : x(other.x), y(other.y) {}
    Point& operator=(const Point& other) {
    // Since x and y are const, they cannot be assigned to after initialization.
    // This means we cannot implement a meaningful assignment operator.
    // We can only return *this.
        if (this != &other) {
            // Normally, we would assign the values here, but since x and y are const,
            // we can't do that. This is just to follow the canonical form.
        }
        return *this;
    }
    ~Point() {}
    
   // Extract coordinates
    Fixed getX() const;
    Fixed getY() const;

    // Main area function
    static Fixed area(Point const &p1, Point const &p2, Point const &p3);

};

// Calculate differences in y-coordinates
Fixed diffY(Point const &p1, Point const &p2);

// Multiply differences by corresponding x-coordinates
Fixed multiplyDiffX(Fixed x, Fixed diffY);

// Sum the products
Fixed sumProducts(Fixed prod1, Fixed prod2, Fixed prod3);

// Calculate and return the area
Fixed calculateArea(Fixed sum);

// Check if point is inside the triangle
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif