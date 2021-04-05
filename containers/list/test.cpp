/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/05 14:33:33 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <cmath>
#include <vector>
#include <iostream>

/*******************************************************************************/
/**Basic test provided on cplusplus.com. STL outputs are copied from the site.**/
/*******************************************************************************/

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

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
	std::cout << "\n\n ***************Test size***********\n\n";
    {
		{std::cout << "ft:" << std::endl;
		  	ft::list<int> myints;
			std::cout << "0. size: " << myints.size() << '\n';

			for (int i=0; i<10; i++) myints.push_back(i);
			std::cout << "1. size: " << myints.size() << '\n';

			myints.insert (myints.begin(),10,100);
			std::cout << "2. size: " << myints.size() << '\n';

			myints.pop_back();
			std::cout << "3. size: " << myints.size() << '\n';}

        std::cout << "-----------------------------" << std::endl;
        {std::cout << "stl :" << std::endl;
		  	std::list<int> myints;
			std::cout << "0. size: " << myints.size() << '\n';

			for (int i=0; i<10; i++) myints.push_back(i);
			std::cout << "1. size: " << myints.size() << '\n';

			myints.insert (myints.begin(),10,100);
			std::cout << "2. size: " << myints.size() << '\n';

			myints.pop_back();
			std::cout << "3. size: " << myints.size() << '\n';}
		
    }
	std::cout << "\n\n ***************Test max_size***********\n\n";
    {
		{unsigned int i;
		ft::list<int> mylist;

		for (int i=0; i<100; i++) mylist.push_back(i);
		std::cout << "max_sizeft(ft): " << (int) mylist.max_size() << '\n';}
        std::cout << "-----------------------------" << std::endl;
		{unsigned int i;
		std::list<int> mylist;

		for (int i=0; i<100; i++) mylist.push_back(i);
		std::cout << "max_sizeft(stl): " << (int) mylist.max_size() << '\n';}
    }
	std::cout << "\n\n ***************Test front***********\n\n";
    {
		{
		  	ft::list<int> mylist;
			mylist.push_back(77);
			mylist.push_back(22);

			// now front equals 77, and back 22

			mylist.front() -= mylist.back();

			std::cout << "mylist.front() is now(ft) " << mylist.front() << '\n';}
        {
		  	std::list<int> mylist;

			mylist.push_back(77);
			mylist.push_back(22);

			// now front equals 77, and back 22

			mylist.front() -= mylist.back();

			std::cout << "mylist.front() is now(std) " << mylist.front() << '\n';}
		
    }
	std::cout << "\n\n ***************Test back***********\n\n";
    {
		{  ft::list<int> mylist;

			mylist.push_back(10);

			while (mylist.back() != 0)
			{
				mylist.push_back ( mylist.back() -1 );
			}

			std::cout << "mylist contains(ft):";
			for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
				std::cout << ' ' << *it;

			std::cout << '\n';}
        {  std::list<int> mylist;

			mylist.push_back(10);

			while (mylist.back() != 0)
			{
				mylist.push_back ( mylist.back() -1 );
			}

			std::cout << "mylist contains(stl):";
			for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
				std::cout << ' ' << *it;

			std::cout << '\n';}
		
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
	std::cout << "\n\n ***************Test push_front***********\n\n";
    {
		ft::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);

		std::cout << "mylist contains(ft):";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
		std::cout << "mylist contains(stl): 300 200 100 100\n";
    }
	std::cout << "\n\n ***************Test pop_front***********\n\n";
    {
		ft::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "Popping out the elements in mylist(ft):";
		while (!mylist.empty())
		{
			std::cout << ' ' << mylist.front();
			mylist.pop_front();
		}

		std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
		std::cout << "Popping out the elements in mylist(stl): 100 200 300 \nFinal size of mylist is 0\n";
    }
	std::cout << "\n\n ***************Test push_back***********\n\n";
    {
		ft::list<int> mylist;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			mylist.push_back (myint);
		} while (myint);

		std::cout << "mylist stores " << mylist.size() << " numbers.\n";
    }
	std::cout << "\n\n ***************Test pop_back***********\n\n";
    {
		ft::list<int> mylist;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		while (!mylist.empty())
		{
			sum+=mylist.back();
			mylist.pop_back();
		}
		std::cout << "The elements of mylist summed(ft) " << sum << '\n';
		std::cout << "The elements of mylist summed(stl) 600\n";
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
	std::cout << "\n\n ***************Test clear***********\n\n";
    {
		
    }
	std::cout << "\n\n ***************Test splice***********\n\n";
    {
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
										// mylist2 (empty)
										// "it" still points to 2 (the 5th element)
												
		mylist2.splice (mylist2.begin(),mylist1, it);
										// mylist1: 1 10 20 30 3 4
										// mylist2: 2
										// "it" is now invalid.
		it = mylist1.begin();
		it++;it++;it++;           		// "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
										// mylist1: 30 3 4 1 10 20

		std::cout << "mylist1 contains(ft):";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist1 contains(stl): 30 3 4 1 10 20\n";
		
		std::cout << "mylist2 contains(ft):";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist2 contains(stl): 2\n";
    }
	std::cout << "\n\n ***************Test remove***********\n\n";
    {
		int myints[]= {17,89,7,14};
		ft::list<int> mylist (myints,myints+4);

		mylist.remove(89);

		std::cout << "mylist contains(ft):";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(stl): 17 7 14\n";
    }
	std::cout << "\n\n ***************Test remove if***********\n\n";
    {
		int myints[]= {15,36,7,17,20,39,4,1};
		ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

		mylist.remove_if (single_digit);           // 15 36 17 20 39

		mylist.remove_if (is_odd());               // 36 20

		std::cout << "mylist contains(ft):";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(ft): 36 20\n";
    }
	std::cout << "\n\n ***************Test unique***********\n\n";
    {
		double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
							12.77, 73.35, 72.25, 15.3,  72.25 };
		ft::list<double> mylist (mydoubles,mydoubles+10);
		
		// mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
		// 							// 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
									// 15.3,  72.25, 73.0,  73.35

		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
											// 15.3,  72.25, 73.0

		mylist.unique (is_near());           //  2.72, 12.15, 72.25

		std::cout << "mylist contains(ft):";
		for (ft::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(stl-not sorted): 12.15 2.72 73 12.77 3.14 12.77 73.35 15.3 72.25\n";
		//std::cout << "mylist contains(stl-sorted): 2.72 12.15 72.25\n";
    }
	std::cout << "\n\n ***************Test merge***********\n\n";
    {
		ft::list<double> first, second;

		first.push_back (3.1);
		first.push_back (2.2);
		first.push_back (2.9);

		second.push_back (3.7);
		second.push_back (7.1);
		second.push_back (1.4);

		first.sort();
		second.sort();

		first.merge(second);

		// (second is now empty)

		second.push_back (2.1);

		first.merge(second,mycomparison);

		std::cout << "first contains(ft):";
		for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "first contains(stl): 1.4 2.2 2.9 2.1 3.1 3.7 7.1\n";
    }
	std::cout << "\n\n ***************Test sort***********\n\n";
    {
		ft::list<std::string> mylist;
		ft::list<std::string>::iterator it;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();

		std::cout << "mylist contains(ft):";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(stl): Three one two\n";

		mylist.sort(compare_nocase);

		std::cout << "mylist contains(ft):";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(stl): one Three two\n";
		
    }
	std::cout << "\n\n ***************Test reverse***********\n\n";
    {
		ft::list<int> mylist;

		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.reverse();

		std::cout << "mylist contains(ft):";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "mylist contains(stl): 9 8 7 6 5 4 3 2 1\n";
    }
	std::cout << "\n\n ***************Test relational operators***********\n\n";
    {
		int myints[] = {10, 20, 30};
		ft::list<int> a(myints, myints + sizeof(myints) / sizeof(int)); 
		ft::list<int> b = a;
		ft::list<int> c(a.rbegin(), a.rend());

		std::cout << "ft output:\n";
		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
		
		std::cout << "-----------------------------" << std::endl;
        std::cout << "stl output:\n";
        std::cout << "a and b are equal\n";
		std::cout << "b and c are not equal\n";
		std::cout << "b is less than c\n";
		std::cout << "c is greater than b\n";
		std::cout << "a is less than or equal to b\n";
		std::cout << "a is greater than or equal to b\n";
	}
	std::cout << "\n\n ***************Test swap overload ***********\n\n";
    {
        unsigned int i;
        ft::list<int> foo (3,100);   // three ints with a value of 100
        ft::list<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains(ft):";
        for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "foo contains(stl): 200 200 200 200 200\n";

        std::cout << "bar contains(ft):";
        for (ft::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "bar contains(stl): 100 100 100\n";
    }
  return 0;
}
