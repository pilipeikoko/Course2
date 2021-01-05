#pragma once
#include <iostream>
#include <vector>
#include "Error.h"

using namespace std;


template<typename Value_type>
class Undirected_graph {

	class Vertex {
	public:
		vector<int> vector_of_edges;
		Value_type id;
		Vertex(vector<int>to_push, Value_type id);
	};

	//matrix is stored here
	vector <Vertex> matrix;

	class Iterator_vertexes {
	public:
		Vertex* ptr;
		Iterator_vertexes() {}
		Iterator_vertexes(Vertex* iter) : ptr(iter) { }
		virtual Vertex* operator++() {
			return ptr++;
		}
		virtual Vertex* operator--() {
			return ptr--;
		}
		virtual bool operator!=(Iterator_vertexes it) { return ptr != it.ptr; }
		virtual bool operator==(Iterator_vertexes it) { return ptr == it.ptr; }

		Vertex operator*() {
			return *(this->ptr);
		}

		friend ostream& operator<<(ostream& out, Iterator_vertexes vector_of_edges) {
			out << (*vector_of_edges).id;
			return out;
		}
	};
	//Iterator_reverse_vertexes inhirits Iterator_vertexes so we could remove by iterator with one method
	class Iterator_reverse_vertexes : public Iterator_vertexes {
	public:
		using Iterator_vertexes::ptr;
		Iterator_reverse_vertexes(Vertex* iter) { ptr = iter; }
		Vertex* operator++() {
			return ptr--;
		}
		Vertex* operator--() {
			return ptr++;
		}
		bool operator!=(Iterator_reverse_vertexes it) { return ptr != it.ptr; }
		bool operator==(Iterator_reverse_vertexes it) { return ptr == it.ptr; }
	};
	class Iterator_constant_vertexes {
	public:
		const Vertex* ptr;
		Iterator_constant_vertexes() {}
		Iterator_constant_vertexes(const Vertex* iter) : ptr(iter) { }
		const Vertex* operator++() {
			return ptr++;
		}
		const Vertex* operator--() {
			return ptr--;
		}
		bool operator!=(Iterator_constant_vertexes it) { return ptr != it.ptr; }
		bool operator==(Iterator_constant_vertexes it) { return ptr == it.ptr; }

		const Vertex operator*() {
			return *(this->ptr);
		}

		friend ostream& operator<<(ostream& out, Iterator_constant_vertexes vector_of_edges) {
			out << (*vector_of_edges).id;
			return out;
		}
	};

	class Iterator_vector {
	public:
		int* ptr;
		Iterator_vector() { }
		Iterator_vector(int* iter) : ptr(iter) { }
		virtual int* operator++() {
			do {
				ptr++;

			} while (*ptr == 0);

			return ptr;
		}
		virtual int* operator--() {
			do {
				ptr--;

			} while (*ptr == 0);

			return ptr;
		}

		virtual bool operator!=(Iterator_vector it) { return ptr != it.ptr; }
		virtual bool operator==(Iterator_vector it) { return ptr == it.ptr; }

		int operator*() {
			return *(this->ptr);
		}

		friend ostream& operator<<(ostream& out, Iterator_vector vector_of_edges) {
			out << *vector_of_edges;
			return out;
		}
	};
	class Iterator_reverse_vector : public Iterator_vector {
	public:
		using Iterator_vector::ptr;
		Iterator_reverse_vector(int* ptr) { this->ptr = ptr; }
		int* operator++() {
			do {
				ptr--;
			} while (*ptr == 0);

			return ptr;
		}
		int* operator--() {
			do {
				ptr++;
			} while (*ptr == 0);

			return ptr;
		}

		bool operator!=(Iterator_reverse_vector it) { return ptr != it.ptr; }
		bool operator==(Iterator_reverse_vector it) { return ptr == it.ptr; }
	};
	class Iterator_constant_vector {
	public:
		const int* ptr;
		Iterator_constant_vector() { }
		Iterator_constant_vector(const int* iter) : ptr(iter) { }
		const int* operator++() {
			do {
				ptr++;

			} while (*ptr == 0);

			return ptr;
		}
		const int* operator--() {
			do {
				ptr--;

			} while (*ptr == 0);

			return ptr;
		}

		bool operator!=(Iterator_constant_vector it) { return ptr != it.ptr; }
		bool operator==(Iterator_constant_vector it) { return ptr == it.ptr; }

		const int operator*() {
			return *(this->ptr);
		}

