-- Average Energy of songs by Drake
SELECT AVG(energy) as avg_energy
FROM songs S JOIN artists a on (s.artist_id = a.id)
WHERE a.name = "Drake";
