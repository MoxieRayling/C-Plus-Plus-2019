// RingBuffer/test_skel.cpp

#include <algorithm>
#include <iostream>

#include "RingBuffer.hpp"

using namespace std;

void show(const RingBuffer<int>& rb)
{
    cout << "Size: " << rb.size() << "  { ";
    std::copy(rb.begin(), rb.end(), ostream_iterator<int>(cout, " "));
    cout << "}" << endl;
}

int main()
{
    RingBuffer<int> rb(7);
    cout << "Capacity: " << rb.capacity()
	 << "\nEmpty? " << rb.empty() << endl;
    rb.push_back(28);
    rb.push_back(56);
    rb.push_back(12);
    rb.push_back(24);
    show(rb);
    rb.pop_front();
    show(rb);
    rb.push_back(24);
    show(rb);
    rb.push_back(24);
    show(rb);
    rb.push_back(24);
    show(rb);
    rb.push_back(24);
    show(rb);
    rb.pop_front();
    show(rb);
    rb.push_back(24);
    show(rb);
    

    RingBuffer<int> rb2(7);
    rb2.push_back(28);
    rb2.push_back(56);
    rb2.push_back(12);
    cout<< "equal: " << (rb==rb2)<<endl;
    rb2.push_back(24);
    for (auto& it : rb2) {
        cout<<it<<" ";
    }
    RingBuffer<int> rb3(rb);
    for (auto& it : rb3) {
        cout<<it<<" ";
    }
    cout<<endl;
    cout<< "equal: " << (rb==rb2)<<endl;

    _RBIterator test = rb.begin();
    _RBIterator test2 = rb.begin();
    test2++;
    test = test2;
    cout<< "begin=: "<< *test<<endl;
    test = rb.begin();
    cout << "begin++: " << *test++<<endl; //28
    cout << "begin++: " << *test++<<endl; //56
    test = rb.begin();
    cout << "++begin: " << *++test<<endl; //56
    test = rb.begin();
    cout << "begin--: " << *test--<<endl; //28
    cout << "begin--: " << *test--<<endl; //0
    test = rb.begin();
    cout << "--begin: " << *--test<<endl; //0
    test = rb.begin();
	show(rb2);
    cout << "minus test: " << *(test+=(-6))<<endl; //56
    test = rb.begin();
    cout << "zero test: " << *(test+=(0))<<endl; //56
    test = rb.begin();
    cout << "1 test: " << *(test+=(1))<<endl; //56
    test = rb.begin();
    cout << "begin+1: " << *(test+1)<<endl; //56
    cout << "begin+1: " << *test<<endl; //28
    test = rb.begin();
    cout << "begin[]: " << test[1]<<endl; //56

    cout << "Empty? " << rb.empty()
         << "\nFront: " << rb.front() << endl;
    show(rb);
    return 0;
}
