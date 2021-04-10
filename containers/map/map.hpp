/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:55:28 by nmbabazi          #+#    #+#             */
/*   Updated: 2021/04/10 13:05:17 by nmbabazi         ###   ########.fr       */
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
    template < class Key, class T, class Compare = ft::less<Key>, typename Alloc = ft::Allocator<pair<const Key,T> > > //creer l'operation less et pes pairs> class map;
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
                bool        isleaf(){return (right == NULL && left == NULL);}
				Node		*getprev()
                {
                    Node *ret;
                    if (isleaf() || this->right == NULL)
                    {  
                        ret = this->parent;
                        while (ret->data.first > this->data.first)
                            ret = ret->parent;
                        return (ret); 
                    }
                    else 
                    {
                        ret = this->left;
                        while(ret->right)
                            ret = ret->right;
                        return (ret);
                    }
                }
				Node		*getnext()
                {
                    Node *ret;
                    if (isleaf() || this->right == NULL)
                    {  
                        ret = this->parent;
                        while (ret->data.first < this->data.first)
                            ret = ret->parent;
                        return (ret); 
                    }
                    else 
                    {
                        ret = this->right;
                        while(ret->left)
                            ret = ret->left;
                        return (ret);
                    }
                }
			};
            allocator_type  _alloc;
			key_compare	    _comp;
            Node            _end;
            Node            _begin;
            Node            _root;
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
                ConstMapRIterator	&operator--(){return _ptr->getnext();}
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
			map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc), _root(NULL), _size(0)
            {
                initMaP();
            }
			template <class InputIterator>
			map (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc), _root(NULL), _size(0)
			{
            }
			map (const map& x)
            {
            }

			~map(){}

			map& operator=(const map& x){}
///////////////////////iterator//////////////////////////////
			iterator begin(){return iterator(getBegin(_root));}
			const_iterator begin() const{return iterator(getBegin(_root));}
			iterator end(){_end->parent = getEnd(_root); return iterator(_end);}
			const_iterator end() const{_end->parent = getEnd(_root); return iterator(_end);}

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
/////////////////////capacity////////////////////////////////
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
/////////////////////acces///////////////////////////////////
			mapped_type& operator[] (const key_type& k)
            {
                Node *ret;
                if ((ret = search_bykey(k, _root)))
                    return ret->data.second;
                value_type pr(k,mapped_type());
                ret = my_insert(pr, &_root);
                    return ret->data.second;
            }
/////////////////////modifiers///////////////////////////////
			pair<iterator,bool> insert (const value_type& val)
            {
                Node *ret;
                if ((ret = search_bykey(val.first, _root)))
                    return ft::pair<iterator, bool>(iterator(ret), false);
                ret = my_insert(val, &_root);
                if (_root != NULL)
                _size++;
                return ft::pair<iterator, bool>(iterator(ret), true);
            }
			iterator insert (iterator position, const value_type& val)
            {
                Node *ret;
                if ((ret = search_bykey(val.first, _root)))
                    return iterator(ret);
                ret = my_insert(val, &_root);
                _size++;
                return iterator(ret);
            }
			template <class InputIterator>
			void insert (typename ft::Enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
            {
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
            }
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);
			void swap (map& x);
			void clear();
/////////////////////observer///////////////////////////////        
			key_compare key_comp() const;
			key_compare value_comp() const; ///checker le retour 
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
/////////////////////utiles///////////////////////////////
            void    printMap(){printMapprivate(_root);}
        private:
            Node    *my_insert(value_type val, Node **tree)
            {
                if (!*tree)
                {
                    *tree = new_node(val);
                    (*tree)->parent = NULL;
                    return *tree;
                }
                if (_comp(val.first, (*tree)->data.first))
                {
                    if ((*tree)->left == NULL)
                        {
                            (*tree)->left = new_node(val);
                            (*tree)->left->parent = *tree;
                            return (*tree)->left;
                        }
                        if ((*tree)->left == _begin)
                        {
                            (*tree)->left = new_node(val);
                            (*tree)->left->parent = *tree;
                            return (*tree)->left;
                        }
                    my_insert(val, &(*tree)->left);
                }
                if (!_comp(val.first, (*tree)->data.first))
                {
                    if ((*tree)->right == NULL)
                        {
                            (*tree)->right = new_node(val);
                            (*tree)->right->parent = *tree;
                            return (*tree)->right;
                        }
                    my_insert(val, &(*tree)->right);
                }
                return (NULL);
            }
            void    printMapprivate(Node *tree)
            {
                if (tree)
                {
                    if (tree->left)
                    {
                        printMapprivate(tree->left);
                    }
                    std::cout << tree->data.first << " = " << tree->data.second <<  std::endl;
                    if (tree->right)
                    {
                        printMapprivate(tree->right);
                    }
                }
                else
                    std::cout << "The tree is empty\n";
            }
            Node    *new_node(value_type val)
            {
                Node    *new_node = _alloc_node.allocate(1);
                _alloc.construct(&new_node->data, val);
                new_node->right = NULL;
                new_node->left = NULL;
                return (new_node);
            }
            Node *search_bykey(key_type key, Node *tree)
            {
                if (tree == NULL)
                    return NULL;
                if (tree->data.first == key)
                    return tree;
                if (_comp(key, tree->data.first))
                    return search_bykey(key, tree->left);
                if (!_comp(key, tree->data.first) && tree->data.first != key)
                    return search_bykey(key, tree->right);
                return (NULL);
            }


            Node    *getBegin(Node *tree)
            {
                if (!tree)
                    return (NULL);
                if (!tree->left)
                    return (tree);
                else
                    return (getBegin(tree->left));  
            }
            Node    *getEnd(Node *tree)
            {
                if (!tree)
                    return (NULL);
                if (!tree->right)
                    return tree;
                else
                    return (getEnd(tree->right));  
            }
            void    initMap()
            {
				_root.left = _begin;
                _root->right = _end;
				_begin.parent = _root;
				_begin.next = NULL;
				_begin.prev = NULL;
				_end.parent = _root;
				_end.next = NULL;
				_end.prev = NULL; 
            }
    };
}

#endif