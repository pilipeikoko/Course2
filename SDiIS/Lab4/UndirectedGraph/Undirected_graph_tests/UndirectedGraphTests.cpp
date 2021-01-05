#include "../UndirectedGraph/UndirectedGraph.hpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Undirectedgraphtests
{
	TEST_CLASS(Undirectedgraphtests)
	{
	public:
		
		TEST_METHOD(Test_vertex_exists_1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.vertex_exists(5));
		}
		TEST_METHOD(Test_vertex_exists_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsFalse(graph.vertex_exists(2));
		}


		TEST_METHOD(Test_edge_exists_1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.edge_exists(5,7));
		}
		TEST_METHOD(Test_edge_exists_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsFalse(graph.edge_exists(5,1));
		}


		TEST_METHOD(Test_get_amount_of_vertexes)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.get_amount_of_vertexes()==5);
		}
		TEST_METHOD(Test_get_amount_of_edges)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.get_amount_of_edges()==3);
		}


		TEST_METHOD(Test_count_degree_of_vertex_1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.count_degree_of_vertex(5) == 2);
		}
		TEST_METHOD(Test_count_degree_of_vertex_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.count_degree_of_vertex(2) == 0);
		}


		TEST_METHOD(Test_count_degree_of_edge_1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.count_degree_of_edge(5,7) == 2);
		}
		TEST_METHOD(Test_count_degree_of_edge_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_vertex(7);
			graph.add_vertex(8);
			graph.add_vertex(9);
			graph.add_edge(5, 7);
			graph.add_edge(7, 8);
			graph.add_edge(5, 9);
			Assert::IsTrue(graph.count_degree_of_edge(2,5) == 0);
		}


		TEST_METHOD(Test_add_vertex_1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			Assert::IsTrue(graph.vertex_exists(5));
		}
		TEST_METHOD(Test_Test_add_vertex_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			Assert::IsFalse(graph.vertex_exists(0));
		}

		TEST_METHOD(Test_add_edge_1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_edge(5, 6);
			Assert::IsTrue(graph.edge_exists(5,6));
		}
		TEST_METHOD(Test_add_edge_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			Assert::IsFalse(graph.edge_exists(2,5));
		}	

		TEST_METHOD(Test_remove_vertex_by_iterator1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			Undirected_graph<int>::vertexes_iterator beg = graph.vertexes_begin();
			graph.remove_vertex_by_iterator(beg);
			Assert::IsFalse(graph.vertex_exists(5));
		}
		TEST_METHOD(Test_remove_vertex_by_iterator_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			Undirected_graph<int>::vertexes_iterator beg = graph.vertexes_begin();
			graph.remove_vertex_by_iterator(beg);
			Assert::IsTrue(graph.vertex_exists(6));
		}

		TEST_METHOD(Test_remove_vertex_by_riterator1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			Undirected_graph<int>::vertexes_riterator beg = graph.vertexes_rbegin();
			graph.remove_vertex_by_iterator(beg);
			Assert::IsFalse(graph.vertex_exists(6));
		}
		TEST_METHOD(Test_remove_vertex_by_riterator_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			Undirected_graph<int>::vertexes_riterator beg = graph.vertexes_rbegin();
			graph.remove_vertex_by_iterator(beg);
			Assert::IsTrue(graph.vertex_exists(5));
		}

		TEST_METHOD(Test_remove_vertex_by_citerator1)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			Undirected_graph<int>::vertexes_citerator beg = graph.vertexes_cbegin();
			graph.remove_vertex_by_iterator(beg);
			Assert::IsFalse(graph.vertex_exists(5));
		}
		TEST_METHOD(Test_remove_vertex_by_citerator_2)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			Undirected_graph<int>::vertexes_citerator beg = graph.vertexes_cbegin();
			graph.remove_vertex_by_iterator(beg);
			Assert::IsTrue(graph.vertex_exists(6));
		}

		TEST_METHOD(Test_remove_edge_by_iterator)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_edge(5, 6);
			Undirected_graph<int>::edges_iterator beg = graph.edges_begin();
			graph.remove_edge_by_iterator(beg);
			Assert::IsFalse(graph.edge_exists(5,6));
		}
		TEST_METHOD(Test_remove_edge_by_riterator)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_edge(5, 6);
			Undirected_graph<int>::edges_riterator beg = graph.edges_rbegin();
			graph.remove_edge_by_iterator(beg);
			Assert::IsFalse(graph.edge_exists(5, 6));
		}

		TEST_METHOD(Test_remove_edge_by_citerator)
		{
			Undirected_graph<int> graph;
			graph.add_vertex(5);
			graph.add_vertex(6);
			graph.add_edge(5, 6);
			Undirected_graph<int>::edges_citerator beg = graph.edges_cbegin();
			graph.remove_edge_by_iterator(beg);
			Assert::IsFalse(graph.edge_exists(5, 6));
		}
	};
}
