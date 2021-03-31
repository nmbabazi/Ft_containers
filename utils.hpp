/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:55:24 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/03/31 13:45:11 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

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
}

#endif