		friend ostream& operator<<(ostream& out, Iterator_constant_vector vector_of_edges) {
			out << *vector_of_edges;
			return out;
		}
	};

	class Iterator_edges {
	public:
		Vertex* ptr_ver;
		int* ptr_num;
		Iterator_edges() {}
		Iterator_edges(int* ptr) :ptr_num(ptr) { }
		Iterator_edges(Vertex* iter) : ptr_ver(iter) {
			ptr_num = &iter->vector_of_edges[0];
			do {
				ptr_num++;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver++;
					ptr_num = &ptr_ver->vector_of_edges[1];
				}

			} while (*ptr_num == 0);
		}

		virtual int* operator++() {
			do {
				ptr_num++;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver++;
					ptr_num = &ptr_ver->vector_of_edges[1];
				}

			} while (*ptr_num == 0);

			return ptr_num;
		}
		virtual int* operator--() {
			do {
				ptr_num--;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver--;
					ptr_num = &ptr_ver->vector_of_edges[ptr_ver->vector_of_edges.size() - 1];
				}

			} while (*ptr_num == 0);

			return ptr_num;
		}

		virtual bool operator!=(Iterator_edges it) { return ptr_num != it.ptr_num; }
		virtual bool operator==(Iterator_edges it) { return ptr_num == it.ptr_num; }

		friend ostream& operator<<(ostream& out, Iterator_edges it) {
			out << (*it.ptr_num);
			return out;
		}
	};
	//Iterator_reverse_edges inherits Iterator_edges so we could remove by iterator with one method
	class Iterator_reverse_edges : public Iterator_edges {
	public:
		using Iterator_edges::ptr_ver;
		using Iterator_edges::ptr_num;
		Iterator_reverse_edges(int* ptr):Iterator_edges(ptr)  {  }
		Iterator_reverse_edges(Vertex* iter):Iterator_edges(iter) {
			ptr_num = &iter->vector_of_edges[iter->vector_of_edges.size() - 1];
			do {
				ptr_num--;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver--;
					ptr_num = &ptr_ver->vector_of_edges[ptr_ver->vector_of_edges.size() - 1];
				}

			} while (*ptr_num == 0);
		}

		int* operator++() {
			do {
				ptr_num--;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver--;
					ptr_num = &ptr_ver->vector_of_edges[ptr_ver->vector_of_edges.size() - 2];
				}

			} while (*ptr_num == 0);

			return ptr_num;
		}
		int* operator--() {
			do {
				ptr_num++;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver++;
					ptr_num = &ptr_ver->vector_of_edges[1];
				}

			} while (*ptr_num == 0);

			return ptr_num;
		}

		bool operator!=(Iterator_reverse_edges it) { return ptr_num != it.ptr_num; }
		bool operator==(Iterator_reverse_edges it) { return ptr_num == it.ptr_num; }

		friend ostream& operator<<(ostream& out, Iterator_reverse_edges it) {
			out << (*it.ptr_num);
			return out;
		}

	};
	class Iterator_constant_edges {
	public:
		const Vertex* ptr_ver;
		const int* ptr_num;
		Iterator_constant_edges() {}
		Iterator_constant_edges(const int* ptr) :ptr_num(ptr) { }
		Iterator_constant_edges(const Vertex* iter) {
			ptr_ver = iter;
			ptr_num = &iter->vector_of_edges[0];
			do {
				ptr_num++;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver++;
					ptr_num = &ptr_ver->vector_of_edges[1];
				}

			} while (*ptr_num == 0);
		}

		const int* operator++() {
			do {
				ptr_num++;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver++;
					ptr_num = &ptr_ver->vector_of_edges[1];
				}

			} while (*ptr_num == 0);

			return ptr_num;
		}
		const int* operator--() {
			do {
				ptr_num--;

				if (*ptr_num != 0 && *ptr_num != 1) {
					ptr_ver--;
					ptr_num = &ptr_ver->vector_of_edges[ptr_ver->vector_of_edges.size() - 1];
				}

			} while (*ptr_num == 0);

			return ptr_num;
		}

		bool operator!=(Iterator_constant_edges it) { return ptr_num != it.ptr_num; }
		bool operator==(Iterator_constant_edges it) { return ptr_num == it.ptr_num; }

		friend ostream& operator<<(ostream& out, Iterator_constant_edges it) {
			out << (*it.ptr_num);
			return out;
		}
	};

	class Iterator_additional_vector : public Iterator_vector {
	public:
		using Iterator_vector::ptr;
		int counter;
		Vertex* ptr_ver;
		Iterator_additional_vector() :ptr(nullptr), counter(1) {}
		Iterator_additional_vector(int* iter, int counter) : Iterator_vector(iter) {
			this->counter = counter;
			//	ptr_ver = matrix.begin()+counter;
		}
		int* operator++() {
			do {
				ptr++;
				counter++;
			} while (*ptr == 0);
			return ptr;
		}
		int* operator--() {
			do {
				ptr--;
				counter--;
			} while (*ptr == 0);
			return ptr;
		}
		bool operator!=(Iterator_additional_vector it) { return ptr != it.ptr; }
		bool operator==(Iterator_additional_vector it) { return ptr == it.ptr; }

		friend ostream& operator<<(ostream& out, Iterator_additional_vector it) {

			out << it.counter;
			return out;
		}
	};
	class Iterator_additional_reverse_vector :public  Iterator_vector {
	public:
		using Iterator_vector::ptr;
		int counter;
		Vertex* ptr_ver;
		Iterator_additional_reverse_vector() :Iterator_vector(nullptr), counter(1) {}
		Iterator_additional_reverse_vector(int* iter, int counter):Iterator_vector(iter) {
			this->counter = counter;
		}
		int* operator++() {
			do {
				ptr--;
				counter--;
			} while (*ptr == 0);
			return ptr;
		}
		int* operator--() {
			do {
				ptr++;
				counter++;
			} while (*ptr == 0);
			return ptr;
		}
		bool operator!=(Iterator_additional_reverse_vector it) { return ptr != it.ptr; }
		bool operator==(Iterator_additional_reverse_vector it) { return ptr == it.ptr; }

		friend ostream& operator<<(ostream& out, Iterator_additional_reverse_vector it) {

			out << it.counter;
			return out;
		}
	};
	class Iterator_additional_constant_vector {
	public:
		const int* ptr;
		int counter;
		const Vertex* ptr_ver;
		Iterator_additional_constant_vector() :ptr(nullptr), counter(1) {}
		Iterator_additional_constant_vector(const int* iter, int counter) {
			ptr = iter;
			this->counter = counter;
		}
		const int* operator++() {
			do {
				ptr++;
				counter++;
			} while (*ptr == 0);
			return ptr;
		}
		const int* operator--() {
			do {
				ptr--;
				counter--;
			} while (*ptr == 0);
			return ptr;
		}
		bool operator!=(Iterator_additional_constant_vector it) { return ptr != it.ptr; }
		bool operator==(Iterator_additional_constant_vector it) { return ptr == it.ptr; }

		friend ostream& operator<<(ostream& out, Iterator_additional_constant_vector it) {

			out << it.counter;
			return out;
		}
	};

	Value_type get_id_by_index(int index);
	void supplement_matrix();
	int find_index_of_vertex(Value_type id);
	int find_first_edge_in_line(int index);
	int find_last_edge_in_line(int index);

