/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/01 14:03:48 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

namespace ft
{
    template <class T> 
    class list
    {
///////////////////////typedef//////////////////////////////        

///////////////////////constructeur//////////////////////////
        public:          
            list (const allocator_type& alloc = allocator_type());	
            list (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type());	
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