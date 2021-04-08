/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:55:28 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/04/08 16:13:06 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "pair.hpp"
#include "../../allocator.hpp"
#include "../../utils.hpp"

namespace ft
{
    template < class Key, class T, class Compare = less<Key>, typename Alloc = ft::Allocator<pair<const Key,T> > > //creer l'operation less et pes pairs> class map;
    class map
    {
        public:
///////////////////////typedef//////////////////////////////
			typedef Key									key_type;     
			typedef T									mapped_type;
			typedef pair<const key_type,mapped_type>	value_type;
			typedef Compare								key_compare;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
	        typedef ptrdiff_t							difference_type; 
    		typedef size_t								size_type;
			typedef Alloc								allocator_type;
            
        private:
			struct Node
			{
				value_type  data;
				Node        *right;
				Node        *left;
				Node		*parent;
				Node		*getprev(){}
				Node		*getnext(){}
			};
            allocator_type  _alloc;
			key_compare		_comp;
            Node            *_root;
            size_type       _size;
            ft::Allocator<Node> _alloc_node; 
        public:	
///////////////////////iterator/////////////////////////////////
 			class MapIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef ptrdiff_t						difference_type;

                MapIterator(pointeur ptr = 0): _ptr(ptr){}
                MapIterator(MapIterator const &cp){_ptr = cp.get_ptr();}
                MapIterator operator=(MapIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp.get_ptr();
                    return *this;
                }
                ~MapIterator(){}
                
                value_type		&operator*()const {return _ptr->data;}
                value_type       *operator->()const{return &(operator*());}
                MapIterator	&operator++(){_ptr = _ptr->getnext(); return *this;}
                MapIterator	operator++(int){MapIterator it = *this; ++(*this); return it;}
                MapIterator	&operator--(){ _ptr = _ptr->getprev(); return *this;}
                MapIterator	operator--(int){MapIterator it = *this; --(*this); return it;}
                pointeur        get_ptr()const{return _ptr;}

                bool			operator==(const MapIterator &it){ return _ptr == it.get_ptr();}
                bool			operator!=(const MapIterator &it){ return _ptr != it.get_ptr();}
                
                private:
                    pointeur _ptr; 
            };

            class ConstMapIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef const T&                        const_ref;
                typedef const T*                        const_pointeur;
                typedef ptrdiff_t						difference_type;

                ConstMapIterator(pointeur ptr = 0): _ptr(ptr){}
                ConstMapIterator(MapIterator const &cp){_ptr = cp.get_ptr();}
                ConstMapIterator operator=(ConstMapIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp.get_ptr();
                    return *this;
                }
                ~ConstMapIterator(){}
                
                const_ref		operator*()const {return _ptr->data;}
                value_type       *operator->()const{return &(operator*());}
                ConstMapIterator	&operator++(){_ptr = _ptr->getnext(); return *this;}
                ConstMapIterator	operator++(int){ConstMapIterator it = *this; ++(*this); return it;}
                ConstMapIterator	&operator--(){ _ptr = _ptr->getprev(); return *this;}
                ConstMapIterator	operator--(int){ConstMapIterator it = *this; --(*this); return it;}
                pointeur            get_ptr()const{return _ptr;}
                
                bool			operator==(const ConstMapIterator &it){ return _ptr == it.get_ptr();}
                bool			operator!=(const ConstMapIterator &it){ return _ptr != it.get_ptr();}
                
                private:
                    pointeur _ptr; 
            };

            class MapRIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef ptrdiff_t						difference_type;

                MapRIterator(pointeur ptr = 0): _ptr(ptr){}
                MapRIterator(MapRIterator const &cp){_ptr = cp.get_ptr();}
                MapRIterator(MapIterator const &cp){_ptr = cp.get_ptr()->prev;}
                MapRIterator operator=(MapRIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp.get_ptr();
                    return *this;
                }
                ~MapRIterator(){}
                
                value_type		&operator*()const {return _ptr->data;}
                value_type       *operator->()const{return &(operator*());}
                MapRIterator	&operator++(){_ptr = _ptr->getprev(); return *this;}
                MapRIterator	operator++(int){MapRIterator it = *this; ++(*this); return it;}
                MapRIterator	&operator--(){ _ptr = _ptr->getnext(); return *this;}
                MapRIterator	operator--(int){MapRIterator it = *this; --(*this); return it;}
                pointeur        get_ptr()const{return _ptr;}

                bool			operator==(const MapRIterator &it){ return _ptr == it.get_ptr();}
                bool			operator!=(const MapRIterator &it){ return _ptr != it.get_ptr();}
                
                private:
                    pointeur _ptr; 
            };

            class ConstMapRIterator
            {
                public:
                typedef Node*                           pointeur;
                typedef const T&                        const_ref;
                typedef const T*                        const_pointeur;
                typedef ptrdiff_t						difference_type;

                ConstMapRIterator(pointeur ptr = 0): _ptr(ptr){}
                ConstMapRIterator(MapRIterator const &cp){_ptr = cp.get_ptr();}
                ConstMapRIterator(MapIterator const &cp){_ptr = cp.get_ptr()->prev;}
                ConstMapRIterator operator=(ConstMapRIterator const &cp)
                { 
                    if (this != &cp)
                        this->_ptr = cp.get_ptr();
                    return *this;
                }
                ~ConstMapRIterator(){}
                
                const_ref		operator*()const {return _ptr->data();}
                value_type       *operator->()const{return &(operator*());}
                ConstMapRIterator	&operator++(){ return _ptr->getprev();}
                ConstMapRIterator	operator++(int){ConstMapRIterator it = *this; ++(*this); return it;}
                ConstMapRIterator	&operator--(){return _prt->getnext()}
                ConstMapRIterator	operator--(int){ConstMapRIterator it = *this; --(*this); return it;}
                pointeur            get_ptr()const{return _ptr;}
                
                bool			operator==(const ConstMapRIterator &it){ return _ptr == it.get_ptr();}
                bool			operator!=(const ConstMapRIterator &it){ return _ptr != it.get_ptr();}
                
                private:
                    pointeur _ptr; 
            };
            
            typedef MapIterator        iterator;
            typedef ConstMapIterator   const_iterator;
            typedef MapRIterator        reverse_iterator;
            typedef ConstMapRIterator   const_reverse_iterator;

///////////////////////constructeur//////////////////////////////
			map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc){}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc)
			{}
			map (const map& x);

			~map();

			map& operator=(const map& x);
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
			mapped_type& operator[] (const key_type& k);
/////////////////////modifiers///////////////////////////////
			pair<iterator,bool> insert (const value_type& val);
			iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last);
			
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);
			void swap (map& x);
			void clear();
/////////////////////observer///////////////////////////////        
			key_compare key_comp() const;
			value_compare value_comp() const;
/////////////////////operation///////////////////////////////
			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
			size_type count (const key_type& k) const;
			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>             equal_range (const key_type& k);
    };
}

#endif