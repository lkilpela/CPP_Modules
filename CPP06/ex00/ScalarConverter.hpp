/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:36:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/15 13:08:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string> // std::string, std::stoi, std::stof, std::stod

class ScalarConverter {
private:
    ScalarConverter() = delete;
    ScalarConverter(ScalarConverter const&) = delete;
    ScalarConverter& operator=(ScalarConverter const&) = delete;  
    ~ScalarConverter();

public:
    static void convert(const std::string& literal);

};

#endif