/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:02:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/15 12:38:05 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;
    public:
        // Constructor accepting std::string
        Weapon(const std::string& type) : type(type) {}
        
        void setType(const std::string& newType) {
            type = newType;
        }
        const std::string& getType() const {
            return type;
        }
};

#endif