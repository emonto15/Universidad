
/**
 * Created by Edwin Montoya and Daniel Hoyos on 11/05/2016.
 */
package AgenteViajero;
import java.util.*;
/**
 * This Class has the role to find out the path
 */
public class Dijkstra {
    public Map<String, Graph.Vertex> graph; // mapping of vertex names to Vertex objects, built from a set of Edges, and Vertexs
    /**
     * This is the constructor of the Dijkstra's Algorithm
     *
     * @param graph is the map of the city as a graph
     */
    public Dijkstra(Map<String, Graph.Vertex> graph)
    {
        this.graph=graph;
    }
    /**
     * This method start the Dijkstra's Algorithm with a starting node
     *
     * @param startName is the vertex where the algorithm starts
     */
    public  void dijkstra(String startName) {

        if (!graph.containsKey(startName)) {
            System.err.printf("Graph doesn't contain start vertex \"%s\"\n", startName);
            return;
        }
        final Graph.Vertex source = graph.get(startName);
        NavigableSet<Graph.Vertex> q = new TreeSet<>();

        // set-up vertices
        for (Graph.Vertex v : graph.values()) {
            v.previous = v == source? source : null;
            v.dist = v == source ? 0 : Float.MAX_VALUE;
            q.add(v);
        }

        dijkstra(q);
    }

    /**
     * Implementation of dijkstra's algorithm using a binary heap.
     *
     * @param q is set that contains all the vertex
     */
    private void dijkstra(final NavigableSet<Graph.Vertex> q) {
        Graph.Vertex u, v;
        while (!q.isEmpty()) {

            u = q.pollFirst(); // vertex with shortest distance (first iteration will return source)
            if (u.dist == Float.MAX_VALUE) break; // we can ignore u (and any other remaining vertices) since they are unreachable

            //look at distances to each neighbour
            for (Map.Entry<Graph.Vertex, Float> a : u.neighbours.entrySet()) {
                v = a.getKey(); //the neighbour in this iteration

                final Float alternateDist = u.dist + a.getValue();
                if (alternateDist < v.dist) { // shorter path to neighbour found
                    q.remove(v);
                    v.dist = alternateDist;
                    v.previous = u;
                    q.add(v);
                }
            }
        }
    }
    /**
     * Prints a path from the source to the specified vertex
     *
     * @param endName is the key from the map
     * @param reset   is the boolean which check if the vertex have neighbour.
     * @return is the weight of the neighbour of a vertex
     */
    public Float getPath(String endName, boolean reset) {
        if (!graph.containsKey(endName)) {
            System.err.printf("Graph doesn't contain end vertex \"%s\"\n", endName);
            return 0f;
        }
        System.out.println();
        return graph.get(endName).getWeigth(reset);

    }
}
