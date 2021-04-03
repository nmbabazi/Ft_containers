/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/03 16:31:46 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <iterator>


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
	std::cout << "\n\n ***************Test empty***********\n\n";
    {
		ft::list<int> mylist;
		int sum (0);

		for (int i=1;i<=10;++i) mylist.push_back(i);

		while (!mylist.empty())
		{
			sum += mylist.front();
			mylist.pop_front();
		}
		std::cout << "total(ft): " << sum << '\n';
		std::cout << "total(std): 55 \n";
		
    }
	std::cout << "\n\n ***************Test reverse it***********\n\n";
    {
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		std::cout << "mylist backwards(ft):";
		for (ft::list<int>::r_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << '\n';
		std::cout << "mylist backwards(std): 5 4 3 2 1\n";
    }
	std::cout << "\n\n ***************Test assign***********\n\n";
    {
		ft::list<int> first;
		ft::list<int> second;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first

		int myints[]={1776,7,4};
		first.assign (myints,myints+3);            // assigning from array

		std::cout << "Size of first(ft): " << int (first.size()) << '\n';
		std::cout << "Size of first(std): 3\n";
		std::cout << "Size of second(ft): " << int (second.size()) << '\n';
		std::cout << "Size of second(std): 7\n";
    }
	std::cout << "\n\n ***************Test insert**********\n\n";
    {
		ft::list<int> mylist;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it;       // it points now to number 2           ^

		mylist.insert (it,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^

		std::vector<int> myvector (2,30);
		mylist.insert (it,myvector.begin(),myvector.end());
														// 1 10 20 30 30 20 2 3 4 5
														//               ^
		std::cout << "mylist contains(ft):";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(std): 1 10 20 30 30 20 2 3 4 5\n";
	}
	std::cout << "\n\n ***************Test erase***********\n\n";
    {
		ft::list<int> mylist;
		ft::list<int>::iterator it1,it2;

		// set some values:
		for (int i=1; i<10; ++i) mylist.push_back(i*10);

									// 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		for(int i = 0; i < 6; i++)
			it2++;            // ^                 ^
		++it1;                      //    ^              ^

		it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
									//    ^           ^

		it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
									//    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		mylist.erase (it1,it2);     // 10 30 60 80 90
									//        ^

		std::cout << "mylist contains:";
		for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
		std::cout << "mylist contains: 10 30 60 80 90\n";
	}
	std::cout << "\n\n ***************Test swap***********\n\n";
    {
		ft::list<int> first (3,100);   // three ints with a value of 100
		ft::list<int> second (5,200);  // five ints with a value of 200

		first.swap(second);

		std::cout << "first contains(ft):";
		for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "first contains(std): 200 200 200 200 200\n";
		std::cout << "second contains(ft):";
		for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "second contains(std): 100 100 100\n";
	}
	std::cout << "\n\n ***************Test resize***********\n\n";
    {
		ft::list<int> mylist;

		// set some initial content:
		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8,100);
		mylist.resize(12);

		std::cout << "mylist contains(ft):";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(std): 1 2 3 4 5 100 100 100 0 0 0 0\n";
	}
	std::cout << "\n\n ***************Test relational operators***********\n\n";
    {
		int myints[] = {10, 20, 30};
		ft::list<int> a(myints, myints + sizeof(myints) / sizeof(int)); 
		ft::list<int> b = a;
		ft::list<int> c(a.rbegin(), a.rend());

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
		
		std::cout << "STL output \n";
		std::cout << "a and b are equal\n";
		std::cout << "b and c are not equal\n";
		std::cout << "b is less than c\n";
		std::cout << "c is greater than b\n";
		std::cout << "a is less than or equal to b\n";
		std::cout << "a is greater than or equal to b\n";
	}
  return 0;
}
