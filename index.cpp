#include <stdio.h>
#define MAX_ARRAY_NUM (100)

int main(void)
{
	class String {
		public:
			char m_string[MAX_ARRAY_NUM] = "";
			char m_tempString[MAX_ARRAY_NUM] = "";
			size_t m_length = 0;

			String(const char p_paramString[MAX_ARRAY_NUM]) {
				char* p_tempString = m_string;
				while (*p_paramString != '\0') {
					m_length++;
					*p_tempString++ = *p_paramString++;
				}
				*p_tempString = '\0';
			};
			~String(void) {};

			static void copy(char* destination, const char& source) 
			{
				const char* p_string = &source;
				char* p_dest = destination;
				while (*p_string != '\0')
				{
					*p_dest++ = *p_string++;
				}
				*p_dest = '\0';
			}
			static void copyByNum(char* destination, const char& string, size_t num)
			{
				const char* p_string = &string;
				char* p_dest = destination;
				size_t index = 0;
				while (*p_string != '\0' && index < num)
				{
					*p_dest++ = *p_string++;
					index++;
				}
				*p_dest = '\0';
			}
			static void concat(char* destination, const char& string) {
				const char* p_string = &string;
				char* p_tempString = destination;
				while (*p_tempString != '\0')
				{
					p_tempString++;
				}
				while (*p_string != '\0')
				{
					*p_tempString++ = *p_string++;
				}
				*p_tempString = '\0';
			}
			static int compare(const char& string1, const char& string2) {
				const char* p_string1 = &string1;
				const char* p_string2 = &string2;
				int charNum1 = *p_string1;
				int charNum2 = *p_string2;
				while (charNum1 != '\0' && charNum1 == charNum2)
				{
					charNum1 = *++p_string1;
					charNum2 = *++p_string2;
				}
				if (charNum1 == charNum2)
				{
					return 0;
				}
				return charNum1 > charNum2 ? 1 : -1;
			}
			static size_t getLength(const char& string) {
				const char* p_string = &string;
				size_t ret_Length = 0;
				while (*p_string++ != '\0') {
					ret_Length++;
				}
				return ret_Length;
			}
			static void reverse(char* p_destination, const char& string) 
			{
				const char* p_string = &string;
				char tempString[MAX_ARRAY_NUM];
				char* p_tempString;

				size_t stringLength = 0;
				{
					while (*p_string++ != '\0') {
						stringLength++;
					}
				}

				{
					p_string = &string + stringLength - 1;
					p_tempString = tempString;
	
					while (stringLength != 0) {
						*p_tempString++ = *p_string--;
						stringLength--;
					}
					*p_tempString = '\0';
				}

				{
					p_tempString = tempString;
					while (*p_tempString != '\0')
					{
						*p_destination++ = *p_tempString++;
					}
					*p_destination = '\0';
				}
			}
			//static void token(char* string, const char& delimiters)
			//{
			//	 char* p_string = string;
			//	 const char* p_delimiters = &delimiters;

			//}
			String* selfCopy() 
			{
				return new String(m_string);
			};
			void reverseString()
			{
				char* p_string = m_string + m_length - 1;
				char* p_tempString = m_tempString;
				{
					size_t index = m_length;
					while (index != 0) {
						*p_tempString++ = *p_string--;
						index--;
					}
					*p_tempString = '\0';
				}
				{
					p_string = m_tempString;
					p_tempString = m_string;
					while (*p_string != '\0') {
						*p_tempString++ = *p_string++;
					}
					*p_tempString = '\0';
				}
			};
			void printString() 
			{
				char* p_string = m_string;
				while (*p_string != '\0') {
					 printf("%c",*p_string++); 
				}
			}
	};
	String* string = new String("hello world");

	char dest[MAX_ARRAY_NUM] = "hello";
	char source[MAX_ARRAY_NUM] = "world";

	String::concat(dest,*source);
	printf("dest %s \n", dest);

	size_t num = String::getLength(*dest);
	printf("num %d \n", num);

	char str1[MAX_ARRAY_NUM] = "abc";
	char str2[MAX_ARRAY_NUM] = "dbc";
	size_t num2 = String::compare(*str1, *str2);
	printf("compare %d \n", num2);

	String::reverse(str1, *str2);
	printf("reverse str1 %s", str1);

	delete string;

	return 0;
}