public:
	Undirected_graph() {}
	Undirected_graph(const Undirected_graph<Value_type>& graph);

	bool is_clear();

	void delete_vertex(Value_type id) throw(Find_error);
	void delete_edge(Value_type first_id, Value_type second_id) throw(Find_error);

	int count_degree_of_edge(Value_type first_id, Value_type second_id);
	int count_degree_of_vertex(Value_type id);

	int get_amount_of_edges();
	int get_amount_of_vertexes();

	bool edge_exists(Value_type first_id, Value_type second_int);
	bool vertex_exists(Value_type id);

	void add_vertex(Value_type id) throw(Adding_error);
	void add_edge(Value_type first_id, Value_type second_id) throw(Find_error);

	void print_matrix();
	void clear_matrix();

	typedef Iterator_vertexes vertexes_iterator;
	typedef Iterator_reverse_vertexes vertexes_riterator;
	typedef Iterator_constant_vertexes vertexes_citerator;

	vertexes_iterator vertexes_begin() {
		return &matrix[1];
	}
	vertexes_iterator vertexes_end() {
		return &matrix[matrix.size() - 1];
	}
	vertexes_riterator vertexes_rbegin() {
		return &matrix[matrix.size() - 2];
	}
	vertexes_riterator vertexes_rend() {
		return &matrix[0];
	}
	vertexes_citerator vertexes_cbegin() {
		return &matrix[1];
	}
	vertexes_citerator vertexes_cend() {
		return &matrix[matrix.size() - 1];
	}
	

	typedef Iterator_vector Adjacency_iterator;
	typedef Iterator_reverse_vector Adjacency_riterator;
	typedef Iterator_constant_vector Adjacency_citerator;

	Adjacency_iterator adjacency_begin(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		int first_edge = find_first_edge_in_line(index);
		if (first_edge == -1) {
			throw Find_error("There are no connections\n");
		}
		return &matrix[index].vector_of_edges[first_edge];
	}
	Adjacency_iterator adjacency_end(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		return &matrix[index].vector_of_edges[matrix[index].vector_of_edges.size() - 1];
	}
	Adjacency_riterator adjacency_rbegin(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		int first_edge = find_last_edge_in_line(index);
		if (first_edge == -1) {
			throw Find_error("There are no connections\n");
		}
		return &matrix[index].vector_of_edges[first_edge];
	}
	Adjacency_riterator adjacency_rend(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		return &matrix[index].vector_of_edges[0];
	}
	Adjacency_citerator adjacency_cbegin(Value_type id){
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		int first_edge = find_first_edge_in_line(index);
		if (first_edge == -1) {
			throw Find_error("There are no connections\n");
		}
		return &matrix[index].vector_of_edges[first_edge];
	}
	Adjacency_citerator adjacency_cend(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		return &matrix[index].vector_of_edges[matrix[index].vector_of_edges.size() - 1];
	}


	typedef Iterator_edges edges_iterator;
	typedef Iterator_reverse_edges edges_riterator;
	typedef Iterator_constant_edges edges_citerator;

	edges_iterator edges_begin() {
		return &matrix[1];
	}
	edges_iterator edges_end() {
		return &matrix[matrix.size() - 1].vector_of_edges[matrix[matrix.size() - 1].vector_of_edges.size() - 1];
	}
	edges_riterator edges_rbegin() {
		edges_riterator r(&matrix[matrix.size() - 2]);
		return r;
	}
	edges_riterator edges_rend() {
		edges_riterator a(&matrix[0].vector_of_edges[0]);
		return a;
	}
	edges_citerator edges_cbegin() {
		return &matrix[1];
	}
	edges_citerator edges_cend() {
		return &matrix[matrix.size() - 1].vector_of_edges[matrix[matrix.size() - 1].vector_of_edges.size() - 1];
	}

	typedef Iterator_additional_vector incidental_iterator;
	typedef Iterator_additional_reverse_vector incidental_riterator;
	typedef Iterator_additional_constant_vector incidental_citerator;

	incidental_iterator iccidental_begin(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		int first_edge = find_first_edge_in_line(index);
		if (first_edge == -1) {
			throw Find_error("There are no connections\n");
		}
		Iterator_additional_vector vector_of_edges(&matrix[index].vector_of_edges[first_edge], first_edge);
		return vector_of_edges;
	}
	incidental_iterator iccidental_end(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		Iterator_additional_vector vector_of_edges(&matrix[index].vector_of_edges[matrix[index].vector_of_edges.size() - 1], 0);
		return vector_of_edges;
	}
	incidental_riterator iccidental_rbegin(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		int first_edge = find_last_edge_in_line(index);
		if (first_edge == -1) {
			throw Find_error("There are no connections\n");
		}
		Iterator_additional_reverse_vector vector_of_edges(&matrix[index].vector_of_edges[first_edge], 5);
		return vector_of_edges;
	}
	incidental_riterator iccidental_rend(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		Iterator_additional_reverse_vector vector_of_edges(&matrix[index].vector_of_edges[0], 0);
		return vector_of_edges;
	}
	incidental_citerator iccidental_cbegin(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		int first_edge = find_first_edge_in_line(index);
		if (first_edge == -1) {
			throw Find_error("There are no connections\n");
		}
		Iterator_additional_constant_vector vector_of_edges(&matrix[index].vector_of_edges[first_edge], first_edge);
		return vector_of_edges;
	}
	incidental_citerator iccidental_cend(Value_type id) {
		int index = find_index_of_vertex(id);
		if (index == -1)
			throw Find_error("Vertex not found\n");
		Iterator_additional_constant_vector vector_of_edges(&matrix[index].vector_of_edges[matrix[index].vector_of_edges.size() - 1], 0);
		return vector_of_edges;
	}

	void remove_edge_by_iterator(Iterator_edges it);
	void remove_edge_by_iterator(Iterator_constant_edges it);
	void remove_vertex_by_iterator(Iterator_vertexes it);
	void remove_vertex_by_iterator(Iterator_constant_vertexes it);
};


