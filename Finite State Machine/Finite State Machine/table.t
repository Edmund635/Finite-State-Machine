/////////////////////////////////// digraph.t /////////////////////////////////////////////////////////////////////////
//
// File name          : table.t
//
//
// Programmer         : EDMUND ADJEI
//
// Date created       : 11/10/2021
//
// Professor		  : Bradley J. Streller
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


template < class Key, typename T >
Table<Key, T>::Table(int n, int (*map)(Key k))
{

	tableSize = n;
	Mapping = map;
	the_table = new Pair<key_type, T>[tableSize];

	for (int i = 0; i < tableSize; i++) {
		the_table[i] = Pair<key_type, T>();
	}
}

template < class Key, typename T >
bool Table<Key, T>::insert(Pair<  Key, T >  kvpair) {
	int found = Mapping(kvpair.first);
	if (found > tableSize || found < 0)
		return false;
	else if (the_table[found].first == Key() && the_table[found].second == T())
	{
		the_table[found] = kvpair;
		return true;
	}
	else
		return false;

}

template < class Key, typename T >
bool Table<Key, T>::remove(const Key  aKey) {
	int found = Mapping(aKey);
	if (Mapping(aKey) > tableSize || Mapping(aKey) < 0)
		return false;
	else if (the_table[found] == Pair<key_type, T>())
		return false;
	else
	{
		the_table[found] = Pair<key_type, T>();
		return true;
	}


}

template < class Key, typename T >
T  Table<Key, T>::lookUp(const Key aKey) {
	T temp;
	int found = Mapping(aKey);
	if (!isIn(aKey)) {
		std::cout << " Key does not exist in the table!" << '\n';
		return temp;
	}
	else
	{
		return the_table[found].second;
	}
}

template < class Key, typename T >
Table<Key, T>::	Table(const Table &t1)
{

	tableSize = t1.tableSize;
	Mapping = t1.Mapping;
	the_table = new Pair<key_type, T>[t1.tableSize];

	for (int i = 0; i < t1.tableSize; i++) {
		the_table[i] = t1.the_table[i];
	}
}

template < class Key, typename T >
Table<Key, T>::~Table() {

	
}

template < class Key, typename T >
bool Table<Key, T>::isIn(const Key& key) const {
	int found = Mapping(key);
	if (found > tableSize || found < 0)
		return false;
	else if (the_table[found].first == Key())
	{
		return false;
	}
	else
		return true;

}

template < class Key, typename T >
void Table<Key, T>::operator= (const Table& initTable) {
	
	tableSize = initTable.tableSize;
	Mapping = initTable.Mapping;
	the_table = new Pair<key_type, T>[initTable.tableSize];
	for (int i = 0; i < initTable.tableSize; i++) {
		the_table[i] = initTable.the_table[i];
	}
}

template < class Key, typename T >
bool Table<Key, T>::empty() const {
	
	for (int i = 0; i < tableSize; i++) {
		if (the_table[i] != Pair<key_type, T>()) {
			return false;
		}
	}
	return true;
}

template < class Key, typename T >
bool Table<Key, T>::full() const {

	for (int i = 0; i < tableSize; i++) {
		if (the_table[i] == Pair<key_type, T>()) {
			return false;
		}
	}
	return true;
}

template < class Key, typename T >
int Table<Key, T>::size() const {
	int count = 0;
	for (int i = 0; i < tableSize; i++) {
		if (the_table[i] != Pair<key_type, T>()) {
			count++;
		}
	}
	return count;

}
