# Write your MySQL query statement below
select * from users
where regexp_LIKE(mail, '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$','c')      -- '.' means any char in regex, '$' MARK END OF STRING LIKE THERE SHOULD BE NO CHAR AFTER IT 