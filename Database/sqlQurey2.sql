-- Task 2

-- 1a   From table actors, find the average age 
SELECT AVG(date_part('year', age("Actor"."dateOfBirth"))) AS "Average Age"
FROM public."Actor";


-- 1b   Find the number of different countries in which actors from the movie "Taxi" were born.  
SELECT DISTINCT COUNT("nameCountry") AS "Distinct Country''s for a Movie"
FROM public."Location"
LEFT JOIN public."Actor"
ON "Location"."locationID" = "Actor"."actorID"
LEFT JOIN public."Movie"
ON "Actor"."actorID" = "Movie"."movieID"
WHERE "Movie".title = 'Taxi';

-- 1c   Find the number of actors with violet eye colour 
SELECT COUNT("eyeColour")
FROM public."Actor"
WHERE "eyeColour" = 'Violet';

-- 1d   What is the number of movies in which Bobby Mattiazziwas playing
SELECT COUNT("movieID")
FROM public."Movie"
LEFT JOIN public."Actor"
ON "Movie"."movieID" = "Actor"."actorID"
WHERE "Actor"."First Name" = 'Bobby' AND "Actor"."Surname" = 'Mattiazzi';


-- 1e   Find the minimum, average, and maximum budget for each type of movie 
SELECT "Genres".genre, MIN(budget) AS "Minimum Budget", AVG(budget) AS "Average Budget", MAX(budget) AS "Maximum Budget" 
FROM public."Movie"
LEFT JOIN public."Genres"
ON "Movie"."movieID" = "Genres"."movieID"
GROUP BY "Genres".genre;


-- 1f   Find the average rating for each movie which has a director born in California or violet eye colour 
SELECT AVG(rating) AS "Average Rating"
FROM public."Movie"
LEFT JOIN public."Actor"
ON "Movie"."movieID" = "Actor"."actorID"
LEFT JOIN public."Location"
ON "Actor"."actorID" = "Location"."locationID"
WHERE "Location"."nameState" = 'California' OR "Actor"."eyeColour" = 'Violet';

-- 1g   Find all of the movies that have actors born in at least two different countries 
SELECT title, "Location"."nameCountry"
FROM public."Movie"
LEFT JOIN public."Actor" 
ON "Movie"."movieID" = "Actor"."actorID"
LEFT JOIN public."Location"
ON "Actor"."locationID" = "Location"."locationID"
GROUP BY "Location"."nameCountry", "Movie".title 
HAVING COUNT(*) >= 1;

-- 1h   Find how many awards each movie in has receved and rank the movies (display the title) by the amount of rewards 
SELECT title, COUNT("Award"."awardID") AS "Total Awards"
FROM public."Movie"
LEFT JOIN public."Award"
ON "Movie"."movieID" = "Award"."awardID"
GROUP BY "Award"."awardID", "Movie".title
ORDER BY COUNT("Award"."awardID") DESC;