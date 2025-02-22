-- Top 5 movies starring Chadwick Boseman
SELECT DISTINCT m.title
FROM people p JOIN stars s ON (p.id = s.person_id) JOIN movies m ON (m.id = s.movie_id) JOIN ratings r ON (r.movie_id = m.id)
WHERE p.name = "Chadwick Boseman"
ORDER BY r.rating DESC limit 5;
