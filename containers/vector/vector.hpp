/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/03/26 16:44:21 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "iterator.hpp"

namespace ft
{
    template <typename T, typename Alloc = std::allocator<T> > 
    class vector
    {
        public:
///////////////////////typedef//////////////////////////////        
            typedef T					value_type;
            typedef value_type&			reference;
            typedef value_type const & 	const_reference;
            typedef value_type*			pointer;
            typedef value_type const * 	const_pointer;
			typedef ptrdiff_t			difference_type;
    		typedef size_t				size_type;
			//typedef Alloc				alloc;
        	typedef VectIterator<T> iterator;
    		// typedef VectorIterator<value_type const> const_iterator;
    		// typedef ReverseIterator<iterator> reverse_iterator;
    		// typedef ReverseIterator<const_iterator> const_reverse_iterator;
            
            vector(const allocator_type& alloc = allocator_type());
            vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
            vector (const vector& x);
            ~vector();
            vector& operator=(const vector& x);
///////////////////////iterator//////////////////////////////
            begin();
            end();
            rbegin();
            rend();
/////////////////////capacity////////////////////////////////
            size();
            max_size();
            empty();
            resize();
            capacity();
            reserve();
/////////////////////acces///////////////////////////////////
            front();
            back();
            operator[]();
            at();
/////////////////////modifiers///////////////////////////////
            assign();
            insert();
            erase();
            push_back();
            pop_back();
            clear();
            swap();
        
    };
/////////////////////overload///////////////////////////////
// operator==
// operator!=
// operator<
// operator<=
// operator>
// operator>=

}

#endif