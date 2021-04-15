/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/15 17:58:24 by nailambz         ###   ########.fr       */
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

	std::cout << "\n\n ***************Test constructeur***********\n\n";
	{
		{ft::map<char,int> mymap;

		ft::pair<const char, int> b('b',100);
		ft::pair<const char, int> a('a',200);
		ft::pair<const char, int> c('c',300);
		ft::pair<const char, int> d('d',70);

		mymap.insert(b);
		mymap.insert(a);
		mymap.insert(c);
		mymap.insert(d);
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;

		ft::map<char,int> second (mymap.begin(),mymap.end());
		for (ft::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;

		ft::map<char,int> third (second);
		for (ft::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
		
		ft::map<char,int,classcomp> fourth;
		bool(*fn_pt)(char,char) = fncomp;
  		ft::map<char,int,bool(*)(char,char)> fifth (fn_pt);
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{std::map<char,int> mymap;

		std::pair<const char, int> b('b',100);
		std::pair<const char, int> a('a',200);
		std::pair<const char, int> c('c',300);
		std::pair<const char, int> d('d',70);

		mymap.insert(b);
		mymap.insert(a);
		mymap.insert(c);
		mymap.insert(d);
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
		
		std::map<char,int> second (mymap.begin(),mymap.end());
		for (std::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
		
		std::map<char,int> third (second);
		for (std::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << std::endl;
		
		std::map<char,int,classcomp> fourth;
		bool(*fn_pt)(char,char) = fncomp;
  		std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
		}
	}
	std::cout << "\n\n ***************Test assignation***********\n\n";
	{
		{
		ft::map<char,int> first;
		ft::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=ft::map<char,int>();  // and first is now empty

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> first;
		std::map<char,int> second;

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=std::map<char,int>();  // and first is now empty

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
		}

	}
	std::cout << "\n\n ***************Test reverse iterator***********\n\n";
	{
		{
			ft::map<char,int> mymap;
			
			ft::pair<const char, int> x('x',100);
			ft::pair<const char, int> y('y',200);
			ft::pair<const char, int> z('z',300);

			mymap.insert(x);
			mymap.insert(y);
			mymap.insert(z);

			// show content:
			ft::map<char,int>::reverse_iterator rit;
			for (rit=mymap.rbegin(); rit!=mymap.rend(); rit++)
			{
				std::cout << rit->first << " => " << rit->second << '\n' ;

			}
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";

		{
			std::map<char,int> mymap;

			mymap['x'] = 100;
			mymap['y'] = 200;
			mymap['z'] = 300;

			// show content:
			std::map<char,int>::reverse_iterator rit;
			for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
				std::cout << rit->first << " => " << rit->second << '\n';
		}
	}
	std::cout << "\n\n ***************Test size***********\n\n";
	{
		{
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		std::cout << "mymap.size() is " << mymap.size() << '\n';
		}
		std::cout << "-----------------------------" << std::endl << "stl\n";

		{
		std::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		std::cout << "mymap.size() is " << mymap.size() << '\n';
		}
	}
	std::cout << "\n\n ***************Test empty***********\n\n";
	{
		{
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
		}

	}
	std::cout << "\n\n ***************Test operator[] ***********\n\n";
	{
		{
		ft::map<char,std::string> mymap;

		mymap['a']= "an element";
		mymap['b']= "another element";
		mymap['c']= mymap['b'];;

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,std::string> mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
		}

	}
	std::cout << "\n\n ***************Test erase***********\n\n";
	{
		{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		}

	}
	std::cout << "\n\n ***************Test swap***********\n\n";
	{
		{
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}
	
		std::cout << "-----------------------------" << std::endl << "stl\n";

		{
		std::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}
	}
	std::cout << "\n\n ***************Test clear***********\n\n";
	{
		{
		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "mymap contains:\n";

		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
				{
		std::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		std::cout << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		std::cout << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}
	}
		std::cout << "\n\n ***************Test key_comp***********\n\n";
	{
		{
		ft::map<char,int> mymap;

		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> mymap;

		std::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
		}

	}
	std::cout << "\n\n ***************Test value_comp***********\n\n";
	{
		{
		ft::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		ft::pair<const char,int> highest = *mymap.rbegin();          // last element

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		std::pair<char,int> highest = *mymap.rbegin();          // last element

		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
		}

	}
	std::cout << "\n\n ***************Test find***********\n\n";
	{
		{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
		}
	}
	std::cout << "\n\n ***************Test count***********\n\n";
	{
		{
		ft::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
			else 
			std::cout << " is not an element of mymap.\n";
		}
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
			else 
			std::cout << " is not an element of mymap.\n";
		}
		}

	}
	std::cout << "\n\n ***************Test bound***********\n\n";
	{
		{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";

		{
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}

	}
		std::cout << "\n\n ***************Test equal_range***********\n\n";
	{
		{
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";

		{
		std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		}
	}
	std::cout << "\n\n ***************Test swap***********\n\n";
	{
		{
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		swap(foo,bar);

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		swap(foo,bar);

		std::cout << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		}

	}
	std::cout << "\n\n ***************Test relational operators***********\n\n";
	{
		{
		ft::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
		}

		std::cout << "-----------------------------" << std::endl << "stl\n";
		{
		std::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
		}

	}
}