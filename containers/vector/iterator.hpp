/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/05 16:50:36 by nmbabazi         ###   ########.fr       */
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
        typedef T                       value_type;
        typedef ptrdiff_t				difference_type;

        VectIterator(value_type *ptr = 0): _ptr(ptr){}
        VectIterator(VectIterator<T> const &cp){_ptr = cp.get_ptr();}
        VectIterator operator=(VectIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp.get_ptr();
            return *this;
        }
        ~VectIterator(){}

        VectIterator    operator+(difference_type n)const{VectIterator it = *this; return it += n;}
        VectIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this;}
        VectIterator    operator-(difference_type n)const{VectIterator it = *this; return it -= n;}
        VectIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this;}
        difference_type	operator-(VectIterator const &it)const{ return (it.get_ptr() - this->_ptr);}
        
        value_type		&operator*()const {return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
        VectIterator	&operator++(){_ptr++; return *this;}
        VectIterator	operator++(int){VectIterator it = *this; ++(*this); return it;}
        VectIterator	&operator--(){ _ptr--; return *this;}
        VectIterator	operator--(int){VectIterator it = *this; --(*this); return it;}
        value_type      *get_ptr()const{return _ptr;}

        bool			operator==(const VectIterator &it){ return _ptr == it.get_ptr();}
        bool			operator!=(const VectIterator &it){ return _ptr != it.get_ptr();}
        bool			operator>=(const VectIterator &it){ return _ptr >= it.get_ptr();}
        bool			operator<=(const VectIterator &it){ return _ptr <= it.get_ptr();}
        bool			operator>(const VectIterator &it){ return _ptr > it.get_ptr();}
        bool			operator<(const VectIterator &it){ return _ptr < it.get_ptr();}
        
        private:
            value_type *_ptr; 
    };

    template <typename T>
    class ConstVectIterator
    {
        public:
        typedef T                               value_type;
        typedef T*                              pointeur;
        typedef const T&                        const_reference;
        typedef const T*                        const_pointer;
        typedef ptrdiff_t						difference_type;

        ConstVectIterator(pointeur ptr = 0): _ptr(ptr){}
        ConstVectIterator(VectIterator<T> const &cp){ _ptr = cp.get_ptr();}
        ConstVectIterator operator=(ConstVectIterator const &cp)
        { 
            if (this != &cp)
                this->_ptr = cp.get_ptr();
            return *this;
        }
        ~ConstVectIterator(){}

        ConstVectIterator    operator+(difference_type n)const{ConstVectIterator it = *this; return it += n;}
        ConstVectIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this;}
        ConstVectIterator    operator-(difference_type n)const{ConstVectIterator it = *this; return it -= n;}
        ConstVectIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this;}
        difference_type	operator-(ConstVectIterator const &it)const{ return (it.get_ptr() - this->_ptr);}
        
        const_reference operator*()const {return *_ptr;}
        pointeur		*operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
        ConstVectIterator	&operator++(){_ptr++; return *this;}
        ConstVectIterator	operator++(int){ConstVectIterator it = *this; ++(*this); return it;}
        ConstVectIterator	&operator--(){ _ptr--; return *this;}
        ConstVectIterator	operator--(int){ConstVectIterator it = *this; --(*this); return it;}
        pointeur             get_ptr()const{return _ptr;}

        bool			operator==(const ConstVectIterator&it){ return _ptr == it.get_ptr();}
        bool			operator!=(const ConstVectIterator &it){ return _ptr != it.get_ptr();}
        bool			operator>=(const ConstVectIterator &it){ return _ptr >= it.get_ptr();}
        bool			operator<=(const ConstVectIterator &it){ return _ptr <= it.get_ptr();}
        bool			operator>(const ConstVectIterator &it){ return _ptr > it.get_ptr();}
        bool			operator<(const ConstVectIterator &it){ return _ptr < it.get_ptr();}
        
        private:
            pointeur _ptr; 
    };

