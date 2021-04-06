/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:55:28 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/04/06 17:25:37 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "pair.hpp"
#include "../../allocator.hpp"
#include "../../utils.hpp"

namespace ft
{
    template < class Key, class T, class Compare = less<Key>, class Alloc = ft::Allocator<pair<const Key,T> >  //creer l'operation less et pes pairs> class map;
    class map
    {
        public:
///////////////////////typedef//////////////////////////////
            typedef Key                     key_type;     
            typedef T                       mapped_type;
            typedef pair<const key_type,mapped_type>					    value_type;
            typedef Compare                 value_compare;
            typedef value_type&			    reference;
            typedef const value_type&       const_reference;
            typedef value_type*             pointer;
            typedef const value_type*       const_pointer;
			typedef ptrdiff_t			    difference_type;
    		typedef size_t				    size_type;
			typedef Alloc				    allocator_type;
            
        private:
///////////////////////constructeur//////////////////////////////
        public:	
        map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type());
        map (const map& x);

        ~map();

        map& operator=(const map& x);
///////////////////////iterator//////////////////////////////
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
/////////////////////capacity////////////////////////////////
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
/////////////////////acces///////////////////////////////////
        mapped_type& operator[] (const key_type& k);
/////////////////////modifiers///////////////////////////////
        pair<iterator,bool> insert (const value_type& val);
        iterator insert (iterator position, const value_type& val);
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last);
        
        void erase (iterator position);
        size_type erase (const key_type& k);
        void erase (iterator first, iterator last);
        void swap (map& x);
        void clear();
/////////////////////observer///////////////////////////////        
        key_compare key_comp() const;
        value_compare value_comp() const;
/////////////////////operation///////////////////////////////
        iterator find (const key_type& k);
        const_iterator find (const key_type& k) const;
        size_type count (const key_type& k) const;
        iterator lower_bound (const key_type& k);
        const_iterator lower_bound (const key_type& k) const;
        iterator upper_bound (const key_type& k);
        const_iterator upper_bound (const key_type& k) const;
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
        pair<iterator,iterator>             equal_range (const key_type& k);
    };
}

#endif