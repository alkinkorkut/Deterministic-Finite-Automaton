# Deterministic-Finite-Automaton (DFA)

The Deterministic Finite Automaton (DFA) is implemented in this project by using C++ programming 
language. It takes the information about the DFA from a text file and simulate the DFA for given 
strings. During the simulation progress, it will first provide the path (route taken) about the visited 
states and at the end the decision is determined whether the string(s) is/are accepted or rejected. 

All logic is implemented within the main function based on the procedural programming paradigm. 
Thus, it is a procedural program that runs sequentially. The program reads the input from a text file 
(“input.txt”) to define the specifications of a deterministic finite automaton. These inputs consists of 
number of states, number of variables, number of goal states, states, goal state(s), variables 
(symbols), transition relations and string information to be detected by DFA. 

<h2>Input File Format</h2>

• Line 1 consists of number of states. </br>
• Line 2 consists of number of variables. </br>
• Line 3 consists of number of goal states. </br>
• Line 4 consists of state names. </br>
• Line 5 consists of goal state(s). </br> 
• Line 6 consists of variables. </br>
• Consecutive lines consists of transition relations. </br>
• After transition relations last consecutive lines consists of strings to be detected. </br>

<i>
Sample input file: 

2 </br>
2 </br>
1 </br>
q1 q2 </br>
q2 </br>
a b </br>
q1 a q1 </br>
q1 b q2 </br>
q2 a q2 </br>
q2 b q1 </br>
aba </br>
ababababa </br>
</i>

<h2>Output File Format</h2>

The route taken will be written in the first lines. The decision whether the string is accepted 
or rejected by the DFA will be written after. When the program executes, the output file will 
be generated if it is not in the directory of the project and the output will be available in the 
“output.txt”. Also after the execution, the output can be seen in the terminal.

<i>
Sample output file: 

q1 q2 q2 </br>
Accepted </br>
q1 q2 q2 q1 q1 q2 q2 q1 q1 </br>
Rejected </br>
</i>

<h2>Conclusion</h2>

Based on the input parameters, the program effectively simulates a finite automaton, offering insights 
into the acceptance or rejection of input strings. Additional improvements might be made for a more 
complete and adaptable solution.
