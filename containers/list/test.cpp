/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/03 13:59:11 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>


int main ()
{

    std::cout << "\n\n ***************Test constructeur***********\n\n";
    {
        // constructors used in the same order as described above:
		ft::list<int> first;                                // empty list of ints
		ft::list<int> second (4,100);                       // four ints with value 100
		ft::list<int> third (second.begin(),second.end());  // iterating through second
		ft::list<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are(ft): ";
		for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';
		std::cout << "\nThe contents of fifth are(std): 16 2 77 29\n";
    }
	std::cout << "\n\n ***************Test assignation***********\n\n";
    {
		ft::list<int> first (3);      // list of 3 zero-initialized ints
		ft::list<int> second (5);     // list of 5 zero-initialized ints

		second = first;
		first = ft::list<int>();

		std::cout << "Size of first(ft): " << int (first.size()) << '\n';
		std::cout << "Size of first(std): 0" << '\n';
		std::cout << "Size of second(ft): " << int (second.size()) << '\n';
		std::cout << "Size of second(std): 3" << '\n';

    }
	std::cout << "\n\n ***************Test iterator***********\n\n";
    {

    }
	// std::cout << "\n\n ***************Test ***********\n\n";
    // {

    // }

  return 0;
}