template<typename Value_type>
inline Value_type Undirected_graph<Value_type>::get_id_by_index(int index)
{
	return matrix[index].id;
}

template<typename Value_type>
inline void Undirected_graph<Value_type>::supplement_matrix()
{

	auto iter = matrix.begin() + 1;

	for (; iter != matrix.end() - 1; ++iter)
	{
		while (iter->vector_of_edges.size() != matrix.size())
		{
			//shadow edge
			if (iter->vector_of_edges.size() == 1) {
				iter->vector_of_edges.push_back(-1);
				continue;
			}
			//inserting to prev_end position coz last are taken by shadow edges
			iter->vector_of_edges.insert(iter->vector_of_edges.end() - 1, 0);
		}
	}

}

template<typename Value_type>
int Undirected_graph<Value_type>::find_index_of_vertex(Value_type id)
{
	for (int i = 1; i < matrix.size() - 1; i++)
	{
		if (matrix[i].id == id)
			return i;
	}
	return -1;
}

template<typename Value_type>
inline int Undirected_graph<Value_type>::find_first_edge_in_line(int index)
{
	for (int i = 1; i < matrix.size() - 1; i++) {
		if (matrix[index].vector_of_edges[i] == 1)
			return i;
	}
	return -1;
}

template<typename Value_type>
inline int Undirected_graph<Value_type>::find_last_edge_in_line(int index)
{
	for (int i = matrix.size() - 1; i >= 1; i--) {
		if (matrix[index].vector_of_edges[i] == 1)
			return i;
	}
	return -1;
}



