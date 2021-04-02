/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/02 16:50:40 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>

int main()
{
    std::cout << std::endl << "//////////////////////test iterator/////////////////////////" << std::endl;
    std::cout << "                 ****iterator" << std::endl << std::endl;
    ft::list<int> lst1;
    for (int i = 5; i < 11; i++)
         lst1.push_back(i);
    for (int i = 0; i < 5; i++)
        lst1.push_front(i);
    std::cout << "list 1 :"; lst1.printlist();
    lst1.pop_back();
    ft::list<int>::iterator it = lst1.begin();
    ft::list<int>::iterator rit = lst1.end();
    std::cout << "list iterator :";
    while (it != rit)
    {
         std::cout << "["<< *it << "] ";
         it++;
    }
    std::cout << std::endl;
    const ft::list<int> lst2(lst1);
    ft::list<int>::c_iterator cit = lst2.begin();
    ft::list<int>::c_iterator crit = lst2.end();
    std::cout << "list const it :";
    while (cit != crit)
    {
         std::cout << "["<< *cit << "] ";
         cit++;
    }
    std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "                 ****const_iterator";
    // std::cout << std::endl << std::endl;
    // const ft::list<int> lst2(lst1.begin() + 3, lst1.end());       
    // ft::list<int>::c_iterator cit = lst2.begin(); 
    // ft::list<int>::c_iterator crit = lst2.end();
    // std::cout << "list :";
    // while (cit != crit)
    // {
    //      std::cout << "[" << *cit << "] ";
    //      cit++;
    // }
    // std::cout << std::endl;
    //     std::cout << "                 ****reverse_iterator";
    // std::cout << std::endl;      
    // ft::list<int>::r_iterator rev_it = lst1.rbegin(); 
    // ft::list<int>::r_iterator rev_rit = lst1.rend();
    // std::cout << "list :";
    // while (rev_it != rev_rit)
    // {
    //      std::cout << "[" << *rev_it << "] ";
    //      rev_it++;
    // }
    // std::cout << std::endl;
    // std::cout << "                 ****const_reverse_iterator";
    // std::cout << std::endl;      
    // ft::list<int>::cr_iterator crev_it = lst2.rbegin(); 
    // ft::list<int>::cr_iterator crev_rit = lst2.rend();
    // std::cout << "list :";
    // while (crev_it != crev_rit)
    // {
    //      std::cout << "[" << *crev_it << "] ";
    //      crev_it++;
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "////////////////////////constructeur///////////////////////////";               
    // std::cout << std::endl;
    // std::cout << "                 ****constructeur par copy" << std::endl;
    // ft::list<int> lst3(lst1);
    // std::cout << "list 3:"; lst3.printlist();
    // std::cout << std::endl;
    // std::cout << "                 ****constructeur par assignation" << std::endl;
    // ft::list<int> lst4;
    // lst4 = lst3;
    // std::cout << "list 4:"; lst4.printlist();
    // std::cout << std::endl;
    // std::cout << "                 ****constructeur par range" << std::endl;
    // ft::list<int> lst5(lst4.begin() + 3, lst4.end());
    // std::cout << "list 5:"; lst5.printlist();
    // std::cout << std::endl; 

} 