/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/02 16:57:18 by nmbabazi         ###   ########.fr       */
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
    template <typename T, typename  Alloc = ft::Allocator<T> > 
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
            ft::Allocator<Node> _alloc_node;
            
///////////////////////constructeur//////////////////////////
        public:

            class ListIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef ptrdiff_t						difference_type;

                ListIterator(pointeur ptr = 0): _ptr(ptr){}
                ListIterator(ListIterator const &cp){_ptr = cp._ptr;}
                ListIterator operator=(ListIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp._ptr;
                    return *this;
                }
                ~ListIterator(){}
                
                value_type		&operator*()const {return _ptr->data;}
                value_type		*operator->()const{return _ptr;}
                ListIterator	&operator++(){_ptr = _ptr->next; return *this;}
                ListIterator	operator++(int){ListIterator it = *this; ++(*this); return it;}
                ListIterator	&operator--(){ _ptr = _ptr->prev; return *this;}
                ListIterator	operator--(int){ListIterator it = *this; --(*this); return it;}

                bool			operator==(const ListIterator &it){ return _ptr == it._ptr;}
                bool			operator!=(const ListIterator &it){ return _ptr != it._ptr;}
                
                private:
                    pointeur _ptr; 
            };

            class ConstListIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef const T&                        const_ref;
                typedef ptrdiff_t						difference_type;

                ConstListIterator(pointeur ptr = 0): _ptr(ptr){}
                ConstListIterator(ConstListIterator const &cp){_ptr = cp._ptr;}
                ConstListIterator operator=(ConstListIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp._ptr;
                    return *this;
                }
                ~ConstListIterator(){}
                
                const_ref		operator*()const {return _ptr->data;}
                value_type		*operator->()const{return _ptr;}
                ConstListIterator	&operator++(){_ptr = _ptr->next; return *this;}
                ConstListIterator	operator++(int){ConstListIterator it = *this; ++(*this); return it;}
                ConstListIterator	&operator--(){ _ptr = _ptr->prev; return *this;}
                ConstListIterator	operator--(int){ConstListIterator it = *this; --(*this); return it;}

                bool			operator==(const ConstListIterator &it){ return _ptr == it._ptr;}
                bool			operator!=(const ConstListIterator &it){ return _ptr != it._ptr;}
                
                private:
                    pointeur _ptr; 
            };
            
            // class ListRIterator
            // {
            //     public:
            //     typedef Node*                           pointeur;
            //     typedef ptrdiff_t						difference_type;

            //     ListRIterator(pointeur ptr = 0): _ptr(ptr){}
            //     ListRIterator(ListRIterator const &cp){_ptr = cp._ptr;}
            //     ListRIterator operator=(ListRIterator const &cp)
            //     { 
            //         if (this != &cp)
            //             this->_ptr = cp._ptr;
            //         return *this;
            //     }
            //     ~ListRIterator(){}
                
            //     value_type		&operator*()const {return *(_ptr->data);}
            //     value_type		*operator->()const{return _ptr->data;}
            //     ListRIterator	&operator++(){_ptr = _ptr->prev; return *this;}
            //     ListRIterator	operator++(int){ListRIterator it = *this; ++(*this); return it;}
            //     ListRIterator	&operator--(){ _ptr = _ptr->next; return *this;}
            //     ListRIterator	operator--(int){ListRIterator it = *this; --(*this); return it;}

            //     bool			operator==(const ListRIterator &it){ return _ptr == it._ptr;}
            //     bool			operator!=(const ListRIterator &it){ return _ptr != it._ptr;}
                
            //     private:
            //         pointeur _ptr; 
            // };
            
            typedef ListIterator        iterator;
            typedef ConstListIterator   c_iterator;
    		//typedef ListRIterator       r_iterator;

            list (const allocator_type& alloc = allocator_type()):_list(NULL), _alloc(alloc), _size(0){}
            list (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()):_list(NULL), _alloc(alloc), _size(0)
            {
                for(size_type i = 0; i < n; i++)
                    push_back(val);
            }	
            template <class InputIterator>
            list (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last,const allocator_type& alloc = allocator_type()):_list(NULL), _alloc(alloc), _size(0)
            {
                while(first != last)
                {
                    push_back(*first);
                    first++;
                }
            }	
            list (const list& x):_list(NULL), _size(0)
            {
                c_iterator it = x.begin();
                c_iterator rit = x.end();
                while (it != rit)
                    push_back(*it++);
            }
            ~list()
            {
                size_type size = size;
                iterator start = begin();
                while(_size)
                    pop_back();
                _alloc_node.deallocate(start, size);
            }
            list& operator= (const list& x)
            {
                if (_list != NULL)
                    clear();
                for(iterator start = x.begin(); start != x.end(); start++)
                    push_back(*start);
                return *this;
            }
///////////////////////iterator//////////////////////////////
            iterator begin()
            {
                Node *tmp = _list;
                while (tmp->prev)
                     tmp = tmp->prev;
                return iterator(tmp);}
            c_iterator begin()const
            {
                Node *tmp = _list;
                while (tmp->prev)
                     tmp = tmp->prev;
                return c_iterator(tmp);}
            iterator end()
            {
                Node *tmp = _list;
                while (tmp)
                    tmp = tmp->next;
                return iterator(tmp);}
            c_iterator end()const
            {
                Node *tmp = _list;
                while (tmp)
                    tmp = tmp->next;
                return c_iterator(tmp);}
            // r_iterator rbegin(){return r_iterator(_list + _size - 1);}
            // cr_iterator rbegin()const {return cr_iterator(_list + _size - 1);}
            // r_iterator rend(){return r_iterator(_list - 1);}
            // cr_iterator rend()const{return cr_iterator(_list - 1);}
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
            void push_front (const value_type& val)
            {
                Node *new_node = _alloc_node.allocate(1);
                _alloc.construct(&new_node->data, val);
                new_node->next = NULL;
                new_node->prev = NULL;
                Node *it;
                if (_list)
                {
                    it = _list;
                    while(it->prev)
                        it = it->prev;
                    it->prev = new_node;
		            new_node->next = it;
                    new_node->prev = NULL;
                }
                else 
                    _list = new_node;    
                _size++;
            }
            void pop_front();
            void push_back (const value_type& val)
            {
                Node *new_node = _alloc_node.allocate(1);
                _alloc.construct(&new_node->data, val);
                new_node->next = NULL;
                new_node->prev = NULL;
                Node *it;
                if (_list)
                {
                    it = _list;
                    while(it->next)
                        it = it->next;
                    it->next = new_node;
		            new_node->prev = it;
                    new_node->next = NULL;
                }
                else 
                    _list = new_node;    
                _size++;
            }
            void pop_back()
            {
                iterator it = begin();
                iterator rit = end();
                if (it != rit)
                {
                    _alloc.destroy(&it->data);
                    _size--;
                } 
            }
            iterator insert (iterator position, const value_type& val);	
            void insert (iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);
            void swap (list& x);
            void resize (size_type n, value_type val = value_type());
            void clear()
            {
                while (_size)
                    pop_back();
            }
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

            void printlist()                                  //////////////to delete////////////////////////////
			{
                Node *tmp = _list;
                while (tmp->prev)
                    tmp = tmp->prev;
                while (tmp)
                {
                    std::cout << "-" << tmp->data << "- ";
                    tmp = tmp->next;
                }
				std::cout << std::endl;
			}
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