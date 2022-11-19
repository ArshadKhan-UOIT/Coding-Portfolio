import psycopg2

try:

    conn = psycopg2.connect(database = "PhaseIT2", user = "postgres", password = "arshad khan", host = "localhost", port = 5432)
    cursor = conn.cursor()
    

    #   -----------------------------------------------------------------------------------------------
    #   NOT PASSING PARAMETERS AS VARIABLES
    #   -----------------------------------------------------------------------------------------------


    try:
        cursor.execute(
        """
        INSERT INTO "Location"(
            "locationID",
            "nameCity",
            "nameState",
            "nameCountry"
        )
        VALUES (
            6,
            'Toronto',
            'Ontario',
            'Canada'
        )
        """);
        print("Done Insert Location")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Location')

    try:
        cursor.execute(
        """
        INSERT INTO "University"(
            "universityID",
            name,
            description,
            "numStudents",
            colour
        )
        VALUES (
            6,
            'Ontario Tech U',
            null,
            '10000',
            'Blue'
        )
        """);
        print("Done Insert University")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error University')

    try:
        cursor.execute(
        """
        INSERT INTO "Department"(
            "departmentID",
            "universityID",
            program,
            description,
            "numStudents"
        )
        VALUES (
            6,
            6,
            'Computer Science',
            null,
            1000
        )
        """);
        print("Done Insert Department")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Department')

    try:
        cursor.execute(
        """
        INSERT INTO "Actor"(
            "actorID",
            "locationID",
            "departmentID",
            "universityID",
            "First Name",
            "Surname",
            "eyeColour",
            "dateOfBirth"
        )
        VALUES (
            6,
            6,
            6,
            6,
            'Henry',
            'Cavill',
            'Blue',
            '1983-05-05'
        )
        """);
        print("Done Insert Actor")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Actor')

    try:
        cursor.execute(
        """
        INSERT INTO "Award"(
            "awardID",
            category
        )
        VALUES (
            6,
            'director'
        )
        """);
        print("Done Insert Award")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Award')

    try:
        cursor.execute(
        """
        INSERT INTO "Movie"(
            "movieID",
            title,
            "releaseDate",
            rating,
            budget,
            gross
        )
        VALUES (
            6,
            'Tenet',
            '2020-08-26',
            '7.7',
            205000000,
            356300000 
        )
        """);
        print("Done Insert Movie")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Movie')

    try:
        cursor.execute(
        """
        INSERT INTO "Cinema"(
            "cinemaID",
            "movieID",
            "locationID",
            name
        )
        VALUES (
            6,
            6,
            6,
            'Cineplex'
        )
        """);
        print("Done Insert Cinema")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Cinema')

    try:
        cursor.execute(
        """
        INSERT INTO "ActsIn"(
            "actorID",
            "movieID"
        )
        VALUES (
            6,
            6
        )
        """);
        print("Done Insert ActsIn")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error ActsIn')

    try:
        cursor.execute(
        """
        INSERT INTO "Director"(
            "directorID",
            "locationID",
            "departmentID",
            "universityID",
            "First Name",
            "Surname",
            "yearOfBirth"
        )
        VALUES (
            6,
            6,
            6,
            6,
            'Christopher',
            'Nolan',
            '1970-07-30'
        )
        """);
        print("Done Insert Director")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Director')

    try:
        cursor.execute(
        """
        INSERT INTO "DirectedBy"(
            "directorID",
            "movieID"
        )
        VALUES (
            6,
            6
        )
        """);
        print("Done Insert DirectedBy")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error DirectedBy')

    try:
        cursor.execute(
        """
        INSERT INTO "MovieType"(
            genre,
            description
        )
        VALUES (
            'Action',
            null 
        )
        """);
        print("Done Insert MovieType")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error MovieType')

    try:
        cursor.execute(
        """
        INSERT INTO "Genres"(
            genre,
            "movieID"
        )
        VALUES (
            'Action',
            6
        )
        """);
        print("Done Insert Genres")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Genres')

    try:
        cursor.execute(
        """
        INSERT INTO "IsAwarded"(
            "movieID",
            "awardID",
            category
        )
        VALUES (
            6,
            6,
            'director'
        )
        """);
        print("Done Insert IsAwarded")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error IsAwarded')

    try:
        cursor.execute(
        """
        INSERT INTO "MovieFestival"(
            "festivalName",
            "movieID"
        )
        VALUES (
            'Ontario Place',
            6 
        )
        """);
        print("Done Insert MovieFestival")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error MovieFestival')

    try:
        cursor.execute(
        """
        INSERT INTO "Quote"(
            quote,
            "movieID",
            "actorID"
        )
        VALUES (
            'You Have To Start Looking At The World In A New Way.',
            6,
            6 
        )
        """);
        print("Done Insert Quote")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Quote')

    try:
        cursor.execute(
        """
        INSERT INTO "Ticket"(
            "ticketID",
            "cinemaID",
            "movieID",
            price,
            "time",
            duration,
            type
        )
        VALUES (
            6,
            6,
            6,
            '5.00',
            '7:30:00',
            '2.50',
            'Imax' 
        )
        """);
        print("Done Insert Ticket")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Ticket')



    #   -----------------------------------------------------------------------------------------------
    #   PASSING PARAMETERS AS VARIABLES
    #   -----------------------------------------------------------------------------------------------


    try:
        s = """INSERT INTO "Location"(
                "locationID",
                "nameCity",
                "nameState",
                "nameCountry"
            )
            VALUES (
                %s,
                %s,
                %s,
                %s
            )
            """
        v1 = 7
        v2 = "Toronto"
        v3 = "Ontario"
        v4 = "Canada"
        cursor.execute(s, (v1,v2,v3,v4))  

        print("Done Insert Location Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Location Variable')

    try:
        s = """INSERT INTO "University" (
                "universityID", 
                name, 
                description, 
                "numStudents", 
                colour
            ) 
            VALUES (
                %s, 
                %s, 
                %s, 
                %s, 
                %s
            )
            """
        v1 = 7
        v2 = "Ontario Tech U"
        v3 = None
        v4 = 10000
        v5 = "Blue"
        cursor.execute(s, (v1,v2,v3,v4,v5))
        print("Done Insert University Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error University Variable')
    
    try:
        s = """INSERT INTO "Department"(
                "departmentID",
                "universityID",
                program,
                description,
                "numStudents"
            )
            VALUES (
                %s,
                %s,
                %s,
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        v3 = "Computer Science"
        v4 = None
        v5 = 1000
        cursor.execute(s, (v1,v2,v3,v4,v5))    
        print("Done Insert Department Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Department Variable')

    try:
        s = """INSERT INTO "Actor"(
                "actorID",
                "locationID",
                "departmentID",
                "universityID",
                "First Name",
                "Surname",
                "eyeColour",
                "dateOfBirth"
            )
            VALUES (
                %s,
                %s,
                %s,
                %s,
                %s,
                %s,
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        v3 = 7
        v4 = 7
        v5 = "Henry"
        v6 = "Cavill"
        v7 = "Blue"
        v8 = "1983-05-05"
        cursor.execute(s, (v1,v2,v3,v4,v5,v6,v7,v8))  
        print("Done Insert Actor Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Actor Variable')
    
    try:
        s = """INSERT INTO "Award"(
                "awardID",
                category
            )
            VALUES (
                %s,
                %s
            )
            """
        v1 = 7
        v2 = "director"
        cursor.execute(s, (v1,v2))    
        print("Done Insert Award Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Award Variable')

    try:
        s = """INSERT INTO "Movie"(
                "movieID",
                title,
                "releaseDate",
                rating,
                budget,
                gross
            )
            VALUES (
               %s,
               %s,
               %s,
               %s,
               %s,
               %s
            )
            """
        v1 = 7
        v2 = "Tenet"
        v3 = "2020-08-26"
        v4 = 7.7
        v5 = 205000000,
        v6 = 356300000
        cursor.execute(s, (v1,v2,v3,v4,v5,v6))
        print("Done Insert Movie Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Movie Variable')

    try:
        s = """INSERT INTO "ActsIn"(
                "actorID",
                "movieID"
            )
            VALUES (
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        cursor.execute(s, (v1,v2))    
        print("Done Insert ActsIn Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error ActsIn Variable')


    try:
        s = """INSERT INTO "Cinema"(
                "cinemaID",
                "movieID",
                "locationID",
                name
            )
            VALUES (
                %s,
                %s,
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        v3 = 7
        v4 = "Cineplex"
        cursor.execute(s, (v1,v2,v3,v4))    
        print("Done Insert Cinema Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Cinema Variable')

    try:
        s = """INSERT INTO "Director"(
                "directorID",
                "locationID",
                "departmentID",
                "universityID",
                "First Name",
                "Surname",
                "yearOfBirth"
            )
            VALUES (
                %s,
                %s,
                %s,
                %s,
                %s,
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        v3 = 7
        v4 = 7
        v5 = "Christopher"
        v6 = "Nolan"
        v7 = "1970-07-30"
        cursor.execute(s, (v1,v2,v3,v4,v5,v6,v7))
        print("Done Insert Director Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Director Variable')

    try:
        s = """INSERT INTO "DirectedBy"(
                "directorID",
                "movieID"
            )
            VALUES (
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        cursor.execute(s, (v1,v2))
        print("Done Insert DirectedBy Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error DirectedBy Variable')
    
    try:
        s = """INSERT INTO "MovieType"(
                genre,
                description
            )
            VALUES (
                %s,
                %s
            )
            """
        v1 = "Mystery"
        v2 = None
        cursor.execute(s, (v1,v2))
        print("Done Insert MovieType Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error MovieType Variable')

    try:
        s = """INSERT INTO "Genres"(
                genre,
                "movieID"
            )
            VALUES (
                %s,
                %s
            )
            """
        v1 = "Mystery"
        v2 = 7
        cursor.execute(s, (v1,v2))
        print("Done Insert Genres Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Genres Variable')

    try:
        s = """INSERT INTO "IsAwarded"(
                "movieID",
                "awardID",
                category
            )
            VALUES (
                %s,
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        v3 = "director"
        cursor.execute(s, (v1,v2,v3))
        print("Done Insert IsAwarded Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error IsAwarded Variable')

    try:
        s ="""INSERT INTO "MovieFestival"(
                "festivalName",
                "movieID"
            )
            VALUES (
                %s,
                %s
            )
            """
        v1 = "Ontario Place 1"
        v2 = 7
        cursor.execute(s, (v1,v2))
        print("Done Insert MovieFestival Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error MovieFestival Variable')

    try:
        s = """INSERT INTO "Quote"(
                quote,
                "movieID",
                "actorID"
            )
            VALUES (
                %s,
                %s,
                %s
            )
            """
        v1 = "That Part Is, A Little Dramatic."
        v2 = 7
        v3 = 7
        cursor.execute(s, (v1,v2,v3))
        print("Done Insert Quote Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Quote Variable')

    try:
        s = """INSERT INTO "Ticket"(
                "ticketID",
                "cinemaID",
                "movieID",
                price,
                "time",
                duration,
                type
            )
            VALUES (
                %s,
                %s,
                %s,
                %s,
                %s,
                %s,
                %s
            )
            """
        v1 = 7
        v2 = 7
        v3 = 7
        v4 = "5.00"
        v5 = "7:30:00"
        v6 = 2.50
        v7 = "Imax"
        cursor.execute(s, (v1,v2,v3,v4,v5,v6,v7))
        print("Done Insert Ticket Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Ticket Variable')


    #   -----------------------------------------------------------------------------------------------
    #   NOT PASSING PARAMETERS AS VARIABLES
    #   -----------------------------------------------------------------------------------------------

    
    try:
        print()
        cursor.execute(
        """
        SELECT AVG(date_part('year', age("Actor"."dateOfBirth"))) AS "Average Age"
        FROM public."Actor";
        """);

        rows = cursor.fetchall()

        print("Average Age")
        print("-----------")
        for i in rows:
            print(i[0])
            print()    
        print()

        print("Done Select")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Select')


    #   -----------------------------------------------------------------------------------------------
    #   PASSING PARAMETERS AS VARIABLES
    #   -----------------------------------------------------------------------------------------------


    try:
        print()
        s = """SELECT title 
                FROM public."Director" 
                LEFT JOIN public."Movie" 
                ON "Director"."directorID" = "Movie"."movieID" 
                WHERE "Director"."First Name" = %s AND "Director"."Surname" = %s;
            """
        v1 = "Claudell"
        v2 = "Papen"
        cursor.execute(s, (v1,v2))

        rows = cursor.fetchall()

        print("title")
        print("-----")
        for i in rows:
            print(i[0])
            print()    
        print()

        print("Done Select Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Select Variable')

    try:
        print()
        s = """SELECT "directorID", "First Name", "Surname", "yearOfBirth" 
                FROM public."Director" 
                LEFT JOIN public."Location"
                ON "Director"."locationID" = "Location"."locationID"
                WHERE "Location"."nameCountry" = %s;
            """
        v1 = "USA"
        cursor.execute(s, (v1,))

        rows = cursor.fetchall()

        print("directorID\tFirst Name\tSurname\t\tDateOfBirth")
        print("-------------------------------------------------------------")
        
        for i in rows:
            print(i[0],'\t\t',i[1],'\t',i[2],'\t\t',i[3])
        print()

        print("Done Select Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Select Variable')

    try:
        print()
        s = """SELECT "directorID", "First Name", "Surname"
                FROM public."Director"
                WHERE "Director"."Surname" LIKE %s OR "Director"."Surname" LIKE %s;
            """
        v1 = "A%"
        v2 = "D%"
        cursor.execute(s, (v1,v2))

        rows = cursor.fetchall()

        print("directorID\tFirst Name\tSurname")
        print("-----------------------------------------")
        
        for i in rows:
            print(i[0],'\t\t',i[1],'\t',i[2])
        print()

        print("Done Select Variable")
        # conn.commit()
    except psycopg2.DatabaseError as error:
        print(f'Error {error}')
        print('Error Select Variable')

    conn.commit()
    conn.close()

except psycopg2.DatabaseError as error:
    print(f'Error {error}')
    print("Error Connection")