/////////////////////reverse///////////////////////////

    template <typename T>
    class VectRIterator
    {
        public:
        typedef T                               value_type;
        typedef ptrdiff_t						difference_type;

        VectRIterator(value_type *ptr = 0): _ptr(ptr){}
        VectRIterator(VectRIterator<T> const &cp){ _ptr = cp.get_ptr();}
        VectRIterator operator=(VectRIterator const &cp)
        { if (this != &cp)
                this->_ptr = cp.get_ptr();
            return *this;}
        ~VectRIterator(){}

        VectRIterator    operator+(difference_type n)const{VectRIterator it = *this; return it += n;}
        VectRIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this;}
        VectRIterator    operator-(difference_type n)const{VectRIterator it = *this; return it -= n;}
        VectRIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this;}
        difference_type	operator-(VectRIterator const &it)const{ return (this->_ptr - it.get_ptr());}
        
        value_type		&operator*()const{return *_ptr;}
        value_type		*operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
        VectRIterator	&operator++(){_ptr--; return *this;}
        VectRIterator	operator++(int){VectRIterator it = *this; ++(*this); return it;}
        VectRIterator	&operator--(){ _ptr++; return *this;}
        VectRIterator	operator--(int){VectRIterator it = *this; --(*this); return it;}
        value_type      *get_ptr()const{return _ptr;}

        bool			operator==(const VectRIterator &it){ return _ptr == it.get_ptr();}
        bool			operator!=(const VectRIterator &it){ return _ptr != it.get_ptr();}
        bool			operator>=(const VectRIterator &it){ return _ptr >= it.get_ptr();}
        bool			operator<=(const VectRIterator &it){ return _ptr <= it.get_ptr();}
        bool			operator>(const VectRIterator &it){ return _ptr > it.get_ptr();}
        bool			operator<(const VectRIterator &it){ return _ptr < it.get_ptr();}
        
        private:
            value_type *_ptr;
    };

    template <typename T>
    class ConstVectRIterator
    {
        public:

        typedef T                               value_type;
        typedef T*                              pointeur;
        typedef const T&                        const_reference;
        typedef const T*                        const_pointer;
        typedef ptrdiff_t						difference_type;

        ConstVectRIterator(pointeur ptr = 0): _ptr(ptr){}
        ConstVectRIterator(VectRIterator<T> const &cp){ _ptr = cp.get_ptr();}
        ConstVectRIterator operator=(ConstVectRIterator const &cp)
        { if (this != &cp)
                this->_ptr = cp.get_ptr();
            return *this;}
        ~ConstVectRIterator(){}

        ConstVectRIterator    operator+(difference_type n)const{ConstVectRIterator it = *this; return it += n;}
        ConstVectRIterator    &operator+=(difference_type n){
            if (n >= 0) 
                while (n--) --_ptr;
            else 
                while (n++) ++_ptr;
            return *this;}
        ConstVectRIterator    operator-(difference_type n)const{ConstVectRIterator it = *this; return it -= n;}
        ConstVectRIterator    &operator-=(difference_type n){
            if (n >= 0) 
                while (n--) ++_ptr;
            else 
                while (n++) --_ptr;
            return *this;}
        difference_type	operator-(ConstVectRIterator const &it)const{ return (this->_ptr - it.get_ptr());}
        
        const_reference operator*()const{return *_ptr;}
        const_pointer   operator->()const{return _ptr;}
        value_type		operator[](int n)const{return *(_ptr + n);}
        ConstVectRIterator	&operator++(){_ptr--; return *this;}
        ConstVectRIterator	operator++(int){ConstVectRIterator it = *this; ++(*this); return it;}
        ConstVectRIterator	&operator--(){ _ptr++; return *this;}
        ConstVectRIterator	operator--(int){ConstVectRIterator it = *this; --(*this); return it;}
        pointeur            get_ptr()const{return _ptr;}

        bool			operator==(const ConstVectRIterator &it){ return _ptr == it.get_ptr();}
        bool			operator!=(const ConstVectRIterator &it){ return _ptr != it.get_ptr();}
        bool			operator>=(const ConstVectRIterator &it){ return _ptr >= it.get_ptr();}
        bool			operator<=(const ConstVectRIterator &it){ return _ptr <= it.get_ptr();}
        bool			operator>(const ConstVectRIterator &it){ return _ptr > it.get_ptr();}
        bool			operator<(const ConstVectRIterator &it){ return _ptr < it.get_ptr();}
        
        private:
            pointeur _ptr;
    };    
}

#endif