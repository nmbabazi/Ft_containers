/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:25:47 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/04/15 13:52:11 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        pair(): first(), second(){}
        pair(const T1& k, const T2& val): first(k), second(val) {}
        template<class U, class V>
        pair (const pair<U,V>& pr): first(pr.first), second(pr.second){}
        pair& operator= (const pair& pr)
        {
            if (this == &pr)
				return *this;
            first = pr.first;
            second = pr.second;
            return *this;
        }

        T1 first;
        T2 second;
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