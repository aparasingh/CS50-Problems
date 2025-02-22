-- Average rating of moview in 2012

-- Average rating of movies released in 2012
SELECT AVG(rating) as avg_rating
FROM movies m join ratings r ON (m.id = r.movie_id)
WHERE m.year = 2012;
