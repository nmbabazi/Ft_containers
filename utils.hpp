/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:55:24 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/04/16 10:53:40 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

/*****to do avant rendu
 * rendre un main.cpp pour chaque container
 * checker les friends de map
 * tout mes classe sont canonique?*/

namespace ft{
    template <bool B, class T = void>
    struct Enable_if
    {
    };

    template <class T>
    struct Enable_if<true, T>
    {
        typedef T type;
    };

    template<typename T>
    void ft_swap(T &arg1, T &arg2)
    {
        T temp = arg1;
        arg1 = arg2;
        arg2 = temp;
    }

    template <class T> 
    struct less : std::binary_function <T,T,bool> 
    {
        bool operator() (const T& x, const T& y) const {return (x<y);}
    };
    
}

#endif