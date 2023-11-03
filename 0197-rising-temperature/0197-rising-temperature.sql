select a.Id from

Weather as a , Weather as b

where DATEDIFF(a.recordDate,b.recordDate) = 1 and b.temperature < a.temperature;
