#ifndef STRING_H
#define STRING_H

namespace custom_string {
	class String
	{
		char* str = nullptr;
		size_t size = 0;

	public:
		String();
		String(const String& other);
		String(String&& other) noexcept;
		String(const char* c);
		~String();
		size_t len() const;
		size_t strlen(const char* _str) const;
		String& operator= (const String& other);
		String& operator= (String&& other) noexcept;
		char  operator[] (size_t i) const;
		char& operator[] (size_t i);
	};
}
#endif // STRING_H
