/*
Created: 10/26/2020
Modified: 10/30/2020
Model: PostgreSQL 12
Database: PostgreSQL 12
*/

-- Create tables section -------------------------------------------------

-- Table Director

CREATE TABLE "Director"
(
  "directorID" Bigint NOT NULL,
  "locationID" Bigint,
  "departmentID" Bigint,
  "universityID" Bigint,
  "First Name" Character varying NOT NULL,
  "Surname" Character varying NOT NULL,
  "yearOfBirth" Date NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Director" ADD CONSTRAINT "PK_Director" PRIMARY KEY ("directorID")
;

-- Table Actor

CREATE TABLE "Actor"
(
  "actorID" Bigint NOT NULL,
  "locationID" Bigint,
  "departmentID" Bigint,
  "universityID" Bigint,
  "First Name" Character varying NOT NULL,
  "Surname" Character varying NOT NULL,
  "eyeColour" Character varying,
  "dateOfBirth" Date NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Actor" ADD CONSTRAINT "PK_Actor" PRIMARY KEY ("actorID")
;

-- Table Movie

CREATE TABLE "Movie"
(
  "movieID" Bigint NOT NULL,
  "title" Character varying NOT NULL,
  "releaseDate" Date,
  "rating" Double precision,
  "budget" Bigint,
  "gross" Bigint
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Movie" ADD CONSTRAINT "PK_Movie" PRIMARY KEY ("movieID")
;

-- Table MovieType

CREATE TABLE "MovieType"
(
  "genre" Character varying NOT NULL,
  "description" Character varying
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "MovieType" ADD CONSTRAINT "PK_MovieType" PRIMARY KEY ("genre")
;

-- Table University

CREATE TABLE "University"
(
  "universityID" Bigint NOT NULL,
  "name" Character varying NOT NULL,
  "description" Character varying,
  "numStudents" Bigint NOT NULL,
  "colour" Character varying
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "University" ADD CONSTRAINT "PK_University" PRIMARY KEY ("universityID")
;

-- Table Department

CREATE TABLE "Department"
(
  "departmentID" Bigint NOT NULL,
  "universityID" Bigint NOT NULL,
  "program" Character varying NOT NULL,
  "description" Character varying,
  "numStudents" Bigint NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Department" ADD CONSTRAINT "PK_Department" PRIMARY KEY ("departmentID","universityID")
;

-- Table Location

CREATE TABLE "Location"
(
  "locationID" Bigint NOT NULL,
  "nameCity" Character varying NOT NULL,
  "nameState" Character varying NOT NULL,
  "nameCountry" Character varying NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Location" ADD CONSTRAINT "PK_Location" PRIMARY KEY ("locationID")
;

-- Table DirectedBy

CREATE TABLE "DirectedBy"
(
  "directorID" Bigint NOT NULL,
  "movieID" Bigint NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "DirectedBy" ADD CONSTRAINT "PK_DirectedBy" PRIMARY KEY ("directorID","movieID")
;

-- Table ActsIn

CREATE TABLE "ActsIn"
(
  "actorID" Bigint NOT NULL,
  "movieID" Bigint NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "ActsIn" ADD CONSTRAINT "PK_ActsIn" PRIMARY KEY ("actorID","movieID")
;

-- Table Genres

CREATE TABLE "Genres"
(
  "genre" Character varying NOT NULL,
  "movieID" Bigint NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Genres" ADD CONSTRAINT "PK_Genres" PRIMARY KEY ("genre","movieID")
;

-- Table Ticket

CREATE TABLE "Ticket"
(
  "ticketID" Bigint NOT NULL,
  "cinemaID" Bigint NOT NULL,
  "movieID" Bigint NOT NULL,
  "price" Double precision NOT NULL,
  "time" Time NOT NULL,
  "duration" Double precision NOT NULL,
  "type" Character varying NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Ticket" ADD CONSTRAINT "PK_Ticket" PRIMARY KEY ("ticketID","cinemaID","movieID")
;

-- Table Cinema

CREATE TABLE "Cinema"
(
  "cinemaID" Bigint NOT NULL,
  "movieID" Bigint NOT NULL,
  "locationID" Bigint,
  "name" Character varying NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Cinema" ADD CONSTRAINT "PK_Cinema" PRIMARY KEY ("cinemaID","movieID")
;

-- Table Quote

CREATE TABLE "Quote"
(
  "quote" Character varying NOT NULL,
  "movieID" Bigint,
  "actorID" Bigint
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Quote" ADD CONSTRAINT "PK_Quote" PRIMARY KEY ("quote")
;

-- Table Award

CREATE TABLE "Award"
(
  "awardID" Bigint NOT NULL,
  "category" Character varying NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Award" ADD CONSTRAINT "PK_Award" PRIMARY KEY ("awardID","category")
;

-- Table IsAwarded

CREATE TABLE "IsAwarded"
(
  "movieID" Bigint NOT NULL,
  "awardID" Bigint NOT NULL,
  "category" Character varying NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "IsAwarded" ADD CONSTRAINT "PK_IsAwarded" PRIMARY KEY ("movieID","awardID","category")
;

-- Table MovieFestival

CREATE TABLE "MovieFestival"
(
  "festivalName" Character varying NOT NULL,
  "movieID" Bigint
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "MovieFestival" ADD CONSTRAINT "PK_MovieFestival" PRIMARY KEY ("festivalName")
;

-- Create foreign keys (relationships) section -------------------------------------------------

ALTER TABLE "Department"
  ADD CONSTRAINT "University has many Department(s)"
    FOREIGN KEY ("universityID")
    REFERENCES "University" ("universityID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "DirectedBy"
  ADD CONSTRAINT "directs many"
    FOREIGN KEY ("directorID")
    REFERENCES "Director" ("directorID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "DirectedBy"
  ADD CONSTRAINT "movie has many DirectedBy"
    FOREIGN KEY ("movieID")
    REFERENCES "Movie" ("movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "ActsIn"
  ADD CONSTRAINT "acts-in many"
    FOREIGN KEY ("actorID")
    REFERENCES "Actor" ("actorID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "ActsIn"
  ADD CONSTRAINT "movie has many ActIn"
    FOREIGN KEY ("movieID")
    REFERENCES "Movie" ("movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Director"
  ADD CONSTRAINT "location has many directors"
    FOREIGN KEY ("locationID")
    REFERENCES "Location" ("locationID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Actor"
  ADD CONSTRAINT "location has many actors"
    FOREIGN KEY ("locationID")
    REFERENCES "Location" ("locationID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Director"
  ADD CONSTRAINT "department has many directors"
    FOREIGN KEY ("departmentID", "universityID")
    REFERENCES "Department" ("departmentID", "universityID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Actor"
  ADD CONSTRAINT "departemnt has many actors"
    FOREIGN KEY ("departmentID", "universityID")
    REFERENCES "Department" ("departmentID", "universityID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Genres"
  ADD CONSTRAINT "many genres"
    FOREIGN KEY ("genre")
    REFERENCES "MovieType" ("genre")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Genres"
  ADD CONSTRAINT "movie has many genres"
    FOREIGN KEY ("movieID")
    REFERENCES "Movie" ("movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Cinema"
  ADD CONSTRAINT "location has many cinemas"
    FOREIGN KEY ("locationID")
    REFERENCES "Location" ("locationID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Ticket"
  ADD CONSTRAINT "cinema sells many tickets"
    FOREIGN KEY ("cinemaID", "movieID")
    REFERENCES "Cinema" ("cinemaID", "movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Cinema"
  ADD CONSTRAINT "cinema has many movies"
    FOREIGN KEY ("movieID")
    REFERENCES "Movie" ("movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Quote"
  ADD CONSTRAINT "movies can have quote(s)"
    FOREIGN KEY ("movieID")
    REFERENCES "Movie" ("movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Quote"
  ADD CONSTRAINT "actors can have quote(s)"
    FOREIGN KEY ("actorID")
    REFERENCES "Actor" ("actorID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "IsAwarded"
  ADD CONSTRAINT "movie has many awards"
    FOREIGN KEY ("movieID")
    REFERENCES "Movie" ("movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "IsAwarded"
  ADD CONSTRAINT "many award types"
    FOREIGN KEY ("awardID", "category")
    REFERENCES "Award" ("awardID", "category")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "MovieFestival"
  ADD CONSTRAINT "played at"
    FOREIGN KEY ("movieID")
    REFERENCES "Movie" ("movieID")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;


INSERT INTO public."Location"(
	"locationID", "nameCity", "nameState", "nameCountry")
	VALUES (1, 'New York City', 'New York', 'USA');

INSERT INTO public."Location"(
	"locationID", "nameCity", "nameState", "nameCountry")
	VALUES (2, 'Los Angeles', 'California', 'USA');

INSERT INTO public."Location"(
	"locationID", "nameCity", "nameState", "nameCountry")
	VALUES (3, 'Pittsburgh', 'Pennsylvania', 'USA');

INSERT INTO public."Location"(
	"locationID", "nameCity", "nameState", "nameCountry")
	VALUES (4, 'Reno', 'Nevada', 'USA');

INSERT INTO public."Location"(
	"locationID", "nameCity", "nameState", "nameCountry")
	VALUES (5, 'Richmond', 'Virginia', 'USA');


INSERT INTO public."University"(
	"universityID", name, description, "numStudents", colour)
	VALUES (1, 'European Academy of Arts in Warsaw', null, '5855', 'Indigo');

INSERT INTO public."University"(
	"universityID", name, description, "numStudents", colour)
	VALUES (2, 'Universidad Privada Los Andes', null, '7139', 'Puce');

INSERT INTO public."University"(
	"universityID", name, description, "numStudents", colour)
	VALUES (3, 'Institute of Finance', null, '6718', 'Violet');

INSERT INTO public."University"(
	"universityID", name, description, "numStudents", colour)
	VALUES (4, 'Acdemic Center for Law and Business', null, '2944', 'Red');

INSERT INTO public."University"(
	"universityID", name, description, "numStudents", colour)
	VALUES (5, 'Bangalore University', null, '6452', 'Yellow');

  
INSERT INTO public."Department"(
	"departmentID", "universityID", program, description, "numStudents")
	VALUES (1, 1, 'Support', null, '4128');

INSERT INTO public."Department"(
	"departmentID", "universityID", program, description, "numStudents")
	VALUES (2, 2, 'Engineering', null, '6835');

INSERT INTO public."Department"(
	"departmentID", "universityID", program, description, "numStudents")
	VALUES (3, 3, 'Engineering', null, '2673');

INSERT INTO public."Department"(
	"departmentID", "universityID", program, description, "numStudents")
	VALUES (4, 4, 'Marketing', null, '7905');

INSERT INTO public."Department"(
	"departmentID", "universityID", program, description, "numStudents")
	VALUES (5, 5, 'Support', null, '7085');


INSERT INTO public."Actor"(
	"actorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "eyeColour", "dateOfBirth")
	VALUES (1, 1, 1, 1, 'Bobby', 'Mattiazzi', 'Violet', '1978-03-18');

INSERT INTO public."Actor"(
	"actorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "eyeColour", "dateOfBirth")
	VALUES (2, 2, 2, 2, 'Jan', 'Bushnell', 'Aquamarine', '1970-06-27');

INSERT INTO public."Actor"(
	"actorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "eyeColour", "dateOfBirth")
	VALUES (3, 3, 3, 3, 'Gannon', 'Izakov', 'Violet', '1978-12-27');

INSERT INTO public."Actor"(
	"actorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "eyeColour", "dateOfBirth")
	VALUES (4, 4, 4, 4, 'Farris', 'Levis', 'Orange', '1986-12-01');

INSERT INTO public."Actor"(
	"actorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "eyeColour", "dateOfBirth")
	VALUES (5, 5, 5, 5, 'Keelia', 'Maciejewski', 'Turquoise', '1967-08-03');



INSERT INTO public."Award"(
	"awardID", category)
	VALUES (1, 'female actor');

INSERT INTO public."Award"(
	"awardID", category)
	VALUES (2, 'actor');

INSERT INTO public."Award"(
	"awardID", category)
	VALUES (3, 'director');

INSERT INTO public."Award"(
	"awardID", category)
	VALUES (4, 'movie');

INSERT INTO public."Award"(
	"awardID", category)
	VALUES (5, 'best music');


INSERT INTO public."Movie"(
	"movieID", title, "releaseDate", rating, budget, gross)
	VALUES (1, 'Taxi', '2020-08-01', '7.7', '27043046', '63432614');

INSERT INTO public."Movie"(
	"movieID", title, "releaseDate", rating, budget, gross)
	VALUES (2, 'Clownhouse', '2019-12-30', '7.7', '10816091', '34312358');

INSERT INTO public."Movie"(
	"movieID", title, "releaseDate", rating, budget, gross)
	VALUES (3, 'Laila', '2020-04-26', '7.7','31436651', '30930526');

INSERT INTO public."Movie"(
	"movieID", title, "releaseDate", rating, budget, gross)
	VALUES (4, 'Average Little Man, An (Un borghese piccolo piccolo)', '2020-09-20', '7.7', '32031422', '47058079');

INSERT INTO public."Movie"(
	"movieID", title, "releaseDate", rating, budget, gross)
	VALUES (5, 'Pontiac Moon', '2019-12-16', '7.7', '29866251', '88857483');


INSERT INTO public."Cinema"(
	"cinemaID", "movieID", "locationID", name)
	VALUES (1, 1, 1, 'Cinemas');

INSERT INTO public."Cinema"(
	"cinemaID", "movieID", "locationID", name)
	VALUES (2, 2, 2, 'Cineworld');

INSERT INTO public."Cinema"(
	"cinemaID", "movieID", "locationID", name)
	VALUES (3, 3, 3, 'Cinemark');

INSERT INTO public."Cinema"(
	"cinemaID", "movieID", "locationID", name)
	VALUES (4, 4, 4, 'Cineplex');

INSERT INTO public."Cinema"(
	"cinemaID", "movieID", "locationID", name)
	VALUES (5, 5, 5, 'Cinemex');


INSERT INTO public."ActsIn"(
	"actorID", "movieID")
	VALUES (1, 1);

INSERT INTO public."ActsIn"(
	"actorID", "movieID")
	VALUES (2, 2);

INSERT INTO public."ActsIn"(
	"actorID", "movieID")
	VALUES (3, 3);

INSERT INTO public."ActsIn"(
	"actorID", "movieID")
	VALUES (4, 4);

INSERT INTO public."ActsIn"(
	"actorID", "movieID")
	VALUES (5, 5);

INSERT INTO public."Director"(
	"directorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "yearOfBirth")
	VALUES (1, 1, 1, 1, 'Claudell', 'Papen', '1972-10-27');

INSERT INTO public."Director"(
	"directorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "yearOfBirth")
	VALUES (2, 2, 2, 2, 'Deanna', 'Knowlton', '1981-06-11');

INSERT INTO public."Director"(
	"directorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "yearOfBirth")
	VALUES (3, 3, 3, 3, 'Adaline', 'Wann', '1973-08-26');

INSERT INTO public."Director"(
	"directorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "yearOfBirth")
	VALUES (4, 4, 4, 4, 'Carlota', 'Dilliway', '1968-04-27');

INSERT INTO public."Director"(
	"directorID", "locationID", "departmentID", "universityID", "First Name", "Surname", "yearOfBirth")
	VALUES (5, 5, 5, 5, 'Lars', 'Gaudon', '1988-11-06');


INSERT INTO public."DirectedBy"(
	"directorID", "movieID")
	VALUES (1, 1);

INSERT INTO public."DirectedBy"(
	"directorID", "movieID")
	VALUES (2, 2);

INSERT INTO public."DirectedBy"(
	"directorID", "movieID")
	VALUES (3, 3);

INSERT INTO public."DirectedBy"(
	"directorID", "movieID")
	VALUES (4, 4);

INSERT INTO public."DirectedBy"(
	"directorID", "movieID")
	VALUES (5, 5);


INSERT INTO public."MovieType"(
	genre, description)
	VALUES ('Drama', null);

INSERT INTO public."MovieType"(
	genre, description)
	VALUES ('Drama1', null);

INSERT INTO public."MovieType"(
	genre, description)
	VALUES ('Comedy', null);

INSERT INTO public."MovieType"(
	genre, description)
	VALUES ('Documentary', null);

INSERT INTO public."MovieType"(
	genre, description)
	VALUES ('Comedy1', null);


INSERT INTO public."Genres"(
	genre, "movieID")
	VALUES ('Drama', 1);

INSERT INTO public."Genres"(
	genre, "movieID")
	VALUES ('Drama1', 2);

INSERT INTO public."Genres"(
	genre, "movieID")
	VALUES ('Comedy', 3);

INSERT INTO public."Genres"(
	genre, "movieID")
	VALUES ('Documentary', 4);

INSERT INTO public."Genres"(
	genre, "movieID")
	VALUES ('Comedy1', 5);


INSERT INTO public."IsAwarded"(
	"movieID", "awardID", category)
	VALUES (1, 1, 'female actor');

INSERT INTO public."IsAwarded"(
	"movieID", "awardID", category)
	VALUES (2, 2, 'actor');

INSERT INTO public."IsAwarded"(
	"movieID", "awardID", category)
	VALUES (3, 3, 'director');

INSERT INTO public."IsAwarded"(
	"movieID", "awardID", category)
	VALUES (4, 4, 'movie');

INSERT INTO public."IsAwarded"(
	"movieID", "awardID", category)
	VALUES (5, 5, 'best music');



INSERT INTO public."MovieFestival"(
	"festivalName", "movieID")
	VALUES ('Venice International', 1);

INSERT INTO public."MovieFestival"(
	"festivalName", "movieID")
	VALUES ('The Cannes', 2);

INSERT INTO public."MovieFestival"(
	"festivalName", "movieID")
	VALUES ('TriBeCa', 3);

INSERT INTO public."MovieFestival"(
	"festivalName", "movieID")
	VALUES ('Taormina', 4);

INSERT INTO public."MovieFestival"(
	"festivalName", "movieID")
	VALUES ('Sundance', 5);


INSERT INTO public."Quote"(
	quote, "movieID", "actorID")
	VALUES ('Frankly, my dear, I don''t give a damn', 1, 1);

INSERT INTO public."Quote"(
	quote, "movieID", "actorID")
	VALUES ('I''m gonna make him an offer he can''t refuse.', 2, 2);

INSERT INTO public."Quote"(
	quote, "movieID", "actorID")
	VALUES ('You don''t understand! I coulda had class', 3, 3);

INSERT INTO public."Quote"(
	quote, "movieID", "actorID")
	VALUES ('Toto, I''ve a feeling we''re not in Kansas anymore.', 4, 4);

INSERT INTO public."Quote"(
	quote, "movieID", "actorID")
	VALUES ('Here''s looking at you, kid.', 5, 5);



INSERT INTO public."Ticket"(
	"ticketID", "cinemaID", "movieID", price, "time", duration, type)
	VALUES (1, 1, 1, '11.50', '8:00:09', '1.96', regular);

INSERT INTO public."Ticket"(
	"ticketID", "cinemaID", "movieID", price, "time", duration, type)
	VALUES (2, 2, 2, '6.97', '4:05:32', '1.73', regular);

INSERT INTO public."Ticket"(
	"ticketID", "cinemaID", "movieID", price, "time", duration, type)
	VALUES (3, 3, 3, '16.75', '12:36:56', '2.56', regular);

INSERT INTO public."Ticket"(
	"ticketID", "cinemaID", "movieID", price, "time", duration, type)
	VALUES (4, 4, 4, '12.70', '9:42:23', '2.08', 'Imax');

INSERT INTO public."Ticket"(
	"ticketID", "cinemaID", "movieID", price, "time", duration, type)
	VALUES (5, 5, 5, '16.45', '6:41:50', '1.09', '3d');



