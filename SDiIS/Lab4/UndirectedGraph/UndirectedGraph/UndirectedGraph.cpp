#include <iostream>
#include <vector>
#include "Error.h"
#include "UndirectedGraph.hpp"

using namespace std;


int main()
{
	try {
		Undirected_graph<int> graph;
		graph.add_vertex(5);
		graph.add_vertex(6);
		graph.add_vertex(7);
		graph.add_vertex(8);
		graph.add_vertex(9);
		graph.add_edge(5, 7);
		graph.add_edge(7, 8);
		graph.add_edge(5, 9);
		graph.print_matrix();
		Undirected_graph<int>::vertexes_iterator ver_iter = graph.vertexes_begin();
		for (; ver_iter != graph.vertexes_end(); ++ver_iter) {
			cout << ver_iter << " ";
		}
		cout << endl;
		Undirected_graph<int>::vertexes_riterator ver_rev_iter = graph.vertexes_rbegin();
		for (; ver_rev_iter != graph.vertexes_rend(); ++ver_rev_iter) {
			cout << ver_rev_iter << " ";
		}
		cout << endl;
		Undirected_graph<int>::vertexes_citerator ver_cons_iter = graph.vertexes_cbegin();
		for (; ver_cons_iter != graph.vertexes_cend(); ++ver_cons_iter) {
			cout << ver_cons_iter << " ";
		}
		cout << endl;

		Undirected_graph<int>::edges_iterator edge_iter = graph.edges_begin();
		for (; edge_iter != graph.edges_end(); ++edge_iter) {
			cout << edge_iter << " ";
		}
		cout << endl;
		Undirected_graph<int>::edges_riterator edge_rev_iter = graph.edges_rbegin();
		for (; edge_rev_iter != graph.edges_rend(); ++edge_rev_iter) {
			cout << edge_rev_iter << " ";
		}
		Undirected_graph<int>::edges_citerator edge_cons_iter = graph.edges_cbegin();
		for (; edge_cons_iter != graph.edges_cend(); ++edge_cons_iter) {
			cout << edge_cons_iter << " ";
		}
		cout << endl;

		Undirected_graph<int>::Adjacency_iterator adj_iter = graph.adjacency_begin(5);
		for (; adj_iter != graph.adjacency_end(5); ++adj_iter) {
			cout << adj_iter << " ";
		}
		cout << endl;
		Undirected_graph<int>::Adjacency_riterator adj_rev_iter = graph.adjacency_rbegin(5);
		for (; adj_rev_iter != graph.adjacency_rend(5); ++adj_rev_iter) {
			cout << adj_rev_iter << " ";
		}
		Undirected_graph<int>::Adjacency_citerator adj_cons_iter = graph.adjacency_cbegin(5);
		for (; adj_cons_iter != graph.adjacency_cend(5); ++adj_cons_iter) {
			cout << adj_cons_iter << " ";
		}
		cout << endl;

		Undirected_graph<int>::incidental_iterator inc_iter = graph.iccidental_begin(5);
		for (; inc_iter != graph.iccidental_end(5); ++inc_iter) {
			cout << inc_iter << " ";
		}
		cout << endl;
		Undirected_graph<int>::incidental_riterator inc_rev_iter = graph.iccidental_rbegin(5);
		for (; inc_rev_iter != graph.iccidental_rend(5); ++inc_rev_iter) {
			cout << inc_rev_iter << " ";
		}
		Undirected_graph<int>::incidental_citerator inc_cons_iter = graph.iccidental_cbegin(5);
		for (; inc_cons_iter != graph.iccidental_cend(5); ++inc_cons_iter) {
			cout << inc_cons_iter << " ";
		}
		cout << endl;


		Undirected_graph<int>::vertexes_iterator beg = graph.vertexes_begin();

		Undirected_graph<int>::vertexes_riterator end = graph.vertexes_rbegin();
		graph.remove_vertex_by_iterator(end);

	}
	catch (Adding_error error) {
		cout << error.get_message();
	}
	catch (Find_error error) {
		cout << error.get_message();
	}
}
