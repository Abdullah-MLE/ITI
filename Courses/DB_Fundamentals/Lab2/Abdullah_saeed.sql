-- Q1
-- Insert your own personal data into the Employee table as a new employee in
-- department 30 (Maintenance). Use EmpID = 200100, SuperEmpID = 100714
-- (Sherif Naguib).
-- -- -- -- -- -- -- -- --
INSERT INTO Employee (EmpID, FName, LName, BDate, Address, Sex, Salary, SuperEmpID, DeptID)
VALUES (200100, "Abdullah", "saeed", "2003-11-24", "57 obore city cairo egypt", "M", "99999999", 100714, 30);

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q2
-- Insert a classmate or friend as a new employee in department 30, using EmpID =
-- 200200, but do not enter any value for Salary or SuperEmpID.
-- -- -- -- -- -- -- -- --
INSERT INTO Employee (EmpID, FName, LName, BDate, Address, Sex, DeptID)
VALUES (200200, "Mohamed", "Salah", "2004-10-13", "new cairo city egypt", "M", 30);

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q3
-- Insert a new department called "Ground Handling" with DeptID = 40, using the
-- employee with EmpID = 100305 (Mostafa Hassan) as its manager, with a
-- MgrStartDate of 1/11/2026.
-- -- -- -- -- -- -- -- --
INSERT INTO Department (DeptID, DeptName, MgrEmpID, MgrStartDate)
VALUES (40, "Ground Handling", 100305, "2026-11-01");

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q4
-- Mostafa Hassan (EmpID = 100305) has moved to become the manager of the new
-- Ground Handling department (DeptID = 40). Update his record in the Department
-- table for DeptID = 10 so that Dept 10 is managed instead by the employee you
-- inserted in Task 1 (EmpID = 200100).
-- -- -- -- -- -- -- -- --
UPDATE Department
SET MgrEmpID = 200100
WHERE MgrEmpID = 100305;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q5
-- Update your own record (EmpID = 200100 from Task 1) to reflect that you are now
-- the manager of department 10, and update the Department table's MgrStartDate
-- accordingly.
-- -- -- -- -- -- -- -- --
-- 1-update my instent to reflect that I'am working in dep 10
UPDATE Employee
SET DeptID = 10
WHERE EmpID = 200100;
-- 2-update my frinds to change there super Emp ID
UPDATE Employee
SET SuperEmpID = 200100
WHERE DeptID = 10;
-- 3-make the super emp id for me none cuz iam the manger
UPDATE Employee
SET SuperEmpID = NULL
WHERE EmpID = 200100;
-- checking... 
select * from Employee where DeptID = 10;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q6
-- Update your friend's record (EmpID = 200200 from Task 2) so that they are now
-- supervised by you (SuperEmpID = 200100).
-- -- -- -- -- -- -- -- --
UPDATE Employee
SET SuperEmpID = 200100
WHERE EmpID = 200200;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q7
-- The company has ended its contract with Mostafa Hassan (EmpID = 100305).
-- Delete his data from the database.
-- Hint: before deleting, check whether Mostafa Hassan has any CrewFamilyMember
-- records, whether he is listed as a department manager anywhere, whether he
-- supervises any other employees, and whether he has any FlightAssignment records.
-- Decide how each dependent record should be handled (reassigned or removed)
-- before performing the delete
-- -- -- -- -- -- -- -- --
-- 1- check whether Mostafa Hassan has any CrewFamilyMember records
select * from CrewFamilyMember
where EmpID = 100305;
-- 1.2- delet it
DELETE FROM CrewFamilyMember WHERE EmpID = 100305;

-- 2- check if he is listed as a department manager anywhere
select * from Department
where MgrEmpID = 100305;
-- he IS NOT

-- 3- check if he supervises any other employees
select * from Employee
where SuperEmpID = 100305;
-- he IS NOT

-- 4- check if he has any FlightAssignment records
select * from FlightAssignment
where EmpID = 10030UPDATE Employee
SET salary = salary + salary * 15/100
WHERE EmpID = 200100;5;
-- 4.1- reassien it to me ^^
UPDATE FlightAssignment
SET EmpID = 200100
WHERE EmpID = 100305;

-- 5- delete the employee
DELETE FROM Employee WHERE EmpID = 100305;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q8
-- Your salary has been upgraded by 15 percent of its previous value. Update your
-- own Employee record (EmpID = 200100) to reflect the new salary.
-- -- -- -- -- -- -- -- --
UPDATE Employee
SET Salary = Salary + Salary * 15/100
WHERE EmpID = 200100;

-- -------------------------------------------------------------------------------------------------------
-- Q9
-- Display all employees’ data
select * from Employee;

-- Q10
-- Display each employee’s first name, last name, salary, and department ID.
select FName, LName, Salary, DeptID from Employee;

-- Q11
-- Display all flight names, their origin, destination, and the department that controls each flight.
select FlightName, Origin, Destination, DeptID from Flight;

-- Q12
-- The company pays an annual bonus equal to 8 percent of an employee’s annual
-- salary. Display each employee’s full name and their annual bonus in a column
-- aliased ANNUAL_BONUS. 
select FName, LName, salary*12*8/100 as annual_bouns from Employee;

-- 13
-- Display the ID and name of employees who earn more than 1,500 EGP monthly.
select empid, fname from Employee
where salary > 1500;

-- 14
-- Display the ID and name of employees who earn more than 18,000 EGP annually.
select empid, fname from Employee
where salary > 15000;

-- 15
-- Display the names and salaries of the female employees.
select FName, salary from Employee where sex = "f";


-- 16
-- Display the department ID and name of the department managed by the employee
-- with EmpID = 100714.
select DeptID, DeptName from Department
where MgrEmpID = 100714;


-- 17
-- Display the ID, name, and destination of the flights controlled by department
select FlightNo, FlightName, Destination from Flight;


-- C-1
SELECT FlightName, Origin
FROM Flight
WHERE Destination = 'Aswan'; 

-- C-2
SELECT FName, LName, Address, Salary
FROM Employee
WHERE Salary > 2000; 

-- D
-- 1. List all departments whose manager start date falls within 2016. MgrStartDate is stored as a
-- DATETIME column, even though the sample data only contains pure dates.
SELECT DeptName, MgrStartDate
FROM Department
WHERE MgrStartDate like '2016%';

-- -- -- -- -- -- -- -- --
select * from Employee;
select * from Department;
select * from CrewFamilyMember;
select * from Flight;
select * from FlightAssignment;



