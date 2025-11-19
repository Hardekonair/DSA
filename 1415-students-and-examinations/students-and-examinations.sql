# Write your MySQL query statement below
select st.student_id,st.student_name,sb.subject_name,count(ex.student_id) as attended_exams
from students as st
cross join subjects sb
left join examinations as ex
on st.student_id=ex.student_id and sb.subject_name=ex.subject_name
group by sb.subject_name, st.student_name, ex.student_id
order by st.student_id, sb.subject_name;