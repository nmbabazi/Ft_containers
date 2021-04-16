/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/16 12:07:07 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "../vector/vector.hpp"
#include <stack>
#include <vector>
#include <iostream>

/*******************************************************************************/
/**Basic test provided on cplusplus.com. STL outputs are copied from the site.**/
/*******************************************************************************/

int main()
{
	std::cout << "\n\n ***************Test constructeur***********\n\n";
	{
        {
        ft::vector<int> myvector (2,200);        // vector with 2 elements

        ft::stack<int> first;                    // empty stack
        ft::stack<int> second (myvector);         // stack initialized to copy of vector


        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::vector<int> myvector (2,200);        // vector with 2 elements

        std::stack<int,std::vector<int> > first;  // empty stack using vector
        std::stack<int,std::vector<int> > second (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        }

	}
    std::cout << "\n\n ***************Test empty***********\n\n";
	{
        {
        ft::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }
        std::cout << "total: " << sum << '\n';

        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }
        std::cout << "total: " << sum << '\n';

        }

	}
    std::cout << "\n\n ***************Test size***********\n\n";
	{
        {
        ft::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
        }

	}
    std::cout << "\n\n ***************Test top***********\n\n";
	{
        {
        ft::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
        }

	}
    std::cout << "\n\n ***************Test push***********\n\n";
	{
        {
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        }
	}
    std::cout << "\n\n ***************Test pop***********\n\n";
	{
        {
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
        }
	}
    std::cout << "\n\n ***************Test relational operators***********\n\n";
	{

	std::cout << "-----------------------------" << std::endl << "stl\n";

	}
}