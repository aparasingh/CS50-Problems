-- Movies that start both Bradley Cooper and Jennifer Lawrence
SELECT m1.title
FROM
(SELECT m.title, m.id
FROM people p JOIN stars s ON (p.id = s.person_id) JOIN movies m ON (m.id = s.movie_id)
WHERE p.name = "Bradley Cooper") m1 JOIN (SELECT m.id
FROM people p JOIN stars s ON (p.id = s.person_id) JOIN movies m ON (m.id = s.movie_id)
WHERE p.name = "Jennifer Lawrence") m2 ON (m1.id = m2.id);
