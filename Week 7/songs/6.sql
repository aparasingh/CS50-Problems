-- Songs by Post Malone
SELECT s.name as name
FROM songs S JOIN artists a on (s.artist_id = a.id)
WHERE a.name = "Post Malone";
