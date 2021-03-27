/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/03/27 17:51:42 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "../../allocator.hpp"

namespace ft
{
    template <typename T, typename Alloc = ft::allocator<T>> 
    class vector
    {
        public:
///////////////////////typedef//////////////////////////////        
            typedef T					    value_type;
            typedef T&			            reference;
            typedef const T&                const_reference;
            typedef T*                      pointer;
            typedef const T*                const_pointer;
			typedef ptrdiff_t			    difference_type;
    		typedef size_t				    size_type;
			typedef Alloc				    allocator_type;
        	typedef VectIterator<T>         iterator;
    		typedef VectRIterator<T>        r_iterator;
        	typedef ConstVectIterator<T>    c_iterator;
    		typedef ConstVectRIterator<T>   cr_iterator;
            
            vector(const allocator_type& alloc = allocator_type()):_alloc(alloc), _vector(NULL), _size(0), _capacity(0){}
            vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()):_alloc(alloc), _vector(NULL), _size(0), _capacity(0)
            {
                _vector = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                     _alloc.construct(_vector + i, val);
            }
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(), typename ft::enable_if<std::numeric_limits<InputIterator>::is_integer, InputIterator>::type = NULL):_vector(NULL), _alloc(alloc), _size(0), _capacity(last - first)
            {
                _alloc.allocate(_capacity);
                for(first != last; first++)
                    push_back(*first);
            }
            vector (const vector& x): _alloc(x._alloc), _vector(NULL), _size(x._size), _capacity(x._capacity)
            {
                /////peut etre empty dabord///////
                reserve(_capacity);
                for (size_type i = 0; i < x._size; i++)
                    push_back(x._vector[i]);
            }
            ~vector() 
            {
                for(size_type i = 0; i < _size; i++)
                    _alloc.destroy(_vector[i]);
                _alloc.deallocate(_vector, _capacity);
            }
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
            void reserve (size_type n)
            {
                if (n > _capacity)
                {
                    pointer temp;
                    temp = _alloc.allocate(n);
                    if (_capacity)
                    {
                        for(size_type i = 0; i < n; i++)
                        {
                            _alloc.construct(temp + i, *(_vector + i));
                            _alloc.destroy(_vector + i);
                        }
                        _alloc.deallocate(_vector, _capacity)
                    }
                    _capacity = n;
                    _vector = temp;
                }
            }
/////////////////////acces///////////////////////////////////
            front();
            back();
            operator[]();
            at();
/////////////////////modifiers///////////////////////////////
            assign();
            insert();
            erase();
            void push_back (const value_type& val)
            {
                if (_size == _capacity)
                {
                    if (_capacity == 0)
                        reserve(1);
                    else
                        reserve(capacity * 2);
                }
                _vector[_size] = val;
                _size++;
            }
            pop_back();
            clear();
            swap();
            
        private:
            allocator_type  _alloc;
            pointer         _vector;
            size_type       _size;
            size_type       _capacity;
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