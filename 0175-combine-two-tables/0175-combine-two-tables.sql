# Write your MySQL query statement below
SELECT 
p.firstName,
p.lastname,
a.city,
a.state
From Person p
left join address a
On p.personID=a.personID;
