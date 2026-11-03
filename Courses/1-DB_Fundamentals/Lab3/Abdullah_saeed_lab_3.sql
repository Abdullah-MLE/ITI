-- Q1
-- Display the department ID, department name, manager ID, and manager name.
-- -- -- -- -- -- -- -- --
SELECT d.DeptID, d.DeptName, d.MgrEmpID, e.FName
FROM Department d JOIN Employee e
ON e.EmpID = d.MgrEmpID;

--  Q2
-- Display the name of each department together with the names of the flights it controls.
-- -- -- -- -- -- -- -- --
select d.DeptName, f.FlightName
from Department d join Flight f
on f.DeptID = d.DeptID;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q3
-- Display the full data of every CrewFamilyMember record together with the name of the
-- employee they belong to.
-- -- -- -- -- -- -- -- --
SELECT *
from CrewFamilyMember join Employee
ON Employee.EmpID = CrewFamilyMember.EmpID;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q4
-- Using the UNION operator, display:
-- (a) the name and gender of family members who are female and belong to a female employee, and
-- (b) the name and gender of family members who are male   and belong to a male   employee.
-- -- -- -- -- -- -- -- --
select cfm.MemberName, cfm.Sex
from CrewFamilyMember cfm join Employee e
ON cfm.EmpID = e.EmpID
where e.Sex = "F" and cfm.Sex = "F"
UNION
select cfm.MemberName, cfm.Sex
from CrewFamilyMember cfm join Employee e
ON cfm.EmpID = e.EmpID
where e.Sex = "M" and cfm.Sex = "M";

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q5
-- Display the ID, name, and destination of the flights that fly to Cairo or Hurghada.
-- -- -- -- -- -- -- -- --
select f.FlightNo, f.FlightName, f.Destination
from Flight f
where f.Destination = "Cairo" or f.Destination = "Hurghada";

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q6
-- Display the full data of the flights whose name starts with the letter "S".
-- -- -- -- -- -- -- -- --
select *
from Flight
where FlightName like "S%";

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q7
-- Display all employees in department 30 whose monthly salary is between 1,200 and 1,800 EGP.
-- -- -- -- -- -- -- -- --
select *
from Employee
where Salary between 1200 and 1800 and DeptID = 30;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q8
-- Retrieve the names of all employees in department 10 who work 10 or more hours per week on
-- the "Red Sea Link" flight.
-- -- -- -- -- -- -- -- --
select e.FName, e.LName
from Employee e
join  FlightAssignment fa on e.EmpID = fa.EmpID 
join Flight f on f.FlightNo = fa.FlightNo
where e.DeptID = 10 and fa.HoursPerWeek < 10 and f.FlightName = "Red Sea Link";

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
-- Q9
-- Find the names of the employees who are
-- directly supervised by Mostafa Hassan (EmpID = 100305)
-- -- -- -- -- -- -- -- --
select e.FName, e.LName
from Employee e
join Employee se on e.EmpID = se.SuperEmpID
where se.EmpID = 100305;

-- -------------------------------------------------------------------------------------------------------
-- Q10
-- For each flight, list the flight name and the
-- total hours per week (summed across all assigned employees).
select f.FlightName, sum(fa.HoursPerWeek)
from Flight f
join FlightAssignment fa on f.FlightNo = fa.FlightNo
group by f.FlightNo;

-- -------------------------------------------------------------------------------------------------------
-- Q11
-- Retrieve the names of all employees and the
-- names of the flights they are assigned to, sorted by flight name.
select e.FName, e.LName, f.FlightName
from Employee e
join FlightAssignment fa on e.empid = fa.empid
join Flight f on fa.FlightNo = f.FlightNo
group by e.empid;

-- -------------------------------------------------------------------------------------------------------
-- Q12
-- Display the data of the department-- that has
-- the smallest manager EmpID among all departments.
select DeptID, DeptName, MgrEmpID, MgrStartDate
from Department
where MgrEmpID = (
	select min(MgrEmpID)
	from Department
	);

-- -------------------------------------------------------------------------------------------------------
-- Q13
-- For each department, retrieve the department name and
-- the maximum, minimum, and average salary of its employees.
select d.DeptName, max(e.salary), min(e.salary), avg(e.salary)
from Department d
join Employee e on e.DeptID = d.DeptID
group by d.DeptID;

-- -------------------------------------------------------------------------------------------------------
-- Q14
-- List the last names of all managers who have no CrewFamilyMember records.
select e.LName, cfm.FamilyMemberID
from Employee e
join Department d on e.EmpID = d.MgrEmpID
left join CrewFamilyMember cfm on e.EmpID = cfm.EmpID
where e.EmpID = d.MgrEmpID and cfm.FamilyMemberID is NULL;

-- -------------------------------------------------------------------------------------------------------
-- Q15
-- For each department,
-- if its average salary is less than the average salary of all employees,
-- display its department ID, name, and number of employees.
select d.DeptID, d.DeptName, count(e.empid)
from Department d 
join Employee e on e.DeptID = d.DeptID
group by d.deptid
having avg(e.salary) > (select avg(salary) from Employee);

-- -------------------------------------------------------------------------------------------------------
-- Q16
-- Retrieve a list of employees and the flights they are assigned to,
-- ordered by department,
-- and within each department, ordered alphabetically by last name then first name.
select e.EmpID, e.FName, e.LName, fa.FlightNo, d.DeptName 
from Employee e 
join FlightAssignment fa on e.EmpID = fa.EmpID
join Department d on e.DeptID = d.DeptID
order by d.DeptName, e.LName, e.FName;

-- -------------------------------------------------------------------------------------------------------
-- Q17
-- For each flight destined for Aswan,
-- find the flight number, the controlling department name, the
-- department manager’s last name, address, and birth date.
select f.FlightNo, d.DeptName , e.LName, e.Address, e.BDate 
from Flight f
join Department d on f.DeptID = d.DeptID
join Employee e on d.MgrEmpID = e.empid
where f.Destination = "Aswan";

-- -------------------------------------------------------------------------------------------------------
-- -Part B- --
SELECT d.DeptName, f.Origin, COUNT(f.FlightNo) AS FlightCount
FROM Department AS d
JOIN Flight AS f ON d.DeptID = f.DeptID
GROUP BY d.DeptName, f.Origin;

-- --------------------------------------------------------------------
SELECT fa.EmpID, fa.FlightNo, f.DeptID
FROM FlightAssignment fa
JOIN Employee e ON fa.EmpID = e.EmpID
JOIN Flight f ON fa.FlightNo = f.FlightNo;

-- --------------------------------------------------------------------
-- -Part c- --
-- List every department together with the number of flights it controls,
-- including departments that currently control no flights.
SELECT d.DeptName, COUNT(f.FlightNo) AS FlightCount
FROM Department d
left JOIN Flight f ON d.DeptID = f.DeptID
GROUP BY d.DeptName;

-- --------------------------------------------------------------------
-- Show the average monthly salary for each department.
-- Any employee whose salary has not yet been finalized
-- (stored as NULL, such as the friend inserted in Task 2)
-- should be treated as earning 0
-- EGP, not excluded from the calculation.

SELECT DeptID, AVG(COALESCE(Salary,0)) AS AvgSalary
FROM Employee
GROUP BY DeptID;

-- -- -- -- -- -- -- -- --
select * from Employee;
select * from Department;
select * from CrewFamilyMember;
select * from Flight;
select * from FlightAssignment;
