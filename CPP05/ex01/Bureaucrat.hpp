/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:29:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/16 09:42:46 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"


#define BLUE "\033[34m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

#define LOWEST 150
#define HIGHEST 1

class Form;

class Bureaucrat {
private:
    std::string const name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string& n, int grade);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    ~Bureaucrat();
    
    // Getters
    std::string getName() const;
    int getGrade() const;

    // Increment and decrement grade
    void incrementGrade();
    void decrementGrade();

    // Method to sign form
    void signForm(Form& form);
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
    public:        
        const char* what() const noexcept override;
    };
};

// Overload << operator to print Bureaucrat object
std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj);

#endif