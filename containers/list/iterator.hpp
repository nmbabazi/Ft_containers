/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/01 17:55:51 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
    template <typename T>
    class ListIterator
    {
        public:
        typedef T                       value_type;
        typedef ptrdiff_t				difference_type;

        ListIterator(value_type *ptr = 0): _ptr(ptr){}
        ListIterator(ListIterator<T> const &cp){_ptr = cp._ptr;}
        ListIterator operator=(ListIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;
        }
        ~ListIterator(){}
        
        value_type		&operator*()const {return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        ListIterator	&operator++(){_ptr++; return *this;}
        ListIterator	operator++(int){ListIterator it = *this; ++(*this); return it;}
        ListIterator	&operator--(){ _ptr--; return *this;}
        ListIterator	operator--(int){ListIterator it = *this; --(*this); return it;}

        bool			operator==(const ListIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const ListIterator &it){ return _ptr != it._ptr;}
        
        private:
            value_type *_ptr; 
    };

    template <typename T>
    class RListIterator
    {
        public:
        typedef T                       value_type;
        typedef ptrdiff_t				difference_type;

        RListIterator(value_type *ptr = 0): _ptr(ptr){}
        RListIterator(RListIterator<T> const &cp){_ptr = cp._ptr;}
        RListIterator operator=(RListIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;
        }
        ~RListIterator(){}
        
        value_type		&operator*()const {return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        RListIterator	&operator++(){_ptr--; return *this;}
        RListIterator	operator++(int){RListIterator it = *this; ++(*this); return it;}
        RListIterator	&operator--(){ _ptr++; return *this;}
        RListIterator	operator--(int){RListIterator it = *this; --(*this); return it;}

        bool			operator==(const RListIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const RListIterator &it){ return _ptr != it._ptr;}
        
        private:
            value_type *_ptr; 
    };
}

#endif