# Write your MySQL query statement below
Select max(salary) as SecondHighestSalary from Employee 
where salary < (Select max(Salary) from Employee);