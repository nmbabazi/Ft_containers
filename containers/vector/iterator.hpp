/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/03/26 16:58:14 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
    template <typename T>
    class VectIterator
    {
        public:
        typedef T                               value_type;
        typedef ptrdiff_t						difference_type;

        VectIterator(): _ptr(NULL){}
        VectIterator(value_type *ptr): _ptr(ptr){}
        VectIterator(VectIterator &cp){ _ptr = cp._ptr;}
        VectIterator& operator=(const VectIterator& cp)
        { if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;}
        ~VectIterator();

        VectIterator    operator+(difference_type n){VectIterator it; return it += n;}
        VectIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this}
        VectIterator    operator-(difference_type n){VectIterator it; return it -= n;}
        VectIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this}
        difference_type	operator-(VectIterator const &it) { return (it._ptr - this->_ptr);}
        
        value_type		&operator*(){return *_ptr;}
        value_type		*operator->(){return _ptr;}
        value_type		operator[](int n) {return *(_ptr + n);}
        VectIterator	&operator++(){_ptr--; return *this;}
        VectIterator	operator++(int){VectIterator it = *this; ++(*this); return it;}
        VectIterator	&operator--(){ _ptr++; return *this;}
        VectIterator	operator--(int){VectIterator it = *this; --(*this); return it;}

        bool			operator==(const VectIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const VectIterator &it){ return _ptr != it._ptr;}
        bool			operator>=(const VectIterator &it){ return _ptr >= it._ptr;}
        bool			operator<=(const VectIterator &it){ return _ptr <= it._ptr;}
        bool			operator>(const VectIterator &it){ return _ptr > it._ptr;}
        bool			operator<(const VectIterator &it){ return _ptr < it._ptr;}
        
        private:
            value_type *_ptr;
        
    };

    template <typename T>
    class VectRIterator
    {
        public:
        typedef T                               value_type;
        typedef ptrdiff_t						difference_type;

        VectRIterator(): _ptr(NULL){}
        VectRIterator(value_type *ptr): _ptr(ptr){}
        VectRIterator(VectRIterator &cp){ _ptr = cp._ptr;}
        VectRIterator& operator=(const VectRIterator& cp)
        { if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;}
        ~VectRIterator();

        VectRIterator    operator+(difference_type n){VectRIterator it; return it += n;}
        VectRIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this}
        VectRIterator    operator-(difference_type n){VectRIterator it; return it -= n;}
        VectRIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this}
        difference_type	operator-(VectRIterator const &it) { return (this->_ptr - it._ptr);}
        
        value_type		&operator*(){return *_ptr;}
        value_type		*operator->(){return _ptr;}
        value_type		operator[](int n) {return *(_ptr + n);}
        VectRIterator	&operator++(){_ptr++; return *this;}
        VectRIterator	operator++(int){VectRIterator it = *this; ++(*this); return it;}
        VectRIterator	&operator--(){ _ptr--; return *this;}
        VectRIterator	operator--(int){VectRIterator it = *this; --(*this); return it;}

        bool			operator==(const VectRIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const VectRIterator &it){ return _ptr != it._ptr;}
        bool			operator>=(const VectRIterator &it){ return _ptr >= it._ptr;}
        bool			operator<=(const VectRIterator &it){ return _ptr <= it._ptr;}
        bool			operator>(const VectRIterator &it){ return _ptr > it._ptr;}
        bool			operator<(const VectRIterator &it){ return _ptr < it._ptr;}
        
        private:
            value_type *_ptr;
        
    };
}

#endif