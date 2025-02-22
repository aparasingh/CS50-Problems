-- Stars in movie where Kevin Bacon also stars

SELECT DISTINCT p.name
FROM people p JOIN stars s ON (p.id = s.person_id) JOIN movies m ON (m.id = s.movie_id)
WHERE m.ID IN (SELECT DISTINCT m.id
FROM people p JOIN stars s ON (p.id = s.person_id) JOIN movies m ON (m.id = s.movie_id)
WHERE p.name = "Kevin Bacon" and p.birth=1958) and p.name <> "Kevin Bacon";
