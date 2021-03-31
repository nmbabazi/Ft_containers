/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/03/31 15:42:46 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << "//////////////////////test iterator/////////////////////////";               
    std::cout << std::endl;
    std::cout << "                 ****iterator";               
    std::cout << std::endl << std::endl;
    ft::Vector<int> vec1;
    for (int i = 1; i <= 11; i++)
    {
        vec1.push_back(i);
        std::cout << "size = " << vec1.size() << "  capacity = " << vec1.capacity() << std::endl;
    }
    ft::Vector<int>::iterator it = vec1.begin();
    ft::Vector<int>::iterator rit = vec1.end();
    std::cout << "vector :";
    while (it != rit)
    {
         std::cout << "["<< *it << "] ";
         it++;
    }
    std::cout << std::endl;
    std::cout << "                 ****const_iterator";
    std::cout << std::endl << std::endl;
    const ft::Vector<int> vec2(vec1.begin() + 3, vec1.end());       
    ft::Vector<int>::c_iterator cit = vec2.begin(); 
    ft::Vector<int>::c_iterator crit = vec2.end();
    std::cout << "vector :";
    while (cit != crit)
    {
         std::cout << "[" << *cit << "] ";
         cit++;
    }
    std::cout << std::endl;
        std::cout << "                 ****reverse_iterator";
    std::cout << std::endl;      
    ft::Vector<int>::r_iterator rev_it = vec1.rbegin(); 
    ft::Vector<int>::r_iterator rev_rit = vec1.rend();
    std::cout << "vector :";
    while (rev_it != rev_rit)
    {
         std::cout << "[" << *rev_it << "] ";
         rev_it++;
    }
    std::cout << std::endl;
    std::cout << "                 ****const_reverse_iterator";
    std::cout << std::endl;      
    ft::Vector<int>::cr_iterator crev_it = vec2.rbegin(); 
    ft::Vector<int>::cr_iterator crev_rit = vec2.rend();
    std::cout << "vector :";
    while (crev_it != crev_rit)
    {
         std::cout << "[" << *crev_it << "] ";
         crev_it++;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "////////////////////////constructeur///////////////////////////";               
    std::cout << std::endl;
    std::cout << "                 ****constructeur par copy" << std::endl;
    ft::Vector<int> vec3(vec1);
    std::cout << "vector 3:"; vec3.printvector();
    std::cout << std::endl;
    std::cout << "                 ****constructeur par assignation" << std::endl;
    ft::Vector<int> vec4;
    vec4 = vec3;
    std::cout << "vector 4:"; vec4.printvector();
    std::cout << std::endl;
    std::cout << "                 ****constructeur par range" << std::endl;
    ft::Vector<int> vec5(vec4.begin() + 3, vec4.end());
    std::cout << "vector 5:"; vec5.printvector();
    std::cout << std::endl;   
    std::cout << "////////////////////////capacity///////////////////////////";               
    std::cout << std::endl; 
    std::cout << "                 ****size*************" << std::endl << std::endl;
    std::cout << "size of vec1 = " << vec1.size() << " size of vec2 = " << vec2.size() << std::endl;
    std::cout << "                 ****max_size*************" << std::endl << std::endl;
    std::cout << "max_size of vec1 = " << vec1.max_size() << " max_size of vec2 = " << vec2.max_size() << std::endl;
    std::cout << "                 ****empty*************" << std::endl << std::endl;
    ft::Vector<int> empt;
    std::cout << "is vec1 empty ? " << vec1.empty() << " is vec2 empty ? " << vec2.empty()
    << " is empt empty ?" << empt.empty() << std::endl;
    std::cout << "                 ****capacity*************" << std::endl << std::endl;
    std::cout << "capacity of vec1 = " << vec1.capacity() << " capacity of vec2 = " << vec2.capacity() << std::endl;
    std::cout << "                 ****resize*************" << std::endl << std::endl;
    std::cout << "vector " << vec1.capacity() << ": ";vec1.printvector();
    vec1.resize(5);
    std::cout << "vector " << vec1.capacity() << ": ";vec1.printvector();
    vec1.resize(20);
    std::cout << "vector " << vec1.capacity() << ": ";vec1.printvector();
    vec1.resize(24, 6);
    std::cout << "vector " << vec1.capacity() << ": " ;vec1.printvector();
    std::cout << "                 ****reserve*************" << std::endl << std::endl;
    std::cout << std::endl;
    std::cout << "vector :"; vec1.printvector();
    std::cout << "capacity :" << vec1.capacity() << std::endl;
    vec1.reserve(5);
    std::cout << "capacity :" << vec1.capacity() << std::endl;
    vec1.reserve(35);
    std::cout << "capacity :" << vec1.capacity() << std::endl;
    std::cout << "vector :" ;vec1.printvector();
    std::cout << "/////////////////////////acces/////////////////////////////";               
    std::cout << std::endl;
    std::cout << "                 ****front*************" << std::endl << std::endl;
    std::cout << "front vec1 = " << vec1.front() << " front of vec2 = " << vec2.front() << std::endl;
    std::cout << std::endl;
    std::cout << "                 ****back*************" << std::endl << std::endl;
    std::cout << "back vec1 = " << vec1.back() << " back of vec2 = " << vec2.back() << std::endl;    
    std::cout << std::endl;
    std::cout << "                 ****operator[]*************" << std::endl << std::endl;
    std::cout << "[5] vec1 = " << vec1[5] << "--[5] of vec2 = " << vec2[5] << std::endl;
    std::cout << "[37] vec1 = " << vec1[37] << "--[13] of vec2 = " << vec2[13] << std::endl;
    std::cout << std::endl << "                 ****at*************" << std::endl << std::endl;
    std::cout << "at 4 vec1 = " << vec1.at(4) << " -- 5 of vec2 = " << vec2.at(5) << std::endl;
    try
    {
        std::cout << "at 37 vec1 = " << vec2.at(37) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Out of Range error: "<< e.what() << std::endl; 
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "///////////////////////modifiers//////////////////////////";               
    std::cout << std::endl;
    std::cout << std::endl << "                 ****assign*************" << std::endl << std::endl;
    std::cout << "vec1 initial : "; vec1.printvector();
    vec1.assign(vec2.begin(), vec2.end());
    std::cout << "vec1 assigned : "; vec1.printvector();
    vec1.assign(6, 4);
    std::cout << "vec1 re-assigned : "; vec1.printvector();
    std::cout << std::endl << "                 ****pop_back*************" << std::endl << std::endl;
    std::cout << "vec1 initial size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    vec1.pop_back();
    std::cout << "vec1 initial size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    std::cout << std::endl << "                 ****insert*************" << std::endl << std::endl;
    std::cout << "vec1 initial size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    vec1.insert(vec1.begin() + 2, 2, 100);
    std::cout << "vec1 inserte 2 * 100 size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    ft::Vector<int> test(5, 100);
    std::cout << "test initial size(" << test.size() << ") capacity (" << test.capacity() << "): "; test.printvector();
    test.insert(test.begin() + 1, vec2.begin() + 4, vec2.end() - 2);
    std::cout << "insert vec1 in test size(" << test.size() << ") capacity (" << test.capacity() << "): "; test.printvector();
    std::cout << std::endl << "                 ****erase*************" << std::endl << std::endl;
    std::cout << "vec1 initial size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    vec1.erase(vec1.begin() + 2);
    std::cout << "vec1 erased size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    vec1.erase(vec1.begin() + 2 , vec1.end() - 5);
    std::cout << "vec1 erased size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    std::cout << std::endl << "                 ****clear*************" << std::endl << std::endl;
    std::cout << "vec1 initial size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    vec1.clear();
    std::cout << "vec1 initial size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    std::cout << std::endl << "                 ****swap*************" << std::endl << std::endl;
    std::cout << std::endl;
    ft::Vector<int> swaper(vec2.begin(), vec2.end());
    std::cout << "swaper initial size(" << swaper.size() << ") capacity (" << swaper.capacity() << "): "; swaper.printvector();
    std::cout << "vec1 initial size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    vec1.swap(swaper);
    std::cout << "swap!!!!" << std::endl;
    std::cout << "swaper swaped size(" << swaper.size() << ") capacity (" << swaper.capacity() << "): "; swaper.printvector();
    std::cout << "vec1 swaped size(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    std::cout << std::endl;
    std::cout << "////////////////////////overload//////////////////////////";               
    std::cout << std::endl;
    std::cout << "vec1/2(" << vec1.size() << ") capacity (" << vec1.capacity() << "): "; vec1.printvector();
    std::cout << "vec3(" << vec3.size() << ") capacity (" << vec3.capacity() << "): "; vec3.printvector();
    bool result = vec1 == vec3;
    std::cout << " vec1 == vec3 : " << result << std::endl;
    result = vec1 == vec2;
    std::cout << " vec1 == vec2 : " << result << std::endl;
    vec1.pop_back();
    result = vec1 == vec2;
    std::cout << " vec1(poped) == vec2: " << result << std::endl << std::endl;
    result = vec1 != vec3;
    std::cout << " vec1 != vec3: " << result << std::endl;
    result = vec1 != vec2;
    std::cout << " vec1(poped) != vec2 : " << result << std::endl;
    vec1.push_back(*(vec2.end() - 1));
    result = vec1 != vec2;
    std::cout << " vec1 != vec2 : " << result << std::endl << std::endl;
    result = vec1 < vec3;
    std::cout << " vec1 < vec3 : " << result << std::endl;
    result = vec1 < vec2;
    std::cout << " vec1 < vec2 : " << result << std::endl;
    vec1.pop_back();
    result = vec1 < vec2;
    std::cout << " vec1(poped) < vec2: " << result << std::endl;
    return (0);
}
