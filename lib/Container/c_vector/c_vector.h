#pragma once
#include "c_vector.h"
#include <iostream>

namespace custum {

	template<typename Type>
	struct deleter {

		void operator ()(Type* ptr);
	};

	template<typename Type>
	struct deleter<Type[]> {

		void operator ()(Type* ptr);
	};

	

	template<typename Type, typename mode = deleter<Type>>
	class vector {

		using type = typename std::remove_extent<Type>::type;
		using del = mode;

	public:
		vector() = default;
		explicit vector(vector& other) noexcept;

		vector<Type,mode>& operator = (vector<Type, mode>& other) noexcept;


		type operator [](const size_t number) const;



		void push_back(type value);
		void pop_back(type value);

		~vector();

	private:
		
		del deleter;
		Type* data = nullptr;

	private:
		size_t m_size = 0;
		size_t m_capacity = 0;

	};

}