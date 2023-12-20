# Project_1_EECE7205_Vaibhav_Kejriwal
Project 1 for EECE7205 - Fundamentals of Computer Engineering - Fall 2023


#Problem Description:
You are given an input array 𝐴[1, ... , 𝑁]. A grouping of the array 𝐴 is described by an array 𝐺[1, ... , 𝑀], where the array 𝐴 is partitioned into 𝑀 groups, the 1st group consists of the first 𝐺[1] elements of array 𝐴, the 2nd group consists of the next 𝐺[2] elements, and so forth. Define array 𝐵[1, ... , 𝑀] such that 𝐵[𝑗] is the summation of the elements in the 𝑗-th group of array 𝐴. Use a dynamic programming algorithm to find a grouping of array 𝐴 with 𝑀 groups such that we maximize the minimum element of array 𝐵.
Max-min-grouping(𝐴, 𝑁, 𝑀) {
return 𝐺[1, ... , 𝑀] }
Hint:
• The optimal subproblem property: suppose the optimal solution to Max-min-grouping(𝐴, 𝑁, 𝑀) is 𝐺[1,...,𝑀]=[𝑛1,𝑛2,...,𝑛𝑀−1,𝑛𝑀]. Then 𝐺[1,...,𝑀−1] is the optimal solution to the subproblem Max-min-grouping(𝐴, 𝑁 − 𝑛𝑀 , 𝑀 − 1).

#Submission Instructions
This is an individual project, and each student must implement the codes independently.
In your first submission attempt on Canvas, upload a zip file including your source codes and executable file.
In your second submission attempt, upload a pdf file as project report.
The project report should have the following parts: (1) Pseudo codes of your dynamic programming algorithm. (2) Analysis of the running time asymptotically. (3) Grouping results of several input examples including the one that A={3,9,7,8,2,6,5,10,1,7,6,4} and M=3. (4) Source codes.

