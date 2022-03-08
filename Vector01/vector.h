#pragma once
#include <algorithm>

namespace oe {

	template<typename T>
	class vector
	{
	public:
		vector() = default;
		vector(const size_t size);
		vector(const size_t size, const T& value);
		vector(const vector& other); //copy constructor
		~vector();

		vector& operator=(const vector& other);

		T operator[](const size_t index) const;
		T& operator[](const size_t index);

		void push_back(const T& value);

		size_t size() const;

		class iterator {
		public:
			iterator(T* current);

			bool operator==(const iterator& other) const;
			bool operator!=(const iterator& other) const;
			iterator operator++();
			T& operator*();
		private:
			T* mCurrent;
		};

		iterator begin();
		iterator end();

	private:
		T* mData = nullptr;
		size_t mSize = 0;
		size_t mCapacity = 0;
	};

	template<typename T>
	typename vector<T>::iterator vector<T>::iterator::operator++()
	{
		++mCurrent;
		return iterator(mCurrent);
	}

	template<typename T>
	bool vector<T>::iterator::operator!=(const iterator& other) const
	{
		return !(*this == other);
	}

	template<typename T>
	bool vector<T>::iterator::operator==(const iterator& other) const
	{
		return mCurrent == other.mCurrent;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::end()
	{
		return  iterator(mData + mSize);
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::begin()
	{
		return  iterator(mData);
	}

	template<typename T>
	vector<T>::iterator::iterator(T* current) 
	:mCurrent(current)
	{

	}

	template<typename T>
	void vector<T>::push_back(const T& value) {
		if (mSize < mCapacity) {
			mData[mSize] = value;
			++mSize;
		}
		else {
			if (mCapacity == 0) {
				mSize = 1;
				mCapacity = 1;
				mData = new T[mCapacity];
				mData[0] = value;
			}
			else {
				mCapacity <<= 1;
				T* temp = mData;
				mData = new T[mCapacity];
				std::copy(temp, temp + mSize, mData);
				mData[mSize] = value;
				++mSize;

				delete[] temp;
			}
		}
	}

	template<typename T>
	vector<T>& vector<T>::operator=(const vector& other)
	{
		if (this != &other) {
			delete[] mData;
			mData = new T[other.mCapacity];
			mSize = other.mSize;
			mCapacity = other.mCapacity;
			std::copy(other.mData, other.mData + mSize, mData);
		}
		return *this;
	}

	template<typename T>
	vector<T>::vector(const vector& other)
		:mData(new T[other.mCapacity]), mSize(other.mSize), mCapacity(other.mCapacity)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			std::copy(other.mData, other.mData + mSize, mData);
		}
	}

	template<typename T>
	T& vector<T>::operator[](const size_t index) {
		return mData[index];
	}

	template<typename T>
	T vector<T>::operator[](const size_t index) const {
		return mData[index];
	}

	template<typename T>
	size_t vector<T>::size() const
	{
		return mSize;
	}

	template<typename T>
	vector<T>::vector(const size_t size, const T& value)
		:vector(size)
	{
		std::fill(mData, mData + mSize, value);
	}

	template<typename T>
	vector<T>::~vector()
	{
		delete[] mData;
	}

	template<typename T>
	vector<T>::vector(const size_t size)
		:mData(new T[size]), mSize(size), mCapacity(size)
	{

	}
}

