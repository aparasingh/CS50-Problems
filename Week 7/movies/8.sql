-- Cast of Toy Story
SELECT p.name
FROM movies m join stars s ON (m.id = s.movie_id) JOIN people p ON (p.id = s.person_id)
WHERE m.title = "Toy Story";
