# Day 00 — SQL Bootcamp

## _Relational Data Model and SQL_

In this project you will learn how to create SQL queries using inner subqueries in the FROM and SELECT clauses, as well as filter data by date range.

You will practice skills in working with selection conditions, sorting by multiple fields with different directions, and structuring queries to retrieve the required information.

These skills will be useful for data analysis, report generation, and developing applications that interact with databases.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents
- [How to learn at «School 21»](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#how-to-learn-at-school-21)
- [Chapter I](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#chapter-i)
- [Preamble](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#preamble)
- [Chapter II](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#chapter-ii)
- [Rules of the day](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#rules-of-the-day)
- [Chapter III](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#chapter-iii)
- [First steps into SQL world](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#first-steps-into-sql-world)
- [Exercise 00](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-00)
- [Exercise 01](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-01)
- [Exercise 02](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-02)
- [Exercise 03](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-03)
- [Exercise 04](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-04)
- [Exercise 05](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-05)
- [Exercise 06](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-06)
- [Exercise 07](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-07)
- [Exercise 08](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-08)
- [Exercise 09](https://repos.21-school.ru/masters/SQL_beginner._Day00.ID_574086#exercise-09)


## How to learn at «School 21»
1. «School 21» might feel different from your previous educational experiences. It emphasizes high autonomy: you’re given a task, and you must complete it. Throughout the course, you are expected to delve deeper into the subject and solve problems. Use all available means to find information—the resources of the internet are limitless. Be mindful of your sources (for example, if you use AI tools): verify, think, analyze, and compare.
2. You will need to present your solution to other students and receive feedback from them. Peer-to-peer (P2P) learning is a process where students exchange knowledge and experience, simultaneously acting as both mentors and learners. This way you can learn not only from materials but also from each other.
3. Don’t hesitate to ask for help: around you are peers who are also navigating this path for the first time. Likewise, don’t be afraid to respond to requests for help—your experience is valuable and useful, so share it openly with others. Join RocketChat to stay updated with the latest community announcements.
4. Your learning will be meaningless if you simply copy others’ solutions. If you receive help, always make sure you fully understand the why, how, and purpose behind it. Don’t be afraid to make mistakes.
5. If you’re stuck on something and feel like you’ve tried everything but still don’t know what to do—just take a break! Believe it or not, this advice has helped many professionals in their work. Step away, clear your mind, and the right solution might just come to you next time!
6. The learning process is just as important as the result. It’s not just about solving the task—it’s about understanding how to solve it.

How to work with the project: 
1. Before starting, clone the project from GitLab into a repository of the same name.
2. All code files must be created in the src/ folder of the cloned repository.
3. After cloning, create a develop branch and push changes to it in GitLab. Push to GitLab in the develop branch as well.

## Chapter I
## Preamble

![D01_01](misc/images/D01_01.png)

Standards are everywhere, and Relational Databases are also under control as well :-). To be honest between us, more restricted SQL standards were at the beginning of 2000 years. Actually when the “Big Data” pattern was born, Relational Databases had their own way to realize this pattern and therefore standards are more... lightweight right now. 

![D01_02](misc/images/D01_02.png)

Please take a look at some SQL standards below and try to think about the future of Relational Databases.

|  |  |
| ------ | ------ |
| ![D01_03](misc/images/D01_03.png) | ![D01_04](misc/images/D01_04.png) |
| ![D01_05](misc/images/D01_05.png) | ![D01_06](misc/images/D01_06.png) |
| ![D01_07](misc/images/D01_07.png) | ![D01_08](misc/images/D01_08.png) |


## Chapter II
## Rules of the day

- Make sure you are using the latest version of PostgreSQL.
- It is perfectly fine if you use the IDE to write source code (aka SQL script).
- You should not leave any files in your directory other than those explicitly specified by the exercise instructions. It is recommended that you modify your `.gitignore' to avoid accidents.
-  Please make sure you have your own database and access to it on your PostgreSQL cluster.
- Please download a [script](materials/model.sql) with Database Model here and apply the script to your database (you can use command line with psql or just run it through any IDE, for example DataGrip from JetBrains or pgAdmin from PostgreSQL community). 
- All tasks contain a list of Allowed and Denied sections with listed database options, database types, SQL constructions etc. Please have a look at the section before you start.
- And may the SQL-Force be with you!
- Absolutely anything can be represented in SQL! Let's get started and have fun!


- Please have a look at the Logical View of our Database Model. 

![schema](misc/images/schema.png)


1. **pizzeria** table (Dictionary Table with available pizzerias)
- field id — primary key
- field name — name of pizzeria
- field rating — average rating of pizzeria (from 0 to 5 points)
2. **person** table (Dictionary Table with persons who loves pizza)
- field id — primary key
- field name — name of person
- field age — age of person
- field gender — gender of person
- field address — address of person
3. **menu** table (Dictionary Table with available menu and price for concrete pizza)
- field id — primary key
- field pizzeria_id — foreign key to pizzeria
- field pizza_name — name of pizza in pizzeria
- field price — price of concrete pizza
4. **person_visits** table (Operational Table with information about visits of pizzeria)
- field id — primary key
- field person_id — foreign key to person
- field pizzeria_id — foreign key to pizzeria
- field visit_date — date (for example 2022-01-01) of person visit 
5. **person_order** table (Operational Table with information about persons orders)
- field id — primary key
- field person_id — foreign key to person
- field menu_id — foreign key to menu
- field order_date — date (for example 2022-01-01) of person order 

People's visit and people's order are different entities and don't contain any correlation between data. For example, a customer can be in a restaurant (just looking at the menu) and at the same time place an order in another restaurant by phone or mobile application. Or another case, just be at home and again make a call with order without any visits.

Make sure to check out the materials in the 'Materials' section—they’ll be really helpful for your project.

## Chapter III
## First steps into SQL world
## Exercise 00

| Exercise 00: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex00                                                                                                                     |
| Files to turn-in                      | `day00_ex00.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Let’s make our first task. 
Please make a select statement which returns all person's names and person's ages from the city ‘Kazan’.


## Exercise 01<a name="Exercise 01"></a>

| Exercise 01: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex01                                                                                                                     |
| Files to turn-in                      | `day00_ex01.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make a select statement which returns names , ages for all women from the city ‘Kazan’. Yep, and please sort result by name.

## Exercise 02<a name="Exercise 02"></a>

| Exercise 02: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex02                                                                                                                     |
| Files to turn-in                      | `day00_ex02.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make 2 syntax different select statements which return a list of pizzerias (pizzeria name and rating) with rating between 3.5 and 5 points (including limit points) and ordered by pizzeria rating.
- the 1st select statement must contain comparison signs  (<=, >=);
- the 2nd select statement must contain `BETWEEN` keyword.


## Exercise 03<a name="Exercise 03"></a> 

| Exercise 03: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex03                                                                                                                     |
| Files to turn-in                      | `day00_ex03.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make a select statement that returns the person identifiers (without duplicates) who visited pizzerias in a period from January 6, 2022 to January 9, 2022 (including all days) or visited pizzerias with identifier 2. Also include ordering clause by person identifier in descending mode.

## Exercise 04<a name="Exercise 04"></a> 


| Exercise 04: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex04                                                                                                                     |
| Files to turn-in                      | `day00_ex04.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Please make a select statement which returns one calculated field with name ‘person_information’ in one string like described in the next sample:

`Anna (age:16,gender:'female',address:'Moscow')`

Finally, please add the ordering clause by calculated column in ascending mode.
Please pay attention to the quotation marks in your formula!

## Exercise 05<a name="Exercise 05o"></a> 


| Exercise 05: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex05                                                                                                                     |
| Files to turn-in                      | `day00_ex05.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                           
| SQL Syntax Construction                        | `IN`, any types of `JOINs`                                                                                              |

Write a select statement that returns the names of people (based on an internal query in the `SELECT` clause) who placed orders for the menu with identifiers 13, 14, and 18, and the date of the orders should be January 7, 2022. Be careful with "Denied Section" before your work.

Please take a look at the pattern of internal query.

    SELECT 
	    (SELECT ... ) AS NAME  -- this is an internal query in a main SELECT clause
    FROM ...
    WHERE ...

## Exercise 06<a name="Exercise 06"></a> 


| Exercise 06: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex06                                                                                                                     |
| Files to turn-in                      | `day00_ex06.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                           
| SQL Syntax Construction                        | `IN`, any types of `JOINs`                                                                                              |

Use the SQL construction from Exercise 05 and add a new calculated column (use column name ‘check_name’) with a check statement a pseudocode for this check is given below) in the `SELECT` clause.

    if (person_name == 'Denis') then return true
        else return false

## Exercise 07<a name="Exercise 07"></a> 


| Exercise 07: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex07                                                                                                                     |
| Files to turn-in                      | `day00_ex07.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Let's apply data intervals to the `person` table. 
Please make an SQL statement that returns the identifiers of a person, the person's names, and the interval of the person's ages (set a name of a new calculated column as 'interval_info') based on the pseudo code below.

    if (age >= 10 and age <= 20) then return 'interval #1'
    else if (age > 20 and age < 24) then return 'interval #2'
    else return 'interval #3'

And yes... please sort a result by ‘interval_info’ column in ascending mode.

## Exercise 08<a name="Exercise 08"></a> 


| Exercise 08: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex08                                                                                                                     |
| Files to turn-in                      | `day00_ex08.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |

Create an SQL statement that returns all columns from the `person_order` table with rows whose identifier is an even number. The result must be ordered by the returned identifier.

## Exercise 09<a name="Exercise 09"></a> 


| Exercise 09: First steps into SQL world |                                                                                                                          |
|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Turn-in directory                     | ex09                                                                                                                     |
| Files to turn-in                      | `day00_ex09.sql`                                                                                 |
| **Allowed**                               |                                                                                                                          |
| Language                        | ANSI SQL                                                                                              |
| **Denied**                               |                                           
| SQL Syntax Construction                        | any types of `JOINs`                                                                                              |


Please make a select statement that returns person names and pizzeria names based on the `person_visits` table with a visit date in a period from January 07 to January 09, 2022 (including all days) (based on an internal query in the `FROM' clause).


Please take a look at the pattern of the final query.

    SELECT (...) AS person_name ,  -- this is an internal query in a main SELECT clause
            (...) AS pizzeria_name  -- this is an internal query in a main SELECT clause
    FROM (SELECT … FROM person_visits WHERE …) AS pv -- this is an internal query in a main FROM clause
    ORDER BY ...

Please add a ordering clause by person name in ascending mode and by pizzeria name in descending mode.

