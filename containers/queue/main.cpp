/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/17 14:41:05 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"
#include "../list/list.hpp"
#include <queue>
#include <list>

int main()
{
	std::cout << "\n\n ***************Test constructeur***********\n\n";
	{
        {
        ft::list<int> mylist (2,200);         // list with 2 elements

        ft::queue<int> first;                 // empty queue
        ft::queue<int> second (mylist);       // queue initialized to copy of deque


        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::list<int> mylist (2,200);         // list with 2 elements

        std::queue<int,std::list<int> > first; // empty queue with list as underlying container
        std::queue<int,std::list<int> > second(mylist);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        }

	}
    std::cout << "\n\n ***************Test empty***********\n\n";
	{
        {
        ft::queue<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.front();
            mystack.pop();
        }
        std::cout << "total: " << sum << '\n';

        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::queue<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.front();
            mystack.pop();
        }
        std::cout << "total: " << sum << '\n';

        }

	}
    std::cout << "\n\n ***************Test size***********\n\n";
	{
        {
        ft::queue<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::queue<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
        }

	}
    std::cout << "\n\n ***************Test front***********\n\n";
	{
        {
        ft::queue<int> myqueue;

        myqueue.push(77);
        myqueue.push(16);

        myqueue.front() -= myqueue.back();    // 77-16=61

        std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::queue<int> myqueue;

        myqueue.push(77);
        myqueue.push(16);

        myqueue.front() -= myqueue.back();    // 77-16=61

        std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
        }

	}
    std::cout << "\n\n ***************Test back***********\n\n";
	{
        {
        ft::queue<int> myqueue;

        myqueue.push(12);
        myqueue.push(75);   // this is now the back

        myqueue.back() -= myqueue.front();

        std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::queue<int> myqueue;

        myqueue.push(12);
        myqueue.push(75);   // this is now the back

        myqueue.back() -= myqueue.front();

        std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
        }

	}
    std::cout << "\n\n ***************Test push***********\n\n";
	{
        {
        ft::queue<int> myqueue;
        int myint;

        std::cout << "Please enter some integers (enter 0 to end):\n";

        do {
            std::cin >> myint;
            myqueue.push (myint);
        } while (myint);

        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::queue<int> myqueue;
        int myint;

        std::cout << "Please enter some integers (enter 0 to end):\n";

        do {
            std::cin >> myint;
            myqueue.push (myint);
        } while (myint);

        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << '\n';
        }
	}
    std::cout << "\n\n ***************Test pop***********\n\n";
	{
        {
        ft::queue<int> myqueue;
        int myint;

        std::cout << "Please enter some integers (enter 0 to end):\n";

        do {
            std::cin >> myint;
            myqueue.push (myint);
        } while (myint);

        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << '\n';
        }

	std::cout << "-----------------------------" << std::endl << "stl\n";
        {
        std::queue<int> myqueue;
        int myint;

        std::cout << "Please enter some integers (enter 0 to end):\n";

        do {
            std::cin >> myint;
            myqueue.push (myint);
        } while (myint);

        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << '\n';
        }
	}
}