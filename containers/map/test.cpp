/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/10 10:56:02 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"
#include "map.hpp"
#include <map>
#include <list>
#include <cmath>
#include <vector>
#include <iostream>

/*******************************************************************************/
/**Basic test provided on cplusplus.com. STL outputs are copied from the site.**/
/*******************************************************************************/

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main()
{
	// std::cout << "\n\n ***************Test pair***********\n\n";
	// {
	// 	{
	// 	ft::pair <std::string,double> product1;                     // default constructor
	// 	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	// 	ft::pair <std::string,double> product3 (product2);
	// 	ft::pair <std::string,double> product4 (std::string("lightbulbs"),0.99); 

	// 	product1 = product4;

	// 	product2.first = "shoes";                  // the type of first is string
	// 	product2.second = 39.90;                   // the type of second is double

	// 	std::cout << "(ft)The price of " << product1.first << " is $" << product1.second << '\n';
	// 	std::cout << "(ft)The price of " << product2.first << " is $" << product2.second << '\n';
	// 	std::cout << "(ft)The price of " << product3.first << " is $" << product3.second << '\n';

	// 	}
	// std::cout << "-----------------------------" << std::endl;
	// 	{
	// 	std::pair <std::string,double> product1;                     // default constructor
	// 	std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	// 	std::pair <std::string,double> product3 (product2);
	// 	std::pair <std::string,double> product4 (std::string("lightbulbs"),0.99); 

	// 	product1 = product4;

	// 	product2.first = "shoes";                  // the type of first is string
	// 	product2.second = 39.90;                   // the type of second is double

	// 	std::cout << "(stl)The price of " << product1.first << " is $" << product1.second << '\n';
	// 	std::cout << "(stl)The price of " << product2.first << " is $" << product2.second << '\n';
	// 	std::cout << "(stl)The price of " << product3.first << " is $" << product3.second << '\n';

	// 	}
	// }
	// std::cout << "\n\n ***************Test constructeur***********\n\n";
	// {
	// 	ft::map<char,int> first;

	// 	first['a']=10;
	// 	first['b']=30;
	// 	first['c']=50;
	// 	first['d']=70;

	// 	ft::map<char,int> second (first.begin(),first.end());

	// 	ft::map<char,int> third (second);

	// 	ft::map<char,int,classcomp> fourth;                 // class as Compare

	// 	bool(*fn_pt)(char,char) = fncomp;
	// 	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	// }
	std::cout << "\n\n ***************Test constructeur***********\n\n";
	{
		{ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		
		//show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';}
		// std::cout << "-----------------------------" << std::endl << "stl\n";
		// {std::map<char,int> mymap;

		// mymap['b'] = 100;
		// mymap['a'] = 200;
		// mymap['c'] = 300;

		// // show content:
		// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';}
	}
}