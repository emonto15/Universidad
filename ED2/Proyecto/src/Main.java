/**
 * Created by Edwin Montoya and Daniel Hoyos on 12/05/2016.
 */
package AgenteViajero;

import java.awt.Desktop;
import java.net.*;
import java.io.IOException;
import java.util.*;
import java.io.*;
/**
 * This is the main class where everything begins
 */
public class Main {
    static ArrayList<Graph.Vertex> vertexes; // vertex list from loadData.
    static ArrayList<Graph.Edge>  edges; // edges list from loadData.
    static Graph.Vertex[] vertexes1; //  vertex array for graph constructor.
    static Graph.Edge[] edges1; // edges array for graph constructor.
    static ArrayList<String> coordenateArrayList = new ArrayList<String>(); // list of coordinates
    static String[] visitedNodesArray; //  array of the nodes to visit.
    /**
     * This method is the main of the execution
     * @param args are the params to start the execution
     */
    public static void main (String [] args){
        try {
            vertexes = new ArrayList<Graph.Vertex>();
            edges = new ArrayList<Graph.Edge>();
            loadVisitedNodes("C:\\Users\\USER\\Desktop\\semestre 3\\estructuras de datos y algoritmos 2\\AgenteViajero\\Medellin2.txt");
            visitedNodesArray= new String[coordenateArrayList.size()/2];
            loadGraphData("C:\\Users\\USER\\Desktop\\semestre 3\\estructuras de datos y algoritmos 2\\AgenteViajero\\Medellin.txt");
            vertexes1 = vertexes.toArray(new Graph.Vertex[vertexes.size()]);
            edges1 = edges.toArray(new Graph.Edge[edges.size()]);
            Graph g = new Graph(edges1,vertexes1);
            Dijkstra d = new Dijkstra(g.graph);
            String[] temp=getShortestPath(visitedNodesArray,d);
            visitedNodesArray=temp;
            String url="https://www.google.es/maps/dir/";
            for(String e:visitedNodesArray)
            {
                url=url+g.graph.get(e).x+","+g.graph.get(e).y+"/";
            }
            url=url+g.graph.get(visitedNodesArray[0]).x+","+g.graph.get(visitedNodesArray[0]).y+"/";
            openBrowser(url);

        }
        catch (Exception e){
            System.out.print(e);
        }
    }

    /**
     * This method read the file that contains the map of the city and save it as a graph.
     * @param direccion is the path to the file in your local files
     * @throws FileNotFoundException When the program could not find the specific file
     * @throws IOException           When there is an error in the reading of the file
     */
    public static void loadGraphData(String direccion) throws FileNotFoundException, IOException{
        String line;
        String [] divided_line;
        BufferedReader buffered = new BufferedReader( new FileReader(direccion));
        line = buffered.readLine();
        while ((line = buffered.readLine())!=null){
            if (!line.isEmpty()) {
                divided_line = line.split(" ");
                if(divided_line.length==3) {
                    vertexes.add(new Graph.Vertex(divided_line[1], divided_line[2], divided_line[0]));
                }
                if (coordenateArrayList.contains(divided_line[2])){
                    if (coordenateArrayList.get(coordenateArrayList.indexOf(divided_line[2])+1).equals(divided_line[1])){
                        int aux = coordenateArrayList.indexOf(divided_line[2])/2;
                        visitedNodesArray[aux] = divided_line[0];
                    }
                }
            }
            else {
                break;
            }
        }
        line = buffered.readLine();
        while ((line = buffered.readLine())!=null){
            if (!line.isEmpty()) {
                divided_line = line.split(" ");
                edges.add(new Graph.Edge(divided_line[0],divided_line[1],Float.parseFloat(divided_line[2])));
            }
            else {
                break;
            }
        }
        buffered.close();
    }
    /**
     * This method display the solution on the web
     * @param url is the url where the solution will be show (Google Maps)
     */
    public static void openBrowser(String url)
    {
        if (Desktop.isDesktopSupported()) {
            Desktop desktop = Desktop.getDesktop();
            if (desktop.isSupported(Desktop.Action.BROWSE)) {
                try {
                    desktop.browse(new URI(url));
                }
                catch(IOException ioe) {
                    ioe.printStackTrace();
                }
                catch(URISyntaxException use) {
                    use.printStackTrace();
                }
            }
        }
    }
    /**
     * This method call the algorithm and calulate the shortest path
     * @param visitedNodesArray this is the array of the vertex which the algorithm will organize
     * @param d is the instantiation of the algorithm
     * @return the array of the vertex in the order to walk thru
     */
    public static String[] getShortestPath(String [] visitedNodesArray, Dijkstra d)
    {
        int i=0;
        Float weigth;
        Float lowerWeigth=0f;
        int lowerWeigthIndex=0;
        int j=0;
        int iterador=visitedNodesArray.length;
        boolean reset=false;
        while(i<visitedNodesArray.length) {
            reset=true;
            if(i!=visitedNodesArray.length-1)
            {j=i+1;}
            else
            {break;}
            d.dijkstra(visitedNodesArray[i]);
            while(j<iterador) {
                weigth = d.getPath(visitedNodesArray[j],reset);
                if(j==i+1)
                {
                    lowerWeigth=weigth;
                    lowerWeigthIndex=j;
                }
                if(reset==true)
                {
                    reset=false;
                }
                if(weigth<lowerWeigth)
                {
                    lowerWeigth=weigth;
                    lowerWeigthIndex=j;
                }

                j++;
            }
            String temp=visitedNodesArray[i+1];
            visitedNodesArray[i+1]=visitedNodesArray[lowerWeigthIndex];
            visitedNodesArray[lowerWeigthIndex]=temp;
            i++;
        }
        return visitedNodesArray;
    }
    /**
     * This method loads the arraylist of coordenates that will help to get the nodes ids that we have to reach on the path.
     * @param direccion is the direction of the visitedNodes
     */
    public static void loadVisitedNodes (String direccion) throws IOException {
        String linea;
        String[] linea_dividida;
        BufferedReader buffered = new BufferedReader(new FileReader(direccion));
        while ((linea = buffered.readLine()) != null) {
            if (!linea.isEmpty()) {
                linea_dividida = linea.replace(",","").split(" ");
                coordenateArrayList.add(linea_dividida[1]);
                coordenateArrayList.add(linea_dividida[0]);
            } else {
                break;
            }
        }
    }

}
