#include "generalFunctions.hpp"

template<class T, class U>
bool min(const T &a, const U &b){
	return (a<b)? a : b ;
}

template<class T, class U>
bool max(const T &a, const U &b){
	return (a<b)? b : a ;
}