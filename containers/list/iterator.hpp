/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/02 14:29:00 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
            
    template <typename T, typename Node>
    class ListIterator
    {
        public:
        typedef T                               value_type;
        typedef Node*                           pointeur;
        typedef ptrdiff_t						difference_type;

        ListIterator(pointeur ptr = 0): _ptr(ptr){}
        ListIterator(ListIterator<T, Node> const &cp){_ptr = cp._ptr;}
        ListIterator operator=(ListIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;
        }
        ~ListIterator(){}
        
        value_type		&operator*()const {return *(_ptr->data);}
        value_type		*operator->()const{return _ptr->data;}
        ListIterator	&operator++(){_ptr = _ptr->next; return *this;}
        ListIterator	operator++(int){ListIterator it = *this; ++(*this); return it;}
        ListIterator	&operator--(){ _ptr = _ptr->prev; return *this;}
        ListIterator	operator--(int){ListIterator it = *this; --(*this); return it;}

        bool			operator==(const ListIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const ListIterator &it){ return _ptr != it._ptr;}
        
        private:
            pointeur _ptr; 
    };

    template <typename T, typename Node>
    class ConstListIterator
    {
        public:
        typedef T                               value_type;
        typedef const T&                        const_reference;
        typedef Node*                           pointeur;
        typedef ptrdiff_t						difference_type;

        ConstListIterator(pointeur ptr = 0): _ptr(ptr){}
        ConstListIterator(ConstListIterator<T, Node> const &cp){_ptr = cp._ptr;}
        ConstListIterator operator=(ConstListIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;
        }
        ~ConstListIterator(){}
        
        const_reference operator*()const {return *(_ptr->data);}
        value_type		*operator->()const{return _ptr->data;}
        ConstListIterator	&operator++(){_ptr = _ptr->next; return *this;}
        ConstListIterator	operator++(int){ConstListIterator it = *this; ++(*this); return it;}
        ConstListIterator	&operator--(){ _ptr = _ptr->prev; return *this;}
        ConstListIterator	operator--(int){ConstListIterator it = *this; --(*this); return it;}

        bool			operator==(const ConstListIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const ConstListIterator &it){ return _ptr != it._ptr;}
        
        private:
            pointeur _ptr; 
    };

    template <typename T, typename Node>
    class ListRIterator
    {
        public:
        typedef T                               value_type;
        typedef Node*                           pointeur;
        typedef ptrdiff_t						difference_type;

        ListRIterator(pointeur ptr = 0): _ptr(ptr){}
        ListRIterator(ListRIterator<T, Node> const &cp){_ptr = cp._ptr;}
        ListRIterator operator=(ListRIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;
        }
        ~ListRIterator(){}
        
        value_type		&operator*()const {return *(_ptr->data);}
        value_type		*operator->()const{return _ptr->data;}
        ListRIterator	&operator++(){_ptr = _ptr->prev; return *this;}
        ListRIterator	operator++(int){ListRIterator it = *this; ++(*this); return it;}
        ListRIterator	&operator--(){ _ptr = _ptr->next; return *this;}
        ListRIterator	operator--(int){ListRIterator it = *this; --(*this); return it;}

        bool			operator==(const ListRIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const ListRIterator &it){ return _ptr != it._ptr;}
        
        private:
            pointeur _ptr; 
    };

    template <typename T, typename Node>
    class ConstListRIterator
    {
        public:
        typedef T                               value_type;
        typedef const T&                        const_reference;
        typedef Node*                           pointeur;
        typedef ptrdiff_t						difference_type;

        ConstListRIterator(pointeur ptr = 0): _ptr(ptr){}
        ConstListRIterator(ConstListRIterator<T, Node> const &cp){_ptr = cp._ptr;}
        ConstListRIterator operator=(ConstListRIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;
        }
        ~ConstListRIterator(){}
        
        const_reference operator*()const {return *(_ptr->data);}
        value_type		*operator->()const{return _ptr->data;}
        ConstListRIterator	&operator++(){_ptr = _ptr->prev; return *this;}
        ConstListRIterator	operator++(int){ConstListRIterator it = *this; ++(*this); return it;}
        ConstListRIterator	&operator--(){ _ptr = _ptr->next; return *this;}
        ConstListRIterator	operator--(int){ConstListRIterator it = *this; --(*this); return it;}

        bool			operator==(const ConstListRIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const ConstListRIterator &it){ return _ptr != it._ptr;}
        
        private:
            pointeur _ptr; 
    };
}

#endif