template<typename Value_type>
inline Undirected_graph<Value_type>::Undirected_graph(const Undirected_graph<Value_type>& graph)
{
	Undirected_graph to_return;
	for (auto ch : graph) {
		to_return.add_vertex(ch);
	}
}

template<typename Value_type>
inline bool Undirected_graph<Value_type>::is_clear()
{
	return matrix.size();
}

template<typename Value_type>
inline void Undirected_graph<Value_type>::delete_vertex(Value_type id) throw(Find_error)
{
	int index_of_vertex_to_delete = find_index_of_vertex(id);

	if (index_of_vertex_to_delete == -1)
		throw(Find_error("This vertex doesn't exist\n"));

	matrix.erase(matrix.begin() + index_of_vertex_to_delete);

	//ignoring shadow vertexes
	for (int i = 1; i < matrix.size() - 1; i++) {
		matrix[i].vector_of_edges.erase(matrix[i].vector_of_edges.begin() + index_of_vertex_to_delete);
	}
}

//just replacing current info with zero's
template<typename Value_type>
inline void Undirected_graph<Value_type>::delete_edge(Value_type first_id, Value_type second_id) throw(Find_error)
{
	if (!edge_exists(first_id, second_id))
		throw Find_error("This edge doesn't exist\n");

	int first_el = find_index_of_vertex(first_id);
	int second_el = find_index_of_vertex(second_id);

	matrix[first_el].vector_of_edges[second_el] = 0;
	matrix[second_el].vector_of_edges[first_el] = 0;
}

template<typename Value_type>
inline int Undirected_graph<Value_type>::count_degree_of_edge(Value_type first_id, Value_type second_id)
{
	if (edge_exists(first_id, second_id))
		return 2;
	return 0;
}

//counts positive degree of vertex
template<typename Value_type>
inline int Undirected_graph<Value_type>::count_degree_of_vertex(Value_type id)
{
	int count = 0;
	int row = find_index_of_vertex(id);

	if (row != -1) {
		for (auto ch : matrix[row].vector_of_edges)
			ch == 1 ? count++ : count;
		return count;
	}
	return 0;
}

template<typename Value_type>
inline int Undirected_graph<Value_type>::get_amount_of_edges()
{
	int count = 0;
	auto iter = matrix.begin();
	for (; iter != matrix.end(); ++iter) {
		for (auto element : iter->vector_of_edges) {
			if (element == 1)
				count++;
		}
	}
	// graph is unoriented so we got each edge twice, gotta divide by two
	return count / 2;
}

template<typename Value_type>
inline int Undirected_graph<Value_type>::get_amount_of_vertexes()
{
	return matrix.size() - 2;
}

template<typename Value_type>
inline bool Undirected_graph<Value_type>::edge_exists(Value_type first_id, Value_type second_id)
{
	int first_index = find_index_of_vertex(first_id);
	int second_index = find_index_of_vertex(second_id);

	if(first_index == -1 || second_index == -1) 
		return false;
	if (matrix[first_index].vector_of_edges[second_index]!=0)
		return true;
	return false;
}

