#ifndef ALIST_H
#define ALIST_H
template <typename T> struct alist;

template <typename T> void pushback(alist<T> *&h,alist<T> *&t, T x);

template <typename T> void print(alist<T> *&h,alist<T> *&t);

#endif // ALIST_H
