#The dual of a planar graph#

A [planar graph](http://en.wikipedia.org/wiki/Planar_graph) is a graph that can be drawn in
two dimensions without any two edges overlapping one another. There may be multiple ways of
drawing a planar graph in the plane without edge crossings; each drawing induces a cyclic
ordering of the edges around each vertex called a 
[combinatorial embedding](http://en.wikipedia.org/wiki/Graph_embedding#Combinatorial_embedding).
A planar graph can have many combinatorial embeddings and each combinatorial embedding can
yield many planar drawings of the graph.

Each combinatorial embedding partitions the plane into a set of faces induced by each region of
the plane surrounded by the graph. As a simple example, the complete graph on 3 vertices is a
planar graph that can be drawn in the plane as a triangle. This embedding defines two faces: the
region inside the triangle and the region outside the triangle. The 
[dual of a planar graph](http://en.wikipedia.org/wiki/Dual_graph) represents the relationships
between faces in a planar graph: it contains a vertex for each face in the original graph and
an edge between any two vertices representing faces that share an edge.

#Planar graphs in the Boost Graph Library#

The [Boost Graph Library](http://www.boost.org/doc/libs/release/libs/graph/doc/index.html) (BGL) 
has a suite of algorithms for determining whether a graph is planar or not and drawing planar 
graphs without edge crossings. One of the algorithms provided in the BGL is a generic traversal
of the faces of a planar graph. 

This code is a demonstration of the face traversal which generates the dual of a planar 
embedding of a graph.

#To use this code:#

Install Boost somewhere locally, say, ~/boost. Then compile the from this directory:

    g++ example.cpp -I~/boost

Run it and you should see the following output:

    Input graph looks like:
    vertices: 
    0
    1
    2
    3
    edges: 
    (0,1)
    (1,2)
    (2,0)
    (2,3)
    (3,0)
    
    Output graph looks like:
    vertices: 
    0
    1
    2
    edges: 
    (0,1)
    (0,1)
    (1,2)
    (0,2)
    (0,2)


As you can see from the output above, the input graph is a square with a diagonal, which
can easily be drawn in the plane without any edge crossings. This drawing defines three
faces: the two faces inside the square that are split by the diagonal (represented by
veritces 1 and 2 in the dual graph) and the outer face surrounding the square (represented
by the vertex 0 in the dual graph.)