-- All 2010 movies in descending order of rating
SELECT m.title, r.rating
FROM movies m join ratings r ON (m.id = r.movie_id)
WHERE m.year = 2010
ORDER BY r.rating DESC, m.title ASC;
