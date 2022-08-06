#pragma once

namespace custum {

	template<typename Type>
	struct deleter {
		deleter() = delete;
		~deleter() = delete;
		deleter<Type>& deleter(deleter<Type>& other) = delete;
		
		void operator ()(Type* ptr) noexcept;
	};

	template<typename Type>
	struct deleter<Type[]> {
		deleter() = delete;
		~deleter() = delete;
		deleter<Type[]> & deleter(deleter<Type[]>& other) = delete;

		void operator ()(Type* ptr) noexcept;
	};



	template<typename Type, typename mode = deleter<Type>>
	class vector {

		using type = typename std::remove_extent<Type>::type;
		using del = mode;

	public:
		vector() = default;
		explicit vector& vector(vector& other) noexcept;

		vector<Type,mode>& operator = () noexcept;


		void push_back(Type* value) noexcept;
		void pop_back(Type* value) noexcept;


	private:
		~vector() noexcept;
		del deleter;
		Type* data = nullptr;

	private:
		size_t m_size;
		size_t m_capacity;

	};

}