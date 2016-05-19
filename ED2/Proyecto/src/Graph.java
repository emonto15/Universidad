/**
 * Created by Edwin Montoya and Daniel Hoyos on 12/05/2016.
 */
package AgenteViajero;

import java.util.HashMap;
import java.util.Map;

class Graph {
    public final Map<String, Vertex> graph; // mapping of vertex names to Vertex objects, built from a set of Edges

    /** The Class Edge. */
    public static class Edge {
        public final String startNode, endNode; // stanting and ending nodes of the edge
        public final float dist; // edge weigth
        /**
         * This is the constructor of Edge class.
         * @param startNode the starting node of the edge.
         * @param endNode the ending node of the edge.
         * @param dist is the distance between the nodes.
         */
        public Edge(String startNode, String endNode, float dist) {
            this.startNode = startNode;
            this.endNode = endNode;
            this.dist = dist;
        }
    }

    /** The class Vertex. */
    public static class Vertex implements Comparable<Vertex> {
        public final String name; // name of the vertex
        public float weigth=0; // atribute for calculating the weights.
        public Float dist = Float.MAX_VALUE; // MAX_VALUE assumed to be infinity
        public Vertex previous = null; // previous vertex
        public final Map<Vertex, Float> neighbours = new HashMap<>(); // adyacence Map.
        public String x,y; // coordenate positions of the vertex.
        /**
         * This is the constructor of Vertex class.
         * @param x is the x pos of the vertex.
         * @param y is the y pos of the vertex.
         * @param name is the id of the vertex.
         */
        public Vertex(String x, String y,String name) {
            this.name = name;
            this.x=x;
            this.y=y;
        }
        /**
         * This method get the weight of a neighbourhood
         * @param reset is to reset the weight value
         * @return The weight of the neighbourhood
         */
        public Float getWeigth(boolean reset) {
            if(reset=true)
            {
                this.weigth=0;
            }
            if (this == this.previous) {
                return weigth;
            } else if (this.previous == null) {
            } else {
                this.previous.getWeigth(false);
                weigth=weigth+this.dist;
                return weigth;
            }
            return weigth;
        }
        /**
         * This method compares the distance between two vertexs.
         */
        public int compareTo(Vertex other) {
            return Float.compare(dist, other.dist);
        }
    }

    /**
     * Builds a graph from a set of edges and vertexs.
     * @param edges is the array of the edges
     * @param vertices is the array of the vertex
     */
    public Graph(Edge[] edges, Vertex[] vertices) {
        graph = new HashMap<>(vertices.length);
        //one pass to find all vertices
        for (Vertex e: vertices) {
            if (!graph.containsKey(e.name))
            {
                graph.put(e.name,e);
            }
        }
        //another pass to set neighbouring vertices
        for (Edge e : edges) {
            if(e.dist!=0f) {
                graph.get(e.startNode).neighbours.put(graph.get(e.endNode), e.dist);
            }
        }
    }


}
