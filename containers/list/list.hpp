/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/05 14:22:00 by nmbabazi         ###   ########.fr       */
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
            
///////////////////////iterator//////////////////////////
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
                pointeur        operator->()const{return _ptr;}
                ListIterator	&operator++(){_ptr = _ptr->next; return *this;}
                ListIterator	operator++(int){ListIterator it = *this; ++(*this); return it;}
                ListIterator	&operator--(){ _ptr = _ptr->prev; return *this;}
                ListIterator	operator--(int){ListIterator it = *this; --(*this); return it;}
                pointeur        get_ptr()const{return _ptr;}

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
                typedef const T*                        const_pointeur;
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
                pointeur        operator->()const{return _ptr;}
                ConstListIterator	&operator++(){_ptr = _ptr->next; return *this;}
                ConstListIterator	operator++(int){ConstListIterator it = *this; ++(*this); return it;}
                ConstListIterator	&operator--(){ _ptr = _ptr->prev; return *this;}
                ConstListIterator	operator--(int){ConstListIterator it = *this; --(*this); return it;}
                pointeur            get_ptr()const{return _ptr;}
                
                bool			operator==(const ConstListIterator &it){ return _ptr == it._ptr;}
                bool			operator!=(const ConstListIterator &it){ return _ptr != it._ptr;}
                
                private:
                    pointeur _ptr; 
            };

            class ListRIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef ptrdiff_t						difference_type;

                ListRIterator(pointeur ptr = 0): _ptr(ptr){}
                ListRIterator(ListRIterator const &cp){_ptr = cp._ptr;}
                ListRIterator operator=(ListRIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp._ptr;
                    return *this;
                }
                ~ListRIterator(){}
                
                value_type		&operator*()const {return _ptr->data;}
                pointeur        operator->()const{return _ptr;}
                ListRIterator	&operator++(){_ptr = _ptr->prev; return *this;}
                ListRIterator	operator++(int){ListRIterator it = *this; ++(*this); return it;}
                ListRIterator	&operator--(){ _ptr = _ptr->next; return *this;}
                ListRIterator	operator--(int){ListRIterator it = *this; --(*this); return it;}
                pointeur        get_ptr()const{return _ptr;}

                bool			operator==(const ListRIterator &it){ return _ptr == it._ptr;}
                bool			operator!=(const ListRIterator &it){ return _ptr != it._ptr;}
                
                private:
                    pointeur _ptr; 
            };

            class ConstListRIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef const T&                        const_ref;
                typedef const T*                        const_pointeur;
                typedef ptrdiff_t						difference_type;

                ConstListRIterator(pointeur ptr = 0): _ptr(ptr){}
                ConstListRIterator(ConstListRIterator const &cp){_ptr = cp._ptr;}
                ConstListRIterator operator=(ConstListRIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp._ptr;
                    return *this;
                }
                ~ConstListRIterator(){}
                
                const_ref		operator*()const {return _ptr->data;}
                pointeur        operator->()const{return _ptr;}
                ConstListRIterator	&operator++(){_ptr = _ptr->prev; return *this;}
                ConstListRIterator	operator++(int){ConstListRIterator it = *this; ++(*this); return it;}
                ConstListRIterator	&operator--(){ _ptr = _ptr->next; return *this;}
                ConstListRIterator	operator--(int){ConstListRIterator it = *this; --(*this); return it;}
                pointeur            get_ptr()const{return _ptr;}
                
                bool			operator==(const ConstListRIterator &it){ return _ptr == it._ptr;}
                bool			operator!=(const ConstListRIterator &it){ return _ptr != it._ptr;}
                
                private:
                    pointeur _ptr; 
            };
            
            typedef ListIterator        iterator;
            typedef ConstListIterator   c_iterator;
            typedef ListRIterator        r_iterator;
            typedef ConstListRIterator   cr_iterator;

            list (const allocator_type& alloc = allocator_type()):_alloc(alloc), _size(0){creatList();}
            list (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()):_alloc(alloc), _size(0)
            {
                creatList();
                for(size_type i = 0; i < n; i++)
                    push_back(val);
            }	
            template <class InputIterator>
            list (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last,const allocator_type& alloc = allocator_type()):_alloc(alloc), _size(0)
            {
                creatList();
                while(first != last)
                {
                    push_back(*first);
                    first++;
                }
            }	
            list (const list& x):_size(0)
            {
                creatList();
                c_iterator it = x.begin();
                c_iterator rit = x.end();
                while (it != rit)
                    push_back(*it++);
            }
            ~list()
            {
                clear();
            }
            list& operator= (const list& x)
            {
                if (_list != NULL)
                    clear();
                creatList();
                for(c_iterator start = x.begin(); start != x.end(); start++)
                    push_back(*start);
                return *this;
            }

            void    creatList()
            {
                _list = _alloc_node.allocate(1);
                _alloc.construct(&_list->data, value_type());
                _list->next = _list;
                _list->prev = _list;
            }
