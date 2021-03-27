/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:20:28 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/03/27 13:24:14 by nmbabazi         ###   ########.fr       */
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
    class allocator
    {
        public:
            typedef T					value_type;
            typedef T&                  reference;
            typedef const T&            const_reference;
            typedef T*                  pointer;
            typedef const T*            const_pointer;
			typedef ptrdiff_t			difference_type;
    		typedef size_t				size_type;

			class bad_alloc : public std::exception
			{
			public:
				virtual const char *what() const throw(){return "bad allocation";}
			};
            
            allocator() throw();	
            allocator (const allocator& alloc) throw();
            template <class U>
            allocator (const allocator<U>& alloc) throw();
            ~allocator ( ) throw;

            pointer address(reference x ) const{ return &x;}
            const_pointer address(const_reference x ) const{ return &x}

            pointer allocate(size_type n, allocator<void>::const_pointer hint=0)
            {
                (void)hint;
                pointer ret;
                if (!(ret = reinterpret_cast<pointer>(::operator new(n * (sizeof(value_type))))))
                    throw bad_alloc;
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