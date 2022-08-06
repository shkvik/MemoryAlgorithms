#pragma once

namespace custum {

	template<typename Type>
	struct deleter {
		deleter() = delete;
		~deleter() = delete;
		deleter<Type>& deleter(deleter<Type>& other) = delete;
		
		void operator ()() noexcept;
	};

	template<typename Type>
	struct deleter<Type[]> {
		deleter() = delete;
		~deleter() = delete;
		deleter<Type[]> & deleter(deleter<Type[]>& other) = delete;

		void operator ()() noexcept;
	};



	template<typename Type, typename mode = deleter<Type>>
	class vector {

		using type = typename std::remove_extent<Type>::type;
		using del = mode;

	public:
		vector() = default;
		explicit vector& vector(vector& other) noexcept;
		vector& operator = () noexcept;


		void push_back() noexcept;
		void pop_back() noexcept;


	private:
		~vector() noexcept;
		del deleter;
		Type* data;

	private:
		size_t m_size;
		size_t m_capacity;

	};

}