/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:20:28 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/04/05 14:34:12 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP

#include <memory>
#include <new>
#include <iostream>

namespace ft
{
    template <typename T> 
    class Allocator
    {
        public:
            typedef T					value_type;
            typedef T&                  reference;
            typedef const T&            const_reference;
            typedef T*                  pointer;
            typedef const T*            const_pointer;
			typedef ptrdiff_t			difference_type;
    		typedef size_t				size_type;
            
            Allocator() throw(){}
            Allocator (const Allocator& alloc) throw(){}
            template <class U>
            Allocator (const Allocator<U>& alloc) throw(){}
            ~Allocator () throw(){}

            pointer address(reference x ) const{ return &x;}
            const_pointer address(const_reference x ) const{ return &x;}
            
            size_type max_size() const { return static_cast<size_type>(-1) / sizeof(value_type);} ///to check

            pointer allocate(size_type n)
            {
                pointer ret;
                if (!(ret = reinterpret_cast<pointer>(::operator new(n * (sizeof(value_type))))))
                    throw std::bad_alloc();
                return ret;
            }
            void deallocate (pointer p, size_type n)
            {
                (void)n;
                operator delete(p);
            }
            
            void construct ( pointer p, const_reference val ){new((void *)p) T(val);} //appelle au constructeur de T avec pour arg val
            void destroy (pointer p){((T*)p)->~T();} //appelle au destructeur de T
    };
}

#endif