-- Directors of movies with rating 9.0 or over
SELECT DISTINCT p.name
FROM ratings r JOIN directors s ON (r.movie_id = s.movie_id) JOIN people p ON (p.id = s.person_id)
WHERE r.rating >= 9.0;
