#include <iostream>
#include <sstream>
#include <string>

struct Key
{
	std::string m_text;
	size_t m_key;
	bool m_ocupied;
	bool m_on_good_pos;

	Key() : m_text(""), m_key(0), m_ocupied(false), m_on_good_pos(false) {}

	Key& operator= (const Key& k)
	{
		if (this != &k)
		{
			m_text = k.m_text;
			m_key = k.m_key;
			m_ocupied = k.m_ocupied;
		}

		return *this;
	}
};

struct tracker
{
	size_t m_last_key;
	size_t m_position;
	size_t m_count;

	tracker() : m_last_key(0),m_position(0), m_count(0) {}
};


class HashTable
{
private:
	Key* m_HT;
	tracker m_T;
	size_t m_size;
	size_t m_count;
public:
	HashTable() : m_HT(nullptr),m_T(), m_size(0), m_count(0) {}
	~HashTable()
	{
		clear();
	}

	void clear()
	{
		if(m_size == 0)
			delete m_HT;
	}

	void  add(size_t key, const std::string& text)
	{
		if (m_HT[Hash(key)].m_ocupied == false || m_HT[Hash(key)].m_key == key)
		{
			m_HT[Hash(key)].m_key = key;
			m_HT[Hash(key)].m_text = text;
			m_HT[Hash(key)].m_ocupied = true;
			m_HT[Hash(key)].m_on_good_pos = true;
		}
		else
		{
			size_t finder = Hash(key);

			while (m_HT[finder].m_ocupied != false)
			{
				if (m_HT[finder].m_key == key)
					break;
				else
					finder != m_size - 1 ? finder++ : finder = 0;
			}
	
			if (m_HT[finder].m_key != key)
				m_T.m_count++;

			m_HT[finder].m_key = key;
			m_HT[finder].m_text = text;
			m_HT[finder].m_ocupied = true;


			if (m_T.m_count == 0)
			{
				m_T.m_last_key = key;
				m_T.m_position = finder;

			}

			else if (m_T.m_position >= Hash(m_T.m_last_key))
			{
				//if (m_T.m_position == m_size - 1 && finder < Hash(key))
				//{
				//	m_T.m_last_key = key;
				//	m_T.m_position = finder;
				//}
				if (m_T.m_position < finder)
				{
					m_T.m_last_key = key;
					m_T.m_position = finder;
				}
				else if (static_cast<size_t>(finder) < Hash(key))
				{
					m_T.m_last_key = key;
					m_T.m_position = finder;
				}

			}
			else if (m_T.m_position < Hash(m_T.m_last_key))
			{
				if (static_cast<size_t>(finder) < Hash(key) && finder > m_T.m_position)
				{
					m_T.m_last_key = key;
					m_T.m_position = finder;
				}
				//else if (m_T.m_position < finder)
				//{
				//	m_T.m_last_key = key;
				//	m_T.m_position = finder;
				//}
			}
			

		}
	}

	void fill(size_t index)
	{
		size_t counter = 0;
		size_t tempIndex = m_T.m_position;
		bool found = false;
		if (index != m_T.m_position)
		{
			while (counter < m_T.m_count && found == false)
			{

				if (m_HT[tempIndex].m_ocupied == true && m_HT[tempIndex].m_on_good_pos == false && Hash(m_HT[tempIndex].m_key) <= index)
				{
					found = true;
					m_HT[index] = m_HT[tempIndex];

					if (index == Hash(m_HT[index].m_key))
					{
						m_HT[index].m_on_good_pos = true;
						m_T.m_count--;

					}
					else
					{
						m_HT[index].m_on_good_pos = false;
					}

					m_HT[tempIndex].m_key = 0;
					m_HT[tempIndex].m_text = "";
					m_HT[tempIndex].m_ocupied = false;
					//m_HT[tempIndex].m_on_good_pos = false;

					fill(tempIndex);
				}
				else if (m_HT[tempIndex].m_on_good_pos == false && m_HT[tempIndex].m_ocupied == true)
				{
					counter++;
					tempIndex > 0 ? tempIndex-- : tempIndex = m_size - 1;
				}
				else 
					tempIndex > 0 ? tempIndex-- : tempIndex = m_size - 1;
			}
		}
		else
		{
			size_t temp = index;
			while (temp != m_size - 1)
			{
				if(m_HT[temp].m_ocupied == true && m_HT[temp].m_on_good_pos == false && index >= Hash(m_HT[temp].m_key))
				{
					m_HT[index] = m_HT[temp];

					m_HT[temp].m_key = 0;
					m_HT[temp].m_text = "";
					m_HT[temp].m_ocupied = false;
					break;
				}
				temp++;
			}
			findLast(index);
		}

	}

	void findLast(size_t index)
	{
		size_t counter = 0;
		size_t tempIndex = index;
		bool found = false;
		while (counter < m_T.m_count && found == false)
		{
			//m_T.m_count--;
			if (tempIndex > 0 ? --tempIndex : tempIndex = m_size - 1)

				if (m_HT[tempIndex].m_ocupied == true && m_HT[tempIndex].m_on_good_pos == false)
				{
					m_T.m_last_key = m_HT[tempIndex].m_key;
					m_T.m_position = tempIndex;
					found = true;
				}
		}
	}



	void setHT(size_t size)
	{
		clear();
		m_HT = new Key[size];
	}

	size_t Hash(size_t h)
	{
		return h % m_size;
	}

	void start()
	{
		std::string temp;
		size_t counter = 0;

		std::getline(std::cin, temp);

		m_count = std::stol(temp);

		
			while (counter < m_count)
			{
				std::getline(std::cin, temp);
				std::stringstream ss;
				ss << temp;
				ss >> temp;

				if (temp == "size")
				{
					ss >> temp;
					m_size = stol(temp);
					setHT(m_size);
				}
				else if (temp == "add")
				{
					std::string text;

					ss >> temp;
					ss >> text;

					add(stol(temp), text);

				}
				else if (temp == "print")
				{
					for (int i = 0; i < m_size; i++)
					{
						if (m_HT[i].m_ocupied != false)
							std::cout << i << " " << m_HT[i].m_key << " " << m_HT[i].m_text << std::endl;
					}
					std::cout << '\n';
				}
				else if (temp == "stop")
				{
					counter++;
				}
				else if (temp == "delete")
				{
					ss >> temp;
					size_t counter;
					size_t key = stoi(temp);
					counter = Hash(key);

					if (m_HT[counter].m_ocupied != false) 
					{
						while (m_HT[counter].m_key != key)
							counter < m_size ? counter++ : counter = 0;

						if (m_HT[counter].m_on_good_pos != true && m_T.m_count != 0)
							m_T.m_count--;

						m_HT[counter].m_key = 0;
						m_HT[counter].m_text = "";
						m_HT[counter].m_ocupied = false;
						m_HT[counter].m_on_good_pos = false;

						if (m_T.m_position == counter)
							findLast(counter);
						else //if (m_T.m_count != 0)
							fill(counter);
					}
				}
		}
	}	
};


int main()
{
	HashTable ht;
	ht.start();
	//std::cin.get();
	return 0;
}