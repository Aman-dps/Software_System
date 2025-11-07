# Banking-Management-System

The Banking Management System aims to simulate the core functionalities of a bank, including customer account management, transactions, loan processing, and administrative oversight.
The system features secure login mechanisms and role-based access for customers, employees, managers, and administrators.
The focus is on ensuring data consistency, security, and correct handling of race conditions using file management, locking mechanisms, and process synchronization.

## Roles
### 1. Customer
        ◦ Login System (one session per user)
        ◦ View Account Balance
        ◦ Deposit Money
        ◦ Withdraw Money
        ◦ Transfer Funds
        ◦ Apply for a Loan
        ◦ Change Password
        ◦ Adding Feedback
        ◦ View Transaction History
        ◦ Logout
        ◦ Exit
### 2. Employee
        ◦ Login System (one session per user)
        ◦ Add New Customer
        ◦ Modify Customer Details
        ◦ Process Loan Applications
        ◦ Approve/Reject Loans
        ◦ View Assigned Loan Applications
        ◦ View Customer Transactions( Passbook Kind of feature)
        ◦ Change Password
        ◦ Logout
        ◦ Exit
### 3. Manager
        ◦ Login System (one session per user)
        ◦ Activate/Deactivate Customer Accounts
        ◦ Assign Loan Application Processes to Employees
        ◦ Review Customer Feedback
        ◦ Change Password
        ◦ Logout
        ◦ Exit
### 4. Administrator
        ◦ Login System (one session per user)
        ◦ Add New Bank Employee
        ◦ Modify Customer/Employee Details
        ◦ Manage User Roles
        ◦ Change Password
        ◦ Logout
        ◦ Exit

## Usage
  1. Compile Server: `gcc server.c -o server -L/lib/x86_64-linux-gnu/libcrypt.so -lcrypt -pthread`
  2. Compile Client : `gcc client.c -o client`
  3. Debug File    : To View Customer, Employee, Manager, Transaction text files.
