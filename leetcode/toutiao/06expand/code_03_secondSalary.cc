//176. 第二高的薪水
# Write your MySQL query statement below
select IFNULL 
((select distinct Salary from Employee order by Salary DESC Limit 1 offset 1),NULL)
as SecondHighestSalary;

#select (select distinct Salary from Employee order by Salary DESC limit 1 offset 1) as SecondHighestSalary
