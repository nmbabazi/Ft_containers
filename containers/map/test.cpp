/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/08 10:38:43 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"
// #include "map.hpp"
#include <list>
#include <cmath>
#include <vector>
#include <iostream>

/*******************************************************************************/
/**Basic test provided on cplusplus.com. STL outputs are copied from the site.**/
/*******************************************************************************/

int main()
{
	std::cout << "\n\n ***************Test pair***********\n\n";
	{
		{
		ft::pair <std::string,double> product1;                     // default constructor
		ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
		ft::pair <std::string,double> product3 (product2);
		ft::pair <std::string,double> product4 (std::string("lightbulbs"),0.99); 

		product1 = product4;

		product2.first = "shoes";                  // the type of first is string
		product2.second = 39.90;                   // the type of second is double

		std::cout << "(ft)The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "(ft)The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "(ft)The price of " << product3.first << " is $" << product3.second << '\n';

		}
	std::cout << "-----------------------------" << std::endl;
		{
		std::pair <std::string,double> product1;                     // default constructor
		std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
		std::pair <std::string,double> product3 (product2);
		std::pair <std::string,double> product4 (std::string("lightbulbs"),0.99); 

		product1 = product4;

		product2.first = "shoes";                  // the type of first is string
		product2.second = 39.90;                   // the type of second is double

		std::cout << "(stl)The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "(stl)The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "(stl)The price of " << product3.first << " is $" << product3.second << '\n';

		}
	}
}