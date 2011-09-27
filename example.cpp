#include <iostream>
#include <vector>

#include <boost/tuple/tuple.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/boyer_myrvold_planar_test.hpp>

#include "create_dual_graph.hpp"

using namespace boost;

int main(int argc, char** argv)
{

  typedef adjacency_list
    < vecS,
     vecS,
     undirectedS,
     property<vertex_index_t, int>,
     property<edge_index_t, int>
    >
  graph;

  // Create the graph - two triangles that share an edge
  graph g(4);
  add_edge(0,1,g);
  add_edge(1,2,g);
  add_edge(2,0,g);
  add_edge(2,3,g);
  add_edge(3,0,g);

  // Create an empty graph to hold the dual
  graph dual_g;

  //Initialize the interior edge index
  property_map<graph, edge_index_t>::type e_index = get(edge_index, g);
  graph_traits<graph>::edges_size_type edge_count = 0;
  graph_traits<graph>::edge_iterator ei, ei_end;
  for(tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
  {
    put(e_index, *ei, edge_count++);
  }

  // Compute the planar embedding - we know the input graph is planar,
  // so we're ignoring the return value of the test
  typedef std::vector< graph_traits<graph>::edge_descriptor > vec_t;
  std::vector<vec_t> embedding(num_vertices(g));
  boyer_myrvold_planarity_test(boyer_myrvold_params::graph = g,
                               boyer_myrvold_params::embedding = &embedding[0]
                               );

  create_dual_graph(g, dual_g, &embedding[0]);

  std::cout << "Output graph looks like:" << std::endl;
  std::cout << "vertices: " << std::endl;
  graph_traits<graph>::vertex_iterator vi, vi_end;
  for(tie(vi, vi_end) = vertices(dual_g); vi != vi_end; ++vi)
  {
    std::cout << *vi << std::endl;
  }
  std::cout << "edges: " << std::endl;
  for(tie(ei, ei_end) = edges(dual_g); ei != ei_end; ++ei)
  {
    std::cout << *ei << std::endl;
  }

  return 0;
}
