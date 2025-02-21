-- Top 5 longest songs
SELECT name
FROM songs
ORDER BY duration_ms DESC
limit 5;
