/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/16 10:46:43 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "iterator.hpp"
#include "../../allocator.hpp"
#include "../../utils.hpp"

namespace ft
{
    template <typename T, typename Alloc = ft::Allocator<T> > 
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
    		typedef VectRIterator<T>        reverse_iterator;
        	typedef ConstVectIterator<T>    const_iterator;
    		typedef ConstVectRIterator<T>   const_reverse_iterator;
            
        private:
            pointer         _vector;
            allocator_type  _alloc;
            size_type       _capacity;
            size_type       _size;
///////////////////////constructeur//////////////////////////////
        public:          
            vector(const allocator_type& alloc = allocator_type()):_alloc(alloc), _capacity(0),_size(0){_vector = NULL;}
            vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):_alloc(alloc), _capacity(0),_size(0)
            {
                _vector = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                     push_back(val);
            }
            template <class InputIterator>
            vector (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()):_vector(NULL), _alloc(alloc),_capacity(0), _size(0)
            {
                while(first != last)
                {
                    push_back(*first);
                    first++;
                }
            }
            vector (const vector& x): _alloc(x._alloc), _capacity(x._size), _size(0)
            {
                _vector = _alloc.allocate(_capacity);
                for (size_type i = 0; i < x._size; i++)
                    push_back(x._vector[i]);
            }
            ~vector() 
            {
                while(_size)
                    pop_back();
                _alloc.deallocate(_vector, _capacity);
            }
            vector& operator=(const vector& x)
            {
                if (_vector != NULL)
                    clear();
                if (_capacity < x._capacity)
                    reserve(x._capacity);
                for(const_iterator start = x.begin(); start != x.end(); start++)
                    push_back(*start);
                return *this;
            }
///////////////////////iterator//////////////////////////////
            iterator begin(){return iterator(_vector);}
            const_iterator begin()const {return const_iterator(_vector);}
            iterator end(){return iterator(_vector + _size);}
            const_iterator end()const{return const_iterator(_vector + _size);}
            reverse_iterator rbegin(){return reverse_iterator(_vector + _size - 1);}
            const_reverse_iterator rbegin()const {return const_reverse_iterator(_vector + _size - 1);}
            reverse_iterator rend(){return reverse_iterator(_vector - 1);}
            const_reverse_iterator rend()const{return const_reverse_iterator(_vector - 1);}
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
                    if (n > this->max_size())
					    throw std::length_error("vector::reserve");
                    pointer temp = _alloc.allocate(n);
                    int i = 0;
                    for (iterator it = begin(); it != end(); it++)
                    {
                        _alloc.construct(temp + i, *it);
                        _alloc.destroy(it.get_ptr());
                        i++;
                    }
                    _alloc.deallocate(_vector, _capacity);
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
            reference at (size_type n)
            {
                if (n >= _size)
                    throw std::out_of_range("vector::_M_range_check");
                else
                    return _vector[n]; 
            }
            const_reference at (size_type n) const
            {
                if (n >= _size)
                    throw std::out_of_range("vector::_M_range_check");
                else
                    return _vector[n]; 
            }
/////////////////////modifiers///////////////////////////////
            template <class InputIterator>
            void assign (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
            {
                clear();
                while(first != last)
                {
                    push_back(*first);
                    first++;
                }
            }
            void assign (size_type n, const value_type& val)
            {
                clear();
                for (size_type i = 0; i < n; i++)
                {
                    
                    push_back(val);
                }
            }
            void push_back (const value_type& val)
            {
                if (_size == _capacity)
                {
                    if (_capacity == 0)
                        reserve(1);
                    else
                        reserve(_capacity * 2);
                }
                _alloc.construct(&_vector[_size], val);
                _size++;
            }
            void pop_back()
            {
                if (_size)
                {
                    _alloc.destroy(_vector + (_size - 1));
                    _size--;
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                difference_type diff = position - begin();			
				insert(position, 1, val);
				return begin() + diff; 
                    
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                vector tmp;
                tmp.reserve(_capacity + n);
                iterator it = this->begin();
                while (it < position)
                    tmp.push_back(*it++);
                for (size_type i = 0; i < n; i++)
                    tmp.push_back(val);
                while (it != this->end())
                    tmp.push_back(*it++);
                this->swap(tmp);
            }
            template <class InputIterator>
            void insert (iterator position, typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
            {
                size_type n = 0;
                for (InputIterator count = first; count != last; count++)
                        n++;  
                vector tmp;
                tmp.reserve(_capacity + n);
                iterator it = this->begin();
                while (it < position)
                    tmp.push_back(*it++);
                while (first != last)
                    tmp.push_back(*first++);
                while (it != this->end())
                    tmp.push_back(*it++);
                this->swap(tmp);
            }
            iterator erase (iterator position)
            {
                vector tmp;
                difference_type diff = position - begin();	
                tmp.reserve(_capacity);
                iterator it = this->begin();
                while (it < position)
                    tmp.push_back(*it++);
                it++;
                while (it != this->end())
                    tmp.push_back(*it++);
                this->swap(tmp);
                return begin() + diff;
            }
            iterator erase (iterator first, iterator last)
            {
                vector tmp;
                difference_type diff = first - begin();
                tmp.reserve(_capacity);
                iterator it = this->begin();
                while (it < first)
                    tmp.push_back(*it++);
                while (last != this->end())
                    tmp.push_back(*last++);
                this->swap(tmp);
                return begin() + diff;
            }
            void clear()
            {
                while (_size)
                    pop_back();
            }
            void swap (vector& x)
            {
                ft::ft_swap(_vector, x._vector);
                ft::ft_swap(_alloc, x._alloc);
                ft::ft_swap(_size, x._size);
                ft::ft_swap(_capacity, x._capacity);
            }
            /////////////////////relational operators///////////////////////////////
            friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {
                if (lhs._size != rhs._size)
                    return false;
                for (size_t i = 0; i < lhs._size; i++)
                {
                    if (lhs._vector[i] != rhs._vector[i])
                        return false;
                }
                return true;
            }
            friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {	
                const_iterator lit = lhs.begin();
                const_iterator rit = rhs.begin();

                while (lit != lhs.end())
                {
                    if (rit == rhs.end() || *rit < *lit)
                        return false;
                    else if (*lit < *rit)
                        return true;
                    ++lit;
                    ++rit;
                }
                return rit != rhs.end();
            }
    };
    /////////////////////non-member overloads///////////////////////////////
    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs ) { return !(lhs == rhs);}
    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs )
    { 
        if (lhs == rhs || lhs < rhs)
            return true;
        return false;
    }
    template <class T, class Alloc>
    bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
    { 
        if (!(lhs == rhs) && !(lhs < rhs)) 
            return true;
        return false;
    }
    template <class T, class Alloc>
    bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
    { 
        if (lhs == rhs || lhs > rhs)
            return true;
        return false;
    }
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y);}
}

#endif