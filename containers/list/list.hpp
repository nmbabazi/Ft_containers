/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/01 17:53:48 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "iterator.hpp"
#include "../../allocator.hpp"
#include "../../utils.hpp"

namespace ft
{
    template <typename T, typename Alloc = ft::Allocator<T> > 
    class list
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
            
        private:   
			struct Node
			{
				value_type  data;
				Node        *next;
				Node        *prev;
			};
            allocator_type  _alloc;
            Node            *_list;
            size_type       _size;
            
            push_node(Node **head, value_type val = value_type())
            {
                Node *new_node = this->_alloc()
            }
///////////////////////constructeur//////////////////////////
        public:
            typedef ListIterator<Node>         iterator;
    		typedef RListIterator<Node>        r_iterator;

            list (const allocator_type& alloc = allocator_type()):_list(NULL), _alloc(alloc), _size(0){}
            list (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
            {
                
            }	
            template <class InputIterator>
            list (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());	
            list (const list& x);
            ~list();
            list& operator= (const list& x);
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
            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;
/////////////////////modifiers///////////////////////////////
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last);
            void assign (size_type n, const value_type& val);
            void push_front (const value_type& val);
            void pop_front();
            void push_back (const value_type& val);
            void pop_back();
            iterator insert (iterator position, const value_type& val);	
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);
            void swap (list& x);
            void resize (size_type n, value_type val = value_type());
            void clear();
/////////////////////Operations///////////////////////////////	
            void splice (iterator position, list& x);
            void splice (iterator position, list& x, iterator i);	
            void splice (iterator position, list& x, iterator first, iterator last);
            void remove (const value_type& val);
            template <class Predicate>
            void remove_if (Predicate pred);
            void unique();
            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred);
            void merge (list& x);
            template <class Compare>
            void merge (list& x, Compare comp);
            void sort();
            template <class Compare>
            void sort (Compare comp);
            void reverse();
/////////////////////overload///////////////////////////////
            friend bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);	
            friend bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
            friend bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
            friend bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);	
            friend bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
            friend bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
            friend void swap (list<T,Alloc>& x, list<T,Alloc>& y);
    };

}

#endif