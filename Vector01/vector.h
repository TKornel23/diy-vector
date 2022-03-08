#pragma once

namespace oe {

	template<typename T>
	class vector
	{
	public:
		vector() = default;
		vector(const size_t size);
	private:
		T* mData = nullptr;
		size_t mSize = 0;
		size_t mCapacity = 0;
	};

	template<typename T>
	vector<T>::vector(const size_t size)
		:mData(new T[size]), mSize(size), mCapacity(size)
	{

	}
}

