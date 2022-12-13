Floyd-Warshall:

Output: The shortest distance between two airports 

Correctness and Implementation: Implementation was using a N * N matrix, and continuosly updating the shortest between two airports, if there is no direct path. We find the output of the shortest distance between airports. Implementation of the code is around 3 hours, as it has a run - time of O(N^3) with N being close to 8000. Tests were conducted, to check if it gave accurate results and distances between the two airports having a direct route, and also with two airports who do not have a direct route. 


A Star:

Output: A vector of strings containing the names of the airports one would have to visit to travel the shortest path

Correctness: We went through our dataset and selected two airports and figured out what the shortest flight path was between the two. When we then put the aiports into our main.cpp file to test the functionality, it returned the correct route which we had intended. If there are multiple paths, and a direct route is available, the code correctly returns the direct path from one airport to the other. 


BFS:

Output: 

Correctness:

Answer to leading question: Our leading question was to find the shortest/best path for a passenger to travel from one location to another. The code that we have managed to write implements this, and it also follows the time complexity that we had proposed in our proposal. The Floyd Warshall gives us the shortest distance between any two airports that has a path, as the A* star Algortihm shows us the path that we take to reach our destination. The A* star algorithm, has a shorter run-time, so our code has been compiled in a way that the other functions and algorithms, will be taken into use only if and when needed. 