///////////////////////iterator//////////////////////////////
            iterator begin(){return iterator(_list->next);}
            c_iterator begin()const{return c_iterator(_list->next);}
            iterator end(){return iterator(_list);}
            c_iterator end()const{return c_iterator(_list);}
            r_iterator rbegin(){return r_iterator(_list->prev);}
            cr_iterator rbegin()const {return cr_iterator(_list->prev);}
            r_iterator rend(){return r_iterator(_list);}
            cr_iterator rend()const{return cr_iterator(_list);}
/////////////////////capacity////////////////////////////////
            bool empty() const{ return _size == 0;};
            size_type size() const{return _size;}
            size_type max_size() const{return _alloc_node.max_size();};
/////////////////////acces///////////////////////////////////
            reference front(){return _list->next->data;}
            const_reference front() const{return _list->next->data;}
            reference back(){return _list->prev->data;}
            const_reference back() const{return _list->prev->data;}
/////////////////////modifiers///////////////////////////////
            template <class InputIterator>
            void assign (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
            {
                clear();
                while (first != last)
                    push_back(*first++);
            }
            void assign (size_type n, const value_type& val)
            {
                clear();
                for(size_type i = 0; i < n; i++)
                    push_back(val);
            }
            void push_front (const value_type& val)
            {
                Node *new_node = _alloc_node.allocate(1);
                _alloc.construct(&new_node->data, val);
                new_node->next = _list->next;
                new_node->prev = _list;
                _list->next->prev = new_node;
                _list->next = new_node;
                _size++;
            }
            void push_back (const value_type& val)
            {
                Node *new_node = _alloc_node.allocate(1);
                _alloc.construct(&new_node->data, val);
                new_node->next = _list;
                new_node->prev = _list->prev;
                _list->prev->next = new_node;
                _list->prev = new_node;
                _size++;
            }
            void pop_front()
            {
                if (_size)
                {
                    Node *to_delete = _list->next;
                    _alloc.destroy(&to_delete->data);
                    _list->next = to_delete->next;
                    to_delete->next->prev=_list;
                    _alloc_node.deallocate(to_delete, 1);
                    _size--;
                }
            }
            void pop_back()
            {
                if (_size)
                {
                    Node *to_delete = _list->prev;
                    _alloc.destroy(&to_delete->data);
                    _list->prev = to_delete->prev;
                    to_delete->prev->next=_list;
                    _alloc_node.deallocate(to_delete, 1);
                    _size--;
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                Node *pos = position.get_ptr();
                Node *new_node = _alloc_node.allocate(1);
                _alloc.construct(&new_node->data, val);
                new_node->next = pos;
                new_node->prev = pos->prev;
                pos->prev->next = new_node;
                pos->prev = new_node;
                _size++;
                return iterator(new_node);
            }	
            void insert (iterator position, size_type n, const value_type& val)
            {
                for (size_type i = 0; i < n; i++)
                    position = insert(position, val);
            }
            template <class InputIterator>
            void insert (iterator position, typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
            {
                while (first != last)
                    position = insert(position, *first++);
            }
            iterator erase (iterator position)
            {
                Node *pos = position.get_ptr();
                iterator ret = iterator(pos->next);
                _alloc.destroy(&pos->data);
                pos->prev->next = pos->next;
                pos->next->prev = pos->prev;
                _alloc_node.deallocate(pos, 1);
                _size--;
                return ret;
            }
            iterator erase (iterator first, iterator last)
            {
                iterator ret= first; 
                while (first != last)
                    ret = erase(first++);
                return ret;
            }
            void swap (list& x)
            {
                ft::ft_swap(_size, x._size);
				ft::ft_swap(_list, x._list);
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n > _size)
                {
                    while (n > _size)
					    push_back(val);
                }
                else if (n < _size)
                {
                    while (n < _size)
					    pop_back();
                }
            }
            void clear()
            {
                while (_size)
                    pop_back();
            }
/////////////////////Operations///////////////////////////////
            void splice (iterator position, list& x)
            {
                for (iterator it = x.begin(); it != x.end();)
                {
                    iterator next = it->next;
                    splice(position, x, it);
                    it = next;
                }
            }
            void splice (iterator position, list& x, iterator i)
            {
                i->prev->next = i->next;
                i->next->prev = i->prev;
                
                i->prev = position->prev;
                i->next = position.get_ptr();
                
                position->prev->next = i.get_ptr();
                position->prev = i.get_ptr();
                _size++;
                x._size--;
            }	
            void splice (iterator position, list& x, iterator first, iterator last)
            {
                while(first != last)
                    splice(position, x, first++);
            }
            void remove (const value_type& val)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (*it == val)
                        erase(it);
                }
            }
            template <class Predicate>
            void remove_if (Predicate pred)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (pred(*it))
                        erase(it);
                }
            }
            void unique()
            {
                for (iterator it(begin()->next); it!= end(); it++)
                {
                    if (*it == it->prev->data)
                        erase(it--);
                }
            }
            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred)
            {
                
                for (iterator it(begin()->next); it!= end(); it++)
                {
                    if (binary_pred(*it, it->prev->data))
                        erase(it--);
                }
            }
            void merge (list& x)
            {
                if (&x == this)
                    return ;
                splice(end(), x);
                sort(); 
            }
            template <class Compare>
            void merge (list& x, Compare comp)
            {
                if (&x == this)
                    return ;
                splice(end(), x);
                sort(comp); 
            }
            void sort()
            {
                for (iterator start = begin(); start != end();)
                {							
					iterator hold = start->next;		
					for (iterator it = begin()->next; it != end();)
                    {
						iterator nxt = it->next;
						iterator prv = it->prev;
						if (*it < *prv){
                            Node* tmp= it->next;
							it->next->prev = prv.get_ptr();
							
							it->next = prv.get_ptr();
							it->prev = prv->prev;
							
							prv->prev->next = it.get_ptr();
							prv->prev = it.get_ptr();
							prv->next = tmp;
						}
						it = nxt;
					}
                    start = hold;
				}
            }
            template <class Compare>
            void sort (Compare comp)
            {
                for (iterator start = begin(); start != end();)
                {							
					iterator hold = start->next;		
					for (iterator it = begin()->next; it != end();)
                    {
						iterator nxt = it->next;
						iterator prv = it->prev;
						if (comp(*it, *prv)){
                            Node* tmp= it->next;
							it->next->prev = prv.get_ptr();
							
							it->next = prv.get_ptr();
							it->prev = prv->prev;
							
							prv->prev->next = it.get_ptr();
							prv->prev = it.get_ptr();
							prv->next = tmp;
						}
						it = nxt;
					}
                    start = hold;
				}

            }
            void reverse()
            {
                iterator first = begin();
                Node *tmp = _list->next;
				_list->next = _list->prev;
				_list->prev = tmp;
                for (size_type i = 0; i < _size; i++)
                {	
                    iterator nxt = first->next;
                    first->next = first->prev;
                    first->prev = nxt.get_ptr();
                    first = nxt;                 
				}

            }
/////////////////////overload///////////////////////////////
        friend bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
        {
            if (lhs._size != rhs._size)
                return false;
            c_iterator lit = lhs.begin();
            c_iterator rit = rhs.begin();
            while (lit != lhs.end())
            {
                if (*lit++ != *rit++)
                    return false;
            }
            return true;
        }
        friend bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){ return !(lhs == rhs);}
        friend bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
        {	
            c_iterator lit = lhs.begin();
		    c_iterator rit = rhs.begin();
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
        friend bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
        { 
            if (lhs == rhs || lhs < rhs)
                return true;
            return false;
        }
		friend bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
        { 
            if (!(lhs == rhs) && !(lhs < rhs)) 
                return true;
            return false;
        }
		friend bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
        { 
            if (lhs == rhs || lhs > rhs)
                return true;
            return false;
        }	
        friend void swap (list& x, list& y) { x.swap(y); }
    };

}

#endif