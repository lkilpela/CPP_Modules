/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:46:48 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 13:49:41 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("default", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
: AForm(other)
, target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    AForm::operator=(other);
    target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    // Check if executor has the right grade to execute the form &
    // Check if the form is signed
    if (executor.getGrade() > getGradeToExecute() && getIsSigned()) {
        throw GradeTooLowException();
    }
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream file;
    file.open(filename);
    file << "              ,@@@@@@@,\n";
    file << "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    file << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    file << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    file << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    file << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    file << "  `&%\\ ` /%&'    |.|        \\ '|8'\n";
    file << "       |o|        | |         | |\n";
    file << "       |.|        | |         | |\n";
    file << "   \\\\/ ._\\//_/__/  ,\\\\_//__\\\\/.  \\_//__/_\n";
    file.close();
}
