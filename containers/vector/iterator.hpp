/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/03/27 14:18:38 by nmbabazi         ###   ########.fr       */
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

        VectIterator    operator+(difference_type n)const{VectIterator it; return it += n;}
        VectIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this}
        VectIterator    operator-(difference_type n)const{VectIterator it; return it -= n;}
        VectIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this}
        difference_type	operator-(VectIterator const &it)const{ return (it._ptr - this->_ptr);}
        
        value_type		&operator*()const {return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
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
    class ConstVectIterator
    {
        public:
        typedef const T                               value_type;
        typedef ptrdiff_t						difference_type;

        ConstVectIterator(): _ptr(NULL){}
        ConstVectIterator(const value_type *ptr): _ptr(ptr){}
        ConstVectIterator(ConstVectIterator &cp){ _ptr = cp._ptr;}
        ConstVectIterator& operator=(const ConstVectIterator& cp)
        { if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;}
        ~ConstVectIterator();

        ConstVectIterator    operator+(difference_type n)const{ConstVectIterator it; return it += n;}
        ConstVectIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this}
        ConstVectIterator    operator-(difference_type n)const{ConstVectIterator it; return it -= n;}
        ConstVectIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this}
        difference_type	operator-(ConstVectIterator const &it)const{ return (it._ptr - this->_ptr);}
        
        value_type		&operator*()const{return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
        ConstVectIterator	&operator++(){_ptr--; return *this;}
        ConstVectIterator	operator++(int){ConstVectIterator it = *this; ++(*this); return it;}
        ConstVectIterator	&operator--(){ _ptr++; return *this;}
        ConstVectIterator	operator--(int){ConstVectIterator it = *this; --(*this); return it;}

        bool			operator==(const ConstVectIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const ConstVectIterator &it){ return _ptr != it._ptr;}
        bool			operator>=(const ConstVectIterator &it){ return _ptr >= it._ptr;}
        bool			operator<=(const ConstVectIterator &it){ return _ptr <= it._ptr;}
        bool			operator>(const ConstVectIterator &it){ return _ptr > it._ptr;}
        bool			operator<(const ConstVectIterator &it){ return _ptr < it._ptr;}
        
        private:
            value_type *_ptr; 
    };

/////////////////////reverse///////////////////////////

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

        VectRIterator    operator+(difference_type n)const{VectRIterator it; return it += n;}
        VectRIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this}
        VectRIterator    operator-(difference_type n)const{VectRIterator it; return it -= n;}
        VectRIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this}
        difference_type	operator-(VectRIterator const &it)const{ return (this->_ptr - it._ptr);}
        
        value_type		&operator*()const{return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
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

    template <typename T>
    class ConstVectRIterator
    {
        public:
        typedef const T                               value_type;
        typedef ptrdiff_t						difference_type;

        ConstVectRIterator(): _ptr(NULL){}
        ConstVectRIterator(value_type *ptr): _ptr(ptr){}
        ConstVectRIterator(ConstVectRIterator &cp){ _ptr = cp._ptr;}
        ConstVectRIterator& operator=(const ConstVectRIterator& cp)
        { if (this != &cp)
                this->_ptr = cp._ptr;
            return *this;}
        ~ConstVectRIterator();

        ConstVectRIterator    operator+(difference_type n)const{ConstVectRIterator it; return it += n;}
        ConstVectRIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this}
        ConstVectRIterator    operator-(difference_type n)const{ConstVectRIterator it; return it -= n;}
        ConstVectRIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this}
        difference_type	operator-(ConstVectRIterator const &it)const{ return (this->_ptr - it._ptr);}
        
        value_type		&operator*()const{return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
        ConstVectRIterator	&operator++(){_ptr++; return *this;}
        ConstVectRIterator	operator++(int){ConstVectRIterator it = *this; ++(*this); return it;}
        ConstVectRIterator	&operator--(){ _ptr--; return *this;}
        ConstVectRIterator	operator--(int){ConstVectRIterator it = *this; --(*this); return it;}

        bool			operator==(const ConstVectRIterator &it){ return _ptr == it._ptr;}
        bool			operator!=(const ConstVectRIterator &it){ return _ptr != it._ptr;}
        bool			operator>=(const ConstVectRIterator &it){ return _ptr >= it._ptr;}
        bool			operator<=(const ConstVectRIterator &it){ return _ptr <= it._ptr;}
        bool			operator>(const ConstVectRIterator &it){ return _ptr > it._ptr;}
        bool			operator<(const ConstVectRIterator &it){ return _ptr < it._ptr;}
        
        private:
            value_type *_ptr;
    };    
}

#endif