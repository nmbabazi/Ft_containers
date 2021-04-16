/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/16 13:13:16 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "../vector/vector.hpp"
#include "../../allocator.hpp"
#include "../../utils.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        ///////////////////////typedef//////////////////////////////    
        public:
        typedef T					    value_type;
        typedef Container				container_type;
        typedef size_t				    size_type;
                 
        private:   
        container_type _container;
///////////////////////fonction membre//////////////////////////
        public:
        stack (const container_type& ctnr = container_type()):_container(ctnr){}
        stack (const stack &cp):_container(cp._container){}
        stack& operator=(const stack& cp)
        {
            if (this != &cp)
                this->_container = cp._container;
            return *this;
        }
        ~stack(){}
        bool empty() const{return _container.empty();}
        size_type size() const{return _container.size();}
        value_type& top(){return _container.back();}
        const value_type& top() const{return _container.back();}
        void push (const value_type& val){_container.push_back(val);}
        void pop(){_container.pop_back();}
        
/////////////////////overloads///////////////////////////////
        friend bool operator== (const stack& lhs, const stack& rhs) { return lhs._container == rhs._container; }
        friend bool operator!= (const stack& lhs, const stack& rhs) { return lhs._container != rhs._container; }
        friend bool operator<  (const stack& lhs, const stack& rhs) { return lhs._container < rhs._container; }
        friend bool operator<= (const stack& lhs, const stack& rhs) { return lhs._container <= rhs._container; }
        friend bool operator>  (const stack& lhs, const stack& rhs) { return lhs._container > rhs._container; }
        friend bool operator>= (const stack& lhs, const stack& rhs) { return lhs._container >= rhs._container; }
    };

}
#endif