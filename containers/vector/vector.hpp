/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/03/28 17:31:08 by nmbabazi         ###   ########.fr       */
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
///////////////////////constructeur//////////////////////////////               
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
            vector& operator=(const vector& x)
            {
                //remplacer le curent content // empty;
                //modifier la size //pushback tout x
            }
///////////////////////iterator//////////////////////////////
            iterator begin(){return iterator(_vector);}
            c_iterator begin()const {return c_iterator(_vector);}
            iterator end(){return iterator(_vector + _size);}
            c_iterator end()const{return c_iterator(_vector + _size);}
            r_iterator rbegin(){return r_iterator(_vector - 1);}
            cr_iterator rbegin()const {return cr_iterator(_vector - 1);}
            r_iterator rend(){return iterator(_vector + _size - 1);}
            cr_iterator rend()const{return c_iterator(_vector + _size - 1);}
/////////////////////capacity////////////////////////////////
            size_type size()const{return _size;}
            size_type max_size()const{return _alloc.max_size();};
            bool empty() const { return _size == 0;}
            size_type capacity() const {return _capacity;}
            void resize(size_type n, value_type val = value_type())
            {
                if (n < _size)
                {
                    for (size_type i = n; i < _size; i++)
                        _alloc.destroy(_vector + i);
                    _size = n;
                }
                else if (n >_size)
                {
                    for (size_type i = _size; i < n; i++)
                        push_back(val);
                }
            }
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
            reference front(){return _vector[0];}
            const_reference front() const{return _vector[0];}
            reference back(){return _vector[_size - 1];}
            const_reference back() const{return _vector[_size - 1];}
            reference operator[] (size_type n){return _vector[n];}
            const_reference operator[] (size_type n)const{return _vector[n];}

            class out_of_range: public std::exception
			{
			public:
				virtual const char *what() const throw(){return "vector::_M_range_check";}
			};
            reference at (size_type n)
            {
                if (n >= _size)
                    throw out_of_range;
                else
                    return _vector[n]; 
            }
            const_reference at (size_type n) const
            {
                if (n >= _size)
                    throw out_of_range;
                else
                    return _vector[n]; 
            }
/////////////////////modifiers///////////////////////////////
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename ft::enable_if<std::numeric_limits<InputIterator>::is_integer, InputIterator>::type = NULL)
            {
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_vector + i);
                _size = 0;
                for (first != last; first++)
                {
                    push_back(*first);
                    first++;
                }
            }
            void assign (size_type n, const value_type& val)
            {
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_vector + i);
                _size = 0;
                for (size_type i = 0; i < n; i++)
                {
                    push_back(val);
                    i++;
                }
            }
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
            void pop_back()
            {
                if (_size)
                {
                    _alloc.destroy(_vector[size- 1]);
                    _size--;
                }
            }
        /*
            iterator insert (iterator position, const value_type& val)
            {
                difference_type diff = position - begin();			
				insert(position, 1, val);
				return begin() + diff;
                    
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                pointer temp;
                size_type l = 0;
                size_type newCapacity;
                if (_size + n > _capacity)
                {
                    temp = _alloc.allocate(_capacity + n);
                    newCapacity = _capacity + n;
                }
                else
                {
                    temp = _alloc.allocate(_capacity);
                    newCapacity = _capacity + n;
                }
                for(iterator start = begin(); start != position; start++;)
                {
                    _alloc.construct(temp + l, *start);
                    _alloc.destroy(&(*start));
                    l++;
                }
                for(size_type i = 0; i <= n; i++)
                {
                    _alloc.construct(temp + l, val);
                    l++;
                }
                for(position != end(); position++)
                {
                    _alloc.construct(temp + l, *(position));
                    _alloc.destroy(&(*position));
                    l++;
                }
                _size = l;
                _capacity = newCapacity;
                _alloc.deallocate(_vector, _capacity);
                _vector = temp;
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<std::numeric_limits<InputIterator>::is_integer, InputIterator>::type = NULL)
            {
                pointer temp;
                size_type l = 0;
                size_type newCapacity;
                if (_size + n > _capacity)
                {
                    temp = _alloc.allocate(_capacity + n);
                    newCapacity = _capacity + n;
                }
                else
                {
                    temp = _alloc.allocate(_capacity);
                    newCapacity = _capacity + n;
                }
                for(iterator start = begin(); start != position; start++;)
                {
                    _alloc.construct(temp + l, *start);
                    _alloc.destroy(&(*start));
                    l++;
                }
                for(first != last; first++)
                {
                    _alloc.construct(temp + l, *first);
                    l++;
                }
                for(position != end(); position++)
                {
                    _alloc.construct(temp + l, *(position));
                    _alloc.destroy(&(*position));
                    l++;
                }
                _size = l;
                _capacity = newCapacity;
                _alloc.deallocate(_vector, _capacity);
                _vector = temp;
                
            }
            iterator erase (iterator position)
            {
                /////do a leftshift and rightshift fonction
            }
            iterator erase (iterator first, iterator last)
            {
                pointer temp;
                size_type l = 0;
                difference_type diff = last - first;
                size_type newCapacity;
                if (diff > _capacity)
                {
                    temp = _alloc.allocate(_capacity + diff);
                    newCapacity = _capacity + diff;
                }
                else
                {
                    temp = _alloc.allocate(_capacity);
                    newCapacity = _capacity + diff;
                }
                for(iterator start = begin(); start != first; start++;)
                {
                    _alloc.construct(temp + l, *start);
                    _alloc.destroy(&(*start));
                    l++;
                }
                for(first != last; first++)
                    _alloc.destroy(&(*first));
                for(last != end(); last++)
                {
                    _alloc.construct(temp + l, *(last));
                    _alloc.destroy(&(*last));
                    l++;
                }
                _alloc.deallocate(_vector, _capacity);
                _capacity = newCapacity;
                _vector = temp;
            }*/
            void clear()
            {
                while (_size)
                    pop.back();
            }
            void swap (vector& x)
            {
                
            }
            
        private:
            //////utils fonctions///

            shiftRight();
            shiftLeft();
            vect_copy();
            
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