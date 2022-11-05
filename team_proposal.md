## Leading Question 
For our final project we are going to use the Open Flights Data Set from 2014, and work on finding the best path between 2 locations. We aim to find the lowest number of transits (number of different airports travelled) a passenger has to go through while travelling from Location A to Location B. Our code implementation will hopefully be similar to a general search tool, but not exactly the same. If we have 2 or more routes available at a tie, we shall just display all of the available routes. 

We plan to use the BFS Traversal (So that we are able to terminate our code as soon as we get to a longer path, after looking for all the short paths) and the Dijkstra's Algorithm for our code. Our idea is to set up the airports as the nodes of our graph, and then use this alogrithm, to find the shortest connection between two locations. 

## Dataset Acquisition

### Data Format
In our final project we are using the Open Flights Data Set from 2014, that is already provided to us. From that, we look to just use the Airports data set, and the routes data set, which will allow us to reach the goal we are looking to achieve. The source of these data sets are DAFIF(October 2006 Cycle), "OurAirports" & "Airline Route Mapper". The Airports dataset is about 1MB in size while the Routes dataset is about 2MB in size. We hope to use all the data in these two datasets, so that we are able to find a valid route between any 2 locations. We shall just look at IATA code for the airports, and the Source Airport, the Destination Airport for the routes dataset.

### Data Correction
For our input data, we look to parse our .csv file using the getline() function, and "/n" as our delimiter as we move on to the next line. If we have any errors in the IATA, we shall be eliminating that airport from our code, and the respective routes involved. If there are any errors or null values in the source/destination airport, we will ignore the particular route to provide an error - free output. 

### Data Storage
We look to store the date, in a 2D vector, Graph, and a 1D vector which will be used to return the output. We look to implement our output in O(N^2) and the Dijkstra's algorithm runs in O(E+Nlog(N)), where E is the the number edges, and N is the number of airports. 

## Algorithm 

### Function Inputs
We expect to parse our .csv file into 2D vectors first and then convert it to the relevant graphs, which we shall use for our project. The airports, will be the nodes of the graphs, and the routes between two airports will be the edges of the graph. 

### Function Outputs
The expected output for our algorithm is basically to return all the shortest available paths between two input locations. We look to store the data we will be returning as 1D vector. 

### Function Efficiency
We look to store the date, in a 2D vector, Graph, and a 1D vector which will be used to return the output. We look to implement our output in O(N^2) and the Dijkstra's algorithm runs in O(E+Nlog(N)), where E is the the number edges, and N is the number of airports. 


## Timeline
By the Mid-Project Checkin, we look to have parsed all our data into the expected data types, and hopefully have the edges setup for our graph too. Post Thanksgiving we shall work on to find out the shortest path, and then traverse the graph, to find all the data that we look to display as our output. 
