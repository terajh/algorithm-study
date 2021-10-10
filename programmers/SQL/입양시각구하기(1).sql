-- 코드를 입력하세요
SELECT distinct(HOUR(DATETIME)) as HOUR, count(DATETIME) as count 
FROM ANIMAL_OUTS
group by HOUR(DATETIME)
having HOUR(DATETIME) >= 9 and HOUR(DATETIME) <20
order by HOUR(DATETIME);