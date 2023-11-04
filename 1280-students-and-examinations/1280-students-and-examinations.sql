# Write your MySQL query statement below


WITH CrossJoinResult AS (
    SELECT * 
    FROM Students as s
    CROSS JOIN Subjects
)

select c.student_id , c.student_name, c.subject_name , count(e.student_id) as attended_exams

from CrossJoinResult as c

left join Examinations as e

on c.student_id = e.student_id and c.subject_name = e.subject_name

group by c.student_id,c.student_name,c.subject_name

order by c.student_id , c.subject_name;

# SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) AS attended_exams
# FROM Students s
# CROSS JOIN Subjects sub
# LEFT JOIN Examinations e ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
# GROUP BY s.student_id, s.student_name, sub.subject_name
# ORDER BY s.student_id, sub.subject_name;




