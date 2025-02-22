-- People starred in a movie in 2004
SELECT DISTINCT p.name
FROM movies m join stars s ON (m.id = s.movie_id) JOIN people p ON (p.id = s.person_id)
WHERE m.year = 2004
ORDER BY p.birth ASC;
