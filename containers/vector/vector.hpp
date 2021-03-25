/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/03/25 17:01:32 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft
{
    template <typename T, typename Alloc = std::allocator<T> > 
    class vector
    {
        public:
///////////////////////typedef//////////////////////////////        
            typedef T					value_type;
            typedef value_type&			reference;
            typedef value_type const & 	const_reference;
            typedef value_type*			pointer;
            typedef value_type const * 	const_pointer;
			typedef ptrdiff_t			difference_type;
    		typedef size_t				size_type;
			//typedef Alloc				alloc;
        	/*typedef VectorIterator<value_type> iterator;
    		typedef VectorIterator<value_type const> const_iterator;
    		typedef ReverseIterator<iterator> reverse_iterator;
    		typedef ReverseIterator<const_iterator> const_reverse_iterator;*/
			
///////////////////////class randiterator//////////////////////////////
			template <typename Vector>
			class VectIterator
			{
				public:
				typedef typename Vector::value_type		value_type;
				typedef value_type*						pointer;
				typedef value_type&						reference;
				typedef ptrdiff_t						difference_type;

				VectIterator(): _ptr(NULL){}
				VectIterator(pointer ptr): _ptr(ptr){}
				VectIterator(VectIterator &cp){ _ptr = cp._ptr;}
				VectIterator& operator=(const VectIterator& cp)
				{ if (this != &cp)
						this->_ptr = cp._ptr;
					return *this;}
				~VectIterator();
				
				reference		operator*(){ return *_ptr;}
				pointer			operator->(){ return _ptr;}
				value_type		operator[](int n) { return *(_ptr + n);}
				VectIterator	&operator++(){ _ptr++; return *this;}
				VectIterator	operator++(int){ VectIterator it = *this; ++(*this); return it;}
				VectIterator	&operator--(){ _ptr--; return *this;}
				VectIterator	operator--(int){ VectIterator it = *this; --(*this); return it;}

				difference_type	operator-(VectIterator const &it) { return (this->_ptr - it._ptr);}
				bool			operator==(const VectIterator &it){ return _ptr == it._ptr;}
				bool			operator!=(const VectIterator &it){ return _ptr != it._ptr;}
				bool			operator>=(const VectIterator &it){ return _ptr >= it._ptr;}
				bool			operator<=(const VectIterator &it){ return _ptr <= it._ptr;}
				bool			operator>(const VectIterator &it){ return _ptr > it._ptr;}
				bool			operator<(const VectIterator &it){ return _ptr < it._ptr;}
				
				private:
					pointer _ptr;
				
			};
            
            vector(const allocator_type& alloc = allocator_type());
            vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
            vector (const vector& x);
            ~vector();
            vector& operator=(const vector& x);
///////////////////////iterator//////////////////////////////
            begin();
            end();
            rbegin();
            rend();
/////////////////////capacity////////////////////////////////
            size();
            max_size();
            empty();
            resize();
            capacity();
            reserve();
/////////////////////acces///////////////////////////////////
            front();
            back();
            operator[]();
            at();
/////////////////////modifiers///////////////////////////////
            assign();
            insert();
            erase();
            push_back();
            pop_back();
            clear();
            swap();
        
    };
/////////////////////overload///////////////////////////////
// operator==
// operator!=
// operator<
// operator<=
// operator>
// operator>=

}

#endif