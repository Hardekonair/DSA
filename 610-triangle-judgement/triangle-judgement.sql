# Write your MySQL query statement below
SELECT x,y,z,
case when x+y>z and x+z>y and y+z>x then 'Yes' else 'No' END AS triangle
from triangle;