template<typename Value_type>
inline bool Undirected_graph<Value_type>::vertex_exists(Value_type id)
{
	return find_index_of_vertex(id) == -1 ? false : true;
}

template<typename Value_type>
inline void Undirected_graph<Value_type>::add_vertex(Value_type id) throw(Adding_error)
{
	//if matrix is empty, we have to add shadow vertexes for correct iterators job
	if (matrix.size() < 2) {
		vector <int> to_push(2, -1);
		Vertex base(to_push, id);
		matrix.push_back(base);
		matrix.push_back(base);
	}

	
	if (vertex_exists(id)) {
		throw Adding_error("This vertex already exists\n", id);
	}

	//shadow edges
	vector <int> to_push(1, -1);

	Vertex base(to_push, id);

	matrix.insert(matrix.end() - 1, base);

	supplement_matrix();
}

template<typename Value_type>
inline void Undirected_graph<Value_type>::add_edge(Value_type first_id, Value_type second_id) throw(Find_error)
{

	if (!vertex_exists(first_id) || !vertex_exists(second_id))
	{
		int num_to_throw = vertex_exists(first_id) ? second_id : first_id;

		throw Find_error("This vertex doesn't exist\n");
	}

	int first_el = find_index_of_vertex(first_id);
	int second_el = find_index_of_vertex(second_id);

	matrix[first_el].vector_of_edges[second_el] = 1;
	matrix[second_el].vector_of_edges[first_el] = 1;
}

template<typename Value_type>
inline void Undirected_graph<Value_type>::print_matrix()
{

	auto iter = matrix.begin();

	for (; iter != matrix.end(); ++iter) {
		cout << iter->id << " ";
		for (auto element : iter->vector_of_edges) {
			cout << element << " ";
		}
		cout << endl;
	}


}

template<typename Value_type>
inline void Undirected_graph<Value_type>::clear_matrix()
{
	matrix.clear();
}

// works for Iterator_edges and Iterator_reverse_edges 
template<typename Value_type>
inline void Undirected_graph<Value_type>::remove_edge_by_iterator(Iterator_edges it)
{
	for (int i = 1; i < matrix.size() - 1; i++) {
		for (int j = 1; j < matrix[i].vector_of_edges.size() - 1; j++)
			if (&matrix[i].vector_of_edges[j] == it.ptr_num) {
				matrix[j].vector_of_edges[i] = 0;
				matrix[i].vector_of_edges[j] = 0;
				return;
			}
	}
}

template<typename Value_type>
inline void Undirected_graph<Value_type>::remove_edge_by_iterator(Iterator_constant_edges it)
{
	for (int i = 1; i < matrix.size() - 1; i++) {
		for (int j = 1; j < matrix[i].vector_of_edges.size() - 1; j++)
			if (&matrix[i].vector_of_edges[j] == it.ptr_num) {
				matrix[j].vector_of_edges[i] = 0;
				matrix[i].vector_of_edges[j] = 0;
			}
	}
}

template<typename Value_type>
inline void Undirected_graph<Value_type>::remove_vertex_by_iterator(Iterator_vertexes it)
{
	// starting with ones coz skipping shadow edges and vertexes
	for (int i = 1; i < matrix.size() - 1; i++) {
		if (&matrix[i] == it.ptr) {
			matrix.erase(matrix.begin() + i);
			for (int j = 1; j < matrix.size() - 1; j++) {
				matrix[j].vector_of_edges.erase(matrix[j].vector_of_edges.begin() + i);
			}
			break;
		}
	}

}

template<typename Value_type>
inline void Undirected_graph<Value_type>::remove_vertex_by_iterator(Iterator_constant_vertexes it)
{
	// starting with ones coz skipping shadow edges and vertexes
	for (int i = 1; i < matrix.size() - 1; i++) {
		if (&matrix[i] == it.ptr) {
			matrix.erase(matrix.begin() + i);
			for (int j = 1; j < matrix.size() - 1; j++) {
				matrix[j].vector_of_edges.erase(matrix[j].vector_of_edges.begin() + i);
			}
			break;
		}
	}
}

template<typename Value_type>
inline Undirected_graph<Value_type>::Vertex::Vertex(vector<int> to_push, Value_type id)
{
	this->vector_of_edges = to_push;
	this->id = id;
}
