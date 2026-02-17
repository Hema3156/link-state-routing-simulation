# Link State Routing Simulation

## Overview
This project is a C-based simulation of the Link State Routing protocol, focusing on shortest-path computation and routing table updates.
It demonstrates how routers compute shortest paths to other routers using
Dijkstra’s algorithm.
The simulation allows dynamic updates of link costs and recomputation of routing
tables to reflect network changes.
## Features
- Creation of network topology using adjacency matrix
- Initialization of routing tables
- Shortest path computation using Dijkstra’s algorithm
- Dynamic link cost updates
- Menu-driven console interface
## Data Structures Used
- Adjacency Matrix (Graph representation)
- Arrays for distance and visited routers
## Algorithm Used
- Dijkstra’s Algorithm (Link State Routing)
## How to Run
```bash
gcc link_state_routing.c -o routing
./routing

## What I Learned
- How Link State Routing works internally
- Applying Dijkstra’s algorithm to real network problems
- Using graphs and adjacency matrices in C
- Handling dynamic updates in routing tables
```
