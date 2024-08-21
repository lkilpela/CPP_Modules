/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:36:17 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 19:36:41 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie(std::string name) : name(name) {} 

Zombie::~Zombie() {
    std::cout << name << " is destroyed." << "\n";
}
void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}