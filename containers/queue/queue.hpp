/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:27 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/16 13:11:54 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <memory>
#include <iostream>
#include <limits>
#include "../list/list.hpp"
#include "../../allocator.hpp"
#include "../../utils.hpp"

namespace ft
{
    template <class T, class Container = ft::list<T> >
    class queue
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
        queue (const container_type& ctnr = container_type()):_container(ctnr){}
        queue (const queue &cp):_container(cp._container){}
        queue& operator=(const queue& cp)
        {
            if (this != &cp)
                this->_container = cp._container;
            return *this;
        }
        ~queue(){_container.~container_type();}
        bool empty() const{return _container.empty();}
        size_type size() const{return _container.size();}
        value_type& front(){return _container.front();}
        const value_type& front() const{return _container.front();}
        value_type& back(){return _container.back();}
        const value_type& back() const{return _container.back();}
        void push (const value_type& val){_container.push_back(val);}
        void pop(){_container.pop_front();}
        
/////////////////////overloads///////////////////////////////
        friend bool operator== (const queue& lhs, const queue& rhs) { return lhs._container == rhs._container; }
        friend bool operator!= (const queue& lhs, const queue& rhs) { return lhs._container != rhs._container; }
        friend bool operator<  (const queue& lhs, const queue& rhs) { return lhs._container < rhs._container; }
        friend bool operator<= (const queue& lhs, const queue& rhs) { return lhs._container <= rhs._container; }
        friend bool operator>  (const queue& lhs, const queue& rhs) { return lhs._container > rhs._container; }
        friend bool operator>= (const queue& lhs, const queue& rhs) { return lhs._container >= rhs._container; }
    };

}
#endif