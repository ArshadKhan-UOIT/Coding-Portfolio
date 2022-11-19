-- Task 1 

-- 1a   list all directors who were born in the USA
SELECT *
FROM public."Director" 
Left JOIN public."Location"
ON "Director"."locationID" = "Location"."locationID"
WHERE "Location"."nameCountry" = 'USA';

-- 1b   list all of the movies what were directed by Claudell Papen
SELECT "Movie".title
FROM public."Director" 
Left JOIN public."Movie"
ON "Director"."directorID" = "Movie"."movieID"
WHERE "Director"."First Name" = 'Claudell' AND "Director"."Surname" = 'Papen';

-- 1c List all actors who played in movies for which cost of production was more than $1M, compute cost in CAD, JPY, RUB, EUR, & CHF
SELECT "actorID", "First Name", "Surname", "Movie"."budget" * 1.3 AS "CAD", "Movie"."budget" * 104.31 AS "JPY", "Movie"."budget" * 75.61 AS "RUB", "Movie"."budget" * 0.84 AS "EUR", "Movie"."budget" * 0.91 AS "CHF"    
FROM public."Actor"
LEFT JOIN public."Movie"
ON "Actor"."actorID" = "Movie"."movieID"
WHERE "Movie"."budget" > 1000000;

-- 1d   find all directors whose sirname start with the letter "A" or "D"
SELECT *
FROM public."Director"
WHERE "Director"."Surname" LIKE 'A%' OR "Director"."Surname" LIKE 'D%';

-- 1e   Find all of the comedy movies in which there is a playing actor who is less than 60 years of age 
SELECT title AS "Movie Title", "Genres".genre AS "Genre" 
FROM public."Movie"
LEFT JOIN public."Genres"
ON "Movie"."movieID" = "Genres"."movieID"
LEFT JOIN public."Actor"
ON "Movie"."movieID" = "Actor"."actorID"
WHERE "Genres".genre LIKE 'Comedy%' AND 60 > date_part('year', age("Actor"."dateOfBirth"));

-- 1f   Find all the pairs of actors who hae blue eye colour, produce pairs in alphabetic order 
SELECT a1."Surname", a2."Surname"
FROM public."Actor" a1, public."Actor" a2
WHERE a1."eyeColour" = 'Violet' AND  a2."eyeColour" = 'Violet' AND a1."First Name" != a2."First Name" AND a1."Surname" != a2."Surname"
GROUP BY a1."Surname", a2."Surname";

