#pragma once

namespace oe {

	template<typename T>
	class vector
	{
	public:
		vector() = default;
	private:
		T* mData = nullptr;
		size_t mSize = 0;
		size_t mCapacity = 0;
	};
}

