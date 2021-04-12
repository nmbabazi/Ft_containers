/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/12 13:14:03 by nmbabazi         ###   ########.fr       */
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
	// 	{ft::map<char,int> mymap;

	// 	ft::pair<const char, int> b('b',100);
	// 	ft::pair<const char, int> a('a',200);
	// 	ft::pair<const char, int> c('c',300);
	// 	ft::pair<const char, int> d('d',70);

	// 	mymap.insert(b);
	// 	mymap.insert(a);
	// 	mymap.insert(c);
	// 	mymap.insert(d);
	// 	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	std::cout << std::endl;

	// 	// ft::map<char,int> second (mymap.begin(),mymap.end());
	// 	// for (ft::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
	// 	// 	std::cout << it->first << " => " << it->second << '\n';
	// 	// std::cout << std::endl;

	// 	// ft::map<char,int> third (second);
	// 	// for (ft::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
	// 	// 	std::cout << it->first << " => " << it->second << '\n';
	// 	// std::cout << std::endl;
		
	// 	// ft::map<char,int,classcomp> fourth;
	// 	// bool(*fn_pt)(char,char) = fncomp;
  	// 	// ft::map<char,int,bool(*)(char,char)> fifth (fn_pt);
	// 	}

	// 	std::cout << "-----------------------------" << std::endl << "stl\n";
	// 	{std::map<char,int> mymap;

	// 	std::pair<const char, int> b('b',100);
	// 	std::pair<const char, int> a('a',200);
	// 	std::pair<const char, int> c('c',300);
	// 	std::pair<const char, int> d('d',70);

	// 	mymap.insert(b);
	// 	mymap.insert(a);
	// 	mymap.insert(c);
	// 	mymap.insert(d);
	// 	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	std::cout << std::endl;
		
	// 	// std::map<char,int> second (mymap.begin(),mymap.end());
	// 	// for (std::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
	// 	// 	std::cout << it->first << " => " << it->second << '\n';
	// 	// std::cout << std::endl;
		
	// 	// std::map<char,int> third (second);
	// 	// for (std::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
	// 	// 	std::cout << it->first << " => " << it->second << '\n';
	// 	// std::cout << std::endl;
		
	// 	// std::map<char,int,classcomp> fourth;
	// 	// bool(*fn_pt)(char,char) = fncomp;
  	// 	// std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
	// 	}
	// }

	// std::cout << "\n\n ***************Test assignation***********\n\n";
	// {

	// 	std::cout << "-----------------------------" << std::endl << "stl\n";

	// }
	// std::cout << "\n\n ***************Test reverse iterator***********\n\n";
	// {
	// 	{
	// 		ft::map<char,int> mymap;
			
	// 		ft::pair<const char, int> x('x',100);
	// 		ft::pair<const char, int> y('y',200);
	// 		ft::pair<const char, int> z('z',300);

	// 		mymap.insert(x);
	// 		mymap.insert(y);
	// 		mymap.insert(z);

	// 		// show content:
	// 		ft::map<char,int>::reverse_iterator rit;
	// 		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
	// 			std::cout << rit->first << " => " << rit->second << '\n';
	// 	}

	// 	std::cout << "-----------------------------" << std::endl << "stl\n";

	// 	{
	// 		std::map<char,int> mymap;

	// 		mymap['x'] = 100;
	// 		mymap['y'] = 200;
	// 		mymap['z'] = 300;

	// 		// show content:
	// 		std::map<char,int>::reverse_iterator rit;
	// 		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
	// 			std::cout << rit->first << " => " << rit->second << '\n';
	// 	}
	// }
	// std::cout << "\n\n ***************Test size***********\n\n";
	// {
	// 	{
	// 	ft::map<char,int> mymap;
	// 	mymap['a']=101;
	// 	mymap['b']=202;
	// 	mymap['c']=302;

	// 	std::cout << "mymap.size() is " << mymap.size() << '\n';
	// 	}
	// 	std::cout << "-----------------------------" << std::endl << "stl\n";

	// 	{
	// 	std::map<char,int> mymap;
	// 	mymap['a']=101;
	// 	mymap['b']=202;
	// 	mymap['c']=302;

	// 	std::cout << "mymap.size() is " << mymap.size() << '\n';
	// 	}
	// }
	// std::cout << "\n\n ***************Test empty***********\n\n";
	// {
	// 	// {
	// 	// ft::map<char,int> mymap;

	// 	// mymap['a']=10;
	// 	// mymap['b']=20;
	// 	// mymap['c']=30;

	// 	// while (!mymap.empty())
	// 	// {
	// 	// 	std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
	// 	// 	mymap.erase(mymap.begin());
	// 	// }
	// 	// }

	// 	// std::cout << "-----------------------------" << std::endl << "stl\n";
	// 	// {
	// 	// std::map<char,int> mymap;

	// 	// mymap['a']=10;
	// 	// mymap['b']=20;
	// 	// mymap['c']=30;

	// 	// while (!mymap.empty())
	// 	// {
	// 	// 	std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
	// 	// 	mymap.erase(mymap.begin());
	// 	// }
	// 	// }

	// }
	// std::cout << "\n\n ***************Test operator[] ***********\n\n";
	// {
	// 	{
	// 	ft::map<char,std::string> mymap;

	// 	mymap['a']= "an element";
	// 	mymap['b']= "another element";
	// 	mymap['c']= mymap['b'];;

	// 	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	// 	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	// 	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	// 	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	// 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	// 	}

	// 	std::cout << "-----------------------------" << std::endl << "stl\n";
	// 	{
	// 	std::map<char,std::string> mymap;

	// 	mymap['a']="an element";
	// 	mymap['b']="another element";
	// 	mymap['c']=mymap['b'];

	// 	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	// 	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	// 	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	// 	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	// 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	// 	}

	// }
	std::cout << "\n\n ***************Test erase***********\n\n";
	{
		{
		ft::map<char,int> mymap;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		

		ft::map<char,int>::iterator it = mymap.begin();
		ft::map<char,int>::iterator rit = mymap.end();
		// rit--;
		// it++;

		// mymap.erase (it);                  // erasing by iterator
		// for (ft::map<char,int>::iterator lit=mymap.begin(); lit!=mymap.end(); ++lit)
		// 	std::cout << lit->first << " => " << lit->second << '\n';
		// std::cout << std::endl;
		// mymap.erase ('c');                  // erasing by key
		// for (ft::map<char,int>::iterator lit=mymap.begin(); lit!=mymap.end(); ++lit)
		// 	std::cout << lit->first << " => " << lit->second << '\n';
		// std::cout << std::endl;
		// std::cout << it->first << " => " << it->second << '\n';
		// std::cout << std::endl;
		// it++;it++;it++;
		mymap.erase ( it, rit);    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}

		// std::cout << "-----------------------------" << std::endl << "stl\n";
		// {
		// std::map<char,int> mymap;
		// std::map<char,int>::iterator it;

		// // insert some values:
		// mymap['a']=10;
		// mymap['b']=20;
		// mymap['c']=30;
		// mymap['d']=40;
		// mymap['e']=50;
		// mymap['f']=60;

		// it=mymap.find('b');
		// mymap.erase (it);                   // erasing by iterator

		// mymap.erase ('c');                  // erasing by key

		// it=mymap.find ('e');
		// mymap.erase ( it, mymap.end() );    // erasing by range

		// // show content:
		// for (it=mymap.begin(); it!=mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';
		// }

	}
}