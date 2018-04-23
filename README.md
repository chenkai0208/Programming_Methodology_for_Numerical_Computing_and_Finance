# Programming-Methodology-for-Numerical-Computing-and-Finance
This is a design oriented course that meets in a computer lab/classroom for maximum emphasis on hands-on programming. Lectures will be reinforced with small programming examples during the lecture, followed by homeworks and lab exercises that will focus on numerical computing and computational financial applications. 

This project establishes an account system, including stock account and bank account. Both accounts are connected with each other using a total portfolio balance value. This project can realize every function mentioned in the guideline. One thing that needs to be mentioned at the very beginning is that to draw the portfolio changing graph, this project uses OpenGL package, since it is faster and more compatible with account management program system.

In terms of stock account, the doubly linked list structure is programmed without using standard library for the purpose of practice. Class definition is in “StockAccount.h” and corresponding class functions are in “StockAccount.cpp”. The bank account is much simpler, only managed by BankAccout class. The functions and members of BankAccount class are all included in “BankAccount.h”.

The original stock information is obtained from “Result_1.txt” and “Result_2.txt”. This project saves them into two structures defined in main program for the convenience of reuse. Every time when a stock information is needed, the program will select from those two structures randomly to create randomness for the total portfolio value.

In order to keep track on current stock position, bank balance and account history, several text files are created to save the data.
1.	“bank_account.txt”: save the current cash balance in bank account so that this information can be retrieved when reopen the program.
2.	“stock_account.txt”: save the current stock positions in stock account. Read them into stock account linked list every time reopen the program.
3.	“bank_transaction_history.txt”: save the transaction history for bank account.
4.	“stock_transaction_history.txt”: save the transaction history for stock account.
5.	“portfolio_history.txt”: save the changes of total portfolio value for the convenience of drawing portfolio graph.
