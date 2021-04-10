/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:25:47 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/04/09 14:38:43 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1                    first_type;     
        typedef T2                    second_type;

        pair()
        {
            first = first_type();
            second = second_type();
        }
        pair (const first_type& a, const second_type& b): first(a), second(b){}
        // template<class U, class V>
        // pair (const pair<U,V>& pr)
        // {
        //     first = first_type(pr.first);
        //     second = second_type(pr.second);
        // }

        pair& operator= (const pair& pr)
        {
            if (this == &pr)
				return *this;
            first = pr.first;
            second = pr.second;
            return *this;
        }

        first_type  first;
        second_type second;
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return lhs.first == rhs.first && lhs.second == rhs.second;}

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return !(lhs==rhs); }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);}

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return !(lhs<rhs);}
}

#endif