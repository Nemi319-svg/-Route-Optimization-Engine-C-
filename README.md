# Route Optimization Engine

A high-performance C++ application designed to find the most efficient delivery routes using advanced Graph Theory and Data Structures.

## 🚀 Overview
This project implements **Dijkstra’s Shortest Path Algorithm** to optimize logistics and delivery networks. It calculates the minimum "cost" (time or distance) from a central delivery hub to multiple destination nodes.

## 🛠️ Tech Stack
* **Language:** C++
* **Algorithm:** Dijkstra’s Algorithm
* **Data Structures:** * **Adjacency List:** For memory-efficient graph representation.
    * **Min-Priority Queue:** To optimize vertex selection and improve time complexity to O((V+E) log V).
    * **STL Vectors & Pairs:** For robust data management.

## 📈 Key Features
* **Memory Efficiency:** Uses adjacency lists instead of matrices to handle sparse networks effectively.
* **Optimization:** Designed with a focus on reducing time and space complexity, ensuring scalability for larger networks.
* **Real-world Logic:** Simulates a logistics environment where nodes represent delivery stops and edges represent road connectivity/travel time.

## 📋 How It Works
1. **Graph Construction:** The delivery network is modeled as a weighted undirected graph.
2. **Initial State:** All distances are set to infinity except the source node (Hub), which is 0.
3. **Processing:** The engine iteratively visits the nearest unvisited node and updates the distances of its neighbors.
4. **Output:** Provides a clear list of the shortest travel times from the source to every other location in the network.

## 💻 How to Run
1. Ensure you have a C++ compiler (like G++) installed.
2. Compile the code:
   ```bash
   g++ route_optimizer.cpp -o optimizer
