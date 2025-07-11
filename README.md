# VectorLiteCPP

A lightweight custom implementation of a dynamic array (similar to `std::vector`) using raw pointers and manual memory management in C++.

---

## 📚 Description

`VectorLiteCPP` is a self-contained C++ class that simulates the functionality of `std::vector<int>`. It supports dynamic resizing, element insertion, deletion, and random access — all implemented from scratch without using STL containers.

This project serves as an educational tool for understanding how dynamic arrays work internally, with fine-grained control over capacity, memory, and growth strategies.

---

## ✨ Features

- ✅ Constructor with initial capacity
- ✅ `push_back(value)` to append elements
- ✅ `pop_back()` to remove the last element
- ✅ `insert(index, value)` for inserting at any position
- ✅ `erase(index)` to remove an element at a specific index
- ✅ `resizeVector(newCapacity)` for internal resizing
- ✅ `front()` and `back()` access
- ✅ `at(index)` for bounds-checked access
- ✅ `swap()` with another vector
- ✅ `clear()` to reset the vector
- ✅ `begin()` and `end()` pointer access (for iteration)

---

## 🚧 Limitations

- 🚫 Only works with `int` (no templates or generics)
- 🚫 No support for copy constructor or assignment operator (shallow copy risk)
- ⚠️ No exception handling or iterator class

---

## 🛠️ Compilation

To compile:

```bash
g++ VectorLite.cpp -o VectorLiteCPP
./VectorLiteCPP
