#ifndef	_MESSENGER_H
#define	_MESSENGER_H

#include <vector>
#include <string>

class messenger
{
	public:
		class value_pair
		{
		friend class messenger;
		private:
			std::string key;
			std::string value;
		public:
			value_pair(std::string key, std::string value);
			~value_pair();
			std::string get_value();
			
		};
	private:
		std::vector<value_pair*> _values;
	public:
	messenger();
	~messenger();
	void retrieve_value_pair(std::string key);
	void modify_value_pair(std::string key, std::string value);

};
#endif