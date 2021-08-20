# Friend Suggestion
Friend Suggestion Project using Graph Data Structure in C language

## About The Project

This is a project developed in C programming language for the Friend Suggestion/Recommendation. 

### Problem Statement
1.	You will be given a graph - (i/p to program - Adjacency Matrix) 

2.	Each node in the graph will represent a Person. Links between nodes will represent the association between persons. 

3.	The program shall suggest/recommend the friends by considering the association between nodes. - If a friend is added the corresponding link shall be added to the adjacency matrix 


### Input Screenshot
![Screen Shot][product-screenshot]


### Implementation 
1.	Enter the data of the total people (nodes) present in the graph.
2.	Enter the adjacency matrix to represent whether the link is present between the nodes.
3.	Find the count of adjacent nodes present for each node.
4.	For each adjacent find count of adjacent nodes.
5.	Add those nodes once in the stack.
6.	If the node is already present in the stack then discard the node.
7.	Then display the stack.
8.	This stack represents the friend suggested to be given to the node.
9.	If the request is accepted then change the corresponding value in the adjacency matrix.


### Features
1. Getting a list of friends of a specific person (node)
2. Recommending a friend to any specific person (node)

### Output Screenshot
![Screen Shot][product-screenshot1]


### Built With
* C Programming Language
* Graph Data Structure

<!-- CONTACT -->
## Contact
Project Link: [https://github.com/prathmeshpatil12/Friend_Suggestion](https://github.com/prathmeshpatil12/Friend_Suggestion)

<!-- MARKDOWN LINKS & IMAGES -->
[product-screenshot]: images/Input.png
[product-screenshot1]: images/Output.png
