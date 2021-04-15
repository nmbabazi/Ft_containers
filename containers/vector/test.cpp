/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nailambz <nailambz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:29:25 by nailambz          #+#    #+#             */
/*   Updated: 2021/04/15 11:29:02 by nailambz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

/*******************************************************************************/
/**Basic test provided on cplusplus.com. STL outputs are copied from the site.**/
/*******************************************************************************/

int main ()
{

    std::cout << "\n\n ***************Test constructeur***********\n\n";
    {
        // constructors used in the same order as described above:
        ft::vector<int> first;                                // empty vector of ints
        ft::vector<int> second (4,100);                       // four ints with value 100
        ft::vector<int> third (second.begin(),second.end());  // iterating through second
        ft::vector<int> fourth (third);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "The contents of fifth are(ft):";
        for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "The contents of fifth are(stl): 16 2 77 29\n";
    }

    std::cout << "\n\n ***************Test operator= ***********\n\n";
    {
        ft::vector<int> foo (3,0);
        ft::vector<int> bar (5,0);

        bar = foo;
        foo = ft::vector<int>();

        std::cout << "Size of foo(ft): " << int(foo.size()) << '\n';
        std::cout << "Size of foo(stl): 0" << '\n';
        std::cout << "Size of bar(ft): " << int(bar.size()) << '\n';
        std::cout << "Size of bar(stl): 3" << '\n';
    }

    std::cout << "\n\n ***************Test revers it***********\n\n";
    {
        ft::vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
            *rit = ++i;

        std::cout << "myvector contains(ft):";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "myvector contains(stl): 5 4 3 2 1\n";
    }
    std::cout << "\n\n ***************Test size***********\n\n";
    {
        std::cout << "std :" << std::endl;
        std::vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (myints.end(),10,100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';

        std::cout << "-----------------------------" << std::endl;
        std::cout << "ft :" << std::endl;
        ft::vector<int> myints2;
        std::cout << "0. size: " << myints2.size() << '\n';

        for (int i=0; i<10; i++) myints2.push_back(i);
        std::cout << "1. size: " << myints2.size() << '\n';

        myints2.insert (myints2.end(),10,100);
        std::cout << "2. size: " << myints2.size() << '\n';

        myints2.pop_back();
        std::cout << "3. size: " << myints2.size() << '\n'; 
    }
    std::cout << "\n\n ***************Test resize***********\n\n";
    {
        ft::vector<int> myvector;

        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);
        std::cout << "myvector contains(ft):";
        for (size_t i=0;i < myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "myvector contains(stl): 1 2 3 4 5 100 100 100 0 0 0 0\n";
    }
    std::cout << "\n\n ***************Test capacity***********\n\n";
    {
        {ft::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);

        std::cout << "size(ft): " << (int) myvector.size() << '\n';
        std::cout << "capacity(ft): " << (int) myvector.capacity() << '\n';
        std::cout << "max_size(ft): " << (int) myvector.max_size() << '\n';}
        {std::vector<int> myvector;
        std::cout << "-----------------------------" << std::endl;
        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);

        std::cout << "size(stl): " << (int) myvector.size() << '\n';
        std::cout << "capacity(stl): " << (int) myvector.capacity() << '\n';
        std::cout << "max_size(stl): " << (int) myvector.max_size() << '\n';}
    }
    std::cout << "\n\n ***************Test empty ***********\n\n";
    {
        std::vector<int> nwvec5;
        int sum (0);

        for (int i=1;i<=10;i++) nwvec5.push_back(i);

        while (!nwvec5.empty())
        {
            sum += nwvec5.back();
            nwvec5.pop_back();
        }

        std::cout << "total(stl): " << sum << '\n';

        ft::vector<int> nwvec6;
        sum = 0;

        for (int i=1;i<=10;i++) nwvec6.push_back(i);

        while (!nwvec6.empty())
        {
            sum += nwvec6.back();
            nwvec6.pop_back();
        }

        std::cout << "total(ft): " << sum << '\n';
    }
    std::cout << "\n\n ***************Test reserve***********\n\n";
    {
        std::cout << "std :" << std::endl;
        std::vector<int>::size_type sz;

        std::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i) {
            foo.push_back(i);
            if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }

        std::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) {
            bar.push_back(i);
            if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }

        std::cout << "-----------------------------" << std::endl;
        std::cout << "ft :" << std::endl;

        ft::vector<int>::size_type sz2;

        ft::vector<int> foo2;
        sz2 = foo2.capacity();
        std::cout << "making foo2 grow:\n";
        for (int i=0; i<100; ++i) {
            foo2.push_back(i);
            if (sz2!=foo2.capacity()) {
            sz2 = foo2.capacity();
            std::cout << "capacity changed: " << sz2 << '\n';
            }
        }

        ft::vector<int> bar2;
        sz2 = bar2.capacity();
        bar2.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar2 grow:\n";
        for (int i=0; i<100; ++i) {
            bar2.push_back(i);
            if (sz2!=bar2.capacity()) {
            sz2 = bar2.capacity();
            std::cout << "capacity changed: " << sz2 << '\n';
            }
        }
    }
    std::cout << "\n\n ***************Test operator[] ***********\n\n";
    {
        ft::vector<int> myvector (10);   // 10 zero-initialized elements

        ft::vector<int>::size_type sz = myvector.size();

        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
            int temp;
            temp = myvector[sz-1-i];
            myvector[sz-1-i]=myvector[i];
            myvector[i]=temp;
        }

        std::cout << "myvector contains(ft):";
        for (unsigned i=0; i<sz; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "myvector contains(stl): 9 8 7 6 5 4 3 2 1 0\n";
    }
    std::cout << "\n\n ***************Test at ***********\n\n";
    {
        ft::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
            myvector.at(i)=i;

        std::cout << "myvector contains(ft):";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector.at(i);
        std::cout << '\n';
        std::cout << "myvector contains(stl): 0 1 2 3 4 5 6 7 8 9\n";
    }
    std::cout << "\n\n ***************Test dront/back ***********\n\n";
    {
        ft::vector<int> vec5;

        vec5.push_back(78);
        vec5.push_back(16);

        // now front equals 78, and back 16

        vec5.front() -= vec5.back();

        std::cout << "vec5.front() is now(ft)" << vec5.front() << '\n';

        std::vector<int> vec6;

        vec6.push_back(78);
        vec6.push_back(16);

        // now front equals 78, and back 16

        vec6.front() -= vec6.back();

        std::cout << "vec6.front() is now(stl)" << vec6.front() << '\n';

    }
    std::cout << "\n\n ***************Test assign ***********\n\n";
    {
        ft::vector<int> first;
        ft::vector<int> second;
        ft::vector<int> third;

        first.assign (7,100);             // 7 ints with a value of 100

        ft::vector<int>::iterator it;
        it = first.begin()+1;

        second.assign (it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);   // assigning from array.

        std::cout << "Size of first(ft): " << int (first.size()) << '\n';
        std::cout << "Size of first(stl): 7" << '\n';
        std::cout << "Size of second(ft): " << int (second.size()) << '\n';
        std::cout << "Size of second(stl): 5" << '\n';
        std::cout << "Size of third(ft): " << int (third.size()) << '\n';
        std::cout << "Size of third(stl): 3" << '\n';
    }
    std::cout << "\n\n ***************Test insert ***********\n\n";
    {
        ft::vector<int> myvector (3,100);
        ft::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert ( it , 200 );

        myvector.insert (it,2,300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        std::vector<int> anothervector (2,400);
        myvector.insert (it+2,anothervector.begin(),anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray+3);

        std::cout << "myvector contains(ft):";
        for (it=myvector.begin(); it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "myvector contains(stl): 501 502 503 300 300 400 400 200 100 100 100\n";
    }
    std::cout << "\n\n ***************Test erase ***********\n\n";
    {
        ft::vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i=1; i<=10; i++) myvector.push_back(i);

        // erase the 6th element
        myvector.erase (myvector.begin()+5);

        // erase the first 3 elements:
        myvector.erase (myvector.begin(),myvector.begin()+3);

        std::cout << "myvector contains(ft):";
        for (unsigned i=0; i<myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "myvector contains(stl): 4 5 7 8 9 10\n";
    }
    std::cout << "\n\n ***************Test swap ***********\n\n";
    {
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains(ft):";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';
        std::cout << "foo contains(stl): 200 200 200 200 200\n";
        std::cout << "bar contains(ft):";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
        std::cout << "bar contains(stl): 100 100 100 \n";
    }
    std::cout << "\n\n ***************Test clear ***********\n\n";
    {
        ft::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains(ft):";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "myvector contains(stl): 100 200 300\n";
        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains(ft):";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout << "myvector contains(stl): 1101 2202\n";
    }
    std::cout << "\n\n ***************Test relational operators ***********\n\n";
    {
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (2,200);   // two ints with a value of 200

        std::cout << "ft output:\n";
        if (foo==bar) std::cout << "foo and bar are equal\n";
        if (foo!=bar) std::cout << "foo and bar are not equal\n";
        if (foo< bar) std::cout << "foo is less than bar\n";
        if (foo> bar) std::cout << "foo is greater than bar\n";
        if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

        std::cout << "-----------------------------" << std::endl;
        std::cout << "stl output:\n";
        std::cout << "foo and bar are not equal\n";
        std::cout << "foo is less than bar\n";
        std::cout << "foo is less than or equal to bar\n";
    }
    std::cout << "\n\n ***************Test swap overload ***********\n\n";
    {
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains(ft):";
        for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "foo contains(stl): 200 200 200 200 200\n";

        std::cout << "bar contains(ft):";
        for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "bar contains(stl): 100 100 100\n";
    }
    return (0);
}